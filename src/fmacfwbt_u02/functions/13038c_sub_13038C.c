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

extern uint32_t off_13047C;
extern uint32_t off_130480;
extern uint32_t dword_130484;
extern uint32_t dword_130488;
extern uint32_t dword_13049C;
extern uint32_t dword_1304A0;
extern uint32_t dword_130498;
extern uint32_t dword_13048C;
extern uint32_t dword_130490;
extern uint32_t dword_130494;

// sub_13038C @ 0x13038c, size 238 bytes
uint8_t *sub_13038C()
{
  int *v0; // r6
  int v1; // r0
  uint8_t *result; // r0
  uint8_t *v3; // r4
  int v4; // r3
  int v5; // r2
  uint32_t *v6; // r7
  int v7; // r8
  int v8; // r9
  int v9; // r5
  int v10; // r0
  int v11; // r3
  int v12; // r2
  uint32_t *v13; // r0
  int v14; // r0
  int v15[18]; // [sp+4h] [bp-48h] BYREF

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_13047C = 1;
  }
  v0 = (int *)off_130480;
  v1 = dword_130484;
  ++*(uint32_t *)off_130480;
  result = (uint8_t *)sub_12D4F8(v1);
  v3 = result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(uint32_t *)off_13047C;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (uint32_t *)dword_130488;
    v7 = dword_13049C;
    v8 = dword_1304A0;
    do
    {
      v9 = sub_12F918(v3 + 4, (int)v15);
      if ( v9 )
      {
        v13 = sub_12F9A4(v15[0], v6, 7);
        if ( v13 )
        {
          if ( *((int16_t *)v13 + 5) < v9 || *((int16_t *)v13 + 4) > v9 )
          {
            log_printf(v7, *v13, v13[1]);
          }
          else
          {
            v14 = ((int ( *)(int, int *))v13[3])(v9, v15);
            if ( v14 )
              log_printf(v8, v14);
          }
        }
        else
        {
          log_printf(dword_130498, v15[0]);
        }
      }
      else
      {
        sub_10D60C((uint8_t *)dword_13048C);
      }
      sub_10D60C((uint8_t *)dword_130490);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_13047C = 1;
      }
      v10 = dword_130494;
      ++*v0;
      list_push_tail(v10, v3);
      result = (uint8_t *)sub_12D4F8(dword_130484);
      v3 = result;
      if ( *v0 )
      {
        v11 = *v0 - 1;
        v12 = *(uint32_t *)off_13047C;
        *v0 = v11;
        if ( !v11 )
        {
          if ( v12 )
            __enable_irq();
        }
      }
    }
    while ( result );
  }
  return result;
}

