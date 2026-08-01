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

extern uint32_t dword_115EF4;
extern uint32_t off_115EF8;
extern uint32_t dword_115F00;
extern uint32_t dword_115EFC;

// rssi_compare @ 0x115ec8, size 42 bytes
int rssi_compare()
{
  int v0; // r0
  int v1; // r4

  v0 = list_pop(dword_115EF4);
  v1 = v0;
  if ( **(int16_t **)off_115EF8 < 0 && !v0 )
    irq_disable_mmio_write(dword_115F00, dword_115EFC, 119);
  return v1;
}

