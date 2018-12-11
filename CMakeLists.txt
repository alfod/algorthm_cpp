cmake_minimum_required(VERSION 3.12)
project(Cdemo98)

set(CMAKE_CXX_STANDARD 98)

add_executable(Cdemo98 src/test/main.cpp src/cpp/Stack.h src/cpp/SeqStack.h src/cpp/SeqStack.tpp src/cpp/Calculator.cpp src/cpp/Calculator.h src/test/test.cpp )
add_executable(tree src/cpp/tree/main.cpp src/cpp/tree/Tree.cpp src/cpp/tree/Tree.h)