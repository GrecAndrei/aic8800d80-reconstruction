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

extern uint32_t dword_134CA8;

// mac_irq_dispatch @ 0x134c88, size 30 bytes
int  mac_irq_dispatch(int a1, int a2)
{
  if ( (a2 & 0x810000) == 0x10000 )
    ke_event_schedule(dword_134CA8);
  return mac_tx_start();
}

