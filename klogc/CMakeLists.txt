cmake_minimum_required(VERSION 3.8)

project(klogc VERSION 1.0.0 LANGUAGES C CXX)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})
add_definitions(${GTKMM_CFLAGS_OTHER})

find_package(Lua51 REQUIRED)
include_directories(${LUA_INCLUDE_DIR} ${kio_INCLUDE_DIRS} ${kfile_INCLUDE_DIRS} ${json_INCLUDE_DIRS})

file(GLOB KLOGC_SRC src/*.*)
add_library(klogc SHARED ${KLOGC_SRC})
target_link_libraries(klogc kio kfile json ${GTKMM_LIBRARIES} ${LUA_LIBRARIES})

set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/src CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)