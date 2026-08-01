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

extern uint32_t dword_134A8C;

// bt_free_hci_buffer @ 0x134a6c, size 30 bytes
int  bt_free_hci_buffer(int a1, int a2)
{
  if ( (a2 & 0x810000) == 0x10000 )
    event_dispatch(dword_134A8C);
  return bt_init_hci_buffer();
}

