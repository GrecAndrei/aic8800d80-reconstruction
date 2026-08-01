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

extern uint32_t off_128DD4;
extern uint32_t off_128DD8;

// mfp_key_clear @ 0x128db8, size 28 bytes
int mfp_key_clear()
{
  uint32_t *v0; // r4
  int *v1; // r0
  int result; // r0

  v0 = off_128DD4;
  v1 = sub_100200((int *)off_128DD4, 0, 0x28u);
  result = init_runtime_state(v1);
  v0[4] = off_128DD8;
  *((uint8_t *)v0 + 28) = 1;
  return result;
}

