cmake_minimum_required( VERSION 2.8 )
project ( class_pointer_test_value_change )

set( CMAKE_CXX_COMPILER "g++" )
set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c++11 -march=native -O3" )

add_executable( class_pointer_test_value_change class_pointer_test_value_change.cpp )
