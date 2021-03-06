cmake_minimum_required(VERSION 3.2)
project(LearnedSort)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}  -O3  -march=native")
set(CMAKE_BUILD_TYPE RELEASE)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(BENCHMARK_ENABLE_GTEST_TESTS OFF)

# Dependencies
include_directories(${PROJECT_SOURCE_DIR}/third_party/ips4o)
add_subdirectory(third_party/googletest)
add_subdirectory(third_party/googlebenchmark)
include_directories(${PROJECT_SOURCE_DIR}/third_party/radix)
include_directories(${PROJECT_SOURCE_DIR}/third_party/cpp-TimSort/include)
include_directories(${PROJECT_SOURCE_DIR}/third_party/BlockQuicksort)
include_directories(${PROJECT_SOURCE_DIR}/third_party/pdqsort)
include_directories(${PROJECT_SOURCE_DIR}/third_party/ska_sort)

# Learned Sort library
include_directories(${PROJECT_SOURCE_DIR}/include)

# Executable
set(BINARY ${CMAKE_PROJECT_NAME}_benchmarks)
add_executable(${BINARY} benchmarks_driver.cc)
target_link_libraries(${BINARY} benchmark)

# Tests
set(TESTS ${CMAKE_PROJECT_NAME}_tests)
file(GLOB TEST_SRC "unit_tests/*.cc")
add_executable(${TESTS}  ${TEST_SRC})
add_test(NAME ${TESTS} COMMAND ${TESTS})
target_link_libraries(${TESTS} PUBLIC gtest)
