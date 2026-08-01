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

extern uint32_t dword_12286C;
extern uint32_t off_122870;
extern uint32_t off_122878;
extern uint32_t off_12287C;
extern uint32_t off_122874;
extern uint32_t off_122880;

// read_config_byte @ 0x122794, size 214 bytes
// Doc: sub_12227A0 [unknown]: Helper: save r0 in r4 and call with r4,r5,r6,lr
// sub_12227A0 [unknown]: Helper: save r0 in r4 and call with r4,r5,r6,lr
char * read_config_byte(char *result)
{
  int v1; // r4
  int v2; // r6
  int v3; // r5
  unsigned int v4; // r3
  int v5; // r2
  uint8_t *v6; // r1
  unsigned int v7; // r2
  uint8_t *v8; // r3
  unsigned int v9; // r3

  if ( result[108] )
  {
    v1 = (int)result;
    if ( result[146] && result[148] )
    {
      v9 = (uint8_t)(result[146] - 1);
      result[146] = v9;
      if ( v9 <= 1 )
        return (char *)alloc_kernel_message((int)result);
      if ( v9 == 2 )
        hci_send_cmd_0x59(result[107], 0);
    }
    v2 = *(uint32_t *)(v1 + 36);
    v3 = *(uint32_t *)(dword_12286C + 696 * *(uint8_t *)(v1 + 116) + 8) + v2;
    if ( v1 != *((uint32_t *)off_122870 + 8)
      || (v8 = off_122878, *(uint32_t *)(v1 + 36) = v3, !v8[189]) && **(uint8_t **)off_12287C != 2 )
    {
      unknown_worker(v1 + 24, v3);
    }
    configure_mmio(v1);
    llc_get_conn_idx(v1, *(uint32_t *)(v1 + 136) + v2);
    result = (char *)rx_dispatch_frame(v1, v2, v3);
    if ( !result )
    {
      v4 = (uint8_t)(*(uint8_t *)(v1 + 128) + 1);
      v5 = *(uint32_t *)(v1 + 4) | 1;
      v6 = *(uint8_t **)off_122874;
      *(uint8_t *)(v1 + 128) = v4;
      *(uint32_t *)(v1 + 4) = v5;
      v7 = *v6;
      if ( v4 > v7 )
      {
        return (char *)phy_channel_is_5g(*(uint8_t *)(v1 + 116), (int)off_122880, v1);
      }
      else if ( v4 == v7 )
      {
        return (char *)tx_enqueue_frame(v1);
      }
    }
  }
  return result;
}

