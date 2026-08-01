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

extern uint32_t dword_12FA04;
extern uint32_t dword_12F9F4;
extern uint32_t dword_12F9F8;
extern uint32_t dword_12F9FC;
extern uint32_t dword_12FA00;

// parse_hex_string @ 0x12f920, size 212 bytes
int  parse_hex_string(int a1, int a2)
{
  unsigned int v4; // r5
  int v5; // r0
  int v7; // r3
  int v8; // r0
  int v9; // [sp+4h] [bp-4h]

  v4 = parse_uint_base(*(uint8_t **)(a2 + 4), 0, 0x10u);
  if ( a1 <= 2 )
  {
    v5 = is_two_char_string(*(uint32_t *)a2);
    if ( v5 >= 0 )
      goto LABEL_3;
LABEL_18:
    debug_printf(dword_12FA04, v5);
    return -1;
  }
  v9 = parse_uint_base(*(uint8_t **)(a2 + 8), 0, 0);
  v5 = is_two_char_string(*(uint32_t *)a2);
  if ( v5 < 0 )
    goto LABEL_18;
  if ( v9 == 1 )
  {
LABEL_3:
    if ( ((v4 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      v8 = call_patch_hook_0();
      debug_printf(dword_12F9F4, v4 & 0xFFFFFFFC, v8);
      return 0;
    }
    else if ( v5 == 4 )
    {
      debug_printf(dword_12F9F8, v4, *(uint32_t *)v4);
      return 0;
    }
    else if ( v5 == 2 )
    {
      debug_printf(dword_12F9FC, v4, *(uint16_t *)v4);
      return 0;
    }
    else
    {
      if ( v5 == 1 )
        debug_printf(dword_12FA00, v4, *(uint8_t *)v4);
      return 0;
    }
  }
  v7 = **(uint8_t **)a2 == 82 && v4 < 0x40000000;
  process_packet_params(v4, v9, (uint8_t)v5, v7);
  return 0;
}

