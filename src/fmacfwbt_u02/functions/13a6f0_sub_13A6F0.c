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

extern uint32_t dword_13A798;
extern uint32_t dword_13A79C;

// rf_reset_tx_state @ 0x13a6f0, size 168 bytes
// Doc: sub_123A6F0 [util]: Initialize/reset a control struct fields at offset 0x24
// sub_123A6F0 [util]: Initialize/reset a control struct fields at offset 0x24
int  rf_reset_tx_state(int a1)
{
  int16_t v1; // r2
  int result; // r0
  int v4; // r1
  int v5; // r5
  int v6; // r3
  char v7; // r5
  int16_t v8; // r7
  int v9; // r1
  unsigned int v10; // r3
  char v11; // r5
  char v12; // r1
  int v13; // [sp+4h] [bp-8h] BYREF

  v1 = *(uint16_t *)(a1 + 30);
  result = *(uint8_t *)(a1 + 29);
  v4 = *(uint8_t *)(a1 + 28);
  *(uint32_t *)(a1 + 36) = 0;
  *(uint32_t *)(a1 + 40) = 0;
  if ( (v1 & 1) == 0 )
  {
    v5 = *(uint8_t *)(a1 + 27);
    if ( v5 == 255 )
    {
      v7 = 24;
    }
    else
    {
      v6 = dword_13A798 + 2 * (v5 + 348 * result + 156);
      v7 = 26;
      v8 = *(uint16_t *)(v6 + 4);
      *(uint16_t *)(v6 + 4) = (v8 + 1) & 0xFFF;
      *(uint16_t *)(a1 + 32) = v8;
    }
    v9 = dword_13A79C + 1320 * v4;
    if ( (v1 & 0x100) != 0 )
      v7 += 6;
    if ( !*(uint8_t *)(v9 + 106) && (*(uint32_t *)(dword_13A798 + 696 * result + 4) & 0x20) != 0 )
      v7 += 4;
    *(uint8_t *)(a1 + 50) = v7;
    result = rf_get_cal_entry(a1, &v13);
    v10 = *(uint16_t *)(a1 + 24);
    *(uint16_t *)(a1 + 48) = *(uint16_t *)(a1 + 4);
    v11 = v7 + result;
    *(uint8_t *)(a1 + 53) = v13;
    if ( (uint16_t)__rev16(v10) <= 0x600u )
    {
      v12 = 0;
    }
    else
    {
      v11 += 8;
      v12 = 8;
    }
    *(uint8_t *)(a1 + 51) = v11;
    *(uint8_t *)(a1 + 66) = v11;
    *(uint8_t *)(a1 + 52) = v12;
  }
  return result;
}

