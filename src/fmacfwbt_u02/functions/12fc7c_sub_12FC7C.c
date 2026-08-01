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

extern uint32_t dword_12FD60;
extern uint32_t dword_12FD50;
extern uint32_t dword_12FD54;
extern uint32_t dword_12FD58;
extern uint32_t dword_12FD5C;

// buf_clear16 @ 0x12fc7c, size 212 bytes
int  buf_clear16(int a1, int a2)
{
  unsigned int v4; // r5
  int v5; // r0
  int v7; // r3
  int v8; // r0
  int v9; // [sp+4h] [bp-4h]

  v4 = parse_integer(*(uint8_t **)(a2 + 4), 0, 0x10u);
  if ( a1 <= 2 )
  {
    v5 = has_dot_extension(*(uint32_t *)a2);
    if ( v5 >= 0 )
      goto LABEL_3;
LABEL_18:
    printf_wrapper(dword_12FD60, v5);
    return -1;
  }
  v9 = parse_integer(*(uint8_t **)(a2 + 8), 0, 0);
  v5 = has_dot_extension(*(uint32_t *)a2);
  if ( v5 < 0 )
    goto LABEL_18;
  if ( v9 == 1 )
  {
LABEL_3:
    if ( ((v4 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      v8 = jump_table_1b0();
      printf_wrapper(dword_12FD50, v4 & 0xFFFFFFFC, v8);
      return 0;
    }
    else if ( v5 == 4 )
    {
      printf_wrapper(dword_12FD54, v4, *(uint32_t *)v4);
      return 0;
    }
    else if ( v5 == 2 )
    {
      printf_wrapper(dword_12FD58, v4, *(uint16_t *)v4);
      return 0;
    }
    else
    {
      if ( v5 == 1 )
        printf_wrapper(dword_12FD5C, v4, *(uint8_t *)v4);
      return 0;
    }
  }
  v7 = **(uint8_t **)a2 == 82 && v4 < 0x40000000;
  rx_packet_handler(v4, v9, (uint8_t)v5, v7);
  return 0;
}

