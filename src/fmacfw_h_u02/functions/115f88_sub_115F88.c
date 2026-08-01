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

extern uint32_t dword_116030;

// rx_packet_process @ 0x115f88, size 166 bytes
int  rx_packet_process(int result, int a2)
{
  int v2; // r3
  int v3; // r8
  int v4; // r12
  uint32_t *v5; // r7
  int v6; // lr
  int v7; // r6
  int v8; // r4
  int v9; // r2
  int v10; // r6
  int v11; // r2
  int v12; // r1

  v2 = *(uint32_t *)(result + 72);
  v3 = *(uint8_t *)(result + 50);
  v4 = *(uint32_t *)(v2 + 40);
  v5 = *(uint32_t **)(result + 76);
  v6 = *(uint8_t *)(v2 + 36);
  v7 = v2 - *(uint8_t *)(result + 66) + 172;
  v8 = v3 + v2 + 172 - *(uint8_t *)(result + 51);
  v9 = *(uint8_t *)(result + 53) + *(uint16_t *)(result + 4) - 1 + v2 + 172;
  *(uint32_t *)(v2 + 40) = v4 & 0xFFFFFFFD;
  if ( v3 )
  {
    v5[7] = v7;
    v5[8] = v3 + v7 - 1;
  }
  v10 = v5[17];
  *(uint32_t *)(v2 + 24) = v8;
  *(uint32_t *)(v2 + 28) = v9;
  *(uint32_t *)(v2 + 20) = 0;
  v5[6] = v2 + 16;
  *(uint32_t *)(v2 + 32) = 0;
  v5[17] = v10 | 0x100;
  if ( (v4 & 1) == 0 )
  {
    v11 = *(uint32_t *)(result + 36);
    result = v11 & 0x380000;
    if ( (v11 & 0x380000) == 0x380000 || (v11 & 0x200000) == 0 )
    {
      v12 = dword_116030 + 36 * (a2 + v6);
      result = *(uint8_t *)(v12 + 32);
      *(uint32_t *)(v2 + 40) = v4 & 0xFFFFFFFC | 1;
      *(uint8_t *)(v12 + 32) = result + 1;
      v5[17] = v10 | 0x100;
    }
  }
  *(uint32_t *)(v2 + 20) = 0;
  return result;
}

