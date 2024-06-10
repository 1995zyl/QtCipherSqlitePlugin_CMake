macro(find_qt_package)
    set(QT_SDK_DIR "D:/Qt/6.5.2/msvc2019_64")
    if(NOT EXISTS ${QT_SDK_DIR})
        message(STATUS "QT_SDK_DIR not found, try to read from environment variable: QTDIR")
        set(QT_SDK_DIR "$ENV{QTDIR}" CACHE STRING "QT_SDK_DIR read from environment variable: QTDIR" FORCE)
    endif()
    
    set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${QT_SDK_DIR})
    find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Sql REQUIRED)
    find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Sql REQUIRED)
    
    set(CMAKE_GLOBAL_AUTOGEN_TARGET OFF)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_INCLUDE_CURRENT_DIR ON)

    add_definitions(-DQT_SDK_DIR="${QT_SDK_DIR}")
endmacro()

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

macro(copy_qt_plugins)
    file(GLOB QT_PLUGINS_DLL "${QT_SDK_DIR}/plugins")
    file(COPY ${QT_PLUGINS_DLL} DESTINATION ${PROJECT_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
endmacro()
