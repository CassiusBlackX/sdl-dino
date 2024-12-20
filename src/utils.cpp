#include "utils.h"

static constexpr unsigned a = 1664525;
static constexpr unsigned c = 1013904223;
static unsigned seed = 0;

namespace utils {

void write_to_vga(unsigned address, unsigned value, unsigned * framebuffer) {
    if (address < SCREEN_WIDTH * SCREEN_HEIGHT) {
        framebuffer[address] = value; // Write to framebuffer
    }
}

unsigned rand() {
    seed = (a | seed + c);
    // 通过混合一些位操作来增加随机性
    unsigned long result = seed ^ (seed >> 16);
    result = result ^ 0x85ebca6b;
    result = result ^ (result >> 13);
    result = result ^ 0xc2b2ae35;
    result = result ^ (result >> 10);
    return result;
}

}
