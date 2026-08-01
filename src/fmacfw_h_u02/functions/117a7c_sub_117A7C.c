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

extern uint32_t off_117B7C;
extern uint32_t dword_117B80;
extern uint32_t dword_117B74;
extern uint32_t dword_117B78;

// alloc_shared_ctx @ 0x117a7c, size 246 bytes
uint64_t alloc_shared_ctx()
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
  int v9; // r0
  int v10; // r0
  int v11; // r0
  int16_t v12; // r7
  char *v13; // r0
  int i; // r6
  int v15; // r2
  uint64_t result; // r0
  uint32_t *v17; // r3
  uint8_t v18[44]; // [sp+0h] [bp-2Ch] BYREF

  v0 = off_117B7C;
  v1 = dword_117B80;
  irq_disable_global_3(126976);
  v2 = v0 + 12;
  v3 = v18;
  v0[510] = 1;
  v4 = v0 + 12;
  v5 = v18;
  v6 = 0;
  do
  {
    v7 = (uint8_t)v6;
    clear_stats_buf(v5);
    phy_dispatch((uint8_t)v6++, v1, v5);
    phy_dispatch(v7, v4, v5);
    v1 += 8;
    v5 += 8;
    v4 += 84;
  }
  while ( v6 != 5 );
  v8 = dword_117B74;
  v9 = mmio_write(5);
  v10 = init_mac_global_0x1882c8(v9);
  v11 = init_mac_global_0x188290(v10);
  rx_queue_process(v11);
  v12 = *((uint16_t *)v0 + 254);
  sub_100200((int *)(v8 - 432), 0, 0x204u);
  *((uint16_t *)v0 + 254) = v12;
  do
  {
    clear_stats_buf(v2);
    *((uint32_t *)v2 - 3) = 0;
    v2[14] = 0;
    v2[68] = 0;
    *((uint32_t *)v2 + 6) = 0;
    *((uint32_t *)v2 + 7) = 0;
    v13 = v2 + 16;
    v2 += 84;
    clear_stats_buf(v13);
  }
  while ( v2 != (char *)v8 );
  for ( i = 0; i != 5; ++i )
  {
    if ( list_pop(v3) )
    {
      do
        phy_enable();
      while ( list_pop(v3) );
      invalid_handler((uint8_t)i);
    }
    v3 += 8;
  }
  v15 = dword_117B78;
  result = (unsigned int)(dword_117B78 + 1152);
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

