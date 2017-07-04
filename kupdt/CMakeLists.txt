cmake_minimum_required(VERSION 3.8)

project(kupdt VERSION 1.0.0 LANGUAGES C CXX)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})
add_definitions(${GTKMM_CFLAGS_OTHER})

file(GLOB KUPDT_SRC src/*.*)
file(GLOB KUPDT_UI_SRC src/ui/*.*)
if (WIN32)
    add_executable(kupdt WIN32 ${KUPDT_SRC} ${KUPDT_UI_SRC})
    set_source_files_properties(Main.cpp PROPERTIES COMPILE_DEFINITIONS main=WinMain)
else ()
    add_executable(kupdt ${KUPDT_SRC} ${KUPDT_UI_SRC})
endif ()
target_link_libraries(kupdt ${GTKMM_LIBRARIES})