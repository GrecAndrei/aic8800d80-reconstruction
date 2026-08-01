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

// util_read_status @ 0x1125a4, size 6 bytes
// Doc: util_read_status [rf]: RF bus reset/read register byte stub
// util_read_status [rf]: RF bus reset/read register byte stub
int util_read_status()
{
  return *(uint8_t *)rf_cmd_send_n_36c;
}

