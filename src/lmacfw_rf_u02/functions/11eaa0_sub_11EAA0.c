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

extern uint32_t dword_11EAC4;

// float_to_double @ 0x11eaa0, size 26 bytes
// Doc: sdio_buffer_prepare_n_108 [mac]: Prepares SDIO host buffer for transfer
// sdio_buffer_prepare_n_108 [mac]: Prepares SDIO host buffer for transfer
float  float_to_double(unsigned int a1)
{
  float v1; // r0
  uint64_t v2; // r0
  int v3; // r0

  v1 = float_extract_parts(a1);
  v2 = aeabi_d2f(LODWORD(v1));
  v3 = aeabi_dadd(v2, HIDWORD(v2), sdio_buffer_prepare_n_f4, dword_11EAC4);
  return aeabi_dmul(v3);
}

