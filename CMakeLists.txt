cmake_minimum_required(VERSION 3.28)
project(PostfixIntegerCalculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(PostfixIntegerCalculator main.cpp
        src/BigInt.h
        src/Utils.h
        src/Utils.cpp
        src/Handler.h
        src/AddHandler.cpp
        src/MultiplyHandler.cpp
        src/ExponentHandler.cpp
        src/Calculator.h
        src/BigInt.cpp
        src/Calculator.cpp)
