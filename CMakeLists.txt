cmake_minimum_required(VERSION 3.24)
project(ALr3)

set(CMAKE_CXX_STANDARD 17)

add_executable(ALr3 main.cpp LinkedList.h Stack.h PostfixCalculator.cpp PostfixCalculator.h Queue.h Converter.cpp Converter.h InfixCalculator.cpp InfixCalculator.h)
