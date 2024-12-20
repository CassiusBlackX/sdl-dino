#ifndef UTILS_H_
#define UTILS_H_

constexpr unsigned SCREEN_WIDTH = 900;
constexpr unsigned SCREEN_HEIGHT = 300;
constexpr unsigned FPS = 60;

namespace utils {

void write_to_vga(unsigned address, unsigned value, unsigned * framebuffer);

unsigned rand();

}


#endif  // UTILS_H_