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

extern uint32_t dword_11F794;
extern uint32_t off_11F798;

// sub_11F774 @ 0x11f774, size 32 bytes
int sub_11F774()
{
  sub_11F504(dword_11F794);
  sub_11DC54(1071, 1);
  *((uint32_t *)off_11F798 + 20) &= ~2u;
  return 0;
}

