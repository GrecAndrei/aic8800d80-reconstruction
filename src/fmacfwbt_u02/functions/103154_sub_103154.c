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


extern uint32_t dword_1032B8;
extern uint32_t dword_1032BC;
extern uint32_t dword_1032CC;

// hw_init @ 0x103154, size 356 bytes
int  hw_init(int a1)
{
  uint32_t *v1; // r6
  uint32_t *v2; // r5
  int v3; // r7
  int v4; // r8
  uint16_t v5; // r11
  unsigned int v6; // r2
  int v7; // r10
  unsigned int v8; // r3
  int v9; // r0
  unsigned int v10; // r12
  int v11; // r1
  unsigned int v12; // r12
  int v13; // r1
  int v14; // r12
  int v15; // r1
  int v16; // r7
  uint16_t v17; // r9
  int16_t v18; // r2
  uint8_t v19; // r4
  int result; // r0
  unsigned int v21; // [sp+0h] [bp-Ch]

  v1 = (uint32_t *)dword_1032B8;
  v2 = (uint32_t *)dword_1032BC;
  *(uint32_t *)dword_1032B8 |= 0x10u;
  v3 = 0;
  v4 = 0;
  *v2 = *v2 & 0xFFFFC0FF | 0x300;
  v5 = 0;
  v6 = 64;
  while ( 2 )
  {
    *v1 = *v1 & 0xFFFFFDFF | (v4 << 9);
    LOWORD(v7) = 10;
    do
    {
      *v1 = *v1 & 0xFFFE03FF | (v6 << 10);
      v8 = (uint8_t)v6;
      v9 = 0;
      while ( 1 )
      {
        *v2 |= 0x4000u;
        v10 = REG_4032_0120 + 5;
        do
          v11 = REG_4032_0120 - v10;
        while ( v11 < 0 );
        *v2 &= ~0x4000u;
        v12 = REG_4032_0120 + 5;
        do
          v13 = REG_4032_0120 - v12;
        while ( v13 < 0 );
        v14 = (*v1 >> 3) & 1;
        if ( v9 )
        {
          if ( v14 != v3 )
            break;
        }
        if ( v4 )
          v15 = (*v1 >> 3) & 1;
        else
          v15 = (*v1 & 8) == 0;
        if ( v15 )
        {
          if ( v8 )
          {
            v8 = (uint8_t)(v8 - 1);
            v16 = (v8 << 10) & 0x1FC00;
          }
          else
          {
            v16 = 0;
          }
        }
        else
        {
          if ( v8 <= 0x7E )
            v8 = (uint8_t)(v8 + 1);
          v16 = (v8 << 10) & 0x1FC00;
        }
        v9 = (uint8_t)(v9 + 1);
        *v1 = *v1 & 0xFFFE03FF | v16;
        if ( v9 == 128 )
        {
          v3 = v14;
          break;
        }
        v3 = v14;
      }
      v21 = v8;
      v17 = v8;
      v5 += v8;
      state_check_feature(0x2000, "%x -> %x\n", v6, v8);
      if ( v21 <= 0x40 )
        v18 = v17 - v7;
      else
        v18 = v17 + v7;
      v7 = (uint16_t)(v7 - 20);
      v6 = __usat(7u, v18);
    }
    while ( v7 != 65506 );
    if ( !v4 )
    {
      v4 = 1;
      continue;
    }
    break;
  }
  *(uint32_t *)dword_1032B8 = ((v5 + 2) << 8) & 0x1FC00 | *(uint32_t *)dword_1032B8 & 0xFFFE03FF;
  v19 = ((unsigned int)v5 + 2) >> 2;
  result = printf_wrapper("%dM mdll duty: %x\n", 40 * a1 + 280, v19);
  if ( a1 )
    *(uint8_t *)(dword_1032CC + 1) = v19;
  else
    *(uint8_t *)dword_1032CC = v19;
  return result;
}
