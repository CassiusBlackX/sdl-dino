cmake_minimum_required(VERSION 3.10)

project(sdl_dino)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_C_COMPILER riscv64-unknown-elf-gcc)
set(CMAKE_CXX_COMPILER riscv64-unknown-elf-g++)
set(CMAKE_ASM_COMPILER riscv64-unknown-elf-as)

set(CMAKE_CXX_FLAGS " -O2 -march=rv32im -mabi=ilp32 -nostartfiles -nodefaultlibs -nostdlib -fno-exceptions -fno-rtti -ffreestanding -fno-builtin -mno-relax -fno-PIE")
set(CMAKE_EXE_LINKER_FLAGS "-T ${CMAKE_SOURCE_DIR}/linker.ld")

add_executable(game.elf src/lib/device.cpp src/main.cpp src/trex.cpp src/utils.cpp src/cactus.cpp src/ground.cpp src/score.cpp src/lib/mem.cpp)
