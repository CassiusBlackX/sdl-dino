#include "device.h"

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

static int button_state = 0;

unsigned int time() { return *CLOCK_ADDR; }

void sleep(unsigned int us) {
    unsigned int start = *CLOCK_ADDR;
    while (1) {
        if (*CLOCK_ADDR >= start + us) {
        break;
    }
    }
}

void set_vram(int x, int yWord, unsigned int pixel) {
    VRAM_ADDR[x * VRAM_X / 8 + yWord] = pixel;
}

void commit_vram() { *VRAM_COMMIT_ADDR = 1; }

bool get_button_state() {
    button_state = *BUTTON_ADDR;
    if (button_state != 0) return true;
    else return false;
}

bool get_reset_button_state() {
    return static_cast<bool>(button_state & 1);
}

bool get_jump_button_state() {
    return static_cast<bool>(button_state & 2);
}