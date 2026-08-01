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

// rf_get_rssi_status @ 0x132aa0, size 22 bytes
int  rf_get_rssi_status(int a1)
{
  unsigned int v1; // r3
  int v2; // r0

  v1 = *(uint32_t *)(a1 + 220);
  v2 = HIBYTE(v1) & 0x3F;
  if ( (v1 & 0x40000000) != 0 )
    return v2 | 0x300;
  else
    return v2 | 0x100;
}

