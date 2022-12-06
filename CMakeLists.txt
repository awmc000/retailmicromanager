cmake_minimum_required(VERSION 3.13)
project(retailmicromanager)

set(CMAKE_CXX_STANDARD 14)

add_executable(retailmicromanager
        main.cpp src/utility.cpp src/menu.cpp src/global.cpp src/menu.cpp src/staff.cpp src/inventory.cpp)
