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

extern uint32_t dword_122C94;
extern uint32_t off_122C84;
extern uint32_t dword_122C90;
extern uint32_t dword_122C8C;
extern uint32_t dword_122C88;

// process_hci_command_status @ 0x122bf0, size 148 bytes
int  process_hci_command_status(int a1, int a2, int a3, int a4)
{
  int v4; // r9
  int v6; // r5
  int v9; // r8
  char v10; // r1
  int v11; // r2
  int v12; // r3

  v4 = dword_122C94;
  v6 = *(uint8_t *)(a2 + 5);
  if ( **(int16_t **)off_122C84 < 0 && *(uint8_t *)(dword_122C94 + 1320 * v6 + 106) )
    mmio_irq_clear(dword_122C90, dword_122C8C, 2660);
  v9 = v4 + 1320 * v6;
  v10 = *(uint8_t *)(a2 + 4);
  v11 = *(uint8_t *)(v9 + 149);
  *(uint32_t *)(v9 + 1228) = *(uint32_t *)a2;
  *(uint8_t *)(v9 + 1227) = v10;
  if ( v11 == 1 )
  {
    ke_event_set_lock(1320 * v6 + 152 + v4);
    *(uint8_t *)(v9 + 149) = 0;
  }
  state_check_feature(256, dword_122C88);
  hci_evt_alloc_send(98, a4, a3, v12);
  return 0;
}

