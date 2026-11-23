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


extern uint32_t dword_115CF8;
extern uint32_t dword_115CFC;
extern uint32_t dword_115D00;
extern uint32_t dword_115D04;
extern uint32_t dword_115D08;
extern uint32_t dword_115D0C;
extern uint32_t dword_115D10;
extern uint32_t dword_115D14;
extern uint32_t dword_115D18;
extern uint32_t dword_115D1C;
extern uint32_t dword_115D20;
extern uint32_t dword_115D24;
extern uint32_t dword_115D28;
extern uint32_t dword_115D30;
extern uint32_t dword_115D34;
extern uint32_t dword_115D38;
extern uint32_t dword_115D3C;
extern uint32_t dword_115D40;
extern uint32_t dword_115D44;
extern uint32_t dword_115D48;
extern uint32_t dword_115D4C;
extern uint32_t dword_115D50;
extern uint32_t dword_115D54;
extern uint32_t dword_115D58;
extern uint32_t dword_115D5C;

// clear_rx_config @ 0x115ae4, size 532 bytes
int  clear_rx_config(int result)
{
  uint8_t **v1; // r5
  uint8_t *v2; // r1
  uint8_t **v3; // r6
  int v4; // r3
  int *v5; // r3
  uint8_t *v6; // r4
  uint8_t *v7; // r4
  int v8; // r3
  volatile unsigned int v9; // r2
  int v10; // r0
  volatile unsigned int v11; // r1
  unsigned int v12; // r1
  int v13; // r3
  unsigned int v14; // r2
  unsigned int v15; // r1
  char v16; // r0
  int v17; // r0
  int v18; // r0
  int v19; // r0

  if ( *(uint8_t *)dword_115CF8 && (*(uint32_t *)(dword_115CFC + 0x10) & 0xFFFF00) == 0x10000 )
  {
    v7 = (uint8_t *)dword_115D20;
    v8 = *(uint8_t *)dword_115D1C;
    v9 = 0;
    *(uint8_t *)dword_115D20 = 0;
    if ( v8 )
    {
      v15 = dword_115D48;
    }
    else if ( *(uint8_t *)dword_115D24 )
    {
      if ( *(uint32_t *)dword_115D28
        && (v9 = (*(volatile uint32_t *)0x40501010u), (int)(*(uint32_t *)(*(uint32_t *)dword_115D28 + 12) - v9 - 5000) < 0) )
      {
        v15 = dword_115D54;
      }
      else
      {
        if ( *(uint8_t *)dword_115D30
          || *(uint32_t *)(dword_115D08 + 0x1F8)
          || (dword_115D38 & *(uint32_t *)dword_115D34) != 0 && (unsigned int)(32 * *(uint32_t *)dword_115D3C) <= 0x1387 )
        {
          return result;
        }
        v10 = sub_12EA10(result);
        v11 = (*(volatile uint32_t *)0x40501010u);
        v12 = v11 + 28;
        do
          v13 = v12 - (*(volatile uint32_t *)0x40501010u);
        while ( v13 >= 0 );
        if ( **(uint8_t **)dword_115D04 != 1 || (v10 = (uint8_t)sub_10D304(v10), (*v7 = v10) != 0) )
        {
          v14 = dword_115D40;
          *(uint8_t *)dword_115D14 = 1;
          *(uint32_t *)(v14 + 0x38) |= 0x10u;
          if ( sub_1112F4(v10) )
            return sub_11597C();
          v15 = dword_115D44;
        }
        else
        {
          v15 = dword_115D50;
        }
      }
    }
    else
    {
      v15 = dword_115D4C;
    }
    return sub_12ECD0(2, v15, v9);
  }
  if ( *(uint8_t *)(dword_115CFC + 0x12) )
  {
    v6 = (uint8_t *)dword_115D14;
    goto LABEL_23;
  }
  v1 = (uint8_t **)dword_115D00;
  v2 = *(uint8_t **)dword_115D00;
  if ( **(uint8_t **)dword_115D00 )
  {
    v3 = (uint8_t **)dword_115D04;
    goto LABEL_6;
  }
  v5 = *(int **)(dword_115CFC + 8);
  v6 = (uint8_t *)dword_115D14;
  *(uint8_t *)dword_115D14 = 1;
  if ( !v5 )
  {
LABEL_42:
    v3 = (uint8_t **)dword_115D04;
    if ( **(uint8_t **)dword_115D04 == 3 )
    {
LABEL_8:
      result = sub_128F1C(result);
      if ( !result )
        return result;
      if ( *(uint32_t *)(dword_115D08 + 0x1F8) )
        return result;
      if ( !((*(uint32_t *)dword_115D0C >> 25) & 1 | *(uint8_t *)(dword_115D10 + 0x24)) )
        return result;
      if ( *(uint8_t *)(dword_115D10 + 0x1D) )
        return result;
      result = sub_12BD40();
      if ( !result )
        return result;
      result = (uint8_t)sub_10D304(result);
      *(uint8_t *)dword_115D20 = result;
      if ( !(uint8_t)result )
      {
        v19 = sub_12EA88(dword_115D58);
        result = sub_12EA10(v19);
      }
      if ( (uint8_t)**v1 > 1u )
        return result;
      return sub_11597C();
    }
    result = sub_12ECD0(2, dword_115D18, *v2);
    *v6 = 1;
LABEL_6:
    v4 = **v3;
    if ( v4 == 1 )
    {
      if ( **v1 == 3 )
      {
        v16 = sub_10D304(result);
        *(uint8_t *)dword_115D20 = v16;
        if ( v16 )
          v17 = sub_12EA88(dword_115D5C);
        else
          v17 = sub_12EA88(dword_115D50);
        v18 = sub_1112F4(v17);
        if ( v18 )
          v18 = sub_11597C();
        return sub_12EA10(v18);
      }
      result = sub_1112F4(result);
      if ( !result || *(uint8_t *)dword_115D30 )
        return result;
    }
    else if ( v4 == 2 )
    {
      return result;
    }
    goto LABEL_8;
  }
  while ( !*((uint8_t *)v5 + 106) )
  {
    if ( *((uint8_t *)v5 + 108) )
      goto LABEL_20;
LABEL_17:
    v5 = (int *)*v5;
    if ( !v5 )
      goto LABEL_42;
  }
  if ( *((uint8_t *)v5 + 106) != 2 )
    goto LABEL_17;
LABEL_20:
  if ( **(uint8_t **)dword_115D04 != 3 )
    result = sub_12ECD0(2, dword_115D18, *v2);
LABEL_23:
  *v6 = 0;
  return result;
}
