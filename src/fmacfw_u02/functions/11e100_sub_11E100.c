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

extern uint32_t off_11E1BC;
extern uint32_t dword_11E1C4;
extern uint32_t dword_11E1CC;
extern uint32_t dword_11E1C8;
extern uint32_t off_11E1C0;

// rf_tx_frame @ 0x11e100, size 188 bytes
// Doc: sub_121E100 [unknown]: Small helper reading halfword from offset 0x30
// sub_121E100 [unknown]: Small helper reading halfword from offset 0x30
int  rf_tx_frame(int a1)
{
  int v1; // r4
  int v2; // r3
  int v3; // r2
  int v4; // r3
  unsigned int v5; // r3
  uint32_t *v6; // r1
  int v7; // r2
  int v8; // cf
  unsigned int v9; // r2
  int v11; // r1
  int v12; // r0
  int v13; // r2
  int v14; // [sp+4h] [bp-4h]
  int v15; // [sp+4h] [bp-4h]

  if ( *(uint16_t *)(a1 + 48) )
  {
    v1 = *(uint32_t *)(a1 + 28);
    v2 = **(int16_t **)off_11E1BC;
    if ( v2 < 0 && !v1 )
    {
      v11 = dword_11E1C4;
      v12 = dword_11E1CC;
      v13 = 393;
      return bad_func_0x12f408(v12, v11, v13, v2);
    }
    v3 = *(uint32_t *)(a1 + 84);
    v4 = **(uint16_t **)(v1 + 8) & 0xFC;
    *(uint32_t *)(a1 + 84) = v3 & 0xFEFFFFFF;
    if ( v4 == 36 )
    {
      if ( (v3 & 0x2000) != 0 )
      {
        v14 = a1;
        update_phy_status(a1);
        a1 = v14;
      }
    }
    else if ( v4 == 148 && (~v3 & 0x2002) == 0 )
    {
      v15 = a1;
      init_flag_check(a1, v3 & 0xFEFFFFFF, v3, 0);
      a1 = v15;
    }
    v5 = (*(uint32_t *)(v1 + 12) & 0xFFFFFFFC) + 4;
  }
  else
  {
    if ( **(int16_t **)off_11E1BC < 0 )
    {
      v2 = *(uint32_t *)(a1 + 28);
      if ( v2 )
      {
        v11 = dword_11E1C4;
        v12 = dword_11E1C8;
        v13 = 436;
        return bad_func_0x12f408(v12, v11, v13, v2);
      }
    }
    v5 = a1 + 160;
  }
  v6 = off_11E1C0;
  v7 = *((uint32_t *)off_11E1C0 + 5);
  if ( *((uint32_t *)off_11E1C0 + 4) == v5 )
    v5 = *((uint32_t *)off_11E1C0 + 3);
  *(uint32_t *)(a1 + 152) = v5;
  v8 = v5 >= (v7 & 0x7FFFFFFFu);
  v9 = v7 & 0x80000000;
  if ( !v8 )
    v9 += 0x80000000;
  v6[5] = v5 | v9;
  return radio_get_status(a1);
}

