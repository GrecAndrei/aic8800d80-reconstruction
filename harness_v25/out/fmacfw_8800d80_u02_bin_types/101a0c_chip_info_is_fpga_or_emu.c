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

extern uint32_t off_101A1C;

// chip_info_is_fpga_or_emu @ 0x101a0c, size 14 bytes
// Doc: chip_info_is_fpga_or_emu [util]: Returns 0 if chip type at 0x40341424 <= 1 else 1, distinguishing FPGA/emulator from ASIC
// chip_info_is_fpga_or_emu [util]: Returns 0 if chip type at 0x40341424 <= 1 else 1, distinguishing FPGA/emulator from ASIC
BOOL chip_info_is_fpga_or_emu()
{
  return *(uint32_t *)off_101A1C > 1u;
}

