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

extern uint32_t off_12F54C;
extern uint32_t off_10CBD8;
extern uint32_t off_10CBDC;
extern uint32_t off_10CBE0;

// check_rom_state @ 0x12f538, size 18 bytes
int check_rom_state()
{
  int result; // r0

  if ( **(uint8_t **)off_12F54C != 3 )
    return 1;
  result = *(uint32_t *)(*(uint32_t *)off_10CBD8 + 612);
  *(uint32_t *)off_10CBDC = 32;
  if ( result )
    return 1;
  *(uint32_t *)off_10CBE0 = 32;
  return result;
}

