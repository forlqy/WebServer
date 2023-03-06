cmake_minimum_required(VERSION 2.8)
project(WebServer)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS   "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

set(LIB_SRC
    WebServer/include/log.cpp
)
    
add_library(WebServer SHARED ${LIB_SRC})
#add_library(WebServer STATIC ${LIB_SRC})
#target_

add_executable(test tests/test.cc)
add_dependencies(test WebServer)
target_link_libraries(test WebServer)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
