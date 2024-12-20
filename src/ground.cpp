#include "ground.h"
#include "utils.h"

namespace {
unsigned colors[] = {0xD3D3D3, 0xFFFFFF, 0XEAEAAE};
unsigned arr[SCREEN_WIDTH];  // ground ix maximum 30 pixels height
}

Ground::Ground(int thickness, int step, int x_speed) : step(step), x_speed(x_speed) {
    top = GROUND_Y_POS;
    left = 0;
    height = thickness;
    width = SCREEN_WIDTH;
}

void Ground::reset() {
    left = 0;
}

void Ground::start() {
    for (int i = 0; i < width; i += step) {
        unsigned color = colors[utils::rand() % 3];
        for (int j = 0; j < step; j++) {
            arr[i + j] = color;
        }
    }
}

void Ground::update(unsigned* framebuffer) {
    left = (left + x_speed) % width;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j += step) {
            unsigned color = arr[(left + i) % width];
            for (int k = 0; k < step; k++) {
                unsigned address = (top + i) * SCREEN_WIDTH + (left + j + k);
                utils::write_to_vga(address, color, framebuffer);
            }
        }
    }
}