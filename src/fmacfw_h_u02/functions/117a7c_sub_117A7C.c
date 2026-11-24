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


extern uint32_t dword_117B74;
extern uint32_t dword_117B78;
extern uint32_t dword_117B80;
extern uint32_t off_117B7C;

// alloc_shared_ctx @ 0x117a7c, size 246 bytes
uint64_t alloc_shared_ctx()
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

  v0 = off_117B7C;
  v1 = dword_117B80;
  irq_disable_global_3(126976);
  v2 = v0 + 12;
  v3 = v17;
  v0[510] = 1;
  v4 = (int)(v0 + 12);
  v5 = v17;
  v6 = 0;
  do
  {
    v7 = (uint8_t)v6;
    clear_stats_buf(v5);
    phy_dispatch((uint8_t)v6++, v1, (int)v5);
    phy_dispatch(v7, v4, (int)v5);
    v1 += 8;
    v5 += 2;
    v4 += 84;
  }
  while ( v6 != 5 );
  v8 = dword_117B74;
  mmio_write(5, dword_117B74);
  init_mac_global_0x1882c8();
  v9 = init_mac_global_0x188290();
  rx_queue_process((int)v9);
  v10 = *((uint16_t *)v0 + 254);
  memset_thunk((int *)(v8 - 432), 0, 0x204u);
  *((uint16_t *)v0 + 254) = v10;
  do
  {
    clear_stats_buf(v2);
    *((uint32_t *)v2 - 3) = 0;
    v2[14] = 0;
    v2[68] = 0;
    *((uint32_t *)v2 + 6) = 0;
    *((uint32_t *)v2 + 7) = 0;
    v11 = v2 + 16;
    v2 += 84;
    clear_stats_buf(v11);
  }
  while ( v2 != (char *)v8 );
  for ( i = 0; i != 5; ++i )
  {
    v13 = list_pop((int)v3);
    if ( v13 )
    {
      do
      {
        phy_enable((int)v13, (uint8_t)i);
        v13 = list_pop((int)v3);
      }
      while ( v13 );
      invalid_handler((uint8_t)i);
    }
    v3 += 8;
  }
  v14 = dword_117B78;
  result = (unsigned int)(dword_117B78 + 1152);
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
