cmake_minimum_required(VERSION 3.9)
project(KYDS)

SET(CMAKE_C_COMPILER "/usr/local/Cellar/gcc/7.2.0/bin/")

add_executable(KYDS main.cpp CommonDefine.h "Practice/Practice1.cpp" "Include/Practice1.h" "第二章 线性表/SqList.h" "第二章 线性表/LinkList.cpp" "第二章 线性表/SqList.cpp" "Practice/Practice2.cpp" "Include/Practice2.h" "第二章 线性表/LinkList.h" "第二章 线性表/SLinkList.cpp" "第二章 线性表/SLinkList.h" "第二章 线性表/DuLinkList.cpp" "第二章 线性表/DuLinkList.h")