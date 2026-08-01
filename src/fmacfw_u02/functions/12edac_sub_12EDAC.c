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

// msg_alloc_0x40a @ 0x12edac, size 30 bytes
int  msg_alloc_0x40a(int a1, int a2, int16_t a3, int16_t a4)
{
  uint32_t *v4; // r0

  v4 = (uint32_t *)ke_msg_alloc(1034, a4, a3, 0xCu);
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  ke_msg_send((int)v4);
  return 0;
}

