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

extern uint32_t off_11CA90;

// fw_signature_check @ 0x11ca38, size 88 bytes
// Doc: fw_signature_check [util]: Check firmware header magic against expected value 0x96c
// fw_signature_check [util]: Check firmware header magic against expected value 0x96c
int  fw_signature_check(uint16_t *a1)
{
  int v1; // r3
  int result; // r0

  v1 = *a1;
  result = *(uint32_t *)(*(uint32_t *)off_11CA90 + 16);
  if ( v1 == 2412
    || v1 == 2437
    || v1 == 2462
    || v1 == 2472
    || v1 == 5180
    || v1 == 5220
    || v1 == 5765
    || v1 == 5785
    || v1 == 5805 )
  {
    result += 20000;
  }
  return result;
}

