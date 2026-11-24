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


extern uint32_t dword_11EC88;
extern uint32_t off_11EC80;
extern uint32_t off_11EC84;
extern uint32_t off_11EC90;

// rf_irq_status_check @ 0x11ebfc, size 132 bytes
void rf_irq_status_check()
{
  uint32_t *v0; // r5
  uint32_t *v1; // r6
  int v2; // r3
  int v3; // r7
  uint32_t *v4; // r8
  int v5; // r3
  int v6; // r4
  int v7; // r2
  int v8; // r12
  unsigned int v9; // r1
  unsigned int v10; // r2
  unsigned int v11; // r3
  unsigned int v12; // r2

  v0 = off_11EC80;
  v1 = off_11EC84;
  v2 = *((uint32_t *)off_11EC80 + 5);
  if ( v2 != *(uint32_t *)off_11EC84 )
  {
    v3 = dword_11EC88;
    v4 = off_11EC90;
    do
    {
      v8 = v0[4];
      v9 = v2 & 0x7FFFFFFF;
      v10 = v8 - (v2 & 0x7FFFFFFF);
      v11 = v2 & 0x80000000;
      if ( v10 > 0x9F )
      {
        v5 = v0[5];
      }
      else
      {
        v12 = v0[3];
        if ( v9 > v12 )
          v11 += 0x80000000;
        v5 = v11 | v12;
        v0[5] = v5;
      }
      v6 = v5 & 0x7FFFFFFF;
      v7 = *(uint32_t *)((v5 & 0x7FFFFFFF) + 0x14);
      if ( v7 != v3 )
        event_dispatch(
          "rxbuf2 %08x,%08x: start %08x, end %08x, read %08x, wrptr %08x, rdptr %08x\r\n",
          v5 & 0x7FFFFFFF,
          v7,
          v0[3],
          v8,
          v5,
          *v1,
          *v4);
      ke_task_state_get(v6);
      *(uint8_t *)(v6 + 156) = 1;
      rf_tx_frame(v6);
      v2 = v0[5];
    }
    while ( v2 != *v1 );
  }
}
