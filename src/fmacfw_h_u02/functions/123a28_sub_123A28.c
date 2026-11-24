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


extern uint32_t off_123AA0;
extern uint32_t off_123AAC;

// list_find_entry @ 0x123a28, size 118 bytes
int  list_find_entry(int a1, void ( **a2)(int), unsigned int a3)
{
  uint16_t **v3; // r5
  int result; // r0
  int v7; // r0

  v3 = (uint16_t **)off_123AA0;
  if ( **(uint16_t **)off_123AA0 < 0 && hci_cmd_handler(a3) == 4 )
    irq_disable_mmio_write((int)aKeStateGetDest_0, (int)aMmForceIdleReq_0, 1587);
  result = hci_cmd_handler(a3);
  if ( result )
  {
    if ( result != 2 )
    {
      rf_status_check();
      hci_cmd_preprocess(a3, 2);
      return 2;
    }
  }
  else
  {
    if ( **v3 < 0 && *(uint32_t *)off_123AAC << 28 )
      irq_disable_mmio_write((int)aNxmacCurrentSt, (int)aMmForceIdleReq_0, 1594);
    v7 = hci_cmd_preprocess(a3, 3);
    (*a2)(v7);
    return 0;
  }
  return result;
}
