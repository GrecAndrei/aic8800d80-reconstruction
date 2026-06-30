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

extern uint32_t off_12C040;
extern uint32_t off_12C048;
extern uint32_t off_12C04C;
extern uint32_t off_12C050;
extern uint32_t off_12C044;
extern uint32_t off_12C058;
extern uint32_t dword_12C060;
extern uint32_t dword_12C05C;
extern uint32_t off_12C054;
extern uint32_t dword_12C064;

// tx_timeout_check @ 0x12bf68, size 214 bytes
// Doc: tx_timeout_check [tx]: Check TX path for timeout conditions via MMIO register
// tx_timeout_check [tx]: Check TX path for timeout conditions via MMIO register
int tx_timeout_check()
{
  int v0; // r4
  int v1; // r5
  uint16_t *v2; // r6
  int v3; // r2
  int v4; // r1
  uint32_t *v6; // r3

  v0 = (*(uint32_t *)off_12C040 >> 25) & 1;
  if ( (*(uint32_t *)off_12C040 & 0x2000000) == 0
    && 32 * *(uint32_t *)off_12C048
     - 2000
     - *((uint16_t *)off_12C04C + 92)
     - *((uint16_t *)off_12C04C + 93) < 0 )
  {
    return v0;
  }
  v1 = *(uint32_t *)off_12C050;
  if ( !*(uint32_t *)off_12C050 )
    return 1;
  v2 = (uint16_t *)off_12C04C;
  v3 = *(uint32_t *)(v1 + 12);
  v4 = *((uint16_t *)off_12C04C + 93);
  if ( v3 - *((uint32_t *)off_12C044 + 4) - 2000 - *((uint16_t *)off_12C04C + 92) - v4 < 0 )
  {
    if ( **(int16_t **)off_12C058 < 0 && v3 - *((uint32_t *)off_12C044 + 4) + 5000 < 0 )
    {
      sub_12F694(dword_12C060, dword_12C05C, 575);
      return 0;
    }
    return 0;
  }
  else
  {
    if ( **(uint8_t **)off_12C054 != 1 )
      return 1;
    if ( **(int16_t **)off_12C058 < 0 && v3 - *((uint32_t *)off_12C044 + 4) - v4 < 0 )
    {
      sub_12F694(dword_12C064, dword_12C05C, 580);
      v3 = *(uint32_t *)(v1 + 12);
      v4 = v2[93];
    }
    v6 = off_12C044;
    *((uint32_t *)off_12C044 + 2) = 0x40000;
    v6[12] = v3 - v4;
    v6[2] = 4;
    return 1;
  }
}

