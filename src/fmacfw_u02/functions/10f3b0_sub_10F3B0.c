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


extern uint32_t dword_10F450;
extern uint32_t dword_10F454;
extern uint32_t off_10F44C;

// rf_timer_init @ 0x10f3b0, size 156 bytes
uint64_t rf_timer_init()
{
  uint16_t *v0; // r5
  int *v1; // r4
  int *v2; // r5
  int v3; // r6
  int *v4; // r1
  int v5; // r2
  uint64_t result; // r0
  uint32_t *v7; // r3

  v0 = off_10F44C;
  v1 = (int *)dword_10F450;
  *((uint16_t *)off_10F44C + 3080) = -16193;
  v0[1536] = -16193;
  *((uint8_t *)v0 + 6162) = 0;
  *((uint32_t *)v0 + 1541) = 0;
  *((uint8_t *)v0 + 6176) = 0;
  *((uint8_t *)v0 + 3074) = 0;
  *((uint32_t *)v0 + 769) = 0;
  zero_8_bytes((uint32_t *)v0 + 770);
  zero_8_bytes(v1 - 3);
  zero_8_bytes(v1 + 512);
  zero_8_bytes(v1 + 514);
  v0[4122] = 0;
  *((uint8_t *)v0 + 3074) = 0;
  *((uint32_t *)v0 + 769) = 0;
  memset(v1, 0, 0x800u);
  v2 = v1 + 512;
  v3 = (int)(v1 + 512);
  do
  {
    v4 = v1;
    v1 += 4;
    cmd_handler_a(v3, v4);
  }
  while ( v1 != v2 );
  v5 = dword_10F454;
  result = (unsigned int)(dword_10F454 + 1152);
  do
  {
    v7 = (uint32_t *)(v5 - 36);
    do
      *v7++ = 0;
    while ( v7 != (uint32_t *)v5 );
    v5 = (int)(v7 + 9);
  }
  while ( v7 + 9 != (uint32_t *)result );
  return result;
}
