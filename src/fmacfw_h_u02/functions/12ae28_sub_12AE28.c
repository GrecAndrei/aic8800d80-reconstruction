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


extern uint32_t off_12AEB8;
extern uint32_t off_12AEBC;

// is_state_three @ 0x12ae28, size 138 bytes
int is_state_three()
{
  int v0; // r0
  uint8_t *v1; // r4
  int v2; // r0
  unsigned int v3; // r2
  unsigned int v4; // r3
  int v5; // r1

  if ( hci_cmd_handler(2u) != 3 )
  {
    v0 = hci_cmd_handler(2u);
    alloc_tx_event("end st=%d\n", v0);
  }
  if ( **(uint16_t **)off_12AEB8 < 0 && hci_cmd_handler(2u) != 3 )
    irq_disable_mmio_write((int)aKeStateGetTask_2, (int)aMmScanChannelE, 201);
  v1 = off_12AEBC;
  v2 = *(uint32_t *)off_12AEBC;
  v3 = *(uint8_t *)(*(uint32_t *)off_12AEBC + 367);
  v4 = (uint8_t)(*((uint8_t *)off_12AEBC + 10) + 1);
  *((uint8_t *)off_12AEBC + 10) = v4;
  if ( v3 <= v4 || v1[11] )
  {
    tx_process_jump((char *)(v2 - 12));
    v5 = *((uint16_t *)v1 + 4);
    if ( v1[11] )
    {
      rf_execute_cmd(0, v5);
      v1[11] = 0;
    }
    else
    {
      mac_write_header_word(2050, v5, 2);
    }
    hci_cmd_preprocess(2u, 0);
    return 0;
  }
  else
  {
    process_entry_list();
    return 0;
  }
}
