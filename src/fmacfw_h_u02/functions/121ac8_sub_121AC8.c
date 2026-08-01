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

extern uint32_t off_121B5C;
extern uint32_t dword_121B78;
extern uint32_t dword_121B74;
extern uint32_t off_121B60;
extern uint32_t off_121B64;
extern uint32_t off_121B68;
extern uint32_t off_121B6C;
extern uint32_t off_121B70;

// ke_evt_peek @ 0x121ac8, size 148 bytes
int ke_evt_peek()
{
  int *v1; // r4
  int v2; // r3
  int v3; // r2

  if ( **(int16_t **)off_121B5C < 0 && (hci_cmd_handler(0) == 3 || !hci_cmd_handler(0)) )
    irq_disable_mmio_write(dword_121B78, dword_121B74, 1862);
  if ( hci_cmd_handler(0) == 2 )
  {
    *(uint32_t *)off_121B60 = 48;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_121B64 = 1;
    }
    v1 = (int *)off_121B68;
    ++*(uint32_t *)off_121B68;
    irq_disable_global_3(0x2000000);
    if ( (*(uint32_t *)off_121B6C & 4) != 0 )
      *(uint32_t *)off_121B70 = 4;
    if ( *v1 )
    {
      v2 = *v1 - 1;
      v3 = *(uint32_t *)off_121B64;
      *v1 = v2;
      if ( !v2 )
      {
        if ( v3 )
          __enable_irq();
      }
    }
  }
  return hci_cmd_preprocess(0);
}

