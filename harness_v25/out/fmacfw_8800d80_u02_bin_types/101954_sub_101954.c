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

extern uint32_t off_101978;
extern uint32_t off_10197C;
extern uint32_t dword_101980;

// sub_101954 @ 0x101954, size 36 bytes
int sub_101954()
{
  char *v0; // r2
  int v1; // r1

  v0 = (char *)off_101978;
  v1 = *(uint32_t *)off_101978;
  *(uint32_t *)off_10197C = *(uint32_t *)off_101978;
  if ( (v1 & 0x1000) == 0 )
    return sub_12EA88(dword_101980, v1, v0);
  *(uint32_t *)&v0[-8] &= ~0x1000u;
  return sub_12D104(16);
}

