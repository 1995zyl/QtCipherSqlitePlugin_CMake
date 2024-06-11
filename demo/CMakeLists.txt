set(TARGET test_sqlitecipher)

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Sql REQUIRED)

file(GLOB target_include_file "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB target_source_file "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")
if(MSVC)
       source_group(
       TREE "${CMAKE_CURRENT_SOURCE_DIR}/include"
       PREFIX Include
       FILES ${target_include_file}
       )
endif(MSVC)
if(MSVC)
       source_group(
       TREE "${CMAKE_CURRENT_SOURCE_DIR}/source"
       PREFIX Source
       FILES ${target_source_file}
       )
endif()
add_executable(${TARGET} ${target_include_file} ${target_source_file})

target_include_directories(${TARGET} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(${TARGET} PUBLIC ${PROJECT_SOURCE_DIR}/qt_project/sqlitecipher_plugin/include)

target_link_libraries(${TARGET}
       PUBLIC
       Qt${QT_VERSION_MAJOR}::Core
       Qt${QT_VERSION_MAJOR}::Sql
)
