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

extern uint32_t off_114C24;
extern uint32_t off_114C28;
extern uint32_t off_114C2C;

// get_ke_env @ 0x114bf8, size 42 bytes
void get_ke_env()
{
  int *v0; // r4

  v0 = (int *)off_114C24;
  if ( !*(uint32_t *)off_114C24 )
    *v0 = invalid_handler();
  if ( !*(uint32_t *)off_114C28 )
    *(uint32_t *)off_114C28 = *v0 + 67092480;
  *(uint32_t *)off_114C2C = 1;
}

