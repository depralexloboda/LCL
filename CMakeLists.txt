project(lambda)

add_subdirectory(lcl)

cmake_minimum_required(VERSION 2.8)

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

add_executable(brackets brackets.cpp)
add_executable(check_free check_free.cpp)
add_executable(normalize normalize.cpp)
add_executable(check_normalize check_normalize.cpp)

target_link_libraries (brackets lcl) 
target_link_libraries (check_free lcl)
target_link_libraries (check_normalize lcl) 
target_link_libraries (normalize lcl) 

install(TARGETS brackets RUNTIME DESTINATION bin)
install(TARGETS check_free RUNTIME DESTINATION bin)
install(TARGETS check_normalize RUNTIME DESTINATION bin)
install(TARGETS normalize RUNTIME DESTINATION bin)