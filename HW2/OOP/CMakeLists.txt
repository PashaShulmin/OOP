cmake_minimum_required(VERSION 3.20)
project(OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP main.cpp Transport.cpp Transport.h Plain.cpp Plain.h rnd.h Train.cpp Train.h Ship.cpp Ship.h Container.cpp Container.h)
