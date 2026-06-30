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

extern uint32_t dword_1225B8;
extern uint32_t dword_1225C0;
extern uint32_t dword_1225BC;

// sub_122508 @ 0x122508, size 174 bytes
// Doc: rf_mem_write_n4de [rf]: Write to RF memory, allocates 0x200 byte stack frame for data
// rf_mem_write_n4de [rf]: Write to RF memory, allocates 0x200 byte stack frame for data
int  sub_122508(int a1, int a2)
{
  int result; // r0
  int v5; // r6
  int v6; // r7
  int v7; // r4
  int v8; // r8
  int v9; // r6
  float *v10; // r5
  int v11; // r4
  float v12; // s15
  float v13; // [sp+0h] [bp-200h] BYREF
  char v14; // [sp+4h] [bp-1FCh] BYREF

  result = parse_int(*(uint8_t **)(a2 + 4), 0, 0);
  v5 = result;
  if ( a1 == 2 )
  {
    if ( result )
      return result;
    sub_10DDC8((int)&v13, 64);
    msg_parse(dword_1225B8, 63);
    v6 = 64;
    goto LABEL_10;
  }
  result = parse_int(*(uint8_t **)(a2 + 8), 0, 0);
  v6 = result;
  v7 = result;
  if ( result >= 128 )
    v6 = 128;
  if ( !v5 )
  {
    sub_10DDC8((int)&v13, v6);
    result = msg_parse(dword_1225B8, v6 - 1);
    if ( v7 > 0 )
    {
LABEL_10:
      v8 = dword_1225C0;
      v9 = dword_1225BC;
      msg_parse(dword_1225BC, (int)v13);
      v10 = (float *)&v14;
      v11 = 0;
      while ( 1 )
      {
        ++v11;
        result = v9;
        if ( v11 == v6 )
          break;
        v12 = *v10++;
        msg_parse(v9, (int)v12);
        if ( (v11 & 7) == 7 )
          msg_parse(v8);
      }
    }
  }
  return result;
}

