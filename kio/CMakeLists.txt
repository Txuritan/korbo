cmake_minimum_required(VERSION 3.8)

project(kio VERSION 1.0.0 LANGUAGES C CXX)

file(GLOB KIO_SRC src/*.*)
add_library(kio SHARED ${KIO_SRC} src/File.cpp src/File.hpp)
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/src CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)