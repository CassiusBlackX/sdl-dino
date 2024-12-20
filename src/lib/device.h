#ifndef LIBDEVICE_H_
#define LIBDEVICE_H_

#define CLOCK_ADDR ((volatile unsigned int*)0xfbadbedf)
#define VRAM_ADDR ((volatile unsigned int*)0xfbad0000)
#define VRAM_COMMIT_ADDR ((volatile unsigned char*)0xfbadf000)
#define VRAM_X 128 // X is vertical
#define VRAM_Y 128 // Y is horizontal

unsigned int time();
void sleep(unsigned int us);
void set_vram(int x, int yWord, unsigned int pixel);
void commit_vram();



#endif  // LIBDEVICE_H_