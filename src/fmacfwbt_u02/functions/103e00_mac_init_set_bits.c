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

extern uint32_t off_103E7C;
extern uint32_t off_103E78;
extern uint32_t dword_103E80;

// mac_tx_enable @ 0x103e00, size 118 bytes
// Doc: mac_tx_enable [mac]: Set MMIO bits to initialize MAC subsystem
// mac_tx_enable [mac]: Set MMIO bits to initialize MAC subsystem
int * mac_tx_enable(int a1)
{
  unsigned int *v1; // r3
  int v2; // r5
  int v3; // r7
  int v4; // r12
  unsigned int *v5; // lr
  int v6; // r6
  int v7; // r0
  int *result; // r0
  int v9; // r4
  int *v10; // r3
  uint32_t *v11; // r2
  int v12; // t1

  v1 = (unsigned int *)off_103E7C;
  *(uint32_t *)off_103E78 |= 0x100u;
  v2 = 0;
  v3 = -a1;
  v4 = a1 + 48;
  *v1 &= 0xFFFCFFFF;
  v5 = v1;
  v6 = 0;
  v7 = 128;
  while ( 1 )
  {
    result = (int *)(v4 + 4 * (v7 + v2));
    v9 = dword_103E80 + v3;
    v10 = (int *)(48 - v3);
    do
    {
      v11 = (int *)((char *)v10 + v9);
      v12 = *v10++;
      *v11 = v12;
    }
    while ( v10 != result );
    ++v6;
    if ( v2 == 256 )
      break;
    v2 += 128;
    v3 -= 512;
    *v5 = *v5 & 0xFFFCFFFF | (v6 << 16);
    if ( v6 == 2 )
      v7 = 32;
    else
      v7 = 128;
  }
  *(uint32_t *)off_103E78 &= ~0x100u;
  return result;
}

