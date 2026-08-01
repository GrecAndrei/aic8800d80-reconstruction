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

extern uint32_t dword_11C9C0;
extern uint32_t off_11C9C4;

// get_cal_value @ 0x11c990, size 46 bytes
// Doc: sub_121C990 [scan]: Indexed table lookup using sub-id * 0x528 stride, cap compare 0x3ff
// sub_121C990 [scan]: Indexed table lookup using sub-id * 0x528 stride, cap compare 0x3ff
unsigned int * get_cal_value(unsigned int *result)
{
  int v1; // r2

  v1 = *(uint16_t *)(dword_11C9C0 + 1320 * *((uint8_t *)result + 28) + 1222);
  if ( v1 != 1023 && *((uint8_t *)off_11C9C4 + 361) != 2 )
    return check_packet_bits((unsigned int *)(result[17] + 4), *(uint32_t *)(result[17] + 40), v1);
  return result;
}

