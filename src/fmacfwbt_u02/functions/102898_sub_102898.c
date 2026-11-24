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


extern uint32_t dword_10293C;
extern uint32_t off_102930;
extern uint32_t off_102934;
extern uint32_t off_102938;

// gpio_init @ 0x102898, size 152 bytes
int  gpio_init(uint16_t *a1, int a2)
{
  uint8_t *v3; // r0
  int v4; // r1
  int v5; // r1
  unsigned int v6; // r2
  int a5; // r3
  int result; // r0
  int v9; // r1
  int v10; // r3

  if ( a2 )
    return ke_event_schedule_1("\x9B\x87%s: radio %d does not exist\n", aPhySetChannel, a2);
  if ( *(uint8_t *)off_102930 )
    goto LABEL_4;
  v3 = (uint8_t *)off_102938;
  v4 = *((uint16_t *)off_102938 + 18);
  *(uint32_t *)off_102934 &= ~0x200u;
  if ( v4 != *a1 )
    goto LABEL_4;
  a5 = *((uint8_t *)a1 + 9);
  v5 = a1[1];
  if ( v3[45] != a5 )
  {
    v6 = a1[2];
    goto LABEL_5;
  }
  v6 = a1[2];
  if ( *((uint16_t *)v3 + 19) != v5
    || *((uint16_t *)v3 + 20) != v6
    || *((uint16_t *)v3 + 21) != a1[3] )
  {
    goto LABEL_5;
  }
  if ( hci_cmd_send_short(7u) == 1 || hci_cmd_send_short(6u) == 3 )
  {
LABEL_4:
    v5 = a1[1];
    v6 = a1[2];
    LOBYTE(a5) = *((uint8_t *)a1 + 9);
LABEL_5:
    format_log_message(*(uint8_t *)a1, v5, v6, *((uint8_t *)a1 + 1), a5, 0);
    result = *(uint32_t *)a1;
    v9 = *((uint32_t *)a1 + 1);
    v10 = dword_10293C;
    *(uint32_t *)dword_10293C = *(uint32_t *)a1;
    *(uint32_t *)(v10 + 4) = v9;
    *(uint16_t *)(v10 + 8) = a1[4];
    return result;
  }
  return ke_event_schedule_1("\x9D\x87%s: Setting same channel, do nothing\n", aPhySetChannel);
}
