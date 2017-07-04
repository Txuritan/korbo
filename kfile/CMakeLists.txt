cmake_minimum_required(VERSION 3.8)

project(kfile VERSION 1.0.0 LANGUAGES C CXX)

file(GLOB KFILE_SRC src/*.*)
add_library(kfile SHARED ${KFILE_SRC})
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/src CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)