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

extern uint32_t off_114D60;
extern uint32_t dword_114D68;
extern uint32_t dword_114D64;

// is_rssi_valid @ 0x114d44, size 28 bytes
void __noreturn is_rssi_valid()
{
  if ( **(int16_t **)off_114D60 < 0 )
    irq_disable_mmio_write(dword_114D68, dword_114D64, 242);
  while ( 1 )
    ;
}

