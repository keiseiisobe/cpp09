cmake_minimum_required(VERSION 3.14)
project(cpp09/ex00)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(../)

add_executable(
  btc_test
  regex_test.cpp
  loadfile_test.cpp
  ../Regex.cpp
  ../loadfile.cpp
)
target_link_libraries(
  btc_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(btc_test)
