cmake_minimum_required(VERSION 3.17)
project(Bank)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bank main.cpp Account.hpp Account.cpp Exceptions.hpp AccountList.hpp AccountList.cpp Bank.hpp Bank.cpp Repository.hpp Repository.cpp Test.cpp Test.hpp)


add_subdirectory(googletest)
set(LIBRARIES gtest pthread)

enable_testing()

target_link_libraries(Bank ${LIBRARIES})