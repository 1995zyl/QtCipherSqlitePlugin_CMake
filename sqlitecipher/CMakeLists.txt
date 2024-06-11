set(TARGET sqlitecipher)

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
add_library(${TARGET} SHARED ${target_include_file} ${target_source_file})
target_include_directories(${TARGET} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

if(WIN32)
       if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
              set_target_properties(${TARGET} PROPERTIES OUTPUT_NAME "sqlitecipherd")
       else ()
              set_target_properties(${TARGET} PROPERTIES OUTPUT_NAME "sqlitecipher")
       endif ()
endif ()

add_definitions(-DQT_PLUGIN)

target_include_directories(${TARGET} PUBLIC 
       ${QT_SDK_DIR}/include/QtSql/6.5.2
       ${QT_SDK_DIR}/include/QtCore/6.5.2
       ${QT_SDK_DIR}/include/QtCore/6.5.2/QtCore
)

target_link_libraries(${TARGET}
       PUBLIC
       Qt${QT_VERSION_MAJOR}::Core
       Qt${QT_VERSION_MAJOR}::Sql
       ${SQLITE3MC_LIB_PATH}
)

if (WIN32)
    INSTALL(TARGETS ${TARGET} RUNTIME DESTINATION ${QT_SDK_DIR}/plugins/sqldrivers)
elseif (UNIX)
    INSTALL(TARGETS ${TARGET}  DESTINATION ${QT_SDK_DIR}/plugins/sqldrivers)
endif ()

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
       set(SQLITECIPHER_PDB ${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}/sqlitecipherd.pdb)
else ()
       set(SQLITECIPHER_PDB ${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}/sqlitecipher.pdb)
endif ()
INSTALL(FILES ${SQLITECIPHER_PDB} DESTINATION ${QT_SDK_DIR}/plugins/sqldrivers)
