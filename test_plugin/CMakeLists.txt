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
       Qt${QT_VERSION_MAJOR}::Test
)

copy_qt_plugins()
copy_qt_essential_dll()
