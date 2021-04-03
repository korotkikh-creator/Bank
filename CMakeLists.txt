cmake_minimum_required(VERSION 3.17)
project(Bank)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bank main.cpp Account.h Account.cpp Exceptions.h AccountList.h AccountList.cpp)