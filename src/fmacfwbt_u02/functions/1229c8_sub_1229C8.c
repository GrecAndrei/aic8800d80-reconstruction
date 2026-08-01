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

extern uint32_t dword_122AA0;
extern uint32_t off_122AA4;
extern uint32_t off_122AAC;
extern uint32_t off_122AB0;
extern uint32_t off_122AA8;
extern uint32_t dword_122AB4;

// bt_state_flags_check @ 0x1229c8, size 214 bytes
// Doc: sub_12229D4 [unknown]: Generic helper function
// sub_12229D4 [unknown]: Generic helper function
char * bt_state_flags_check(char *result)
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
        return (char *)alloc_buffer((int)result);
      if ( v9 == 2 )
        mmio_write_phy(result[107], 0);
    }
    v2 = *(uint32_t *)(v1 + 36);
    v3 = *(uint32_t *)(dword_122AA0 + 696 * *(uint8_t *)(v1 + 116) + 8) + v2;
    if ( v1 != *((uint32_t *)off_122AA4 + 8)
      || (v8 = off_122AAC, *(uint32_t *)(v1 + 36) = v3, !v8[189]) && **(uint8_t **)off_122AB0 != 2 )
    {
      ke_event_lock(v1 + 24, v3);
    }
    wlc_bmac_write_shm(v1);
    bt_conn_event_process(v1, *(uint32_t *)(v1 + 136) + v2);
    result = (char *)hci_command_handler(v1, v2, v3);
    if ( !result )
    {
      v4 = (uint8_t)(*(uint8_t *)(v1 + 128) + 1);
      v5 = *(uint32_t *)(v1 + 4) | 1;
      v6 = *(uint8_t **)off_122AA8;
      *(uint8_t *)(v1 + 128) = v4;
      *(uint32_t *)(v1 + 4) = v5;
      v7 = *v6;
      if ( v4 > v7 )
      {
        return (char *)phy_channel_validate(*(uint8_t *)(v1 + 116), dword_122AB4, v1);
      }
      else if ( v4 == v7 )
      {
        return (char *)bt_power_state(v1);
      }
    }
  }
  return result;
}

