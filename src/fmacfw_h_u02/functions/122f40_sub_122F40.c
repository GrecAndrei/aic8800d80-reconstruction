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

extern uint32_t dword_123004;
extern uint32_t off_123008;
extern uint32_t off_123010;
extern uint32_t off_123018;
extern uint32_t off_123014;
extern uint32_t off_12300C;

// rf_calib_table_lookup @ 0x122f40, size 196 bytes
int  rf_calib_table_lookup(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r4
  int v5; // r6
  int v6; // r7
  unsigned int v7; // r5
  int v8; // r1
  unsigned int v9; // r0
  int v11; // r3
  int v12; // [sp+0h] [bp-Ch]
  int v13; // [sp+0h] [bp-Ch]
  int v14; // [sp+0h] [bp-Ch]
  int v16; // [sp+4h] [bp-8h]

  v4 = *(uint8_t *)(a2 + 5);
  v5 = *(uint8_t *)(a2 + 6);
  v6 = dword_123004;
  v7 = *(uint32_t *)a2;
  *(uint32_t *)(dword_123004 + 4 * (v4 + 330 * v5 + 2)) = *(uint32_t *)a2;
  v8 = a4;
  if ( v4 == 1 )
  {
    v11 = *(uint32_t *)(*(uint32_t *)off_123008 + 4);
    if ( v11 )
    {
      if ( (v11 & 0xFFF) != 0 )
        v7 = *(uint32_t *)(*(uint32_t *)off_123008 + 4);
      else
        v7 = v7 & 0xFFF | v11 & 0xFFFFF000;
    }
    if ( *(uint8_t *)(v6 + 1320 * v5 + 108) )
    {
      *(uint32_t *)off_123010 = v7;
      v13 = a3;
      v16 = v8;
      get_mac_ver();
      a3 = v13;
      v8 = v16;
    }
  }
  else
  {
    v9 = *(uint32_t *)(*(uint32_t *)off_123008 + 4 * v4);
    if ( !v9 )
      v9 = v7;
    if ( *(uint8_t *)(v6 + 1320 * v5 + 108) )
    {
      if ( v4 == 2 )
      {
        *(uint32_t *)off_123018 = v9;
        v14 = a3;
        get_mac_ver();
        a3 = v14;
        v8 = a4;
      }
      else
      {
        if ( v4 > 2 )
          *(uint32_t *)off_123014 = v9;
        else
          *(uint32_t *)off_12300C = v9;
        v12 = a3;
        get_mac_ver();
        a3 = v12;
        v8 = a4;
      }
    }
  }
  mac_write_header_word(27, v8, a3);
  return 0;
}

