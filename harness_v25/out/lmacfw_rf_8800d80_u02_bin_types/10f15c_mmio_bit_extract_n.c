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

extern uint32_t dword_10F16C;

// mmio_bit_extract_n @ 0x10f15c, size 16 bytes
// Doc: mmio_bit_extract_n [mmio]: Reads MMIO register 0x7000101c and extracts 5-bit field at bit 11
// mmio_bit_extract_n [mmio]: Reads MMIO register 0x7000101c and extracts 5-bit field at bit 11
int mmio_bit_extract_n()
{
  return (uint16_t)sub_10EFBC(dword_10F16C, 1) >> 11;
}

