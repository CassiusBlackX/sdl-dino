#include "device.h"

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
