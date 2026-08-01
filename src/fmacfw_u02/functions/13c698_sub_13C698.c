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

extern uint32_t dword_13C708;
extern uint32_t dword_13C70C;

// get_channel_tx_power @ 0x13c698, size 110 bytes
int  get_channel_tx_power(int a1, int a2, int a3)
{
  int v3; // r5
  int v4; // r6
  int v5; // r7
  int result; // r0
  char v7; // r4
  int v8; // r2
  int v9; // r5

  v3 = *(uint8_t *)(a1 + 29);
  v4 = *(uint8_t *)(a1 + 28);
  if ( v3 == 255 )
    return 0;
  v5 = dword_13C708;
  result = *(uint32_t *)(dword_13C708 + 1320 * v4 + 1200);
  if ( result )
  {
    v7 = a2;
    result = sub_13C484(a2, a3);
    if ( result )
    {
      v9 = 696 * v3;
      result = *(uint8_t *)(v9 + dword_13C70C) & 1;
      if ( (*(uint8_t *)(v9 + dword_13C70C) & 1) != 0 )
      {
        if ( (v7 & 0xFC) != 0xD0 || (unsigned int)(v8 - 13) > 1 )
        {
          if ( *(uint32_t *)(v5 + 1320 * v4 + 1204) )
            return 2;
          else
            return 0;
        }
      }
      else
      {
        return (*(uint32_t *)(v9 + dword_13C70C - 34) >> 3) & 1;
      }
    }
  }
  return result;
}

