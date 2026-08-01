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

extern uint32_t off_12C52C;
extern uint32_t off_12C530;
extern uint32_t off_12C534;
extern uint32_t off_12C538;
extern uint32_t off_12C53C;
extern uint32_t dword_12C560;
extern uint32_t dword_12C540;
extern uint32_t off_12C544;
extern uint32_t off_12C548;
extern uint32_t off_12C554;
extern uint32_t dword_12C55C;

// mac_irq_clear @ 0x12c408, size 290 bytes
void  mac_irq_clear(int a1, int a2)
{
  int v2; // r4
  int *v3; // r0
  int *v4; // r1
  int v5; // r2
  int v6; // r3
  unsigned int *v7; // r1
  int v8; // r0
  unsigned int v9; // r2
  void *v10; // r2
  int v11; // r0
  int v12; // r6
  int v13; // r2
  int v14; // r0

  v2 = *(uint32_t *)off_12C52C & *(uint32_t *)off_12C530;
  *(uint32_t *)((char *)off_12C52C + 0xFFFFFFFC) = v2;
  if ( v2 << 30 )
  {
    v3 = (int *)off_12C534;
    v4 = (int *)off_12C538;
    v5 = *(uint32_t *)off_12C534;
    v6 = *(uint32_t *)off_12C538;
    if ( (v2 & 1) != 0 && !*((uint8_t *)off_12C53C + 36) )
    {
      v12 = v5 | 0x5400;
      v13 = v5 | 0xFC00;
      *(uint32_t *)off_12C534 = v12;
      *v3 = v13;
      *v4 = v6 | 0x500000;
      v14 = dword_12C560;
      *v4 = v6 | 0xF00000;
      ke_event_schedule(v14, v4, v13);
    }
    else
    {
      v7 = (unsigned int *)off_12C538;
      v8 = dword_12C540;
      v9 = v5 & 0xFFFF57FF;
      *(uint32_t *)off_12C534 = v9;
      *v7 = v6 & 0xFF5FFFFF;
      ke_event_schedule(v8, v7, v9);
    }
  }
  if ( (v2 & 4) != 0 )
  {
    if ( (*(uint32_t *)off_12C544 & 1) != 0 )
    {
      *(uint32_t *)off_12C548 |= 0x400000u;
      while ( 1 )
        ;
    }
    v10 = off_12C554;
    v11 = dword_12C55C;
    *(uint32_t *)off_12C554 |= 1u;
    ke_event_schedule(v11, a2, v10);
  }
}

