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
target_compile_definitions(game.elf PRIVATE
    # DEBUG
    CARROT
    RELEASE
)

add_custom_command(TARGET game.elf POST_BUILD
    COMMAND riscv64-unknown-elf-objcopy ${CMAKE_BINARY_DIR}/game.elf --dump-section .text=rom.bin --dump-section .data=ram.bin
    COMMAND od -w4 -An --endian little -v -t x4 ${CMAKE_BINARY_DIR}/rom.bin > ${CMAKE_BINARY_DIR}/rom.mem
    COMMAND od -w4 -An --endian little -v -t x4 ${CMAKE_BINARY_DIR}/ram.bin > ${CMAKE_BINARY_DIR}/ram.mem
    COMMAND ${CMAKE_COMMAND} -E echo "Generating COE files..."
    COMMAND python3 ${CMAKE_SOURCE_DIR}/script/tocoe.py ${CMAKE_BINARY_DIR}/rom.mem ${CMAKE_BINARY_DIR}/rom.coe
    COMMAND ./toramcoe
    COMMAND ${CMAKE_COMMAND} -E remove(${CMAKE_BINARY_DIR}/rom.bin ${CMAKE_BINARY_DIR}/rom.mem ${CMAKE_BINARY_DIR}/ram.bin ${CMAKE_BINARY_DIR}/ram.mem)
    COMMENT "Post-build steps to generate COE files"
    VERBATIM
)
