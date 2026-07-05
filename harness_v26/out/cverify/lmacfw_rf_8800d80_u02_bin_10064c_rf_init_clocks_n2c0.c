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

#define off_100680 ((uint32_t)0x40343050u)
#define off_100684 ((uint32_t)0x40343004u)
#define off_10067C ((uint32_t)0x40344084u)
// rf_init_clocks_n2c0 @ 0x10064c, size 46 bytes
// Doc: rf_init_clocks_n2c0 [mmio]: Initialize RF clock/regulator MMIO region
// rf_init_clocks_n2c0 [mmio]: Initialize RF clock/regulator MMIO region
uint32_t *rf_init_clocks_n2c0()
{
  uint32_t *result; // r0
  int *v1; // r2

  result = off_100680;
  v1 = (int *)off_100684;
  *(uint32_t *)off_10067C |= 0x10000u;
  *result = 0;
  *v1 = *v1 & 0x1FFFFFFE | 0x20000001;
  return result;
}

