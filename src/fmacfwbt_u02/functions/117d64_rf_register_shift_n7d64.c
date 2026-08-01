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

extern uint32_t off_117E0C;
extern uint32_t off_117E20;
extern uint32_t dword_117E10;
extern uint32_t dword_117E14;
extern uint32_t off_117E18;
extern uint32_t off_117E28;
extern uint32_t dword_117E1C;
extern uint32_t off_117E24;
extern uint32_t dword_117E30;
extern uint32_t dword_117E2C;

// rf_irq_check @ 0x117d64, size 168 bytes
// Doc: rf_irq_check [rf]: Shifts and masks RF register value loaded from HW table
// rf_irq_check [rf]: Shifts and masks RF register value loaded from HW table
int  rf_irq_check(int result)
{
  int v1; // r4
  int v2; // r5
  unsigned int v3; // r3
  unsigned int v4; // r4

  v1 = *(uint32_t *)off_117E0C;
  if ( (*(uint32_t *)off_117E0C & 0x1000) != 0 )
  {
    result = poll_hw_cmd(result, *(uint32_t *)off_117E0C << 19);
    *(uint32_t *)off_117E20 = 4096;
  }
  v2 = dword_117E10;
  if ( (v1 & dword_117E10) != 0 )
  {
    result = rf_init();
    *(uint32_t *)off_117E20 = v2;
  }
  if ( (dword_117E14 & v1) != 0 && (*(uint32_t *)off_117E18 & 0x300000) == 0 )
  {
    *(uint32_t *)off_117E28 |= 0x200u;
    v3 = dword_117E1C & v1;
    if ( (dword_117E1C & v1) == 0 )
      return result;
  }
  else
  {
    v3 = dword_117E1C & v1;
    if ( (dword_117E1C & v1) == 0 )
      return result;
  }
  if ( (v1 & 0x80000) != 0 )
  {
LABEL_9:
    *(uint32_t *)off_117E20 = 0x80000;
    return conn_schedule(5);
  }
  v4 = (uint8_t)(25 - __clz(v3));
  if ( **(int16_t **)off_117E24 >= 0 || v4 <= 6 )
  {
    if ( v4 == 5 )
      goto LABEL_9;
  }
  else
  {
    mmio_irq_clear(dword_117E30, dword_117E2C, 2883);
  }
  *(uint32_t *)off_117E20 = 1 << (v4 + 6);
  return conn_schedule(v4);
}

