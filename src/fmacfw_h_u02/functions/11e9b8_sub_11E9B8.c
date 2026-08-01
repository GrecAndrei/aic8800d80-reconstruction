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

extern uint32_t off_11E9EC;
extern uint32_t off_11E9F0;

// check_fw_rom_signature @ 0x11e9b8, size 52 bytes
unsigned int check_fw_rom_signature()
{
  int v0; // r3
  unsigned int result; // r0
  unsigned int v2; // r3
  int v3; // r3

  v0 = *((uint32_t *)off_11E9EC + 2);
  if ( v0 == *(uint32_t *)off_11E9F0 )
    return 0;
  result = v0 & 0x7FFFFFFF;
  if ( *((uint32_t *)off_11E9EC + 1) - (v0 & 0x7FFFFFFFu) <= 0x9F )
  {
    v2 = v0 & 0x80000000;
    if ( result > *(uint32_t *)off_11E9EC )
      v2 += 0x80000000;
    v3 = v2 | *(uint32_t *)off_11E9EC;
    *((uint32_t *)off_11E9EC + 2) = v3;
    return v3 & 0x7FFFFFFF;
  }
  return result;
}

