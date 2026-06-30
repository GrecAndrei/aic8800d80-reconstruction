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

extern uint32_t dword_10ED8C;

// mmio_read_bitfield_7000101c @ 0x10ed7c, size 16 bytes
// Doc: mmio_read_bitfield_7000101c [mmio]: Reads a 5-bit field at offset 0xb from MMIO 0x7000101c
// mmio_read_bitfield_7000101c [mmio]: Reads a 5-bit field at offset 0xb from MMIO 0x7000101c
int mmio_read_bitfield_7000101c()
{
  return (uint16_t)sub_10EBDC(dword_10ED8C, 1) >> 11;
}

