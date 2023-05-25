cmake_minimum_required(VERSION 2.8)
project(sylar)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

#set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}./cmake)   # 设置中间文件路径

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
    sylar/timer.cpp
    sylar/hook.cpp
    sylar/fd_manager.cpp
    sylar/address.cpp
    sylar/socket.cpp
    sylar/bytearray.cpp
    sylar/http/http.cpp
    sylar/http/http11_parser.cpp
    sylar/http/httpclient_parser.cpp
    sylar/http/http_parser.cpp
    sylar/tcp_server.cpp
    )

add_library(sylar SHARED ${LIB_SRC})
#add_library(sylar_static STATIC ${LIB_SRC})
#SET_TARGET_PROPERTIES (sylar_static PROPERTIES OUTPUT_NAME "sylar")

set(LIB_LIB
    sylar
    dl
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


add_executable(test_hook tests/test_hook.cpp)
add_dependencies(test_hook sylar)
target_link_libraries(test_hook sylar ${LIB_LIB})

add_executable(test_address tests/test_address.cpp)
add_dependencies(test_address sylar)
target_link_libraries(test_address sylar ${LIB_LIB})

add_executable(test_socket tests/test_socket.cpp)
add_dependencies(test_socket sylar)
target_link_libraries(test_socket sylar ${LIB_LIB})

add_executable(test_bytearray tests/test_bytearray.cpp)
add_dependencies(test_bytearray sylar)
target_link_libraries(test_bytearray sylar ${LIB_LIB})

add_executable(test_http tests/test_http.cpp)
add_dependencies(test_http sylar)
target_link_libraries(test_http sylar ${LIB_LIB})

add_executable(test_http_parser tests/test_http_parser.cpp)
add_dependencies(test_http_parser sylar)
target_link_libraries(test_http_parser sylar ${LIB_LIB})

add_executable(test_tcp_server tests/test_tcp_server.cpp)
add_dependencies(test_tcp_server sylar)
target_link_libraries(test_tcp_server sylar ${LIB_LIB})

add_executable(echo_server examples/echo_server.cpp)
add_dependencies(echo_server sylar)
target_link_libraries(echo_server sylar ${LIB_LIB})


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
