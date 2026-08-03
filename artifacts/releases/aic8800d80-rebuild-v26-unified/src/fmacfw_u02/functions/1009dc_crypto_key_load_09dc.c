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

extern uint32_t off_100A98;
extern uint32_t off_100A94;
extern uint32_t dword_100A9C;
extern uint32_t off_100AA0;
extern uint32_t off_100AA4;

// crypto_key_load_09dc @ 0x1009dc, size 184 bytes
// Doc: crypto_key_load_09dc [ke]: Load crypto key into key engine MMIO at 0x40342200 region
// crypto_key_load_09dc [ke]: Load crypto key into key engine MMIO at 0x40342200 region
int  crypto_key_load_09dc(int a1, int a2)
{
  unsigned int *v2; // r3
  int v3; // r7
  unsigned int *v5; // r8
  int v6; // lr
  int v7; // r12
  int v8; // r5
  int v9; // r5
  int v10; // r1
  int v11; // r3
  uint32_t *v12; // r2
  int v13; // t1
  uint32_t *v14; // r2
  int v15; // r5
  int i; // r4
  int v17; // r1
  int result; // r0

  v2 = (unsigned int *)off_100A98;
  *(uint32_t *)off_100A94 |= 0x100u;
  v3 = 0;
  *v2 &= 0xFFFCFFFF;
  v5 = v2;
  v6 = -a1;
  v7 = 0;
  v8 = 128;
  while ( 1 )
  {
    v9 = a1 + 4 * (v8 + v3);
    v10 = dword_100A9C + v6;
    v11 = -v6;
    do
    {
      v12 = (uint32_t *)(v10 + v11);
      v13 = *(uint32_t *)v11;
      v11 += 4;
      *v12 = v13;
    }
    while ( v11 != v9 );
    ++v7;
    if ( v3 == 384 )
      break;
    v3 += 128;
    v6 -= 512;
    *v5 = *v5 & 0xFFFCFFFF | (v7 << 16);
    if ( v7 == 3 )
      v8 = 48;
    else
      v8 = 128;
  }
  v14 = off_100AA0;
  *(uint32_t *)off_100A94 &= ~0x100u;
  *v14 |= 0x1000000u;
  v15 = 1;
  for ( i = 0; i != 12; ++i )
  {
    sub_10410C((2 * i) & 0xFE, *(uint32_t *)(a2 + 8 * i));
    v17 = *(uint32_t *)(a2 + 4 + 8 * i);
    result = sub_10410C(v15, v17);
    v15 = (uint8_t)(v15 + 2);
  }
  *(uint32_t *)off_100AA4 &= ~2u;
  return result;
}

