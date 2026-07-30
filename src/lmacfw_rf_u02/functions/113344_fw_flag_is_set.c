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

extern uint32_t off_113354;

// fw_flag_is_set @ 0x113344, size 16 bytes
// Doc: fw_flag_is_set [util]: Return 1 if firmware flag byte is 0 or 1, else 0
// fw_flag_is_set [util]: Return 1 if firmware flag byte is 0 or 1, else 0
BOOL fw_flag_is_set()
{
  return *((uint8_t *)off_113354 + 8) == 1;
}

