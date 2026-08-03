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

extern uint32_t dword_138BA8;

// sub_138B78 @ 0x138b78, size 46 bytes
uint32_t ** sub_138B78(uint32_t *a1)
{
  int v1; // r5

  v1 = dword_138BA8;
  sub_138AD4(0, 4, a1[5]);
  list_remove_node_d510(v1, a1);
  list_push_tail(v1 - 8, a1);
  return sub_12F770((uint32_t **)(v1 - 32));
}

