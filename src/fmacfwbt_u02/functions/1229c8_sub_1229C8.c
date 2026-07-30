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

// sub_1229C8 @ 0x1229c8, size 214 bytes
// Doc: sub_12229D4 [unknown]: Generic helper function
// sub_12229D4 [unknown]: Generic helper function
char * sub_1229C8(char *result)
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
        return (char *)ipc_msg_alloc((int)result);
      if ( v9 == 2 )
        sub_122810(result[107], 0);
    }
    v2 = *(uint32_t *)(v1 + 36);
    v3 = *(uint32_t *)(dword_122AA0 + 696 * *(uint8_t *)(v1 + 116) + 8) + v2;
    if ( v1 != *((uint32_t *)off_122AA4 + 8)
      || (v8 = off_122AAC, *(uint32_t *)(v1 + 36) = v3, !v8[189]) && **(uint8_t **)off_122AB0 != 2 )
    {
      timestamp_update_4f60(v1 + 24, v3);
    }
    mmio_reg_write_helper(v1);
    sub_12A4A8(v1, *(uint32_t *)(v1 + 136) + v2);
    result = (char *)sub_128160(v1, v2, v3);
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
        return (char *)sub_1194CC(*(uint8_t *)(v1 + 116), dword_122AB4, v1);
      }
      else if ( v4 == v7 )
      {
        return (char *)bt_hci_cmd_dispatch(v1);
      }
    }
  }
  return result;
}

