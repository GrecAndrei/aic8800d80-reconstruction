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


extern uint32_t dword_125034;

// rf_tx_flag_check @ 0x124fa0, size 134 bytes
int  rf_tx_flag_check(uint8_t *a1, int a2)
{
  int v3; // r2
  int result; // r0
  unsigned int v5; // r3
  volatile unsigned int v6; // r2
  uint8_t *v7; // r0
  int v8; // r6

  if ( (a2 & 0x800000) != 0 )
  {
    result = event_dispatch("%s: sta probe succ\n", aApmProbeStaCfm);
    v5 = (uint8_t)a1[35];
    a1[668] = 0;
    if ( v5 <= 0x23 )
    {
      v6 = (*(volatile uint32_t *)0x40501010u);
      *(uint32_t *)(dword_125034 + 696 * v5 + 664) = v6;
      return 696;
    }
  }
  else
  {
    v3 = (uint8_t)(a1[668] + 1);
    a1[668] = v3;
    result = event_dispatch("%s: sta probe fail:%d\n", aApmProbeStaCfm, v3);
    if ( (uint8_t)a1[668] > 9u )
    {
      v7 = (uint8_t *)ke_msg_alloc(125, 13, 0, 8);
      *v7 = a1[35];
      v7[1] = a1[34];
      v8 = (int)v7;
      a1[668] = 0;
      memcpy(v7 + 2, a1 + 38, 6u);
      return (int)ke_msg_send_2(v8);
    }
  }
  return result;
}
