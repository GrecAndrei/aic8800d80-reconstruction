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

extern uint32_t off_11C934;

// mac_addr_copy_to_global @ 0x11c924, size 16 bytes
// Doc: mac_addr_copy_to_global [mac]: Copy 2-byte MAC address fragment to global state buffer
// mac_addr_copy_to_global [mac]: Copy 2-byte MAC address fragment to global state buffer
uint8_t * mac_addr_copy_to_global(uint8_t *result)
{
  uint8_t *v1; // r3

  v1 = off_11C934;
  *((uint8_t *)off_11C934 + 164) = *result;
  v1[165] = result[1];
  return result;
}

