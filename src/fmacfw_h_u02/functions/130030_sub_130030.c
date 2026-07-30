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

extern uint32_t off_130120;
extern uint32_t off_130124;
extern uint32_t dword_130128;
extern uint32_t dword_13012C;
extern uint32_t dword_130140;
extern uint32_t dword_130144;
extern uint32_t dword_13013C;
extern uint32_t dword_130130;
extern uint32_t dword_130134;
extern uint32_t dword_130138;

// sub_130030 @ 0x130030, size 238 bytes
uint8_t *sub_130030()
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
    *(uint32_t *)off_130120 = 1;
  }
  v0 = (int *)off_130124;
  v1 = dword_130128;
  ++*(uint32_t *)off_130124;
  result = (uint8_t *)sub_12D190(v1);
  v3 = result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(uint32_t *)off_130120;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (uint32_t *)dword_13012C;
    v7 = dword_130140;
    v8 = dword_130144;
    do
    {
      v9 = sub_12F5BC(v3 + 4, (int)v15);
      if ( v9 )
      {
        v13 = sub_12F648(v15[0], v6, 7);
        if ( v13 )
        {
          if ( *((int16_t *)v13 + 5) < v9 || *((int16_t *)v13 + 4) > v9 )
          {
            sub_10DAE4(v7, *v13, v13[1]);
          }
          else
          {
            v14 = ((int ( *)(int, int *))v13[3])(v9, v15);
            if ( v14 )
              sub_10DAE4(v8, v14);
          }
        }
        else
        {
          sub_10DAE4(dword_13013C, v15[0]);
        }
      }
      else
      {
        sub_10D674((uint8_t *)dword_130130);
      }
      sub_10D674((uint8_t *)dword_130134);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_130120 = 1;
      }
      v10 = dword_130138;
      ++*v0;
      sub_12D108(v10, v3);
      result = (uint8_t *)sub_12D190(dword_130128);
      v3 = result;
      if ( *v0 )
      {
        v11 = *v0 - 1;
        v12 = *(uint32_t *)off_130120;
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

