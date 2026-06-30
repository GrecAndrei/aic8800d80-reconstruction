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

// rf_bus_write_1 @ 0x11146c, size 162 bytes
// Doc: rf_bus_setup_n_30e [rf]: Configure RF bus register with flag bits
// rf_bus_setup_n_30e [rf]: Configure RF bus register with flag bits
int * rf_bus_write_1(int a1, int a2, int a3)
{
  uint32_t *v3; // r6
  int *v4; // r5
  int v5; // r7
  uint32_t *v6; // r4

  if ( a1 )
  {
    v3 = (uint32_t *)(rf_bus_mark_n384 + 32 * (a1 - 1) + 8);
    v4 = (int *)(rf_bus_mark_n384 + 32 * (a1 - 1));
  }
  else
  {
    v3 = (uint32_t *)rf_bus_reset2_n218;
    v4 = (int *)rf_bus_reset2_n21c;
  }
  v5 = *v4;
  if ( (*v4 & 0x80008000) != 0 && ((rf_bus_write2_field & v5) != 0x20000 || a2 != 0x8000000 || a3) )
  {
    v6 = rf_cmd_queue_next_n15a;
    *((uint32_t *)rf_cmd_queue_next_n15a + 513) |= 0x200u;
    while ( (v6[5] & 0x80) == 0 )
      ;
    *v4 |= a2 | 0x8008000;
    if ( a3 )
      *v4 &= ~a3;
    if ( !a1 )
      goto rf_bus_write2_n_66;
    if ( v5 < 0 )
    {
      *v3 = 2;
      *v4 |= 0x40000000u;
      while ( (*v3 & 2) == 0 )
        ;
      if ( (v5 & 0x8000) != 0 )
        goto rf_bus_write2_n_66;
    }
    else if ( (v5 & 0x8000) != 0 )
    {
rf_bus_write2_n_66:
      *((uint32_t *)rf_cmd_queue_next_n15a + 513) |= 0x400u;
      return rf_bus_mark_ne8(a1);
    }
    *v4 &= ~0x8000u;
    goto rf_bus_write2_n_66;
  }
  return rf_bus_mark_ne8(a1);
}

