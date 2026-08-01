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

extern uint32_t off_10D05C;
extern uint32_t off_10D060;
extern uint32_t off_10D064;
extern uint32_t off_10D068;

// rf_irq_handler @ 0x10d02c, size 48 bytes
// Doc: sub_120D02C [mmio]: Reads MMIO register 0x40035104 and processes bit flags
// sub_120D02C [mmio]: Reads MMIO register 0x40035104 and processes bit flags
int rf_irq_handler()
{
  uint32_t *v0; // r4
  int *v1; // r7
  uint32_t *v2; // r6
  int v3; // r0
  int result; // r0

  v0 = off_10D05C;
  if ( (*(uint32_t *)off_10D05C & 2) != 0 )
  {
    v1 = (int *)off_10D060;
    v2 = off_10D064;
    do
    {
      v3 = *v1;
      *v2 = 2;
      bt_event_process((uint16_t *)(v3 + 4));
    }
    while ( (*v0 & 2) != 0 );
  }
  result = enter_critical_section(0x8000000);
  *(uint32_t *)off_10D068 = 2;
  return result;
}

