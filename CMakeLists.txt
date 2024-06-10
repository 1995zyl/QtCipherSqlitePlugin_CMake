cmake_minimum_required(VERSION 3.18)

project(sqlitecipher
    VERSION 1.0
    DESCRIPTION "sqlitecipher by cmake"
    HOMEPAGE_URL "https://github.com/1995zyl/sqlitecipher"
    # LANGUAGES CXX
)

set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)

set(CMAKE_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(${CMAKE_INCLUDE_PATH}/qt_library.cmake)
find_qt_package()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
message(STATUS "CMAKE_BUILD_TYPE = " ${CMAKE_BUILD_TYPE})

# compile third_party SQLite3MultipleCiphers
if (WIN32)
    if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
        set(MSVC_CONFIG_MODE Debug)
        set(SQLITE3MC_LIB_PATH ${PROJECT_SOURCE_DIR}/SQLite3MultipleCiphers/bin/vc17/lib/debug)
    else ()
        set(MSVC_CONFIG_MODE Release)
        set(SQLITE3MC_LIB_PATH ${PROJECT_SOURCE_DIR}/SQLite3MultipleCiphers/bin/vc17/lib/release)
    endif ()
    if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/SQLite3MultipleCiphers/bin)
        execute_process(COMMAND msbuild ${CMAKE_CURRENT_SOURCE_DIR}/SQLite3MultipleCiphers/build/sqlite3mc_vc17.sln 
            /p:Configuration=${MSVC_CONFIG_MODE}
            WORKING_DIRECTORY D:/Microsoft\ Visual\ Studio/2022/Community/MSBuild/Current/Bin)
    endif()
else ()

endif ()
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/SQLite3MultipleCiphers/Src)

add_subdirectory(sqlitecipher)
# add_subdirectory(test_demo)

copy_qt_plugins()
copy_qt_essential_dll()

# INSTALL(DIRECTORY ${RESOURCE_PATH}
#     DESTINATION ${CMAKE_INSTALL_PREFIX}
# )