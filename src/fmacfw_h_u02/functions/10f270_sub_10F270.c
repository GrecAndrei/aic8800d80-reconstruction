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

extern uint32_t off_10F30C;
extern uint32_t dword_10F310;
extern uint32_t dword_10F314;

// rf_config_bb @ 0x10f270, size 156 bytes
uint64_t rf_config_bb()
{
  uint16_t *v0; // r5
  int *v1; // r4
  int *v2; // r5
  int *v3; // r6
  int v4; // r2
  uint64_t result; // r0
  uint32_t *v6; // r3

  v0 = off_10F30C;
  v1 = (int *)dword_10F310;
  *((uint16_t *)off_10F30C + 3080) = -16193;
  v0[1536] = -16193;
  *((uint8_t *)v0 + 6162) = 0;
  *((uint32_t *)v0 + 1541) = 0;
  *((uint8_t *)v0 + 6176) = 0;
  *((uint8_t *)v0 + 3074) = 0;
  *((uint32_t *)v0 + 769) = 0;
  clear_stats_buf(v0 + 1540);
  clear_stats_buf(v1 - 3);
  clear_stats_buf(v1 + 512);
  clear_stats_buf(v1 + 514);
  v0[4122] = 0;
  *((uint8_t *)v0 + 3074) = 0;
  *((uint32_t *)v0 + 769) = 0;
  sub_100200(v1, 0, 0x800u);
  v2 = v1 + 512;
  v3 = v1 + 512;
  do
  {
    v1 += 4;
    wlan_ioctl_handler_1(v3);
  }
  while ( v1 != v2 );
  v4 = dword_10F314;
  result = (unsigned int)(dword_10F314 + 1152);
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

