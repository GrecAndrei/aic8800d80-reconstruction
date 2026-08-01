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

extern uint32_t off_10DCB4;
extern uint32_t dword_40504080;
extern uint32_t off_10DCB8;
extern uint32_t dword_10DCBC;
extern uint32_t dword_10DCC4;
extern uint32_t off_10DCC0;

// make_bit_mask @ 0x10dc04, size 174 bytes
int  make_bit_mask(int result, int a2, int a3)
{
  int v3; // r4
  uint32_t *v4; // r6
  uint32_t *v5; // r3
  int v6; // r6
  uint32_t *v7; // r3
  uint8_t *v8; // r5
  int v9; // nf

  v3 = 1 << result;
  if ( result <= 7 )
  {
    v4 = off_10DCB4;
    dword_40504080[result] &= 0xFFFFFFF0;
    v4[1] |= v3;
  }
  v5 = off_10DCB4;
  *((uint32_t *)off_10DCB4 + 2) &= ~v3;
  v5[10] |= v3;
  v5[3] &= ~v3;
  v6 = ~v3;
  if ( a2 == 2 )
  {
    v5[4] |= v3;
  }
  else
  {
    v5[4] &= v6;
    if ( a2 )
      v5[5] &= v6;
    else
      v5[5] |= v3;
  }
  v7 = off_10DCB4;
  v8 = off_10DCB8;
  *((uint32_t *)off_10DCB4 + 9) = v3;
  v7[6] |= v3;
  v7[11] |= 7 << (result & 0xFC);
  v9 = (*(uint32_t *)v8 & 0x800000) != 0;
  *(uint32_t *)(dword_10DCBC + 4 * result) = a3;
  if ( !v9 )
  {
    result = dword_10DCC4;
    *(uint32_t *)(*((uint32_t *)off_10DCC0 + 2) + 156) = dword_10DCC4;
    v8[791] = -4;
    *(uint32_t *)v8 = 0x800000;
  }
  return result;
}

