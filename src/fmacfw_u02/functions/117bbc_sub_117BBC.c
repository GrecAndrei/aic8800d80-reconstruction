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


extern uint32_t dword_117CB4;
extern uint32_t dword_117CB8;
extern uint32_t dword_117CC0;
extern uint32_t off_117CBC;

// mem_pool_init @ 0x117bbc, size 246 bytes
uint64_t mem_pool_init()
{
  uint8_t *v0; // r8
  int v1; // r10
  char *v2; // r5
  uint8_t *v3; // r4
  int v4; // r9
  uint32_t *v5; // r7
  int v6; // r6
  unsigned int v7; // r11
  int v8; // r9
  uint32_t *v9; // r0
  uint16_t v10; // r7
  uint32_t *v11; // r0
  int i; // r6
  uint32_t *v13; // r0
  int v14; // r2
  uint64_t result; // r0
  uint32_t *v16; // r3
  uint8_t v17[44]; // [sp+0h] [bp-2Ch] BYREF

  v0 = off_117CBC;
  v1 = dword_117CC0;
  unknown_func_12d14c(126976);
  v2 = v0 + 12;
  v3 = v17;
  v0[510] = 1;
  v4 = (int)(v0 + 12);
  v5 = v17;
  v6 = 0;
  do
  {
    v7 = (uint8_t)v6;
    zero_8_bytes(v5);
    rf_tx_setup((uint8_t)v6++, v1, (int)v5);
    rf_tx_setup(v7, v4, (int)v5);
    v1 += 8;
    v5 += 2;
    v4 += 84;
  }
  while ( v6 != 5 );
  v8 = dword_117CB4;
  rf_pll_lock(5, dword_117CB4);
  process_event_loop();
  v9 = init_buf_188290();
  handle_radio_done((int)v9);
  v10 = *((uint16_t *)v0 + 254);
  memset((int *)(v8 - 432), 0, 0x204u);
  *((uint16_t *)v0 + 254) = v10;
  do
  {
    zero_8_bytes(v2);
    *((uint32_t *)v2 - 3) = 0;
    v2[14] = 0;
    v2[68] = 0;
    *((uint32_t *)v2 + 6) = 0;
    *((uint32_t *)v2 + 7) = 0;
    v11 = v2 + 16;
    v2 += 84;
    zero_8_bytes(v11);
  }
  while ( v2 != (char *)v8 );
  for ( i = 0; i != 5; ++i )
  {
    v13 = mem_word_load((int)v3);
    if ( v13 )
    {
      do
      {
        ll_conn_reset_flags((int)v13, (uint8_t)i);
        v13 = mem_word_load((int)v3);
      }
      while ( v13 );
      test_flag((uint8_t)i);
    }
    v3 += 8;
  }
  v14 = dword_117CB8;
  result = (unsigned int)(dword_117CB8 + 1152);
  do
  {
    v16 = (uint32_t *)(v14 - 36);
    do
      *v16++ = 0;
    while ( (uint32_t *)v14 != v16 );
    v14 += 36;
  }
  while ( (uint32_t)result != v14 );
  return result;
}
