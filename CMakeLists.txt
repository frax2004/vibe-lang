cmake_minimum_required(VERSION 4.4)
project(vibe LANGUAGES C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

file(GLOB SOURCES src/*.c)

add_executable(vibe ${SOURCES})
target_include_directories(vibe PUBLIC ${CMAKE_SOURCE_DIR}/include)
