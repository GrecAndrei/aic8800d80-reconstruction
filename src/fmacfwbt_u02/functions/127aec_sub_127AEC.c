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

// release_buffer @ 0x127aec, size 38 bytes
int  release_buffer(int a1)
{
  int v2; // r0
  int result; // r0

  v2 = mac_check_hw_state(*(uint32_t *)(a1 + 88));
  *(uint32_t *)(a1 + 88) = v2;
  result = rf_write_register(a1, v2);
  *(uint8_t *)(a1 + 85) = *(uint8_t *)(a1 + 85) & 0x9F | 0x20;
  return result;
}

