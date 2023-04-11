cmake_minimum_required(VERSION 3.23)
project(Pilha C)

set(CMAKE_C_STANDARD 99)

add_executable(Pilha main.c Estruturas/Pilha.h Biblioteca.h Estruturas/Pilha.c)
