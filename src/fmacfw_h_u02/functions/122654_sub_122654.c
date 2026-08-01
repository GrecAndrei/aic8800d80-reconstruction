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

extern uint32_t dword_12272C;
extern uint32_t off_122730;
extern uint32_t off_122738;
extern uint32_t off_12273C;
extern uint32_t off_122734;
extern uint32_t off_122740;

// ll_get_state @ 0x122654, size 214 bytes
char * ll_get_state(char *result)
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
        return (char *)alloc_ctrl_block((int)result);
      if ( v9 == 2 )
        send_hci_event(result[107], 0);
    }
    v2 = *(uint32_t *)(v1 + 36);
    v3 = *(uint32_t *)(dword_12272C + 696 * *(uint8_t *)(v1 + 116) + 8) + v2;
    if ( v1 != *((uint32_t *)off_122730 + 8)
      || (v8 = off_122738, *(uint32_t *)(v1 + 36) = v3, !v8[189]) && **(uint8_t **)off_12273C != 2 )
    {
      mem_copy_util(v1 + 24, v3);
    }
    mmio_reg_addr(v1);
    bt_scan_poll(v1, *(uint32_t *)(v1 + 136) + v2);
    result = (char *)cfm_dword_get(v1, v2, v3);
    if ( !result )
    {
      v4 = (uint8_t)(*(uint8_t *)(v1 + 128) + 1);
      v5 = *(uint32_t *)(v1 + 4) | 1;
      v6 = *(uint8_t **)off_122734;
      *(uint8_t *)(v1 + 128) = v4;
      *(uint32_t *)(v1 + 4) = v5;
      v7 = *v6;
      if ( v4 > v7 )
      {
        return (char *)phy_is_channel_valid(*(uint8_t *)(v1 + 116), (int)off_122740, v1);
      }
      else if ( v4 == v7 )
      {
        return (char *)wifi_disable_action(v1);
      }
    }
  }
  return result;
}

