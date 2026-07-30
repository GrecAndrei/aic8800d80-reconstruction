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

extern uint32_t off_114D28;
extern uint32_t off_114D2C;
extern uint32_t dword_114D30;

// sub_114C30 @ 0x114c30, size 248 bytes
// Doc: patch_230_apply_rf_init [rf]: Applies firmware patch #230 by reading a 5-dword patch descriptor from REG_2007_ff4c..0x2007ff5c and copying 4 bytes from stack buffer to destination via 0x143770.
// patch_230_apply_rf_init [rf]: Applies firmware patch #230 by reading a 5-dword patch descriptor from REG_2007_ff4c..0x2007ff5c and copying 4 bytes from stack buffer to destination via 0x143770.
int  sub_114C30(int a1, int a2, unsigned int a3)
{
  int v6; // r4
  unsigned int v7; // r5
  uint32_t v9[4]; // [sp+0h] [bp-4Ch] BYREF
  uint8_t v10[4]; // [sp+10h] [bp-3Ch] BYREF
  uint8_t v11[12]; // [sp+14h] [bp-38h] BYREF
  uint8_t v12[20]; // [sp+20h] [bp-2Ch] BYREF
  uint8_t v13[8]; // [sp+34h] [bp-18h] BYREF
  uint8_t v14[4]; // [sp+3Ch] [bp-10h] BYREF
  uint8_t v15[4]; // [sp+40h] [bp-Ch] BYREF
  uint8_t v16[8]; // [sp+44h] [bp-8h] BYREF

  if ( !*(uint32_t *)off_114D28 )
    sub_114BF8();
  MEMORY[0x1D8](*(uint32_t *)off_114D2C + 0x2000, 72, v9);
  if ( v9[0] != dword_114D30 )
    return -1;
  v6 = a1 & v9[1];
  if ( !v6 )
    return 1;
  v7 = v6 & 1;
  if ( (v6 & 1) != 0 )
  {
    sub_143770(a2, v10, 4);
    v7 = 4;
    if ( (v6 & 2) == 0 )
    {
LABEL_7:
      if ( (v6 & 4) == 0 )
        goto LABEL_8;
      goto LABEL_22;
    }
  }
  else if ( (v6 & 2) == 0 )
  {
    goto LABEL_7;
  }
  sub_143770(a2 + v7, v11, 12);
  v7 += 12;
  if ( (v6 & 4) == 0 )
  {
LABEL_8:
    if ( (v6 & 8) == 0 )
      goto LABEL_9;
    goto LABEL_20;
  }
LABEL_22:
  sub_143770(a2 + v7, v12, 20);
  v7 += 20;
  if ( (v6 & 8) == 0 )
  {
LABEL_9:
    if ( (v6 & 0x20) == 0 )
      goto LABEL_10;
    goto LABEL_18;
  }
LABEL_20:
  sub_143770(a2 + v7, v13, 4);
  v7 += 4;
  if ( (v6 & 0x20) == 0 )
  {
LABEL_10:
    if ( (v6 & 0x40) == 0 )
      goto LABEL_11;
    goto LABEL_16;
  }
LABEL_18:
  sub_143770(a2 + v7, v14, 4);
  v7 += 4;
  if ( (v6 & 0x40) == 0 )
  {
LABEL_11:
    if ( (v6 & 0x80) == 0 )
      goto LABEL_12;
    goto LABEL_15;
  }
LABEL_16:
  sub_143770(a2 + v7, v15, 4);
  v7 += 4;
  if ( (v6 & 0x80) != 0 )
  {
LABEL_15:
    sub_143770(a2 + v7, v16, 4);
    v7 += 4;
  }
LABEL_12:
  if ( a3 < v7 )
    return -2;
  else
    return 0;
}

