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

// ke_cmd_handler @ 0x111d58, size 316 bytes
// Doc: rf_state_check_n_260 [rf]: Updates RF state with bitmask and stores halfword
// rf_state_check_n_260 [rf]: Updates RF state with bitmask and stores halfword
int * ke_cmd_handler(int *result, unsigned int a2, int a3, unsigned int a4)
{
  unsigned int v4; // r6
  unsigned int v7; // r11
  int v8; // r7
  int v9; // r10
  int v10; // r9
  int v11; // r2
  uint16_t *v12; // r4
  int v13; // r1
  uint32_t *v14; // r2
  int v15; // r5
  int v16; // r6
  uint32_t *v17; // r2
  unsigned int v18; // r3
  int v19; // cf

  v4 = a2 - 1;
  if ( (uint8_t)(a2 - 1) <= 4u )
  {
    v7 = a4;
    if ( result )
    {
      if ( (a3 & 0xFD) == 1 )
      {
        if ( a4 > 0x320 )
        {
          v9 = 400;
          LOWORD(v8) = 400;
          v10 = 26214400;
        }
        else
        {
          v8 = (uint16_t)(2 * ((int)(a4 + 3) >> 2));
          v9 = v8;
          v10 = (uint16_t)v8 << 16;
        }
        if ( a4 > 0x400 )
        {
          v18 = -1025;
          v19 = v7 - 1025 >= 0x400;
          if ( v7 - 1025 < 0x400 )
            v7 >>= 1;
          else
            v18 = ((unsigned int)rf_bus_write2_n424 * (unsigned uint64_t)v7) >> 32;
          if ( v19 )
            LOWORD(v7) = v18 >> 1;
        }
      }
      else
      {
        v8 = (uint16_t)(2 * ((int)(a4 + 3) >> 2));
        v9 = v8;
        v10 = (uint16_t)v8 << 16;
      }
      if ( (*((uint32_t *)&REG_4020_0900 + 8 * a2) & 0x80008000) != 0 )
        result = rf_reg_write(result, a2);
      v11 = (a3 << 18) & 0xC0000;
      v12 = rf_state_check_n_19c;
      v13 = *(uint16_t *)rf_state_check_n_19c;
      *((uint32_t *)&REG_4020_0900 + 8 * a2) = v7 & 0x7FF | v11 | (a2 << 22) | 0x18008000;
      if ( v13 + v9 > 2048 )
      {
        result = (int *)printf_wrapper(rf_bus_write2_ea0, v13, v9, 2048);
        v13 = (uint16_t)*v12;
      }
      v14 = log_buffer_alloc;
      *((uint32_t *)log_buffer_alloc + v4 + 65) = v13 | v10;
      v15 = (1 << a2) | v14[519];
      *v12 = v8 + v13;
      v14[519] = v15;
    }
    else
    {
      v16 = 32 * a2 + 1075838976;
      if ( (*((uint32_t *)&REG_4020_0b00 + 8 * a2) & 0x80008000) != 0 )
        result = rf_reg_write(0, a2);
      v17 = log_buffer_alloc;
      *(uint32_t *)(v16 + 2816) = v7 & 0x7FF | (a3 << 18) & 0xC0000 | 0x18008000;
      v17[519] |= 0x10000 << a2;
    }
  }
  return result;
}

