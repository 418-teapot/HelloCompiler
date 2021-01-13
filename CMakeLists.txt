cmake_minimum_required(VERSION 3.5)

project(HelloCompiler)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
    src/main.cpp
    src/lexer.cpp
)

add_executable(HelloCompiler ${SOURCES})

target_include_directories(HelloCompiler
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)