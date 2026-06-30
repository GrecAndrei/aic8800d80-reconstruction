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

extern uint32_t off_12C1CC;
extern uint32_t off_12C1D0;
extern uint32_t dword_12C1E8;
extern uint32_t dword_12C1E4;
extern uint32_t off_12C1D4;
extern uint32_t off_12C1F8;
extern uint32_t off_12C1FC;
extern uint32_t dword_12C200;
extern uint32_t off_12C1D8;
extern uint32_t off_12C1DC;
extern uint32_t off_12C1E0;
extern uint32_t dword_12C1EC;
extern uint32_t dword_12C1F4;
extern uint32_t dword_12C214;
extern uint32_t dword_12C210;
extern uint32_t dword_12C20C;
extern uint32_t dword_12C208;
extern uint32_t dword_12C204;
extern uint32_t dword_12C1F0;

// sub_12C0B4 @ 0x12c0b4, size 280 bytes
// Doc: sub_122C0B4 [mmio]: Copy MMIO register value from 0x40328084 to 0x40328088
// sub_122C0B4 [mmio]: Copy MMIO register value from 0x40328084 to 0x40328088
int  sub_12C0B4(int a1, int a2)
{
  void *v2; // r2
  int v3; // r4
  int result; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r1
  int v9; // r0
  int v10; // r2
  char *v11; // r4
  int v12; // r1
  int v13; // r2

  v2 = off_12C1CC;
  v3 = *(uint32_t *)off_12C1CC;
  *(uint32_t *)off_12C1D0 = *(uint32_t *)off_12C1CC;
  result = v3 << 21;
  if ( (v3 & 0x400) != 0 )
  {
    sub_12ECB0(dword_12C1E8, a2, v2);
    while ( 1 )
      ;
  }
  v5 = v3 << 23;
  if ( (v3 & 0x100) == 0 )
  {
    v6 = v3 << 22;
    if ( (v3 & 0x200) == 0 )
      goto LABEL_4;
LABEL_13:
    sub_12ECB0(dword_12C1E4, v5, v6);
    while ( 1 )
      ;
  }
  result = bt_flag_get();
  v6 = v3 << 22;
  if ( (v3 & 0x200) != 0 )
    goto LABEL_13;
LABEL_4:
  if ( (v3 & 0x10) != 0 )
  {
    patch_sub_1217374(4);
    result = sub_1178DC(4);
  }
  if ( (v3 & 0x2F) != 0 )
  {
    if ( *(uint8_t *)off_12C1D4 )
    {
      v11 = (char *)off_12C1F8;
      rf_power_set(*((uint8_t *)off_12C1F8 + 411));
      v12 = v11[411];
      *((uint8_t *)off_12C1FC + 9) = v12;
      return sub_12ECB0(dword_12C200, v12, v13);
    }
    if ( *(uint8_t *)off_12C1D8 )
    {
      result = *(uint32_t *)off_12C1DC << 28;
      if ( result )
        *((uint8_t *)off_12C1D8 + 6) = 1;
    }
  }
  v7 = **(int16_t **)off_12C1E0;
  if ( v7 < 0 )
  {
    if ( (v3 & 1) != 0 )
    {
      v8 = dword_12C1EC;
      v9 = dword_12C1F4;
      v10 = 760;
    }
    else if ( (v3 & 2) != 0 )
    {
      v8 = dword_12C1EC;
      v9 = dword_12C214;
      v10 = 761;
    }
    else
    {
      v7 = v3 << 29;
      if ( (v3 & 4) != 0 )
      {
        v8 = dword_12C1EC;
        v9 = dword_12C210;
        v10 = 762;
      }
      else
      {
        result = v3 << 28;
        if ( (v3 & 8) != 0 )
        {
          v8 = dword_12C1EC;
          v9 = dword_12C20C;
          v10 = 763;
        }
        else if ( (v3 & 0x80) != 0 )
        {
          v8 = dword_12C1EC;
          v9 = dword_12C208;
          v10 = 765;
        }
        else if ( (v3 & 0x40) != 0 )
        {
          v8 = dword_12C1EC;
          v9 = dword_12C204;
          v10 = 767;
        }
        else
        {
          v7 = v3 << 26;
          if ( (v3 & 0x20) == 0 )
            return result;
          v8 = dword_12C1EC;
          v9 = dword_12C1F0;
          v10 = 769;
        }
      }
    }
    return sub_12F630(v9, v8, v10, v7);
  }
  return result;
}

