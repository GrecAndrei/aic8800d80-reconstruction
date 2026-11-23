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


extern uint32_t dword_115BB8;
extern uint32_t dword_115BBC;
extern uint32_t dword_115BC0;
extern uint32_t dword_115BC4;
extern uint32_t dword_115BC8;
extern uint32_t dword_115BCC;
extern uint32_t dword_115BD0;
extern uint32_t dword_115BD4;
extern uint32_t dword_115BD8;
extern uint32_t dword_115BDC;
extern uint32_t dword_115BE0;
extern uint32_t dword_115BE4;
extern uint32_t dword_115BE8;
extern uint32_t dword_115BF0;
extern uint32_t dword_115BF4;
extern uint32_t dword_115BF8;
extern uint32_t dword_115BFC;
extern uint32_t dword_115C00;
extern uint32_t dword_115C04;
extern uint32_t dword_115C08;
extern uint32_t dword_115C0C;
extern uint32_t dword_115C10;
extern uint32_t dword_115C14;
extern uint32_t dword_115C18;
extern uint32_t dword_115C1C;

// sleep_mode_read @ 0x1159a4, size 532 bytes
int  sleep_mode_read(int result)
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
  int v16; // r1
  int v17; // r3
  unsigned int v18; // r2
  char v19; // r0
  int v20; // r1
  int v21; // r3
  unsigned int v22; // r2
  int v23; // r0
  int v24; // r0
  int v25; // r0

  if ( *(uint8_t *)dword_115BB8 && (*(uint32_t *)(dword_115BBC + 0x10) & 0xFFFF00) == 0x10000 )
  {
    v7 = (uint8_t *)dword_115BE0;
    v8 = *(uint8_t *)dword_115BDC;
    v9 = 0;
    *(uint8_t *)dword_115BE0 = 0;
    if ( v8 )
    {
      v15 = dword_115C08;
    }
    else if ( *(uint8_t *)dword_115BE4 )
    {
      if ( *(uint32_t *)dword_115BE8
        && (v9 = (*(volatile uint32_t *)0x40501010u), (int)(*(uint32_t *)(*(uint32_t *)dword_115BE8 + 12) - v9 - 5000) < 0) )
      {
        v15 = dword_115C14;
      }
      else
      {
        if ( *(uint8_t *)dword_115BF0
          || *(uint32_t *)(dword_115BC8 + 0x1F8)
          || (dword_115BF8 & *(uint32_t *)dword_115BF4) != 0 && (unsigned int)(32 * *(uint32_t *)dword_115BFC) <= 0x1387 )
        {
          return result;
        }
        v10 = sub_12E8D0(result);
        v11 = (*(volatile uint32_t *)0x40501010u);
        v12 = v11 + 28;
        do
          v13 = v12 - (*(volatile uint32_t *)0x40501010u);
        while ( v13 >= 0 );
        if ( **(uint8_t **)dword_115BC4 != 1 || (v10 = (uint8_t)sub_10D1C4(v10), (*v7 = v10) != 0) )
        {
          v14 = dword_115C00;
          *(uint8_t *)dword_115BD4 = 1;
          *(uint32_t *)(v14 + 0x38) |= 0x10u;
          if ( sub_1111B4(v10) )
            return sub_11583C();
          v15 = dword_115C04;
        }
        else
        {
          v15 = dword_115C10;
        }
      }
    }
    else
    {
      v15 = dword_115C0C;
    }
    return feature_guard_sdio(2, v15, v9);
  }
  if ( *(uint8_t *)(dword_115BBC + 0x12) )
  {
    v6 = (uint8_t *)dword_115BD4;
    goto LABEL_23;
  }
  v1 = (uint8_t **)dword_115BC0;
  v2 = *(uint8_t **)dword_115BC0;
  if ( **(uint8_t **)dword_115BC0 )
  {
    v3 = (uint8_t **)dword_115BC4;
    goto LABEL_6;
  }
  v5 = *(int **)(dword_115BBC + 8);
  v6 = (uint8_t *)dword_115BD4;
  *(uint8_t *)dword_115BD4 = 1;
  if ( !v5 )
  {
LABEL_42:
    v3 = (uint8_t **)dword_115BC4;
    if ( **(uint8_t **)dword_115BC4 == 3 )
    {
LABEL_8:
      result = sub_128DDC(result);
      if ( !result )
        return result;
      if ( *(uint32_t *)(dword_115BC8 + 0x1F8) )
        return result;
      if ( !((*(uint32_t *)dword_115BCC >> 25) & 1 | *(uint8_t *)(dword_115BD0 + 0x24)) )
        return result;
      if ( *(uint8_t *)(dword_115BD0 + 0x1D) )
        return result;
      result = sub_12BC00();
      if ( !result )
        return result;
      LOBYTE(result) = sub_10D1C4(result);
      v18 = dword_115BE0;
      result = (uint8_t)result;
      *(uint8_t *)dword_115BE0 = result;
      if ( !(uint8_t)result )
      {
        v25 = msg_parse(dword_115C18, v16, v18, v17);
        result = sub_12E8D0(v25);
      }
      if ( (uint8_t)**v1 > 1u )
        return result;
      return sub_11583C();
    }
    result = feature_guard_sdio(2, dword_115BD8, *v2);
    *v6 = 1;
LABEL_6:
    v4 = **v3;
    if ( v4 == 1 )
    {
      if ( **v1 == 3 )
      {
        v19 = sub_10D1C4(result);
        v22 = dword_115BE0;
        *(uint8_t *)dword_115BE0 = v19;
        if ( v19 )
          v23 = msg_parse(dword_115C1C, v20, v22, v21);
        else
          v23 = msg_parse(dword_115C10, v20, v22, v21);
        v24 = sub_1111B4(v23);
        if ( v24 )
          v24 = sub_11583C();
        return sub_12E8D0(v24);
      }
      result = sub_1111B4(result);
      if ( !result || *(uint8_t *)dword_115BF0 )
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
  if ( **(uint8_t **)dword_115BC4 != 3 )
    result = feature_guard_sdio(2, dword_115BD8, *v2);
LABEL_23:
  *v6 = 0;
  return result;
}
