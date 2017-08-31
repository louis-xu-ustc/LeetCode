cmake_minimum_required(VERSION 3.8)
project(C++)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/TrieTree.cpp src/TrieTree.h src/utils.h src/BinPacking.cpp src/BinPacking.h src/TreeNode.cpp src/TreeNode.h src/multiThread.c src/multiThread.h)
add_executable(C++ ${SOURCE_FILES})