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

extern uint32_t off_117CBC;
extern uint32_t dword_117CC0;
extern uint32_t dword_117CB4;
extern uint32_t dword_117CB8;

// mem_pool_init @ 0x117bbc, size 246 bytes
// Doc: mem_pool_init [util]: Initialize UMAC subsystem with 0x1f000 base
// mem_pool_init [util]: Initialize UMAC subsystem with 0x1f000 base
uint64_t mem_pool_init()
{
  uint8_t *v0; // r8
  int v1; // r10
  char *v2; // r5
  uint8_t *v3; // r4
  char *v4; // r9
  uint8_t *v5; // r7
  int v6; // r6
  int v7; // r11
  int v8; // r9
  int inited; // r0
  int v10; // r0
  int v11; // r0
  int16_t v12; // r7
  char *v13; // r0
  int i; // r6
  int v15; // r2
  uint64_t result; // r0
  uint32_t *v17; // r3
  uint8_t v18[44]; // [sp+0h] [bp-2Ch] BYREF

  v0 = off_117CBC;
  v1 = dword_117CC0;
  unknown_func_12d14c(126976);
  v2 = v0 + 12;
  v3 = v18;
  v0[510] = 1;
  v4 = v0 + 12;
  v5 = v18;
  v6 = 0;
  do
  {
    v7 = (uint8_t)v6;
    zero_8_bytes(v5);
    rf_tx_setup((uint8_t)v6++, v1, v5);
    rf_tx_setup(v7, v4, v5);
    v1 += 8;
    v5 += 8;
    v4 += 84;
  }
  while ( v6 != 5 );
  v8 = dword_117CB4;
  inited = rf_pll_lock(5);
  v10 = process_event_loop(inited);
  v11 = init_buf_188290(v10);
  handle_radio_done(v11);
  v12 = *((uint16_t *)v0 + 254);
  memset((int *)(v8 - 432), 0, 0x204u);
  *((uint16_t *)v0 + 254) = v12;
  do
  {
    zero_8_bytes(v2);
    *((uint32_t *)v2 - 3) = 0;
    v2[14] = 0;
    v2[68] = 0;
    *((uint32_t *)v2 + 6) = 0;
    *((uint32_t *)v2 + 7) = 0;
    v13 = v2 + 16;
    v2 += 84;
    zero_8_bytes(v13);
  }
  while ( v2 != (char *)v8 );
  for ( i = 0; i != 5; ++i )
  {
    if ( mem_word_load(v3) )
    {
      do
        ll_conn_reset_flags();
      while ( mem_word_load(v3) );
      test_flag((uint8_t)i);
    }
    v3 += 8;
  }
  v15 = dword_117CB8;
  result = (unsigned int)(dword_117CB8 + 1152);
  do
  {
    v17 = (uint32_t *)(v15 - 36);
    do
      *v17++ = 0;
    while ( (uint32_t *)v15 != v17 );
    v15 += 36;
  }
  while ( (uint32_t)result != v15 );
  return result;
}

