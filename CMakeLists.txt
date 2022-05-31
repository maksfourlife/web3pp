cmake_minimum_required(VERSION 3.19.6)

set(PROJECT_NAME web3++)
set (CMAKE_CXX_STANDARD 11)

project(${PROJECT_NAME})

include_directories(include)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/client.cpp
    src/utils.cpp
    include/client.hpp
    include/provider.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC /usr/local/include)
