cmake_minimum_required(VERSION 3.8)

find_package(Boost 1.7 REQUIRED COMPONENTS filesystem system thread context exception)

add_executable(hotswap main.cpp)
target_link_libraries(hotswap ${Boost_LIBRARIES} ${CMAKE_DL_LIBS})