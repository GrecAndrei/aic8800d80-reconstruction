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

extern uint32_t off_12EA4C;

// fmacfw_version_get @ 0x12ea44, size 6 bytes
// Doc: fmacfw_version_get [util]: Return pointer to firmware version string
// fmacfw_version_get [util]: Return pointer to firmware version string
int fmacfw_version_get()
{
  return *(uint32_t *)off_12EA4C;
}

