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

extern uint32_t off_101900;

// fmacfwbt_init_or_handler @ 0x1018e4, size 28 bytes
// Doc: fmacfwbt_init_or_handler [unknown]: FMAC BT firmware init/handler stub
// fmacfwbt_init_or_handler [unknown]: FMAC BT firmware init/handler stub
uint32_t * fmacfwbt_init_or_handler(uint32_t *result, uint32_t *a2)
{
  uint32_t *v2; // r3

  v2 = off_101900;
  *(uint32_t *)off_101900 = *result;
  v2[1] = result[1];
  v2[2] = *a2;
  v2[3] = a2[1];
  v2[4] = a2[2];
  v2[5] = a2[3];
  return result;
}

