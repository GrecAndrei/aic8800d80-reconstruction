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

extern uint32_t dword_1347F0;
extern uint32_t off_1347F4;
extern uint32_t dword_1347FC;
extern uint32_t dword_1347F8;

// sub_1347BC @ 0x1347bc, size 52 bytes
int sub_1347BC()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r4

  v0 = rf_bus_mark_n100_d2d0(dword_1347F0);
  v1 = v0;
  if ( **(int16_t **)off_1347F4 < 0 && !v0 )
    sub_12F46C(dword_1347FC, dword_1347F8, 766);
  return sdio_buffer_prepare_n_4e8((int)(v1 + 3));
}

