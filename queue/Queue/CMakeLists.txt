cmake_minimum_required(VERSION 3.8)
project(Queue)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Sequentialqueue.cpp Sequentialqueue.h LinkedQueue.cpp LinkedQueue.h LinkNode.cpp LinkNode.h)
add_executable(Queue ${SOURCE_FILES})