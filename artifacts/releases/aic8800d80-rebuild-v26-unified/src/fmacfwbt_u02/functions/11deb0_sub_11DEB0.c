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

extern uint32_t off_11E014;
extern uint32_t off_11E034;
extern uint32_t dword_11E040;
extern uint32_t off_11E018;
extern uint32_t off_11E02C;
extern uint32_t dword_11E030;
extern uint32_t dword_11E020;
extern uint32_t off_11E024;
extern uint32_t off_11E028;
extern uint32_t off_11E038;
extern uint32_t off_11E03C;

// sub_11DEB0 @ 0x11deb0, size 356 bytes
int  sub_11DEB0(int inited)
{
  uint32_t *v1; // r7
  uint8_t *v2; // r9
  int v3; // r8
  int v4; // r6
  int i; // r5
  int v6; // r3
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r2
  int v12; // r3
  int v13; // r4
  int result; // r0
  int v15; // r1
  int v16; // r2
  void ( *v17)(uint32_t); // r2
  void *v18; // r3
  uint32_t *v19; // r5
  int v20; // [sp+14h] [bp-8h]

  v1 = off_11E014;
  v2 = off_11E034;
  v3 = dword_11E040;
  v4 = inited;
  for ( i = 0; ; ++i )
  {
    v13 = fw_version_check_n_38(inited);
    *v1 = 0x10000;
    result = sub_12D374(0x80000);
    if ( !v13 )
      break;
    if ( !v4 )
    {
      v6 = (uint8_t)v2[192];
      if ( v2[192] )
      {
        v6 = *(uint32_t *)off_11E018;
        if ( *(uint32_t *)off_11E018 > 0x80000u || i > 31 )
          return irq_nesting_or(0x80000);
      }
      else if ( i > 3 )
      {
        return irq_nesting_or(0x80000);
      }
    }
    v7 = sub_12F754(result, v15, v16, v6);
    if ( !v7 || (v7 = sub_13A5A0(v7, v8, v9, v10)) == 0 )
    {
      v18 = off_11E02C;
      *((uint8_t *)off_11E02C + 69) = 1;
      sub_13A5A0(v7, v8, 1, v18);
      return feature_guard_sdio(1024, dword_11E030);
    }
    v11 = *(uint32_t *)(v13 + 20);
    if ( v11 != v3 )
      sub_12ECB0(dword_11E020, v13, v11);
    chan_get_curr_id(v13);
    inited = bt_hci_cmd_handler(v13);
    if ( inited )
    {
      if ( inited != 1 )
        goto LABEL_10;
    }
    else
    {
      inited = sub_139FF8(v13);
      if ( inited )
        goto LABEL_10;
    }
    inited = sub_11EEE0(v13);
LABEL_10:
    v12 = **(uint8_t **)off_11E024;
    switch ( v12 )
    {
      case 2:
        goto LABEL_22;
      case 4:
        if ( !*(uint32_t *)off_11E028 || *(uint32_t *)(*(uint32_t *)off_11E028 + 12) != v13 || (*(uint8_t *)(v13 + 16) & 1) == 0 )
        {
LABEL_22:
          inited = init_alloc_0x200000();
          continue;
        }
        v20 = *(uint32_t *)off_11E028;
        sub_12D4F8(off_11E028);
        v17 = *(void ( **)(uint32_t))(v20 + 4);
        *(uint8_t *)(v20 + 16) = 0;
        if ( v17 )
          v17(*(uint32_t *)(v20 + 8));
        inited = rx_desc_status_get(v13);
        break;
      case 3:
        inited = fw_subsystem_init();
        break;
    }
  }
  if ( *((uint8_t *)off_11E034 + 192) )
  {
    v19 = off_11E038;
    if ( *((uint8_t *)off_11E038 + 33) )
    {
      result = log_queue_push2(*((uint32_t *)off_11E038 + 4), *((uint32_t *)off_11E038 + 5), *((uint32_t *)off_11E038 + 6));
      v19[5] = 0;
      v19[7] = 0;
      v19[4] = 0;
      v19[6] = 0;
      *((uint8_t *)v19 + 33) = 0;
    }
  }
  *(uint32_t *)off_11E03C |= 0x10000u;
  return result;
}

