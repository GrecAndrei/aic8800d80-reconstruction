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


extern uint32_t dword_119D7C;
extern uint32_t off_119D80;
extern uint32_t off_119D84;

// init_mac_global_0x1882c8 @ 0x119d34, size 72 bytes
uint32_t *init_mac_global_0x1882c8()
{
  uint32_t *v0; // r4
  int *v1; // r7
  int *v2; // r6
  int v3; // r9
  uint32_t *result; // r0
  int v5; // t1
  int v6; // r5
  int v7; // r8

  v0 = (uint32_t *)dword_119D7C;
  v1 = off_119D80[0];
  v2 = off_119D84;
  v3 = dword_119D7C + 48;
  do
  {
    result = clear_stats_buf(v0);
    v5 = *v1++;
    if ( v5 > 0 )
    {
      v6 = 0;
      v7 = 0;
      do
      {
        result = (uint32_t *)wlan_ioctl_handler_1((int)v0, (uint32_t *)(*v2 + v6));
        ++v7;
        v6 += 360;
      }
      while ( v7 < *(v1 - 1) );
    }
    v0 += 2;
    ++v2;
  }
  while ( v0 != (uint32_t *)v3 );
  return result;
}
