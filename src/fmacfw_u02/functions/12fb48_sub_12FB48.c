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

extern uint32_t dword_12FC30;
extern uint32_t dword_12FC34;
extern uint32_t dword_12FC24;
extern uint32_t dword_12FC28;
extern uint32_t dword_12FC2C;

// parse_config_entry @ 0x12fb48, size 220 bytes
int  parse_config_entry(int a1, int a2)
{
  int v4; // r10
  unsigned int v5; // r4
  int v6; // r6
  int v7; // r5
  int v8; // r9
  int v9; // r8
  int v10; // r7
  unsigned int v11; // r4
  int v13; // r0

  v4 = is_strlen_two(*(uint32_t *)a2);
  if ( v4 >= 0 )
  {
    v5 = parse_hex_or_dec(*(uint8_t **)(a2 + 4), 0, 0x10u);
    v6 = parse_hex_or_dec(*(uint8_t **)(a2 + 8), 0, 0x10u);
    if ( a1 > 3 )
    {
      v13 = parse_hex_or_dec(*(uint8_t **)(a2 + 12), 0, 0);
      if ( !v13 )
        return 0;
      v7 = v13 - 1;
    }
    else
    {
      v7 = 0;
    }
    v8 = dword_12FC30;
    v9 = dword_12FC34;
    v10 = dword_12FC24;
    do
    {
      while ( ((v5 >> 20) & 0xFFFFFDFF) == 0x500 )
      {
        v11 = v5 & 0xFFFFFFFC;
        log_printf(dword_12FC28, v11, v6);
        --v7;
        call_ptr_1b4();
        v5 = v11 + v4;
        if ( v7 == -1 )
          return 0;
      }
      switch ( v4 )
      {
        case 4:
          log_printf(v10, v5, v6);
          *(uint32_t *)v5 = v6;
          break;
        case 2:
          log_printf(v9, v5);
          *(uint16_t *)v5 = v6;
          break;
        case 1:
          log_printf(v8, v5, (uint8_t)v6);
          *(uint8_t *)v5 = v6;
          break;
      }
      --v7;
      v5 += v4;
    }
    while ( v7 != -1 );
    return 0;
  }
  log_printf(dword_12FC2C, v4);
  return -1;
}

