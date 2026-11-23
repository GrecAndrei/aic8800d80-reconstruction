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


extern uint32_t dword_115DE4;
extern uint32_t dword_115DE8;
extern uint32_t dword_115DEC;
extern uint32_t dword_115DF0;
extern uint32_t dword_115DF4;
extern uint32_t dword_115DF8;
extern uint32_t dword_115DFC;
extern uint32_t dword_115E00;
extern uint32_t dword_115E04;
extern uint32_t dword_115E08;
extern uint32_t dword_115E0C;
extern uint32_t dword_115E14;
extern uint32_t dword_115E18;
extern uint32_t dword_115E1C;
extern uint32_t dword_115E20;
extern uint32_t dword_115E24;

// ll_init_tables @ 0x115c20, size 452 bytes
void  ll_init_tables(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r5
  int v5; // r0
  uint8_t **v6; // r10
  int v7; // r3
  int v8; // r0
  uint8_t *v9; // r7
  int *v10; // r8
  int *v11; // r4
  int *v12; // r6
  unsigned int v13; // r11
  int v14; // r2
  int v15; // r3
  int v16; // r3
  int v17; // r2
  int v18; // r3
  volatile unsigned int v19; // r2
  unsigned int v20; // r2
  volatile unsigned int v21; // r3
  uint32_t *v22; // r2

  v4 = dword_115DF0;
  v5 = msg_parse(dword_115DEC, dword_115DE8, dword_115DE4, a4);
  if ( *(uint32_t *)dword_115DF4 )
  {
    sub_10EDD4(v5);
    if ( *(uint16_t *)(*(uint32_t *)v4 + 8) )
      sub_10ED98(*(uint16_t *)(*(uint32_t *)v4 + 8));
  }
  v6 = (uint8_t **)dword_115E1C;
  if ( **(uint8_t **)dword_115E1C == 2 )
  {
    v7 = *(uint32_t *)v4;
    *(uint8_t *)(v7 + 6) = 2;
    *(uint8_t *)(v7 + 3) = 1;
  }
  v8 = sub_1144FC(*(uint16_t *)(*(uint32_t *)v4 + 4));
  if ( !*(uint8_t *)(*(uint32_t *)v4 + 3) )
    v8 = sub_114588(v8);
  __enable_irq();
  __dsb(0xFu);
  __isb(0xFu);
  v9 = (uint8_t *)dword_115DF8;
  v10 = (int *)dword_115E20;
  v11 = (int *)dword_115DFC;
  v12 = (int *)dword_115E00;
  v13 = dword_115E24;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( *(uint8_t *)(*(uint32_t *)v4 + 3) )
        v8 = sub_114578(v8);
      if ( !*v9 )
        v8 = sub_12D050(v8);
      v8 = sub_130030(v8);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v10 = 1;
      }
      v14 = *v12;
      v15 = *v11 + 1;
      *v11 = v15;
      if ( !v14 )
        break;
      if ( v15 )
        goto LABEL_15;
    }
    v8 = idle_processing(v8);
    if ( *(uint8_t *)(*(uint32_t *)v4 + 3) )
      v8 = sub_114588(v8);
    if ( **v6 == 1 && *(uint8_t *)dword_115E04 )
      break;
    do
    {
LABEL_21:
      __dsb(0xFu);
      __wfi();
      __isb(0xFu);
      if ( **v6 != 3 )
      {
        if ( *(uint8_t *)(*(uint32_t *)v4 + 3) )
          goto LABEL_28;
LABEL_23:
        if ( *(uint8_t *)(v13 + 1) )
          goto LABEL_29;
        goto LABEL_24;
      }
      v8 = sub_115470(v8);
    }
    while ( !v8 );
    if ( !*(uint8_t *)(*(uint32_t *)v4 + 3) )
      goto LABEL_23;
LABEL_28:
    v8 = sub_11459C(v8);
    if ( *(uint8_t *)(v13 + 1) )
LABEL_29:
      v8 = sub_115500(v8);
LABEL_24:
    v15 = *v11;
    if ( *v11 )
    {
LABEL_15:
      v16 = v15 - 1;
      v17 = *v10;
      *v11 = v16;
      if ( !v16 )
      {
        if ( v17 )
          __enable_irq();
      }
    }
  }
  v18 = **(uint8_t **)dword_115E08;
  if ( v18 == 3 )
  {
    v8 = sub_1111B4(v8);
    if ( v8 )
      goto LABEL_36;
    v18 = **(uint8_t **)dword_115E08;
  }
  if ( v18 == 1 )
  {
    if ( !*(uint8_t *)(v13 + 1) || *(uint8_t *)dword_115E18 )
      goto LABEL_21;
  }
  else if ( v18 || !*(uint8_t *)dword_115E0C || !*(uint8_t *)(v13 + 1) )
  {
    goto LABEL_21;
  }
LABEL_36:
  v8 = sub_12E8D0(v8);
  v19 = (*(volatile uint32_t *)0x40501010u);
  v20 = v19 + 28;
  do
    v21 = (*(volatile uint32_t *)0x40501010u);
  while ( (int)(v20 - v21) >= 0 );
  v22 = (uint32_t *)dword_115E14;
  *(uint32_t *)(dword_115E14 + 4) |= 0x1000u;
  v22[21] |= 0x1000u;
  *v22 |= 0x1000u;
  goto LABEL_21;
}
