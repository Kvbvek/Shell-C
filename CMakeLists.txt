cmake_minimum_required(VERSION 3.5.0)
project(Shell-C VERSION 0.1.0 LANGUAGES C)

add_executable(Shell-C src/command.c src/token.c src/shc.c main.c)

