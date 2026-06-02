cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME "ttl")

project(${PROJECT_NAME} LANGUAGES CXX C ASM_NASM)

# FLAGS:
set(CMAKE_ASM_NASM_FLAGS "-f elf64 -g")
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# LIBRARIES:
add_library(exit src/ttl/sys/exit.nasm)
add_library(start src/ttl/start.nasm)
add_library(io src/ttl/sys/io.nasm)
add_library(c_string src/ttl/colls/c_string.nasm)
add_library(std src/ttl/std/std.nasm)

# MAIN EXECUTABLE:
add_executable(${PROJECT_NAME} main.cpp)

target_link_options(${PROJECT_NAME} PUBLIC -nostdlib -nostartfiles
                    -Wl,-e,_start)
target_compile_options(${PROJECT_NAME} PUBLIC -g -O0 -ffreestanding
                                              -fno-exceptions -nostdlib)
target_link_libraries(${PROJECT_NAME} PUBLIC start std io c_string exit)
target_include_directories(${PROJECT_NAME}
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
