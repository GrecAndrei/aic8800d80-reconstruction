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

extern uint32_t off_11DA94;
extern uint32_t off_11DAB4;
extern uint32_t dword_11DAC0;
extern uint32_t off_11DA98;
extern uint32_t off_11DAAC;
extern uint32_t dword_11DAB0;
extern uint32_t dword_11DAA0;
extern uint32_t off_11DAA4;
extern uint32_t off_11DAA8;
extern uint32_t off_11DAB8;
extern uint32_t off_11DABC;

// sub_11D930 @ 0x11d930, size 356 bytes
int  sub_11D930(int a1)
{
  uint32_t *v1; // r7
  uint8_t *v2; // r9
  int v3; // r8
  int v4; // r6
  int i; // r5
  int v6; // r3
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r2
  int v12; // r3
  int v13; // r4
  int result; // r0
  int v15; // r1
  int v16; // r2
  void ( *v17)(uint32_t); // r2
  void *v18; // r3
  uint32_t *v19; // r5
  int v20; // [sp+14h] [bp-8h]

  v1 = off_11DA94;
  v2 = off_11DAB4;
  v3 = dword_11DAC0;
  v4 = a1;
  for ( i = 0; ; ++i )
  {
    v13 = sub_11E9B8(a1);
    *v1 = 0x10000;
    result = sub_12D00C(0x80000);
    if ( !v13 )
      break;
    if ( !v4 )
    {
      v6 = (uint8_t)v2[192];
      if ( v2[192] )
      {
        v6 = *(uint32_t *)off_11DA98;
        if ( *(uint32_t *)off_11DA98 > 0x80000u || i > 31 )
          return sub_12CFC4(0x80000);
      }
      else if ( i > 3 )
      {
        return sub_12CFC4(0x80000);
      }
    }
    v7 = sub_12F3F8(result, v15, v16, v6);
    if ( !v7 || (v7 = sub_13A3C4(v7, v8, v9, v10)) == 0 )
    {
      v18 = off_11DAAC;
      *((uint8_t *)off_11DAAC + 69) = 1;
      sub_13A3C4(v7, v8, 1, v18);
      return sub_12EB90(1024, dword_11DAB0);
    }
    v11 = *(uint32_t *)(v13 + 20);
    if ( v11 != v3 )
      sub_12E948(dword_11DAA0, v13, v11);
    sub_11E9F4(v13);
    a1 = sub_11D1E0(v13);
    if ( a1 )
    {
      if ( a1 != 1 )
        goto LABEL_10;
    }
    else
    {
      a1 = sub_139E1C(v13);
      if ( a1 )
        goto LABEL_10;
    }
    a1 = sub_11E960(v13);
LABEL_10:
    v12 = **(uint8_t **)off_11DAA4;
    switch ( v12 )
    {
      case 2:
        goto LABEL_22;
      case 4:
        if ( !*(uint32_t *)off_11DAA8 || *(uint32_t *)(*(uint32_t *)off_11DAA8 + 12) != v13 || (*(uint8_t *)(v13 + 16) & 1) == 0 )
        {
LABEL_22:
          a1 = sub_11D864();
          continue;
        }
        v20 = *(uint32_t *)off_11DAA8;
        sub_12D190(off_11DAA8);
        v17 = *(void ( **)(uint32_t))(v20 + 4);
        *(uint8_t *)(v20 + 16) = 0;
        if ( v17 )
          v17(*(uint32_t *)(v20 + 8));
        a1 = sub_11DF74(v13);
        break;
      case 3:
        a1 = sub_11D7AC();
        break;
    }
  }
  if ( *((uint8_t *)off_11DAB4 + 192) )
  {
    v19 = off_11DAB8;
    if ( *((uint8_t *)off_11DAB8 + 33) )
    {
      result = sub_110EDC(*((uint32_t *)off_11DAB8 + 4), *((uint32_t *)off_11DAB8 + 5), *((uint32_t *)off_11DAB8 + 6));
      v19[5] = 0;
      v19[7] = 0;
      v19[4] = 0;
      v19[6] = 0;
      *((uint8_t *)v19 + 33) = 0;
    }
  }
  *(uint32_t *)off_11DABC |= 0x10000u;
  return result;
}

