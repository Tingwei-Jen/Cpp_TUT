cmake_minimum_required( VERSION 2.8 )
project( SmartPtr_FactoryMethod_TUT )

set( CMAKE_CXX_COMPILER "g++" )
set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin )

add_executable( SmartPtr_FactoryMethod_TUT SmartPtr_FactoryMethod_TUT.cpp  )


