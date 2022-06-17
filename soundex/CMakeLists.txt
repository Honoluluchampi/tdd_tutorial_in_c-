cmake_minimum_required(VERSION 3.16) # c++20 features

project(soundex_test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-g3 -O0")

# build google mock
set(GMOCK_DIR ~/programs/external_libraries/googletest/googlemock)
set(GTEST_DIR ~/programs/external_libraries/googletest/googletest)
set(GMOCK_TARGETS ${GTEST_DIR}/src/gtest-all.cc ${GMOCK_DIR}/src/gmock-all.cc)

add_library(gmock STATIC ${GMOCK_TARGETS})
target_include_directories(gmock PUBLIC
  ${GMOCK_DIR}
  ${GTEST_DIR}
)
target_link_libraries(gmock PUBLIC pthread)

file(GLOB_RECURSE TARGETS ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp)

add_executable(soundex_test ${TARGETS})

target_include_directories(soundex_test PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${GMOCK_DIR}/include
)

target_link_libraries(soundex_test PUBLIC gmock)