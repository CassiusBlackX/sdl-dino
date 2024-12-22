#!/bin/bash

riscv64-unknown-elf-objcopy ../build/game.elf  --dump-section .text=rom.bin --dump-section .data=ram.bin
od -w4 -An --endian little -v -t x4 ./rom.bin > rom.mem
od -w4 -An --endian little -v -t x4 ./ram.bin > ram.mem