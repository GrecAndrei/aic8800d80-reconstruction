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

extern uint32_t dword_12A184;
extern uint32_t off_12A188;

// sub_12A168 @ 0x12a168, size 26 bytes
int *sub_12A168()
{
  int *result; // r0
  uint8_t *v1; // r3

  result = memset_thunk((int *)dword_12A184, 0, 1u);
  v1 = off_12A188;
  *((uint8_t *)off_12A188 + 113) = -1;
  v1[253] = -1;
  return result;
}

