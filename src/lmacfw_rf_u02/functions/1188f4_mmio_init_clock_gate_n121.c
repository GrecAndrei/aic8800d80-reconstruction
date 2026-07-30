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

extern uint32_t off_118904;

// mmio_init_clock_gate_n121 @ 0x1188f4, size 14 bytes
// Doc: mmio_init_clock_gate_n121 [mmio]: Writes 0x30 to MMIO 0x40320038 to configure clock gate/control
// mmio_init_clock_gate_n121 [mmio]: Writes 0x30 to MMIO 0x40320038 to configure clock gate/control
int mmio_init_clock_gate_n121()
{
  *(uint32_t *)off_118904 = 48;
  return sub_11E1E4(0);
}

