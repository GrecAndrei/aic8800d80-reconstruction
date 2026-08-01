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

extern uint32_t off_1033E0;
extern uint32_t off_1033E4;

// crypto_start_operation @ 0x10327c, size 356 bytes
void __noreturn crypto_start_operation()
{
  unsigned int *v0; // r6
  unsigned int *v1; // r5

  v0 = (unsigned int *)off_1033E0;
  v1 = (unsigned int *)off_1033E4;
  *(uint32_t *)off_1033E0 |= 0x10u;
  *v1 = *v1 & 0xFFFFC0FF | 0x300;
  *v0 &= ~0x200u;
  *v0 = *v0 & 0xFFFE03FF | 0x10000;
  *v1 |= 0x4000u;
  while ( 1 )
    ;
}

