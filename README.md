# sdl dino
a chrome dinosaur game implementation, aiming for `rv32im`, requiring riscv cross-compile environment

## structure
+ `src`: the implementation code using c++ for the dino game
  + `src/lib/`: code that needs to communicate with hardware
+ `script`: a few scripts to help generate target files for Vivado

## build
```sh
cmake -B build -S .
cmake --build build
```
after the commands above, you will have `ram0.coe`, ..., `ram3.coe` and `rom.coe` files under `build/`, which are the files you will need to use in Vivado

