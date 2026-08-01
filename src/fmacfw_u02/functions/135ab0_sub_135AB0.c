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

// hci_recv_packet @ 0x135ab0, size 76 bytes
uint8_t * hci_recv_packet(uint8_t *a1, int a2)
{
  uint8_t *result; // r0
  int v3; // r2
  unsigned int v4; // r3
  uint8_t *v5; // r0
  int v6; // r1
  unsigned int v7; // r3
  uint8_t *v8; // r0
  char v9[5]; // [sp+7h] [bp-5h] BYREF

  result = buf_calc_5(a1, a2, v9);
  if ( result )
  {
    if ( (uint8_t)v9[0] <= 0x1Du )
      return 0;
    v3 = (uint16_t)(4 * *((uint16_t *)result + 4));
    v4 = (uint8_t)(v9[0] - 10 - 4 * result[8]);
    if ( v4 <= 0x15 )
      return 0;
    v5 = result + 10;
    v6 = (uint16_t)(4 * *(uint16_t *)&v5[v3]);
    v7 = (uint8_t)(v4 - 2 - 4 * v5[v3]);
    v8 = &v5[v3];
    if ( v7 <= 0x13 )
      return 0;
    else
      return (uint8_t *)*(uint16_t *)&v8[v6 + 4];
  }
  return result;
}

