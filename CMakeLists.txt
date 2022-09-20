cmake_minimum_required(VERSION 3.23)
project(trabalho_1_SO)

set(CMAKE_CXX_STANDARD 23)

add_executable(trabalho_1_SO src/main.cpp src/sequential/matriz_sequencial.cpp src/auxiliar.h src/implementation/Matriz.cpp include/Matriz.h include/File.h include/MultiplyMatrix.h src/implementation/File.cpp src/assistant/assistant.cpp)
