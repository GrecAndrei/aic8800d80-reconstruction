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

extern uint32_t dword_13C7D0;

// is_conn_active @ 0x13c710, size 192 bytes
int  is_conn_active(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5; // lr
  uint64_t v6; // r4
  uint64_t v7; // kr00_8
  uint8_t *v8; // r8
  int v9; // r5
  unsigned int v10; // r4
  int v11; // r6
  uint8_t *v12; // r6
  uint8_t *v13; // r4
  unsigned int v14; // r0
  unsigned int v15; // r1
  int i; // r3
  int v17; // r2
  unsigned int v18; // r4

  result = *(uint32_t *)(dword_13C7D0 + 1320 * *(uint8_t *)(a1 + 28) + 1204);
  if ( result )
  {
    if ( a4 )
      v5 = a4;
    else
      v5 = a3 + a2;
    *(uint8_t *)v5 = 76;
    *(uint8_t *)(v5 + 1) = 16;
    v6 = *(uint64_t *)(result + 72);
    *(uint16_t *)(v5 + 2) = *(uint8_t *)(result + 97);
    v7 = v6 + 1;
    *(uint64_t *)(result + 72) = v6 + 1;
    v8 = (uint8_t *)(v5 + 4);
    v9 = 0;
    while ( 1 )
    {
      v10 = ((unsigned int)v7 >> v9) | (HIDWORD(v7) << (32 - v9));
      v11 = HIDWORD(v7) >> (v9 - 32);
      v9 += 8;
      *v8++ = v10 | v11;
      if ( v9 == 48 )
        break;
      v7 = *(uint64_t *)(result + 72);
    }
    v12 = (uint8_t *)(v5 + 10);
    v13 = (uint8_t *)(v5 + 10);
    do
      *v13++ = 0;
    while ( (uint8_t *)(v5 + 18) != v13 );
    v14 = rf_get_tx_pwr(result, a2, a3, 24, a4);
    for ( i = 0; i != 64; i += 8 )
    {
      v17 = (v14 >> i) | (v15 << (32 - i));
      v18 = v15 >> (i - 32);
      *v12++ = v17 | v18;
    }
    return 18;
  }
  return result;
}

