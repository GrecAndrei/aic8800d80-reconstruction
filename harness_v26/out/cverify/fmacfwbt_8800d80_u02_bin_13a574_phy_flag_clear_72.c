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

#define off_13A584 ((uint32_t)0x00195088u)
// phy_flag_clear_72 @ 0x13a574, size 14 bytes
// Doc: phy_flag_clear_72 [mac]: Clear 16-bit flag at offset 0x72 in PHY struct
// phy_flag_clear_72 [mac]: Clear 16-bit flag at offset 0x72 in PHY struct
int phy_flag_clear_72()
{
  int result; // r0

  result = *((uint8_t *)off_13A584 + 114);
  *((uint16_t *)off_13A584 + 57) = 0;
  return result;
}

