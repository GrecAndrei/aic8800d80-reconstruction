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

// extract_chan_bits @ 0x12e1c8, size 14 bytes
// Doc: extract_chan_bits [mac]: SDIO buffer prep extracting flags from word at offset 4-5
// extract_chan_bits [mac]: SDIO buffer prep extracting flags from word at offset 4-5
int  extract_chan_bits(int a1)
{
  return ((2 * *(uint8_t *)(a1 + 5)) | (*(uint8_t *)(a1 + 4) >> 7)) << 22;
}

