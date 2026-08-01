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

extern uint32_t off_118A60;
extern uint32_t dword_118A64;
extern uint32_t dword_118A68;

// rf_pll_lock @ 0x1189f8, size 102 bytes
int  rf_pll_lock(int a1, int a2)
{
  int16_t **v2; // r5
  int v3; // r7
  int v4; // r6
  int v6; // r0
  int v7; // r1
  int v8; // r3
  int v9; // r2
  int v10; // r0

  v2 = (int16_t **)off_118A60;
  v3 = dword_118A64;
  v4 = dword_118A68;
LABEL_2:
  v6 = mem_word_load(a2);
  v7 = 2080374784;
  v8 = v6;
  if ( v6 )
  {
    while ( 1 )
    {
      v9 = *(uint32_t *)(v8 + 76);
      if ( *(uint32_t *)(v8 + 68) )
        goto LABEL_4;
      if ( *(int *)(v9 + 4) >= 0 )
        break;
LABEL_5:
      if ( !*(uint16_t *)(v8 + 4) )
      {
        free_buf_1882c0(v8);
        goto LABEL_2;
      }
      if ( **v2 >= 0 )
        goto LABEL_2;
      mmio_clear_register(v4, v3, 1147);
      v10 = mem_word_load(a2);
      v7 = 2080374784;
      v8 = v10;
      if ( !v10 )
        return tx_pool_init();
    }
    v7 = 0x40000000;
LABEL_4:
    *(uint32_t *)(v9 + 4) = v7;
    goto LABEL_5;
  }
  return tx_pool_init();
}

