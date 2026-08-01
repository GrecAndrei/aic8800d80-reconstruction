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

extern uint32_t off_10F2A4;
extern uint32_t dword_10F2A8;
extern uint32_t dword_10F2AC;

// init_fw_table @ 0x10f208, size 156 bytes
uint64_t init_fw_table()
{
  uint16_t *v0; // r5
  int *v1; // r4
  int *v2; // r5
  int *v3; // r6
  int v4; // r2
  uint64_t result; // r0
  uint32_t *v6; // r3

  v0 = off_10F2A4;
  v1 = (int *)dword_10F2A8;
  *((uint16_t *)off_10F2A4 + 3080) = -16193;
  v0[1536] = -16193;
  *((uint8_t *)v0 + 6162) = 0;
  *((uint32_t *)v0 + 1541) = 0;
  *((uint8_t *)v0 + 6176) = 0;
  *((uint8_t *)v0 + 3074) = 0;
  *((uint32_t *)v0 + 769) = 0;
  zero_struct(v0 + 1540);
  zero_struct(v1 - 3);
  zero_struct(v1 + 512);
  zero_struct(v1 + 514);
  v0[4122] = 0;
  *((uint8_t *)v0 + 3074) = 0;
  *((uint32_t *)v0 + 769) = 0;
  memset_byte(v1, 0, 0x800u);
  v2 = v1 + 512;
  v3 = v1 + 512;
  do
  {
    v1 += 4;
    check_abort_flag(v3);
  }
  while ( v1 != v2 );
  v4 = dword_10F2AC;
  result = (unsigned int)(dword_10F2AC + 1152);
  do
  {
    v6 = (uint32_t *)(v4 - 36);
    do
      *v6++ = 0;
    while ( v6 != (uint32_t *)v4 );
    v4 = (int)(v6 + 9);
  }
  while ( v6 + 9 != (uint32_t *)result );
  return result;
}

