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

extern uint32_t off_120768;
extern uint32_t off_12076C;

// clear_intr_status @ 0x120750, size 24 bytes
void clear_intr_status()
{
  int v0; // r3

  v0 = *((uint8_t *)off_120768 + 18) + *((uint8_t *)off_120768 + 17);
  *(uint32_t *)off_12076C = 0;
  if ( v0 <= 1 )
    si_secure_check();
}

