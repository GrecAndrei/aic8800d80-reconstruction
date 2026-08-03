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

extern uint32_t off_135CC8;

// sub_135C9C @ 0x135c9c, size 44 bytes
uint32_t * sub_135C9C(int a1)
{
  uint32_t *v1; // r5

  v1 = off_135CC8;
  sub_12C964(6154, 6);
  sub_14380C(a1, v1[4], 54);
  j_buffer_pool_get(v1[4] - 12);
  v1[4] = a1;
  return fmacfwbt_init_handler();
}

