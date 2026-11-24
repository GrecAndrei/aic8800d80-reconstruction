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

// parse_hex_value @ 0x121f44, size 212 bytes
int  parse_hex_value(int a1, uint32_t *a2)
{
  unsigned int v4; // r5
  int v5; // r0
  int v7; // r3
  int v8; // r0
  int a2a; // [sp+4h] [bp-4h]

  v4 = parse_number((uint8_t *)a2[1], nullptr, 0x10u);
  if ( a1 <= 2 )
  {
    v5 = str_has_extension(*a2);
    if ( v5 >= 0 )
      goto LABEL_3;
LABEL_18:
    log_printf("Unknown data size:%d\r\n", v5);
    return -1;
  }
  a2a = parse_number((uint8_t *)a2[2], nullptr, 0);
  v5 = str_has_extension(*a2);
  if ( v5 < 0 )
    goto LABEL_18;
  if ( a2a == 1 )
  {
LABEL_3:
    if ( ((v4 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      v8 = call_indirect_table();
      log_printf("[0x%08X] = 0x%08X\r\n", v4 & 0xFFFFFFFC, v8);
      return 0;
    }
    else if ( v5 == 4 )
    {
      log_printf("[0x%08lX] = 0x%08lX\r\n", v4, *(uint32_t *)v4);
      return 0;
    }
    else if ( v5 == 2 )
    {
      log_printf("[0x%08lX] = 0x%04X\r\n", v4, *(uint16_t *)v4);
      return 0;
    }
    else
    {
      if ( v5 == 1 )
        log_printf("[0x%08lX] = 0x%02X\r\n", v4, *(uint8_t *)v4);
      return 0;
    }
  }
  v7 = *(uint8_t *)*a2 == 82 && v4 < 0x40000000;
  handle_ipc_request(v4, a2a, (uint8_t)v5, v7);
  return 0;
}
