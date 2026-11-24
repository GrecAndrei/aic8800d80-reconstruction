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


extern uint32_t dword_10DF50;
extern uint32_t dword_10DF58;
extern uint32_t dword_10DF60;
extern uint32_t off_10DF68;

// sub_10DF08 @ 0x10df08, size 72 bytes
unsigned int sub_10DF08()
{
  uint32_t *v0; // r3
  uint64_t v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0
  uint64_t v4; // r0

  while ( *((uint32_t *)off_10DF68 + 7) != 1 )
    ;
  v0 = off_10DF68;
  *((uint32_t *)off_10DF68 + 7) = 1;
  v1 = sub_142874(v0[4]);
  v2 = sub_142968(v1, *(uint64_t *)&dword_10DF50);
  v3 = sub_142BBC(v2, *(uint64_t *)&dword_10DF58);
  v4 = sub_1425F8(v3, *(uint64_t *)&dword_10DF60);
  return sub_142F2C(v4);
}
