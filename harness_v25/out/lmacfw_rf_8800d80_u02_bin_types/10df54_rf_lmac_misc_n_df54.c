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

extern uint32_t off_10DFE8;
extern uint32_t off_10DFEC;
extern uint32_t dword_10DFF0;
extern uint32_t dword_10DFF4;
extern uint32_t dword_10DFF8;
extern uint32_t dword_10DFFC;

// rf_lmac_misc_n_df54 @ 0x10df54, size 146 bytes
// Doc: rf_lmac_misc_n_df54 [rf]: LMAC RF misc handler
// rf_lmac_misc_n_df54 [rf]: LMAC RF misc handler
float rf_lmac_misc_n_df54()
{
  uint32_t *v0; // r4
  uint32_t *v1; // r2
  int v2; // r3
  int v3; // r0
  int v4; // r1
  unsigned int v5; // r4

  v0 = off_10DFE8;
  v1 = off_10DFEC;
  v2 = dword_10DFF0;
  v3 = dword_10DFF4;
  v4 = dword_10DFF8;
  *(uint32_t *)off_10DFE8 = 0;
  v1[14] = 296;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  v0[3] = v2 & v0[3] | 0xA06A000;
  v0[3] = v4 | v3 & v0[3];
  mmio_config_init();
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v5 = v0[4];
  rf_reg_write_cb(dword_10DFFC, 0, 15360);
  return (float)((float)((float)((float)v5 / flt_10E000) - 1.0) * flt_10E004) * 5.5;
}

