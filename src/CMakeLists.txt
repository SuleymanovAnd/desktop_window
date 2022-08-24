cmake_minimum_required(VERSION 3.22)
set( MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

set (SOURCE
        main.cpp
        overflow.cpp
        window_class.cpp)
set (INCLUDE
      ${MY_INCLUDE}/overflow.h
      ${MY_INCLUDE}/window_class.h
      ${MY_INCLUDE}/monitor.h
        window_class.cpp)

add_executable(desktop_window ${INCLUDE} ${SOURCE} )
target_include_directories(desktop_window PUBLIC ${MY_INCLUDE})