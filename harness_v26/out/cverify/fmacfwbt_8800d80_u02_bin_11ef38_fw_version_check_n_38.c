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

#define off_11EF6C ((uint32_t)0x00188cd4u)
#define off_11EF70 ((uint32_t)0x403281d4u)
// fw_version_check_n_38 @ 0x11ef38, size 52 bytes
// Doc: fw_version_check_n_38 [util]: Compare firmware version or build ID against expected value
// fw_version_check_n_38 [util]: Compare firmware version or build ID against expected value
unsigned int fw_version_check_n_38()
{
  int v0; // r3
  unsigned int result; // r0
  unsigned int v2; // r3
  int v3; // r3

  v0 = *((uint32_t *)off_11EF6C + 2);
  if ( v0 == *(uint32_t *)off_11EF70 )
    return 0;
  result = v0 & 0x7FFFFFFF;
  if ( *((uint32_t *)off_11EF6C + 1) - (v0 & 0x7FFFFFFFu) <= 0x9F )
  {
    v2 = v0 & 0x80000000;
    if ( result > *(uint32_t *)off_11EF6C )
      v2 += 0x80000000;
    v3 = v2 | *(uint32_t *)off_11EF6C;
    *((uint32_t *)off_11EF6C + 2) = v3;
    return v3 & 0x7FFFFFFF;
  }
  return result;
}

