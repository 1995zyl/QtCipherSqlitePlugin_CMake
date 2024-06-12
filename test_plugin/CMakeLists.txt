set(TARGET test_plugin)

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Test REQUIRED)

add_executable(${TARGET} "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

target_include_directories(${TARGET} PRIVATE 
       ${QT_SDK_DIR}/include/QtSql/6.5.2
       ${QT_INSTALL_PATH_PREFIX}/qtbase/include/QtSql
)

target_link_libraries(${TARGET}
       PUBLIC
       Qt${QT_VERSION_MAJOR}::Core
       Qt${QT_VERSION_MAJOR}::Sql
       Qt${QT_VERSION_MAJOR}::Test
)

macro(copy_qt_essential_dll)
    if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
        file(GLOB QT_ESSENTIAL_DLL 
            "${QT_SDK_DIR}/bin/Qt6Cored.dll"
            "${QT_SDK_DIR}/bin/Qt6Sqld.dll"
        )
    else ()
        file(GLOB QT_ESSENTIAL_DLL 
            "${QT_SDK_DIR}/bin/Qt6Core.dll"
            "${QT_SDK_DIR}/bin/Qt6Sql.dll"
        )
    endif ()
    file(COPY ${QT_ESSENTIAL_DLL} DESTINATION ${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
endmacro()

add_custom_command(TARGET ${TARGET} 
       POST_BUILD
       COMMAND ${CMAKE_COMMAND} -E copy_directory 
       "${QT_INSTALL_PATH_PREFIX}/qtbase/plugins"
       "${PROJECT_SOURCE_DIR}/bin/${QT_PLUGINS_COPY_DIR}"
)