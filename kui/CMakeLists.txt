cmake_minimum_required(VERSION 3.8)

project(kui VERSION 1.0.0 LANGUAGES C CXX)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})
add_definitions(${GTKMM_CFLAGS_OTHER})

include_directories(${json_INCLUDE_DIRS})

file(GLOB KUI_SRC src/*.*)

add_library(kui SHARED ${KUI_SRC})
target_link_libraries(kui json ${GTKMM_LIBRARIES})
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/src CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)