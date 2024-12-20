#ifndef UTILS_H_
#define UTILS_H_

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 300
#define GROUND_Y_POS 280
#define GROUND_DISTANCE 3
#define GRAVITY 1
#define TREX_X_POS 50
#define FPS 30
namespace utils {

void write_to_vga(unsigned address, unsigned value, unsigned * framebuffer);

unsigned rand();

}


#endif  // UTILS_H_