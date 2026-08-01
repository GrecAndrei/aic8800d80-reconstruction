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

extern uint32_t dword_102940;
extern uint32_t dword_102944;
extern uint32_t off_102930;
extern uint32_t off_102938;
extern uint32_t off_102934;
extern uint32_t dword_102948;

// gpio_init @ 0x102898, size 152 bytes
int  gpio_init(uint16_t *a1, int a2)
{
  uint8_t *v3; // r0
  int v4; // r1
  int v5; // r1
  int v6; // r2
  int v7; // r2
  int v8; // r0
  int v9; // r1

  if ( a2 )
  {
    v7 = a2;
    v8 = dword_102940;
    v9 = dword_102944;
  }
  else
  {
    if ( *(uint8_t *)off_102930 )
      goto LABEL_4;
    v3 = (uint8_t *)off_102938;
    v4 = *((uint16_t *)off_102938 + 18);
    *(uint32_t *)off_102934 &= ~0x200u;
    if ( v4 != *a1 )
      goto LABEL_4;
    v5 = a1[1];
    if ( v3[45] != *((uint8_t *)a1 + 9) )
    {
      v6 = a1[2];
      goto LABEL_5;
    }
    v6 = a1[2];
    if ( *((uint16_t *)v3 + 19) != v5
      || *((uint16_t *)v3 + 20) != v6
      || *((uint16_t *)v3 + 21) != a1[3] )
    {
LABEL_5:
      format_log_message(*(uint8_t *)a1, v5, v6, *((uint8_t *)a1 + 1));
    }
    if ( hci_cmd_send_short(7) == 1 || hci_cmd_send_short(6) == 3 )
    {
LABEL_4:
      v5 = a1[1];
      v6 = a1[2];
      goto LABEL_5;
    }
    v9 = dword_102944;
    v8 = dword_102948;
  }
  return ke_event_schedule(v8, v9, v7);
}

