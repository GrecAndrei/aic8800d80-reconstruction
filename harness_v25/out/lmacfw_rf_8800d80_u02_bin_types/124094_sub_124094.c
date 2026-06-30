#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

extern uint32_t off_1240A8;

// sub_124094 @ 0x124094, size 18 bytes
int  sub_124094(int a1)
{
  *(uint32_t *)off_1240A8 = *(uint32_t *)off_1240A8 & 0xFFFFFDFF | (a1 << 9);
  return 0;
}

