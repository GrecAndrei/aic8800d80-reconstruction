#include <stdint.h>
#define BYTE1(x) ((uint8_t)(((uint32_t)(x) >> 8) & 0xFFu))
#define BYTE2(x) ((uint8_t)(((uint32_t)(x) >> 16) & 0xFFu))
#define BYTE3(x) ((uint8_t)(((uint32_t)(x) >> 24) & 0xFFu))
#define __noreturn
#define _VF 0
#define _CF 0
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

#define off_10F3AC ((uint32_t)0x001850a0u)
// log_pool_default_config @ 0x10f37c, size 48 bytes
// Doc: log_pool_default_config [util]: Initialize log pool with default P/Q type configuration
// log_pool_default_config [util]: Initialize log pool with default P/Q type configuration
int log_pool_default_config()
{
  uint8_t *v0; // r4
  char *v1; // r0

  v0 = off_10F3AC;
  v1 = (char *)off_10F3AC + 1624;
  *((uint16_t *)off_10F3AC + 810) = 80;
  v0[1622] = 81;
  sub_12D240(v1);
  *((uint16_t *)v0 + 1216) = 39;
  v0[2434] = 40;
  return sub_12D240(v0 + 2436);
}

