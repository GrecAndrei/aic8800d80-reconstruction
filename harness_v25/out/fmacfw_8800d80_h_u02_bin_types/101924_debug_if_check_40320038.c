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

extern uint32_t off_101938;
extern uint32_t dword_101940;
extern uint32_t dword_10193C;

// debug_if_check_40320038 @ 0x101924, size 18 bytes
// Doc: debug_if_check_40320038 [util]: Check debug interface status register at 0x40320038 and load status string
// debug_if_check_40320038 [util]: Check debug interface status register at 0x40320038 and load status string
int  debug_if_check_40320038(int a1, int a2, int a3)
{
  int result; // r0

  if ( *(uint32_t *)off_101938 << 28 )
    return msg_parse(dword_101940, dword_10193C, a3);
  return result;
}

