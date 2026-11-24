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


extern uint32_t dword_114788;
extern uint32_t dword_11478C;

// init_osal_objects @ 0x114754, size 52 bytes
uint32_t *init_osal_objects()
{
  int v0; // r4
  uint32_t *v1; // r6
  uint32_t *v2; // r5

  v0 = dword_114788;
  v1 = (uint32_t *)dword_11478C;
  v2 = (uint32_t *)(dword_114788 + 8);
  zero_struct((uint32_t *)dword_114788);
  zero_struct(v2);
  check_abort_flag((int)v2, v1);
  check_abort_flag((int)v2, v1 + 256);
  return zero_struct((uint32_t *)(v0 + 16));
}
