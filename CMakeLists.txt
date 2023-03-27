cmake_minimum_required(VERSION 2.8)
project(sylar)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

include_directories(.)
include_directories(/apps/sylar/include)
link_directories(/apps/sylar/lib)

find_library(YAMLCPP yaml-cpp)
find_library(PTHREAD pthread)
message("***", ${YAMLCPP})

set(LIB_SRC
    sylar/log.cpp
    sylar/util.cpp
    sylar/config.cpp
    sylar/thread.cpp
    sylar/fiber.cpp
    sylar/scheduler.cpp
    sylar/iomanager.cpp
    )

add_library(sylar SHARED ${LIB_SRC})
#add_library(sylar_static STATIC ${LIB_SRC})
#SET_TARGET_PROPERTIES (sylar_static PROPERTIES OUTPUT_NAME "sylar")

set(LIB_LIB
    sylar
    ${PTHREAD}
    ${YAMLCPP}
    )

add_executable(test tests/test.cpp)
add_dependencies(test sylar)
target_link_libraries(test ${LIB_LIB})

add_executable(test_config tests/test_config.cpp)
add_dependencies(test_config sylar)
target_link_libraries(test_config sylar ${LIB_LIB})


add_executable(test_thread tests/test_thread.cpp)
add_dependencies(test_thread sylar)
target_link_libraries(test_thread sylar ${LIB_LIB})


add_executable(test_util tests/test_util.cpp)
add_dependencies(test_util sylar)
target_link_libraries(test_util sylar ${LIB_LIB})


add_executable(test_fiber tests/test_fiber.cpp)
add_dependencies(test_fiber sylar)
target_link_libraries(test_fiber sylar ${LIB_LIB})

add_executable(test_scheduler tests/test_scheduler.cpp)
add_dependencies(test_scheduler sylar)
target_link_libraries(test_scheduler sylar ${LIB_LIB})


add_executable(test_iomanager tests/test_iomanager.cpp)
add_dependencies(test_iomanager sylar)
target_link_libraries(test_iomanager sylar ${LIB_LIB})


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
