cmake_minimum_required( VERSION 2.8 )
project ( const_usage )

set( CMAKE_CXX_COMPILER "g++" )
set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c++11 -march=native -O3" )

add_executable( const_usage const_usage.cpp )
