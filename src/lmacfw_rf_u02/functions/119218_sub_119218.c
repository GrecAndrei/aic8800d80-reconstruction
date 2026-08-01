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

extern uint32_t off_119300;
extern uint32_t dword_119304;

// timer_start_capture @ 0x119218, size 232 bytes
// Doc: sub_1219218 [mmio]: Read RF status words from MMIO 0x40501000 region
// sub_1219218 [mmio]: Read RF status words from MMIO 0x40501000 region
BOOL  timer_start_capture(int a1, int a2, int a3, int *a4)
{
  int v5; // r10
  uint32_t *v6; // r4
  int v7; // r8
  int v8; // r1
  int v9; // r6
  int v10; // r0
  int v11; // r7
  int v13; // r0
  int *v14; // r6
  uint8_t *v15; // r1
  int v16; // r7
  unsigned int v17; // r5
  int v18; // r11
  uint8_t *v19; // r4
  int v21; // [sp+Ch] [bp-10h]
  int v23; // [sp+14h] [bp-8h]
  int v24; // [sp+14h] [bp-8h]

  v5 = *(uint16_t *)(a1 + 28);
  v6 = off_119300;
  v7 = *(uint32_t *)(*(uint32_t *)(a1 + 8) + 8);
  v8 = dword_119304;
  v9 = a1;
  v11 = *(uint32_t *)(a2 + 112);
  v10 = *(uint32_t *)(a2 + 108);
  *(uint8_t *)(a2 + 116) = 0;
  v21 = v11;
  if ( v8 - v6[4] + v10 < 0 && !rate_index_lookup_fast(*(uint8_t *)(a2 + 102), 0, 0) )
    *(uint32_t *)(a2 + 108) = v6[4];
  v23 = *(char *)(v9 + 45);
  chip_info_nibble0_get();
  rf_temp_compensate((uint8_t *)a2, v23);
  v13 = crc32_update_msb(v7 + 32, 4, 0);
  *a4 = 0;
  if ( (uint16_t)(v5 - 36) > 1u )
  {
    v24 = v9;
    v14 = a4;
    v15 = (uint8_t *)(v7 + 36);
    v16 = a2;
    v17 = (uint16_t)(v5 - 36);
    do
    {
      v18 = (uint8_t)v15[1];
      v19 = v15 + 2;
      if ( v18 + 1 >= (int)v17 )
        break;
      if ( *v15 == 5 )
        *v14 = (int)v15;
      else
        v13 = crc32_update_msb(v19, (uint8_t)v15[1], v13);
      v17 = (uint16_t)(v17 + -2 - v18);
      v15 = &v19[v18];
    }
    while ( v17 > 1 );
    a2 = v16;
    a4 = v14;
    v9 = v24;
  }
  *(uint32_t *)(a2 + 112) = v13;
  send_acl_packet(v7, v5, v9, (uint32_t *)a2, a3, *a4);
  return *(uint32_t *)(a2 + 112) != v21;
}

