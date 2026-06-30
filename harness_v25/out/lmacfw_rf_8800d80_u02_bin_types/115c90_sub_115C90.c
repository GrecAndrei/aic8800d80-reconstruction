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

extern uint32_t off_115C9C;
extern uint32_t dword_115CA0;

// sub_115C90 @ 0x115c90, size 12 bytes
void sub_115C90()
{
  *((uint32_t *)off_115C9C + 1) = dword_115CA0 & *(uint32_t *)off_115C9C;
}

