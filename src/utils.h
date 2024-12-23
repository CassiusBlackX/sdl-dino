#ifndef UTILS_H_
#define UTILS_H_

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 128
#define GROUND_Y_POS 120
#define GROUND_DISTANCE 3
#define GRAVITY 1
#define TREX_X_POS 1
#define SCORE_UP_BOUND 1
#define SCORE_RIGHT_BOUND 1
#define SCORE_MAX_CHARS 8
#define FPS 30
namespace utils {

void write_to_vga(unsigned address, unsigned value, unsigned * framebuffer);

unsigned rand();

}


#endif  // UTILS_H_