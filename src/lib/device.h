#ifndef LIBDEVICE_H_
#define LIBDEVICE_H_

#define CLOCK_ADDR ((volatile unsigned int*)0xfbadbedf)
#define VRAM_ADDR ((volatile unsigned int*)0xfbad0000)
#define VRAM_COMMIT_ADDR ((volatile unsigned char*)0xfbadf000)

#define UART_RECV_READY_ADDR ((volatile unsigned char*)0xfbada000)
#define UART_SEND_READY_ADDR ((volatile unsigned char*)0xfbada001)
#define UART_RECV_DATA_ADDR ((volatile unsigned char*)0xfbada002)
#define UART_SEND_DATA_ADDR ((volatile unsigned char*)0xfbada003)

#define LED_ADDR ((volatile unsigned int*)0xfbadc0fe)

#define BUTTON_ADDR ((volatile unsigned char*)0xfbadc100)
#ifdef CARROT
#define VRAM_X 128 // X is vertical
#define VRAM_Y 128 // Y is horizontal
#else
#define VRAM_X 640
#define VRAM_Y 480
#endif

unsigned int time();
void sleep(unsigned int us);
void set_vram(int x, int yWord, unsigned int pixel);
void commit_vram();

bool get_button_state();
bool get_reset_button_state();
bool get_jump_button_state();

unsigned char uart_recv_ready();
unsigned char uart_send_ready();
unsigned char uart_recv();
void uart_send(unsigned char data);

void set_led(unsigned int val);

#endif  // LIBDEVICE_H_