cmake_minimum_required(VERSION 2.8)

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

add_library(lcl SHARED abstraction.cpp application.cpp variable.cpp lambda.cpp)