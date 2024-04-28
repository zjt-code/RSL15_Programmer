cmake_minimum_required(VERSION 3.5)
set(Qt5_DIR "D:/Qt/Qt5.12.9/5.12.9/msvc2017_64/lib/cmake/Qt5")

project(P3A_RSL15_Programmer LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#plantform is X64
add_compile_definitions(_AMD64_)


# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(P3A_RSL15_Programmer SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    optiondialog.cpp
    optiondialog.h
    optiondialog.ui
  )
else()
  add_executable(P3A_RSL15_Programmer
    #WIN32    # cancel consol
    main.cpp
    mainwindow.cpp
    mainwindow.h
    optiondialog.cpp
    optiondialog.h
    optiondialog.ui
    JLink_API_Typedef.h
    mainwindow.ui
    cgms_prm.h
    myutils.cpp
    myutils.h
    # myoptiondialog.h
    # myoptiondialog.cpp
  )
endif()

target_link_libraries(P3A_RSL15_Programmer PRIVATE Qt5::Widgets)
