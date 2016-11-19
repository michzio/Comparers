cmake_minimum_required(VERSION 3.6)
project(Comparers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set(SOURCE_FILES comparer.h comparer.c)

if(CYGWIN)
    message("building for Cygwin")
else()
    message("building for Unix")
endif()

add_library(Comparers_Lib SHARED ${SOURCE_FILES})
set_target_properties(Comparers_Lib PROPERTIES OUTPUT_NAME comparers_shared)

add_library(Comparers_Lib_Static ${SOURCE_FILES})
set_target_properties(Comparers_Lib_Static PROPERTIES OUTPUT_NAME comparers)

add_executable(Comparers main.c)
set_target_properties(Comparers PROPERTIES OUTPUT_NAME comparers)
target_link_libraries(Comparers Comparers_Lib_Static)

# install targets (executables, shared libraries, static libraries) in current project source directory
add_custom_target(Install_${PROJECT_NAME}
                  $(MAKE) install
                  DEPENDS ${PROJECT_NAME}
                  COMMENT "Installing ${PROJECT_NAME}")

if(CYGWIN)
    set(RUNTIME_DEST_DIR ${CMAKE_SOURCE_DIR}/output/windows/bin)
    set(LIBRARY_DEST_DIR ${CMAKE_SOURCE_DIR}/output/windows/lib)
    set(ARCHIVE_DEST_DIR ${CMAKE_SOURCE_DIR}/output/windows/lib/static)
else()
    set(RUNTIME_DEST_DIR ${CMAKE_SOURCE_DIR}/output/unix/bin)
    set(LIBRARY_DEST_DIR ${CMAKE_SOURCE_DIR}/output/unix/lib)
    set(ARCHIVE_DEST_DIR ${CMAKE_SOURCE_DIR}/output/unix/lib/static)
endif()

install(TARGETS Comparers Comparers_Lib Comparers_Lib_Static
        RUNTIME DESTINATION ${RUNTIME_DEST_DIR}
        LIBRARY DESTINATION ${LIBRARY_DEST_DIR}
        ARCHIVE DESTINATION ${ARCHIVE_DEST_DIR})