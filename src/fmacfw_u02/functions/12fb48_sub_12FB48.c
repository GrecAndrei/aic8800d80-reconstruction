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

// parse_config_entry @ 0x12fb48, size 220 bytes
int  parse_config_entry(int a1, uint32_t *a2)
{
  int v4; // r10
  unsigned int v5; // r4
  int v6; // r6
  int v7; // r5
  unsigned int v8; // r4
  int v10; // r0

  v4 = is_strlen_two(*a2);
  if ( v4 < 0 )
  {
    log_printf("Unknown data size:%d\r\n", v4);
    return -1;
  }
  else
  {
    v5 = parse_hex_or_dec((uint8_t *)a2[1], nullptr, 0x10u);
    v6 = parse_hex_or_dec((uint8_t *)a2[2], nullptr, 0x10u);
    if ( a1 <= 3 )
    {
      v7 = 0;
      goto LABEL_9;
    }
    v10 = parse_hex_or_dec((uint8_t *)a2[3], nullptr, 0);
    if ( v10 )
    {
      v7 = v10 - 1;
      do
      {
LABEL_9:
        while ( ((v5 >> 20) & 0xFFFFFDFF) == 0x500 )
        {
          v8 = v5 & 0xFFFFFFFC;
          log_printf("[0x%08X] = 0x%08lX\r\n", v8, v6);
          --v7;
          call_ptr_1b4();
          v5 = v8 + v4;
          if ( v7 == -1 )
            return 0;
        }
        switch ( v4 )
        {
          case 4:
            log_printf("[0x%08lX] = 0x%08lX\r\n", v5, v6);
            *(uint32_t *)v5 = v6;
            break;
          case 2:
            log_printf("[0x%08lX] = 0x%04X\r\n", v5, (uint16_t)v6);
            *(uint16_t *)v5 = v6;
            break;
          case 1:
            log_printf("[0x%08lX] = 0x%02X\r\n", v5, (uint8_t)v6);
            *(uint8_t *)v5 = v6;
            break;
        }
        --v7;
        v5 += v4;
      }
      while ( v7 != -1 );
    }
    return 0;
  }
}
