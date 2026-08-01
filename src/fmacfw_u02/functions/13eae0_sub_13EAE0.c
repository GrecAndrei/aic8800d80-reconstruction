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

// int_status_check @ 0x13eae0, size 42 bytes
// Doc: misc_bit_extract_helper [util]: Extracts and combines bit fields from input value
// misc_bit_extract_helper [util]: Extracts and combines bit fields from input value
unsigned int  int_status_check(unsigned int result)
{
  unsigned int v1; // r2

  v1 = *(uint32_t *)(*(uint32_t *)(result + 76) + 4);
  if ( (v1 & 0x810000) != 0 )
    return ipc_dispatch_cmd(result, BYTE1(v1) + 1, (HIWORD(v1) & 1) + BYTE1(v1), 0, 0);
  return result;
}

