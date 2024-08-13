cmake_minimum_required(VERSION 3.5.0)
project(Shell-C VERSION 0.1.0 LANGUAGES C)

set(SOURCES
    src/command.c
    src/token.c
    src/process.c
    src/shc.c
    src/commandHandlers/shc_handler.c
)

add_executable(Shell-C ${SOURCES} main.c)

