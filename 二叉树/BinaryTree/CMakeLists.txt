cmake_minimum_required(VERSION 3.8)
project(BinaryTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        BinaryTree.cpp
        BinaryTree.h
        BinaryTreeNode.cpp
        BinaryTreeNode.h
        main.cpp)

add_executable(BinaryTree ${SOURCE_FILES})