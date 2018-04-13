cmake_minimum_required(VERSION 3.9)
project(KYDS)

SET(CMAKE_C_COMPILER "/usr/local/Cellar/gcc/7.2.0/bin/")

add_executable(KYDS main.cpp CommonDefine.h "第一章 绪论/Practice1.cpp" "第一章 绪论/Practice1.h" "第二章 线性表/ListBase.h")