cmake_minimum_required(VERSION 3.25.0)
project(order-book-sim VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

add_executable(order-book-sim
    src/main.cpp
    src/classes/OrderBook.cpp
    src/classes/Order.cpp
)

target_include_directories(order-book-sim PRIVATE header)

# ---------------------------------------------------------------------------
# Tests (GoogleTest via FetchContent) -- nur wenn explizit eingeschaltet.
# Release-/Normalbuild: aus. Tests bauen mit: cmake -B build -DBUILD_TESTS=ON
# ---------------------------------------------------------------------------
option(BUILD_TESTS "Build unit tests (downloads GoogleTest)" ON)

if(BUILD_TESTS)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.15.2
    )
    # Verhindert, dass gtest die Compiler-/Linker-Settings des Projekts ueberschreibt (Windows)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    add_executable(order-book-tests
        tests/Price_test.cpp
        tests/Order_test.cpp
        tests/OrderBook_test.cpp
        src/classes/OrderBook.cpp
        src/classes/Order.cpp
    )
    target_include_directories(order-book-tests PRIVATE header)
    target_link_libraries(order-book-tests PRIVATE GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(order-book-tests)
endif()

