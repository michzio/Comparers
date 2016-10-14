cmake_minimum_required(VERSION 3.6)
project(Comparers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set(SOURCE_FILES comparer.h comparer.c)

add_library(Comparers_Lib SHARED ${SOURCE_FILES})
set_target_properties(Comparers_Lib PROPERTIES OUTPUT_NAME comparers_shared)

add_library(Comparers_Lib_Static ${SOURCE_FILES})
set_target_properties(Comparers_Lib_Static PROPERTIES OUTPUT_NAME comparers)

add_executable(Comparers main.c)
target_link_libraries(Comparers Comparers_Lib_Static)