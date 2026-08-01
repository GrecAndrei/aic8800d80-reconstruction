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

extern uint32_t off_13F164;
extern uint32_t dword_13F168;
extern uint32_t dword_13F170;
extern uint32_t dword_13F16C;
extern uint32_t dword_13F178;
extern uint32_t dword_13F174;

// ble_ll_conn_sm_get @ 0x13f0bc, size 168 bytes
// Doc: ble_ll_conn_sm_get [mac]: Indexed lookup into 0x2b8-stride table keyed by r0
// ble_ll_conn_sm_get [mac]: Indexed lookup into 0x2b8-stride table keyed by r0
int  ble_ll_conn_sm_get(int a1)
{
  int16_t **v1; // r7
  int v2; // r6
  int16_t *v3; // r8
  unsigned int v4; // r5
  unsigned int v6; // r0
  int v7; // r0
  uint32_t v9[10]; // [sp+0h] [bp-28h] BYREF

  v1 = (int16_t **)off_13F164;
  v2 = dword_13F168;
  v3 = *(int16_t **)off_13F164;
  v4 = *(uint32_t *)(dword_13F168 + 696 * a1 + 340);
  if ( **(int16_t **)off_13F164 < 0 && !v4 )
  {
    mmio_clear_register(dword_13F170, dword_13F16C, 3297);
    v3 = *v1;
  }
  v6 = bt_state_handler(v4);
  *(uint16_t *)(v4 + 184) = v6;
  if ( *v3 < 0 )
  {
    if ( !v6 )
    {
      mmio_clear_register(dword_13F178, dword_13F16C, 3301);
      if ( **v1 >= 0 )
        goto LABEL_3;
      v6 = *(uint16_t *)(v4 + 184);
    }
    if ( v6 > 0xA )
      mmio_clear_register(dword_13F174, dword_13F16C, 3302);
  }
LABEL_3:
  process_list_entries(v4);
  v7 = scan_process_list(v4, v9);
  bt_clr_flag(v7);
  *(uint8_t *)(v2 + 696 * a1 + 350) |= 1u;
  return 696;
}

