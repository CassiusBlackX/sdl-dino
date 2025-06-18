# sdl dino
a chrome dinosaur game implementation, aiming for `rv32im`, requiring riscv cross-compile environment

## feature
### libraries
this branch requires no third party libraries nor std libraries so that it can run on baremetal environment.

### memory
since there is no OS on baremetal board, if we intend to manage memory, we will have to implement our own `malloc` and `free` functions

however, we could also carefully write our code, making sure that there is no heap memory allocation in the whole program. and is my final choice.

as for stack memory, it is automatically managed when running.

### linker
the reason why there must be a `main` function in an executable is that the `gcc` linker will automatically tries to link the `main` function into its generated `_start` function.

therefor the following code is necessary in your source code 
```cpp 
extern "C" {
// top of stack
extern unsigned __stacktop;
// initial stack pointer is first address of program
__attribute__((section(".stack"), used)) unsigned* __stack_init = &__stacktop;

extern int main();

__attribute__((section(".text.start"))) __attribute__((naked)) void _start() {
  asm("mv sp, %0\n\t" ::"r"(&__stacktop));
  asm("j %0\n\t" ::"i"(&main));
}
}
```
note that the `extern "C"` is necessary if you are using c++ instead of C, because c++ compiler would make the assemble code a different name with the name you write in your source code, and without this will lead to a link fail because the linker would no be able to find the `_start` function.

inside `linker.ld`, we can see that the entry point of the program is set at `_start`, so the moment the board is on, it will try to execute code from `_start`.

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

## BUG 
### flying dinosaur
due to the incorrect design of the status machine, when dinosaur is at `jumping` state, pressing `start` button will make the dinosaur holds its state in `jumping` and will never fall

however, this feature is suitable to check, with the increasing of the score, if the obstacles will move faster and faster(making the game harder to play)

I decided to call this a "cheat code" just like the Nintendo's "Contra" game.

