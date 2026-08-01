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

// alloc_kernel_message @ 0x120314, size 210 bytes
int  alloc_kernel_message(int a1)
{
  uint8_t *v2; // r5
  int v3; // r0
  int v4; // r1
  int v5; // r0
  char v6; // r1
  int v7; // r3
  int v8; // r7
  char v10[5]; // [sp+7h] [bp-5h] BYREF

  v2 = (uint8_t *)ke_msg_alloc(88, 13, 0, 3);
  v3 = *(uint8_t *)(a1 + 107);
  v10[0] = -1;
  sta_get_by_index(v3);
  v4 = *(uint32_t *)(a1 + 1216);
  *(uint32_t *)(a1 + 412) = *(uint32_t *)(a1 + 1212);
  *(uint32_t *)(a1 + 416) = v4;
  *(uint16_t *)(a1 + 420) = *(uint16_t *)(a1 + 1220);
  *(uint8_t *)(a1 + 464) = 0;
  rf_temperature_comp(a1);
  v5 = scan_find_empty_slot(a1 + 1212, v10);
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
        sta_lookup_by_bss();
        *((uint8_t *)off_1203F0 + 9) = 1;
      }
    }
    return ke_msg_send(v2);
  }
  *(uint8_t *)(a1 + 146) = v7;
  if ( !v5 )
  {
    v8 = *(uint8_t *)(a1 + 116);
    sta_lookup_by_bss();
    fault_handler(a1 + 48);
    unknown_worker(a1 + 24, *((uint32_t *)off_1203EC + 4) + *(uint32_t *)(dword_1203E8 + 696 * v8 + 8));
    *(uint8_t *)(a1 + 128) = 0;
    *(uint8_t *)(a1 + 147) = 1;
    return ke_msg_send(v2);
  }
  send_fw_cmd(a1);
  return ke_msg_send(v2);
}

