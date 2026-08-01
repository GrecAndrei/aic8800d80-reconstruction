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

extern uint32_t off_10CC30;
extern uint32_t dword_10CC48;
extern uint32_t dword_10CC40;
extern uint32_t dword_10CC50;
extern uint32_t dword_10CC4C;
extern uint32_t dword_10CC44;
extern uint32_t off_10CC34;
extern uint32_t off_10CC3C;
extern uint32_t off_10CC38;

// patch_dispatch @ 0x10cb70, size 190 bytes
int  patch_dispatch(uint16_t *a1)
{
  int16_t **v2; // r7
  int v3; // r0
  int16_t *v4; // r6
  int v5; // r4
  int v6; // r2
  unsigned int v7; // r7
  int *v8; // r3
  int *v9; // r2
  int v10; // r1
  int v11; // t1
  uint32_t *v12; // r1
  int16_t v13; // r3

  v2 = (int16_t **)off_10CC30;
  v3 = ((int ( *)(int))loc_12C9A4)((uint16_t)a1[5] + 16);
  v4 = *v2;
  v5 = v3;
  if ( **v2 < 0 && !v3 )
  {
    irq_disable_mmio_write(dword_10CC48, dword_10CC40, 1358);
    v4 = *v2;
  }
  v6 = (uint16_t)a1[5];
  v7 = (uint16_t)a1[3];
  *(uint16_t *)(v5 + 4) = a1[2];
  *(uint16_t *)(v5 + 8) = 13;
  *(uint16_t *)(v5 + 10) = v6;
  *(uint16_t *)(v5 + 6) = v7;
  *(uint32_t *)v5 = 0;
  v8 = (int *)(a1 + 6);
  if ( v6 )
  {
    v9 = (int *)((char *)a1 + ((v6 - 1) & 0xFFFFFFFC) + 16);
    v10 = v5 + 8;
    do
    {
      v11 = *v8++;
      *(uint32_t *)(v10 + 4) = v11;
      v10 += 4;
    }
    while ( v8 != v9 );
  }
  if ( *v4 < 0 )
  {
    if ( v7 > 0xE )
    {
      irq_disable_mmio_write(dword_10CC50, dword_10CC4C, 183);
      irq_disable_mmio_write(dword_10CC44, dword_10CC40, 1375);
    }
    else if ( v7 > 0xC )
    {
      irq_disable_mmio_write(dword_10CC44, dword_10CC40, 1375);
    }
  }
  if ( **(uint8_t **)off_10CC34 == 3 )
  {
    v12 = off_10CC3C;
    v13 = *((uint8_t *)off_10CC38 + 21);
    *((uint8_t *)off_10CC38 + 21) = v13 + 1;
    a1[4] = v13;
    *v12 = 4;
  }
  return rx_process_packet(v5 + 12);
}

