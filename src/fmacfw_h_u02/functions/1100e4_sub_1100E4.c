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

extern uint32_t off_110138;
extern uint32_t dword_11012C;
extern uint32_t off_110130;
extern uint32_t dword_110134;

// get_core_temp @ 0x1100e4, size 72 bytes
int get_core_temp()
{
  void *v0; // r8
  int result; // r0
  uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  unsigned int v6; // r1

  v0 = off_110138;
  result = clear_stats_buf(dword_11012C);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 8) )
  {
    v2 = off_110130;
    v3 = dword_110134;
    v4 = dword_11012C;
    v5 = 0;
    do
    {
      tx_irq_handler(v3, 0x6B8u);
      result = wlan_ioctl_handler_1(v4);
      v6 = *(uint16_t *)(*(uint32_t *)v0 + 8);
      ++v5;
      ++*v2;
    }
    while ( v6 > (uint16_t)v5 );
  }
  return result;
}

