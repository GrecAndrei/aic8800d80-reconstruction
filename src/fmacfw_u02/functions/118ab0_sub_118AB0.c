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

extern uint32_t dword_118B98;
extern uint32_t dword_118B9C;
extern uint32_t dword_118BA0;
extern uint32_t dword_118BB0;
extern uint32_t dword_118BB4;
extern uint32_t dword_118B94;
extern uint32_t off_118BA4;
extern uint32_t off_118BA8;
extern uint32_t dword_118BAC;

// fw_magic_check @ 0x118ab0, size 228 bytes
int  fw_magic_check(int a1)
{
  int v2; // r4
  uint32_t *v3; // r6
  uint32_t *v4; // r5
  int v5; // r11
  int v6; // r10
  int v7; // r9
  int v8; // r8
  uint32_t *v9; // r6
  int v10; // r8
  int v11; // r0
  int *v12; // r5
  int v13; // r7
  int result; // r0

  v2 = dword_118B98;
  v3 = (uint32_t *)dword_118B9C;
  v4 = (uint32_t *)dword_118BA0;
  v5 = dword_118BB0;
  v6 = dword_118BB4;
  v7 = dword_118B94;
  zero_8_bytes(dword_118B94);
  zero_8_bytes(v7 + 8);
  v8 = v2 + 400;
  do
  {
    if ( !a1 || !*(uint8_t *)(v2 + 97) )
    {
      memset((int *)v2, 0, 0x64u);
      *(uint32_t *)(v2 + 44) = v3 + 11;
      *(uint32_t *)(v2 + 72) = v3;
      *(uint32_t *)(v2 + 76) = v4;
      v4[13] = 0;
      v4[14] = 0;
      v3[24] = 0;
      v3[25] = 0;
      v4[3] = v5;
      v3[11] = v6;
      *(uint8_t *)(v2 + 96) = 0;
      v4[10] = 0;
      v4[15] = 0;
      v4[7] = v3 + 27;
      cmd_handler_a(v7);
    }
    v2 += 100;
    v3 += 155;
    v4 += 20;
  }
  while ( v2 != v8 );
  v9 = off_118BA4;
  v10 = dword_118BB4;
  *(uint32_t *)off_118BA4 = dword_118BB4;
  v9[13] = 0;
  v9[14] = 0;
  v9[15] = 0;
  v9[1] = rf_get_field4() << 14;
  v11 = get_hw_clock_multiplier();
  v12 = (int *)off_118BA8;
  v13 = dword_118BAC;
  v9[2] = v11;
  v9[4] = v13;
  v9[5] = 1024;
  v9[6] = 0;
  v9[7] = 0;
  v9[3] = 0;
  v9[8] = 0;
  *v12 = v10;
  v9[10] = 0;
  v9[11] = 0;
  v12[13] = 0;
  v12[14] = 0;
  v9[12] = 0;
  v12[15] = 0;
  v12[1] = rf_get_field4() << 14;
  result = get_hw_clock_multiplier();
  v12[2] = result;
  v12[3] = 0;
  v12[6] = 0;
  v12[7] = 0;
  v12[10] = 0;
  v12[11] = 0;
  v12[4] = v13;
  v12[8] = 0;
  v12[12] = 0;
  v12[5] = 4;
  return result;
}

