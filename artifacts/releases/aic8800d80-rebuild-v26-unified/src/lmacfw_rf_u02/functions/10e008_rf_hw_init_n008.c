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

extern uint32_t off_10E098;
extern uint32_t off_10E09C;
extern uint32_t dword_10E0A0;
extern uint32_t dword_10E0A4;
extern uint32_t dword_10E0A8;
extern uint32_t dword_10E0AC;

// rf_hw_init_n008 @ 0x10e008, size 142 bytes
// Doc: rf_hw_init_n008 [rf]: Initialize RF MMIO registers and hardware state
// rf_hw_init_n008 [rf]: Initialize RF MMIO registers and hardware state
float rf_hw_init_n008()
{
  uint32_t *v0; // r4
  uint32_t *v1; // r2
  int v2; // r3
  int v3; // r0
  int v4; // r1
  unsigned int v5; // r4

  v0 = off_10E098;
  v1 = off_10E09C;
  v2 = dword_10E0A0;
  v3 = dword_10E0A4;
  v4 = dword_10E0A8;
  *(uint32_t *)off_10E098 = 0;
  v1[14] = 296;
  v0[2] = v0[2] & 0xF000FFFF | 0x2000000;
  v0[3] = v2 & v0[3] | 0xA06A000;
  v0[3] = v4 | v3 & v0[3];
  rf_subsystem_init();
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v5 = v0[4];
  rf_reg_write_cb(dword_10E0AC, 0, 15360);
  return (float)((float)((float)((float)v5 / flt_10E0B0) - 1.0) * flt_10E0B4)
       + (float)((float)((float)((float)v5 / flt_10E0B0) - 1.0) * flt_10E0B4);
}

