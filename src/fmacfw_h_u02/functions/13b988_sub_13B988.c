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

extern uint32_t dword_13BAD8;
extern uint32_t off_13BADC;
extern uint32_t off_13BAE0;
extern uint32_t dword_13BAE4;

// dispatch_command @ 0x13b988, size 334 bytes
int  dispatch_command(int a1, uint16_t *a2, int a3)
{
  int v4; // r4
  unsigned int v6; // r3
  unsigned int v7; // r8
  unsigned int v8; // r5
  int v9; // r6
  char v10; // r7
  int v11; // r0
  unsigned int v12; // r3
  unsigned int v13; // r2

  if ( a3 != 1 )
  {
    if ( a3 == 2 )
    {
      v12 = a2[1];
      v13 = v12 >> 12;
      if ( v12 < 0x9000 && a1 != 255 )
      {
        if ( (v12 & 0x800) != 0 )
          return *(uint8_t *)(696 * (uint8_t)a1 + 12 * v13 + dword_13BAD8 + 452);
        else
          return *(uint8_t *)(696 * (uint8_t)a1 + 12 * v13 + dword_13BAD8 + 453);
      }
    }
    else if ( !a3 )
    {
      v7 = *(uint16_t *)((char *)a2 + 3);
      v8 = (v7 >> 2) & 0xF;
      if ( v8 <= 8 )
      {
        v9 = (uint8_t)a1;
        v10 = *((uint8_t *)a2 + 2);
        if ( ll_get_tx_power_alt((uint8_t)a1, (v7 >> 2) & 0xF) )
          return *(uint8_t *)(696 * v9 + 12 * v8 + dword_13BAD8 + 452);
        if ( *((uint32_t *)off_13BADC + 4) - 500000 - *(uint32_t *)(696 * v9 + 12 * v8 + dword_13BAD8 + 448) >= 0 )
        {
          if ( *(uint8_t *)(dword_13BAD8 + 696 * a1 + 36) == 1 )
            goto LABEL_22;
          if ( *(uint32_t *)off_13BAE0 )
          {
            v4 = *((uint8_t *)list_pop((int)off_13BAE0) + 26);
            if ( v4 != 33 )
              return v4;
          }
          v11 = load_global_pointer((int **)dword_13BAE4);
          if ( v11 == 33 )
          {
LABEL_22:
            init_state_table(v9, 0, 1, v10, v7, 37, 0);
            return 33;
          }
          else
          {
            v4 = v11;
            mac_write_header_word(8193, ((uint16_t)v11 << 8) | 8, 255);
          }
          return v4;
        }
      }
    }
    return 33;
  }
  v6 = (*(uint16_t *)((char *)a2 + 5) >> 2) & 0xF;
  if ( v6 > 8 )
    return 33;
  return *(uint8_t *)(696 * (uint8_t)a1 + 12 * v6 + dword_13BAD8 + 453);
}

