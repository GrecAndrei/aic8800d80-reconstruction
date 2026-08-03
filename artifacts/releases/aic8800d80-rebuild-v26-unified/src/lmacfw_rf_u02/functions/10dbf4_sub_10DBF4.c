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

extern uint32_t dword_10DC3C;
extern uint32_t off_10DC34;
extern uint32_t dword_10DC38;

// sub_10DBF4 @ 0x10dbf4, size 64 bytes
int  sub_10DBF4(int a1)
{
  int v1; // r3
  int v2; // r0
  int v3; // r1

  v1 = dword_10DC3C;
  if ( (*(uint8_t *)off_10DC34 & 0xC0) == 0xC0 )
    v1 = dword_10DC38;
  v2 = 4 * a1;
  v3 = v1 + 16;
  do
  {
    *(uint32_t *)(v3 - 12) = *(uint32_t *)(v3 - 12) & 0xFFFFFFF3 | v2;
    v3 += 12;
  }
  while ( v1 + 208 != v3 );
  return sub_102D4C(1, 16, 0x10u, v1);
}

