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


extern uint32_t dword_130268;
extern uint32_t dword_130278;
extern uint32_t off_130260;
extern uint32_t off_130264;
extern uint32_t off_13026C;

// parse_large_ioctl @ 0x130170, size 238 bytes
int  parse_large_ioctl(int a1, int a2)
{
  int *v2; // r6
  int v3; // r0
  int result; // r0
  int v5; // r4
  int v6; // r3
  int v7; // r2
  uint8_t **v8; // r7
  int v9; // r5
  int v10; // r0
  int v11; // r3
  int v12; // r2
  uint8_t **v13; // r0
  int v14; // r0
  uint8_t *a1a[18]; // [sp+4h] [bp-48h] BYREF

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_130260 = 1;
  }
  v2 = (int *)off_130264;
  v3 = dword_130268;
  ++*(uint32_t *)off_130264;
  result = (int)mem_word_load(v3);
  v5 = result;
  if ( *v2 )
  {
    v6 = *v2 - 1;
    v7 = *(uint32_t *)off_130260;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v8 = (uint8_t **)off_13026C;
    do
    {
      v9 = parse_token_until_space((uint8_t *)(v5 + 4), (int)a1a);
      if ( v9 )
      {
        v13 = parse_ipv4_dot(a1a[0], v8, 7);
        if ( v13 )
        {
          if ( *((uint16_t *)v13 + 5) < v9 || *((uint16_t *)v13 + 4) > v9 )
          {
            log_printf(aUsageSS, *v13, v13[1]);
          }
          else
          {
            v14 = ((int ( *)(int, uint8_t **))v13[3])(v9, a1a);
            if ( v14 )
              log_printf("Command fail, ret=%d\r\n", v14);
          }
        }
        else
        {
          log_printf("Unknown command '%s'\r\n", (const char *)a1a[0]);
        }
      }
      else
      {
        read_memory_byte(aNoCommand);
      }
      read_memory_byte(aAic);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_130260 = 1;
      }
      v10 = dword_130278;
      ++*v2;
      cmd_handler_a(v10, (uint32_t *)v5);
      result = (int)mem_word_load(dword_130268);
      v5 = result;
      if ( *v2 )
      {
        v11 = *v2 - 1;
        v12 = *(uint32_t *)off_130260;
        *v2 = v11;
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
