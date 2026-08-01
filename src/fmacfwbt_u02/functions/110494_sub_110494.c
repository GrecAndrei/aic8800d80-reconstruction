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

extern uint32_t off_1105B8;
extern uint32_t off_1105BC;
extern uint32_t off_1105B4;
extern uint32_t off_1105E4;
extern uint32_t off_1105E8;
extern uint32_t dword_1105E0;
extern uint32_t dword_1105DC;
extern uint32_t off_1105C0;
extern uint32_t off_1105C4;
extern uint32_t off_1105C8;
extern uint32_t off_1105CC;
extern uint32_t dword_1105D4;
extern uint32_t dword_1105D8;
extern uint32_t off_1105D0;

// rf_isr @ 0x110494, size 286 bytes
int  rf_isr(int a1, int a2)
{
  uint32_t *v2; // r4
  int *v3; // r7
  unsigned int v6; // r2
  uint32_t *v7; // r9
  int *v8; // r11
  int v9; // r10
  uint32_t *v10; // r0
  uint32_t *v11; // r5
  int v12; // r0
  int *v13; // r3
  int v14; // r0
  int v15; // r1
  int16_t v16; // r2
  uint32_t *v17; // r1
  int v18; // r0
  int v19; // r2
  unsigned int v21; // [sp+4h] [bp-8h]

  v2 = off_1105B8;
  v3 = (int *)off_1105BC;
  v21 = *(uint16_t *)(*(uint32_t *)off_1105B4 + 48);
  usb_irq_handler(a2);
  v6 = *(uint16_t *)(a2 + 0xC);
LABEL_2:
  v7 = off_1105E4;
  v8 = (int *)off_1105E8;
  while ( v21 > v6 )
  {
    if ( *v7 <= 4u )
      goto LABEL_24;
    v9 = (*(int ( **)(uint32_t))(*(uint32_t *)(a1 + 4 + 4) + 16))(*(uint32_t *)(a1 + 4));
    if ( !v9 )
    {
      printf_wrapper(dword_1105E0, *v7);
LABEL_23:
      if ( *(uint16_t *)(a2 + 0xC) >= (unsigned int)*(uint16_t *)(*(uint32_t *)off_1105B4 + 50) )
        return 1;
LABEL_24:
      set_system_flag_1(32);
      return 1;
    }
    v10 = (uint32_t *)critical_enter_0();
    v11 = v10;
    if ( !v10 )
    {
      printf_wrapper(dword_1105DC);
      (*(void ( **)(uint32_t, int))(*(uint32_t *)(a1 + 4 + 4) + 20))(*(uint32_t *)(a1 + 4), v9);
      goto LABEL_23;
    }
    *v10 = 0;
    v12 = *v8;
    v11[1] = 0;
    v11[2] = 0;
    *v11 = v12 + v9;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_1105C0 = 1;
    }
    v13 = (int *)off_1105C4;
    v14 = *(uint32_t *)off_1105C4 + 1;
    *(uint32_t *)off_1105C4 = v14;
    *v2 = 1;
    while ( (*v2 & 2) != 0 )
      ;
    if ( *v3 )
    {
      v19 = *(uint32_t *)(a2 + 4);
      if ( v19 )
        *(uint32_t *)(v19 + 4) = v11;
    }
    else
    {
      if ( **(int16_t **)off_1105C8 < 0 && *(uint32_t *)off_1105CC )
      {
        mmio_irq_clear(dword_1105D4, dword_1105D8, 400);
        v13 = (int *)off_1105C4;
        v14 = *(uint32_t *)off_1105C4;
      }
      *(uint32_t *)off_1105CC = v11;
    }
    v15 = *v3;
    v16 = *(uint16_t *)(a2 + 0xC);
    *(uint32_t *)(a2 + 4) = v11;
    v6 = (uint16_t)(v16 + 1);
    *(uint16_t *)(a2 + 0xC) = v6;
    *v3 = (uint16_t)(v15 + 1);
    *(uint32_t *)off_1105D0 = 1;
    if ( v14 )
    {
      v17 = off_1105C0;
      v18 = v14 - 1;
      *v13 = v18;
      if ( !v18 )
      {
        if ( *v17 )
        {
          __enable_irq();
          v6 = *(uint16_t *)(a2 + 0xC);
        }
      }
      goto LABEL_2;
    }
  }
  return 1;
}

