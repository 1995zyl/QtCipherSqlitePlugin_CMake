macro(find_qt_package)
    if (WIN32)    
        set(QT_SDK_DIR "D:/Qt/6.5.2/msvc2019_64")
    else()
        set(QT_INSTALL_PATH_PREFIX "/Users/wps/wps_branch_3/wps/vcpkg_install/qt5/build_arm64")
        set(QT_SDK_DIR "${QT_INSTALL_PATH_PREFIX}/qtbase/lib/cmake/Qt5")
    endif()

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

    include_directories(
        ${QT_INSTALL_PATH_PREFIX}/qtbase/include
        ${QT_INSTALL_PATH_PREFIX}/qtbase/include/QtSql/5.12.12
        ${QT_INSTALL_PATH_PREFIX}/qtbase/include/QtCore/5.12.12
        ${QT_INSTALL_PATH_PREFIX}/qtbase/include/QtCore/5.12.12/QtCore
    )
endmacro()

