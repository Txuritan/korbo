cmake_minimum_required(VERSION 3.8)

project(json VERSION 1.0.0 LANGUAGES C CXX)

file(GLOB JSON_SRC src/*.*)
add_library(json SHARED ${JSON_SRC})
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/src CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)