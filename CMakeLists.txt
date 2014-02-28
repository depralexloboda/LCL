project(lambda)

add_subdirectory(lcl)

cmake_minimum_required(VERSION 2.8)


ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

add_executable(lambda main.cpp)
target_link_libraries (lambda lcl) 
install(TARGETS lambda RUNTIME DESTINATION bin)
