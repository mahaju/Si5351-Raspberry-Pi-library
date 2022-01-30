cmake_minimum_required(VERSION 2.8)
project(Main)
message(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(Main 
	       main.cpp
 	       si5351.cpp
)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fpermissive")


