cmake_minimum_required(VERSION 3.8)
project(stack)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ChainStack.cpp ChainStack.h SequenceStack.cpp SequenceStack.h Node.cpp Node.h)
add_executable(stack ${SOURCE_FILES})