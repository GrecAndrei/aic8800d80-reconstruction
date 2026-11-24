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


extern uint32_t off_102DD4;

// copy_config_struct @ 0x102da4, size 48 bytes
int copy_config_struct()
{
  uint64_t v0; // kr00_8
  int v1; // r4

  v0 = *(uint64_t *)(off_102DD4 + 4);
  v1 = *(uint32_t *)off_102DD4;
  memcpy(0, 32, 0x10u, SHIDWORD(v0));
  memcpy(0, 48, 0x10u, v0);
  return memcpy(0, 64, 0x10u, v1);
}
