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

extern uint32_t off_130260;
extern uint32_t off_130264;
extern uint32_t dword_130268;
extern uint32_t dword_13026C;
extern uint32_t dword_130280;
extern uint32_t dword_130284;
extern uint32_t dword_13027C;
extern uint32_t dword_130270;
extern uint32_t dword_130274;
extern uint32_t dword_130278;

// parse_large_ioctl @ 0x130170, size 238 bytes
// Doc: sub_1230170_handler [unknown]: Pushes r4-r8,sb,lr; allocates 0x4c stack; handler stub
// sub_1230170_handler [unknown]: Pushes r4-r8,sb,lr; allocates 0x4c stack; handler stub
uint8_t *parse_large_ioctl()
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
    *(uint32_t *)off_130260 = 1;
  }
  v0 = (int *)off_130264;
  v1 = dword_130268;
  ++*(uint32_t *)off_130264;
  result = (uint8_t *)mem_word_load(v1);
  v3 = result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(uint32_t *)off_130260;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (uint32_t *)dword_13026C;
    v7 = dword_130280;
    v8 = dword_130284;
    do
    {
      v9 = parse_token_until_space(v3 + 4, (int)v15);
      if ( v9 )
      {
        v13 = parse_ipv4_dot(v15[0], v6, 7);
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
          log_printf(dword_13027C, v15[0]);
        }
      }
      else
      {
        read_memory_byte((uint8_t *)dword_130270);
      }
      read_memory_byte((uint8_t *)dword_130274);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_130260 = 1;
      }
      v10 = dword_130278;
      ++*v0;
      cmd_handler_a(v10, v3);
      result = (uint8_t *)mem_word_load(dword_130268);
      v3 = result;
      if ( *v0 )
      {
        v11 = *v0 - 1;
        v12 = *(uint32_t *)off_130260;
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

