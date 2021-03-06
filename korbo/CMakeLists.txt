cmake_minimum_required(VERSION 3.8)

project(korbo VERSION 1.0.0 LANGUAGES C CXX)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

link_directories(${GTKMM_LIBRARY_DIRS})
include_directories(${GTKMM_INCLUDE_DIRS})
add_definitions(${GTKMM_CFLAGS_OTHER})

include_directories(${kui_INCLUDE_DIRS} ${klogc_INCLUDE_DIRS} ${kfile_INCLUDE_DIRS} ${kio_INCLUDE_DIRS})

file(GLOB KORBO_SRC src/*.*)
if (WIN32)
    add_executable(korbo WIN32 ${KORBO_SRC})
    set_source_files_properties(Main.cpp PROPERTIES COMPILE_DEFINITIONS main=WinMain)
else ()
    add_executable(korbo ${KORBO_SRC})
endif ()
target_link_libraries(korbo ${GTKMM_LIBRARIES} kui klogc kfile kio)