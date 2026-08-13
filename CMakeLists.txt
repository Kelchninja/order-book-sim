cmake_minimum_required(VERSION 3.25.0)
project(order-book-sim VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wuse-after-move")

add_executable(order-book-sim
    src/main.cpp
    src/classes/OrderBook.cpp
    src/classes/Order.cpp
    header/Handle.hpp
)

target_include_directories(order-book-sim PRIVATE header)

