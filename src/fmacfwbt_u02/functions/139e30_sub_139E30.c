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

extern uint32_t dword_139F84;
extern uint32_t dword_139F80;
extern uint32_t off_139F8C;
extern uint32_t dword_139F88;
extern uint32_t dword_139F90;

// tx_power_set_band @ 0x139e30, size 336 bytes
int  tx_power_set_band(char *a1, char a2, int a3)
{
  char v4; // r3
  int v6; // r4
  char *v7; // r8
  int v8; // r7
  int v10; // r2
  int v11; // r3
  char *v12; // r5
  uint32_t *v13; // r1
  int v14; // r6
  unsigned int v15; // r3
  uint16_t v16; // [sp+6h] [bp-2h] BYREF

  if ( *a1 >= 0 )
    v4 = 24;
  else
    v4 = 26;
  v16 = 0;
  if ( (a2 & 0x78) == 8 )
  {
    v4 += 8;
  }
  else if ( (a2 & 0x7C) == 4 )
  {
    v4 += 4;
  }
  v6 = (uint8_t)(v4 + 6);
  v7 = &a1[v6];
  memcpy_aligned(&v16, &a1[v6], 2);
  v8 = a1[4] & 1;
  if ( (a1[4] & 1) != 0 )
  {
    if ( v16 == 1544 )
      return v8;
    if ( v16 != 56710 )
      return 0;
  }
  else if ( v16 != 56710 )
  {
    if ( v16 == 8 )
    {
      v10 = (uint8_t)v7[11];
      if ( v10 == 2 )
      {
        ke_event_schedule(dword_139F84, (uint8_t)v7[10], 2, 8);
        return v8;
      }
      if ( v10 == 17 )
      {
        v12 = &a1[4 * (v7[2] & 0xF) + 2 + v6];
        if ( (uint8_t)*(v12 - 4) == 239
          && (uint8_t)*(v12 - 3) == 255
          && (uint8_t)*(v12 - 2) == 255
          && (uint8_t)*(v12 - 1) == 250 )
        {
          ke_event_schedule(dword_139F80, (uint8_t)v12[3] | ((uint8_t)v12[2] << 8));
          return v8;
        }
      }
    }
    return 1;
  }
  if ( v7[8] == 58 )
  {
    v11 = (uint8_t)v7[42];
    if ( v11 == 134 )
    {
      v13 = off_139F8C;
      v14 = dword_139F88 + 696 * a3;
      v15 = (uint8_t)v7[49] | ((uint8_t)v7[48] << 8);
      *(uint16_t *)(v14 + 690) = _byteswap_ushort(*((uint16_t *)v7 + 24));
      if ( (int)(*(uint32_t *)(v14 + 692) - v13[4] + dword_139F90 * (v15 >> 1)) < 0 )
      {
        *(uint32_t *)(v14 + 692) = v13[4];
        return 1;
      }
      return 0;
    }
    return v11 == 136 || v11 == 135 && ((uint8_t)v7[26] != 255 || v7[27] != 2);
  }
  return (uint8_t)(1 - v8);
}

