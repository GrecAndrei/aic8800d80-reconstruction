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

extern uint32_t off_128EA8;
extern uint32_t off_128EB0;
extern uint32_t off_128EAC;
extern uint32_t off_128EB4;
extern uint32_t off_128EBC;
extern uint32_t off_128EB8;
extern uint32_t dword_128EC0;

// sub_128E5C @ 0x128e5c, size 76 bytes
int  sub_128E5C(int a1, int a2)
{
  int result; // r0
  uint8_t *v4; // r3
  int v5; // r2
  int v6; // r2
  int v7; // r1
  int v8; // r0

  result = sub_128D50(a1, a2, (int)off_128EA8);
  if ( result )
  {
    v4 = off_128EB0;
    v5 = *((uint8_t *)off_128EAC + 2);
    *((uint8_t *)off_128EB0 + 28) = 1;
    if ( v5 )
      *(uint32_t *)off_128EB4 &= ~0x80000000;
    if ( v4[8] )
      --v4[8];
    v6 = *((uint32_t *)off_128EBC + 4);
    v7 = *(uint16_t *)(*(uint32_t *)off_128EB8 + 54);
    v8 = dword_128EC0;
    *((uint32_t *)v4 + 5) = a1;
    v4[29] = 4;
    result = timestamp_update_4f60(v8, v7 + v6);
    *(uint32_t *)(a1 + 4) |= 0x200u;
  }
  return result;
}

