cmake_minimum_required(VERSION 3.20)
project(minicalc C)

set(CMAKE_C_STANDARD 11)

add_executable(minicalc main.c arq.c arq.h lexer.c lexer.h parser.c parser.h)

add_executable(lexertest lexertest.c arq.c arq.h lexer.c lexer.h)
