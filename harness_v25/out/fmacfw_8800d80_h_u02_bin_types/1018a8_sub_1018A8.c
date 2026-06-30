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

extern uint32_t off_1018CC;
extern uint32_t off_1018D0;
extern uint32_t dword_1018D4;

// sub_1018A8 @ 0x1018a8, size 36 bytes
int sub_1018A8()
{
  char *v0; // r2
  int v1; // r1

  v0 = (char *)off_1018CC;
  v1 = *(uint32_t *)off_1018CC;
  *(uint32_t *)off_1018D0 = *(uint32_t *)off_1018CC;
  if ( (v1 & 0x1000) == 0 )
    return sub_12E948(dword_1018D4, v1, v0);
  *(uint32_t *)&v0[-8] &= ~0x1000u;
  return sub_12CFC4(16);
}

