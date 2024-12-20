#include "mem.h"

void *memset(void *ptr, int value, unsigned num) {
    unsigned char *p = (unsigned char *)ptr;
    while (num--) {
        *p++ = (unsigned char)value;
    }
    return ptr;
}