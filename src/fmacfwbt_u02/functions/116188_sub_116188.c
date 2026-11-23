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


extern uint32_t dword_116368;
extern uint32_t dword_11636C;
extern uint32_t dword_116370;
extern uint32_t dword_116374;
extern uint32_t dword_116378;
extern uint32_t dword_11637C;
extern uint32_t dword_116380;
extern uint32_t dword_116384;
extern uint32_t dword_116388;
extern uint32_t dword_11638C;
extern uint32_t dword_116394;
extern uint32_t dword_116398;
extern uint32_t dword_11639C;
extern uint32_t dword_1163A0;
extern uint32_t dword_1163A4;

// ke_init_structures @ 0x116188, size 472 bytes
void  ke_init_structures()
{
  unsigned int v0; // r5
  int v1; // r0
  uint8_t **v2; // r8
  int v3; // r3
  int v4; // r0
  uint8_t *v5; // r7
  int *v6; // r9
  int *v7; // r4
  int *v8; // r6
  unsigned int v9; // r11
  int v10; // r2
  int v11; // r3
  int v12; // r3
  int v13; // r2
  int v14; // r3
  volatile unsigned int v15; // r2
  unsigned int v16; // r2
  volatile unsigned int v17; // r3
  uint32_t *v18; // r2

  v0 = dword_11636C;
  v1 = sub_12ECB0(dword_116368);
  if ( *(uint32_t *)dword_116370 )
  {
    sub_10ED6C(v1);
    if ( *(uint16_t *)(*(uint32_t *)v0 + 8) )
      sub_10ED30(*(uint16_t *)(*(uint32_t *)v0 + 8));
  }
  v2 = (uint8_t **)dword_11639C;
  if ( **(uint8_t **)dword_11639C == 2 )
  {
    v3 = *(uint32_t *)v0;
    *(uint8_t *)(v3 + 6) = 2;
    *(uint8_t *)(v3 + 3) = 1;
  }
  v4 = sub_114498(*(uint16_t *)(*(uint32_t *)v0 + 4));
  if ( !*(uint8_t *)(*(uint32_t *)v0 + 3) )
    v4 = sub_114524(v4);
  __enable_irq();
  __dsb(0xFu);
  __isb(0xFu);
  v5 = (uint8_t *)dword_116374;
  v6 = (int *)dword_1163A0;
  v7 = (int *)dword_116378;
  v8 = (int *)dword_11637C;
  v9 = dword_1163A4;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( *(uint8_t *)(*(uint32_t *)v0 + 3) )
        v4 = sub_114514(v4);
      if ( !*v5 )
        v4 = sub_12D3B8(v4);
      v4 = sub_13038C(v4);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v6 = 1;
      }
      v10 = *v8;
      v11 = *v7 + 1;
      *v7 = v11;
      if ( !v10 )
        break;
      if ( v11 )
        goto LABEL_15;
    }
    if ( *(uint8_t *)(dword_116380 + 0x12) )
    {
      *(uint8_t *)dword_11638C = 0;
      if ( *(uint8_t *)(*(uint32_t *)v0 + 3) )
LABEL_40:
        v4 = sub_114524(v4);
    }
    else
    {
      v4 = sub_116034(v4);
      if ( *(uint8_t *)(*(uint32_t *)v0 + 3) )
        goto LABEL_40;
    }
    if ( **v2 == 1 && *(uint8_t *)dword_116384 )
    {
      v14 = **(uint8_t **)dword_116388;
      if ( v14 == 3 )
      {
        v4 = sub_111150(v4);
        if ( !v4 )
        {
          v14 = **(uint8_t **)dword_116388;
          goto LABEL_32;
        }
      }
      else
      {
LABEL_32:
        if ( v14 == 1 )
        {
          if ( !*(uint8_t *)(v9 + 1) || *(uint8_t *)dword_116398 )
            goto LABEL_21;
        }
        else if ( v14 || !*(uint8_t *)dword_11638C || !*(uint8_t *)(v9 + 1) )
        {
          goto LABEL_21;
        }
      }
      v4 = sub_12EC38(v4);
      v15 = (*(volatile uint32_t *)0x40501010u);
      v16 = v15 + 28;
      do
        v17 = (*(volatile uint32_t *)0x40501010u);
      while ( (int)(v16 - v17) >= 0 );
      v18 = (uint32_t *)dword_116394;
      *(uint32_t *)(dword_116394 + 4) |= 0x1000u;
      v18[21] |= 0x1000u;
      *v18 |= 0x1000u;
      goto LABEL_21;
    }
    do
    {
LABEL_21:
      __dsb(0xFu);
      __wfi();
      __isb(0xFu);
      if ( **v2 != 3 )
      {
        if ( *(uint8_t *)(*(uint32_t *)v0 + 3) )
          goto LABEL_28;
LABEL_23:
        if ( *(uint8_t *)(v9 + 1) )
          goto LABEL_29;
        goto LABEL_24;
      }
      v4 = sub_115B00(v4);
    }
    while ( !v4 );
    if ( !*(uint8_t *)(*(uint32_t *)v0 + 3) )
      goto LABEL_23;
LABEL_28:
    v4 = sub_114538(v4);
    if ( *(uint8_t *)(v9 + 1) )
LABEL_29:
      v4 = sub_115B90(v4);
LABEL_24:
    v11 = *v7;
    if ( *v7 )
    {
LABEL_15:
      v12 = v11 - 1;
      v13 = *v6;
      *v7 = v12;
      if ( !v12 )
      {
        if ( v13 )
          __enable_irq();
      }
    }
  }
}
