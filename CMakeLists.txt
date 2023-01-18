cmake_minimum_required(VERSION 3.20)
project(Data-Structure)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD 20)
# 98 11 14 17 20 23 26
message(STATUS "CMAKE_CXX_STANDARD: C++${CMAKE_CXX_STANDARD}")

find_program(CCACHE_FOUND ccache)
if (CCACHE_FOUND)
    message(STATUS "ccache enabled")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif (CCACHE_FOUND)

list(APPEND SOURCE_DIR "Design")

#foreach (dir ${SOURCE_DIR})
#    file(GLOB_RECURSE CPPFILES "${CMAKE_CURRENT_SOURCE_DIR}/${dir}/*.cpp")
#endforeach ()

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_DIR}" CPPFILES)

foreach (file ${CPPFILES})
    get_filename_component(fname ${file} NAME_WE)
    message(STATUS "Adding target for problem ${fname}")
    add_executable(run_${fname} "${file}")
endforeach ()

#set_property(TARGET run_6114 PROPERTY CXX_STANDARD 11)

add_executable(CTF Design/CTF.cpp)