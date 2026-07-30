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

extern uint32_t dword_124964;
extern uint32_t off_12495C;
extern uint32_t off_124960;

// sub_124944 @ 0x124944, size 22 bytes
int sub_124944()
{
  sub_11F504(dword_124964, *(uint32_t *)off_12495C, *(uint32_t *)off_124960 + *(uint32_t *)off_12495C);
  return 0;
}

