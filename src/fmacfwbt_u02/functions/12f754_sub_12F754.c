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

extern uint32_t off_12F768;
extern uint32_t off_10CA30;
extern uint32_t off_10CA34;
extern uint32_t off_10CA38;

// state_ready_check @ 0x12f754, size 18 bytes
int state_ready_check()
{
  int result; // r0

  if ( **(uint8_t **)off_12F768 != 3 )
    return 1;
  result = *(uint32_t *)(*(uint32_t *)off_10CA30 + 548);
  *(uint32_t *)off_10CA34 = 32;
  if ( result )
    return 1;
  *(uint32_t *)off_10CA38 = 32;
  return result;
}

