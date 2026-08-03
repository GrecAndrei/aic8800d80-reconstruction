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

extern uint32_t off_1203F0;
extern uint32_t off_1203EC;
extern uint32_t dword_1203E8;

// sub_120314 @ 0x120314, size 210 bytes
int  sub_120314(int a1)
{
  uint8_t *v2; // r5
  int v3; // r0
  int v4; // r1
  int v5; // r0
  char v6; // r1
  int v7; // r3
  int v8; // r7
  char v10[5]; // [sp+7h] [bp-5h] BYREF

  v2 = (uint8_t *)sub_12C92C(88, 13, 0, 3);
  v3 = *(uint8_t *)(a1 + 107);
  v10[0] = -1;
  sub_1285BC(v3);
  v4 = *(uint32_t *)(a1 + 1216);
  *(uint32_t *)(a1 + 412) = *(uint32_t *)(a1 + 1212);
  *(uint32_t *)(a1 + 416) = v4;
  *(uint16_t *)(a1 + 420) = *(uint16_t *)(a1 + 1220);
  *(uint8_t *)(a1 + 464) = 0;
  message_dispatch_408(a1);
  v5 = sub_127D34(a1 + 1212, v10);
  v6 = v10[0];
  v2[1] = v5;
  v2[2] = v6;
  *v2 = *(uint8_t *)(a1 + 107);
  v7 = *(uint8_t *)(a1 + 106);
  if ( *(uint8_t *)(a1 + 106) )
  {
    if ( v7 == 2 )
    {
      *(uint8_t *)(a1 + 231) = 0;
      if ( !v5 )
      {
        sub_128888();
        *((uint8_t *)off_1203F0 + 9) = 1;
      }
    }
    return sdio_buffer_prepare_n_4e8(v2);
  }
  *(uint8_t *)(a1 + 146) = v7;
  if ( !v5 )
  {
    v8 = *(uint8_t *)(a1 + 116);
    sub_128888();
    timestamp_remove(a1 + 48);
    timestamp_update(a1 + 24, *((uint32_t *)off_1203EC + 4) + *(uint32_t *)(dword_1203E8 + 696 * v8 + 8));
    *(uint8_t *)(a1 + 128) = 0;
    *(uint8_t *)(a1 + 147) = 1;
    return sdio_buffer_prepare_n_4e8(v2);
  }
  send_msg_to_host_c43(a1);
  return sdio_buffer_prepare_n_4e8(v2);
}

