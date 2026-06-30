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

extern uint32_t off_101BA4;
extern uint32_t off_101BA8;
extern uint32_t off_101BB0;
extern uint32_t off_101BB4;
extern uint32_t off_101BAC;
extern uint32_t off_101BB8;
extern uint32_t off_101BC4;
extern uint32_t dword_101BCC;
extern uint32_t dword_101BC8;
extern uint32_t dword_101BD0;
extern uint32_t off_101BBC;
extern uint32_t off_101BC0;

// sub_10197C @ 0x10197c, size 550 bytes
int  sub_10197C(int a1, uint8_t *a2, uint8_t *a3)
{
  int result; // r0
  unsigned int v5; // r10
  int v7; // r9
  int v8; // r6
  char v9; // r8
  char v10; // r11
  unsigned int v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r3
  int v14; // r2
  int v15; // r6
  char v16; // r8
  unsigned int v17; // r3
  char v18; // r3
  int v19; // r2
  int v20; // r2
  int v21; // r3
  unsigned int v22; // [sp+4h] [bp-8h]

  result = *((uint8_t *)off_101BA4 + 36);
  v5 = *((uint16_t *)off_101BA4 + 20);
  if ( !*((uint8_t *)off_101BA4 + 36) )
  {
    if ( *((uint8_t *)off_101BA8 + 197) )
    {
      if ( v5 > 0x97B )
      {
        if ( v5 > 0x994 )
          result = 2;
        else
          result = 1;
      }
      v7 = *((char *)off_101BA8 + 198);
      v8 = *((char *)off_101BA8 + 210);
      v9 = *((uint8_t *)off_101BB0 + 10) + *(uint8_t *)off_101BB4 + *(uint8_t *)(*(uint32_t *)off_101BAC + result + 6);
      v10 = *(uint8_t *)off_101BB4 + *((uint8_t *)off_101BB0 + 8) + *(uint8_t *)(*(uint32_t *)off_101BAC + result);
      v11 = v10;
      if ( *((uint8_t *)off_101BA8 + 396) )
      {
        result = *(uint8_t *)(*(uint32_t *)off_101BB8 + result);
        v7 = (char)(result + v7);
        v8 = (char)(v8 + result);
      }
      if ( (*((uint32_t *)off_101BA8 + 98) & 2) != 0 )
      {
        result = sub_132418(0, *((uint16_t *)off_101BA4 + 20));
        v11 = v10;
        if ( result )
        {
          v20 = *(char *)(result + 4);
        }
        else
        {
          if ( **(int16_t **)off_101BC4 < 0 )
          {
            sub_12F6C4(dword_101BCC, dword_101BC8, 6857);
            v11 = v10;
          }
          v22 = v11;
          result = sub_12ECB0(dword_101BD0, 0, v5);
          v11 = v22;
          v20 = 15;
        }
        if ( v7 >= v20 )
          LOBYTE(v7) = v20;
        if ( v8 >= v20 )
          LOBYTE(v8) = v20;
      }
      if ( (v10 & 1) != 0 )
        v12 = v11 - 1;
      else
        v12 = v11 + (v11 >> 31);
      if ( (v10 & 1) != 0 )
        v12 += v12 >> 31;
      if ( (v9 & 1) != 0 )
        v13 = v9 - 1 + ((unsigned int)(v9 - 1) >> 31);
      else
        v13 = v9 + ((unsigned int)v9 >> 31);
      *a2 = (v12 >> 1) + v7;
      *a3 = (v13 >> 1) + v8;
      return result;
    }
    if ( **(int16_t **)off_101BC4 >= 0 )
      return result;
    v19 = 6875;
    return sub_12F694(dword_101BCC, dword_101BC8, v19);
  }
  if ( !*((uint8_t *)off_101BA8 + 197) )
  {
    if ( **(int16_t **)off_101BC4 >= 0 )
      return result;
    v19 = 6921;
    return sub_12F694(dword_101BCC, dword_101BC8, v19);
  }
  if ( v5 <= 0x1666 )
  {
    if ( v5 > 0x1616 )
    {
      v14 = 4;
    }
    else if ( v5 > 0x15C6 )
    {
      v14 = 3;
    }
    else if ( v5 > 0x1571 )
    {
      v14 = 2;
    }
    else
    {
      v14 = v5 > 0x1486;
    }
  }
  else
  {
    v14 = 5;
  }
  result = *((uint8_t *)off_101BA8 + 396);
  v15 = *((char *)off_101BA8 + 236);
  v16 = *((uint8_t *)off_101BB4 + 1) + *((uint8_t *)off_101BB0 + 11) + *(uint8_t *)(*(uint32_t *)off_101BBC + v14);
  if ( *((uint8_t *)off_101BA8 + 396) )
    v15 = (char)(*(uint8_t *)(*(uint32_t *)off_101BC0 + v14) + v15);
  if ( (*((uint32_t *)off_101BA8 + 98) & 2) != 0 )
  {
    result = sub_132418(1, *((uint16_t *)off_101BA4 + 20));
    if ( result )
    {
      v21 = *(char *)(result + 4);
    }
    else
    {
      if ( **(int16_t **)off_101BC4 < 0 )
        sub_12F6C4(dword_101BCC, dword_101BC8, 6907);
      result = sub_12ECB0(dword_101BD0, 1, v5);
      v21 = 15;
    }
    if ( v15 >= v21 )
      LOBYTE(v15) = v21;
  }
  if ( (v16 & 1) != 0 )
    v17 = v16 - 1 + ((unsigned int)(v16 - 1) >> 31);
  else
    v17 = v16 + ((unsigned int)v16 >> 31);
  v18 = (v17 >> 1) + v15;
  *a3 = v18;
  *a2 = v18;
  return result;
}

