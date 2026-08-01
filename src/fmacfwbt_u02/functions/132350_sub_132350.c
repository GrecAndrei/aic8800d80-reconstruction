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

extern uint32_t off_1323E0;

// llm_event_wait_next @ 0x132350, size 144 bytes
int  llm_event_wait_next(int a1, uint8_t *a2, unsigned int a3, int16_t a4)
{
  uint16_t *v7; // r7
  int *v9; // r0
  char v10; // r1
  int v11; // r3

  if ( hci_cmd_send_short(5u) == 1 )
    return 2;
  v7 = off_1323E0;
  if ( *(uint32_t *)off_1323E0 )
  {
    if ( *a2 )
    {
      *(uint32_t *)off_1323E0 |= 1 << a2[1];
      hci_evt_alloc_send(5144, a4, a3);
      return 0;
    }
  }
  else if ( !*a2 )
  {
    hci_evt_alloc_send(5144, a4, a3);
    return 0;
  }
  v9 = (int *)bt_buf_alloc(34, 0, a3, 1u);
  v10 = a2[1];
  if ( *a2 )
    v11 = (1 << v10) | *(uint32_t *)v7;
  else
    v11 = *(uint32_t *)v7 & ~(1 << v10);
  *(uint32_t *)v7 = v11;
  v7[4] = a4;
  *v9 = v11 == 0;
  hci_evt_send((int)v9);
  hci_cmd_send(a3, 1);
  return 0;
}

