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

extern uint32_t dword_13B8C0;
extern uint32_t dword_13B8C4;
extern uint32_t dword_13B8C8;

// init_locks @ 0x13b82c, size 146 bytes
uint32_t *init_locks()
{
  uint32_t *v0; // r9
  int v1; // r5
  int v2; // r8
  unsigned int i; // r4
  uint32_t *result; // r0

  v0 = (uint32_t *)dword_13B8C0;
  clear_stats_buf((uint32_t *)dword_13B8C0);
  clear_stats_buf(v0 + 2);
  clear_stats_buf(v0 + 4);
  clear_stats_buf(v0 + 6);
  clear_stats_buf(v0 + 8);
  clear_stats_buf(v0 + 10);
  v1 = dword_13B8C4;
  v2 = dword_13B8C8;
  for ( i = 0; ; ++i )
  {
    *(uint8_t *)(v1 + 16) = -1;
    *(uint8_t *)(v1 + 26) = i;
    if ( i > 0xF )
      break;
    wlan_ioctl_handler_1((int)v0, (uint32_t *)v1);
    hci_cmd_preprocess((i << 8) & 0xFF00 | 8, 0);
LABEL_3:
    v1 += 32;
  }
  *(uint32_t *)(v1 + 28) = v2 + 268 * i;
  wlan_ioctl_handler_1((int)(v0 + 6), (uint32_t *)v1);
  result = hci_cmd_preprocess((i << 8) & 0xFF00 | 8, 0);
  if ( i != 31 )
    goto LABEL_3;
  return result;
}

