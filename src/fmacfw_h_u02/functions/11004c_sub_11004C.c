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


extern uint32_t dword_110094;
extern uint32_t dword_11009C;
extern uint32_t off_110098;
extern uint32_t off_1100A0;

// get_noise_floor @ 0x11004c, size 72 bytes
uint32_t *get_noise_floor()
{
  void *v0; // r8
  uint32_t *result; // r0
  uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  uint32_t *v6; // r0
  unsigned int v7; // r1

  v0 = off_1100A0;
  result = clear_stats_buf((uint32_t *)dword_110094);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 6) )
  {
    v2 = off_110098;
    v3 = dword_11009C;
    v4 = dword_110094;
    v5 = 0;
    do
    {
      v6 = tx_irq_handler(v3, 0x63Cu);
      result = (uint32_t *)wlan_ioctl_handler_1(v4, v6);
      v7 = *(uint16_t *)(*(uint32_t *)v0 + 6);
      ++v5;
      ++*v2;
    }
    while ( v7 > (uint16_t)v5 );
  }
  return result;
}
