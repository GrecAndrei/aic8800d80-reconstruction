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


extern uint32_t off_11E420;
extern uint32_t off_11E42C;

// tx_timestamp_get @ 0x11e3bc, size 98 bytes
int  tx_timestamp_get(int a1, int a2)
{
  int result; // r0
  unsigned int v3; // r3
  uint32_t *v4; // r1
  int v5; // r2
  int v6; // cf
  unsigned int v7; // r2

  if ( !a2 )
  {
    v3 = a1 + 160;
    goto LABEL_9;
  }
  if ( (*(uint16_t *)(a2 + 16) & 1) != 0 )
  {
LABEL_8:
    v3 = (*(uint32_t *)(a2 + 12) & 0xFFFFFFFC) + 4;
LABEL_9:
    v4 = off_11E42C;
    v5 = *((uint32_t *)off_11E42C + 2);
    if ( *((uint32_t *)off_11E42C + 1) == v3 )
      v3 = *(uint32_t *)off_11E42C;
    *(uint32_t *)(a1 + 152) = v3;
    result = v5 & 0x7FFFFFFF;
    v6 = v3 >= (v5 & 0x7FFFFFFFu);
    v7 = v5 & 0x80000000;
    if ( !v6 )
      v7 += 0x80000000;
    v4[2] = v3 | v7;
    return result;
  }
  while ( 1 )
  {
    a2 = *(uint32_t *)(a2 + 4);
    if ( **(uint16_t **)off_11E420 < 0 && !a2 )
      return ke_int_lock_1((int)aPdNull, (int)aRxlGoToLastRbd, 1119);
    if ( (*(uint16_t *)(a2 + 16) & 1) != 0 )
      goto LABEL_8;
  }
}
