cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(hog)
set(CMAKE_PREFIX_PATH "/u/faghri/.local/" ${CMAKE_PREFIX_PATH})
# set(CMAKE_MODULE_PATH "/u/faghri/.local/share/OpenCV/" ${CMAKE_MODULE_PATH})
find_package(OpenCV REQUIRED)
find_package(PythonLibs REQUIRED)
message(${OpenCV_DIR})

add_library(hog SHARED main_python.cpp hog.cpp hog.h)
include_directories("/usr/include/python2.7/" "/usr/lib/python2.7/dist-packages/numpy/core/include/numpy/" "/usr/include/")
find_library(LIBBOOSTPYT libboost_python.so)
find_library(LIBBOOSTSYS libboost_system.so)
find_library(LIBBOOSTFSYS libboost_filesystem.so)
target_link_libraries(hog ${OpenCV_LIBS} ${LIBBOOSTPYT} ${LIBBOOSTSYS} ${LIBBOOSTFSYS})



