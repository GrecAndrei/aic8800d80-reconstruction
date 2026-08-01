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

extern uint32_t off_128D48;
extern uint32_t dword_128D4C;

// get_current_entry_owner @ 0x128cf8, size 80 bytes
int  get_current_entry_owner(int a1)
{
  uint8_t *v1; // r6
  int v2; // r4
  uint8_t *v4; // r0

  v1 = (uint8_t *)off_128D48;
  v2 = dword_128D4C + 1320 * *((uint8_t *)off_128D48 + 16);
  if ( *(uint32_t *)(v2 + 72) )
  {
    get_entry_by_index(*((uint8_t *)off_128D48 + 16));
  }
  else
  {
    v4 = (uint8_t *)bt_buf_alloc(5143, 5, 5, 2);
    *v4 = 1;
    v4[1] = *(uint8_t *)(v2 + 107);
    hci_evt_send(v4);
  }
  return update_entries_from_config(v1[16], a1);
}

