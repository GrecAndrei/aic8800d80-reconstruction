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

extern uint32_t off_10CC7C;
extern uint32_t off_10CC80;

// controller_config_read @ 0x10cc50, size 44 bytes
int controller_config_read()
{
  uint32_t *v0; // r4
  int result; // r0

  v0 = off_10CC7C;
  while ( !*(uint32_t *)off_10CC7C )
    ;
  result = *(uint32_t *)(*(uint32_t *)off_10CC80 + 596);
  if ( result )
  {
    result = mem_word_load(*(uint32_t *)off_10CC80 + 596);
    *v0 = 1;
    if ( result )
      result += 4;
  }
  else
  {
    *(uint32_t *)off_10CC7C = 1;
  }
  return result;
}

