cmake_minimum_required(VERSION 3.12)
project(Cdemo98)

set(CMAKE_CXX_STANDARD 98)

add_executable(Cdemo98 src/test/main.cpp src/cpp/Stack.h src/cpp/SeqStack.h src/cpp/SeqStack.tpp src/cpp/Calculator.cpp src/cpp/Calculator.h src/test/test.cpp src/cpp/fishingday/main.cpp)
add_executable(tree src/cpp/preinpostorder/main.cpp src/cpp/preinpostorder/Tree.cpp src/cpp/preinpostorder/Tree.h src/cpp/oddevencheck/main.cpp src/cpp/numberFive/main.cpp)
add_executable(odd-even-check src/cpp/oddevencheck/main.cpp)
add_executable(fishingday src/cpp/fishingday/main.cpp)
add_executable(minitree src/cpp/hanoi/main.cpp)
add_executable(b-tree src/cpp/hanoi/main.cpp)
add_executable(numberFive src/cpp/numberFive/main.cpp)
add_executable(calculator src/cpp/calculator/main.cpp)