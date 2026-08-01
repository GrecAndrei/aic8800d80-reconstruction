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

// mmio_set_bit @ 0x1119fc, size 242 bytes
// Doc: rf_bus_reg_set_bits_n_20e [rf]: Set OR-mask bits in RF bus control register
// rf_bus_reg_set_bits_n_20e [rf]: Set OR-mask bits in RF bus control register
int mmio_set_bit()
{
  uint32_t *v0; // r2
  uint32_t *v1; // r2
  uint32_t *v2; // r1
  uint32_t *v3; // r2
  uint32_t *v4; // r1
  int v5; // r3
  uint32_t *v6; // r2
  int v7; // r0

  v0 = rf_bus_write_n_74;
  *((uint32_t *)rf_bus_write_n_74 + 4) |= 1u;
  while ( (v0[4] & 1) != 0 )
    ;
  v1 = rf_bus_write_n_74;
  while ( *((int *)rf_bus_write_n_74 + 4) >= 0 )
    ;
  v2 = rf_bus_write_n_74;
  *((uint32_t *)rf_bus_write_n_74 + 3) |= 0x40000007u;
  v1[3] = v1[3] & 0xFFFFC0FF | 0x2700;
  v1[4] |= 1u;
  while ( (v2[4] & 1) != 0 )
    ;
  v3 = rf_bus_write_n_74;
  while ( *((int *)rf_bus_write_n_74 + 4) >= 0 )
    ;
  v4 = rf_bus_write_n_74;
  *((uint32_t *)rf_bus_write_n_74 + 3) |= 0x40000007u;
  v3[3] = v3[3] & 0xFFFFC0FF | 0x2700;
  v3[512] &= 0xFFFFE7FC;
  v3[512] |= 0x800004u;
  v3[6] = 0;
  v5 = 1;
  v3[5] = -1;
  v3[519] = 0;
  v3[517] = 0;
  v3[516] = 0;
  while ( 1 )
  {
    v6 = &v4[8 * v5 - 16];
    if ( v5 != 1 )
      break;
    v4[706] = -1;
    v4[578] = -1;
LABEL_11:
    ++v5;
  }
  v6[714] = -1;
  v6[586] = -1;
  if ( v5 != 6 )
    goto LABEL_11;
  v4[6] = rf_bus_reset2_nf8;
  v7 = rf_bus_write_n_6c;
  v4[513] &= ~2u;
  v4[513] |= 0x8000u;
  v4[2] = 46;
  v4[2] |= 1u;
  return event_dispatch(v7, v4, 46);
}

