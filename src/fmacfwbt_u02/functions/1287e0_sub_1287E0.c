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

extern uint32_t off_128AA8;
extern uint32_t dword_128AA0;
extern uint32_t dword_128A90;
extern uint32_t dword_128A8C;
extern uint32_t off_128A78;
extern uint32_t dword_128A7C;
extern uint32_t dword_128A88;
extern uint32_t off_128A80;
extern uint32_t dword_128A94;
extern uint32_t dword_128A98;
extern uint32_t dword_128A9C;
extern uint32_t dword_128AA4;
extern uint32_t dword_128A84;

// get_entry_by_index @ 0x1287e0, size 664 bytes
int  get_entry_by_index(int a1)
{
  int16_t **v1; // r9
  int v2; // r8
  int v3; // r10
  uint8_t *v4; // r6
  int v6; // r5
  char *v7; // r7
  int v8; // r1
  int v9; // r3
  int v10; // r2
  int v11; // r3
  int v12; // r4
  int v13; // r3
  int v14; // r5
  uint8_t *v15; // r3
  int v16; // r0
  int v17; // r3
  char *v18; // r4
  int v19; // r2
  int v20; // r3
  int v22; // r1
  int16_t *v23; // r2
  unsigned int v24; // r3
  int v25; // r3
  uint32_t *v26; // r0
  int v27; // r1
  int v28; // r3
  int v29; // r2
  char *v30; // r1
  int v31; // r0

  v1 = (int16_t **)off_128AA8;
  v2 = dword_128AA0;
  v3 = 1320 * a1;
  v4 = *(uint8_t **)(dword_128AA0 + 1320 * a1 + 72);
  if ( **(int16_t **)off_128AA8 < 0 && !v4 )
    mmio_irq_clear(dword_128A90, dword_128A8C, 3149);
  v6 = v2 + 1320 * a1;
  v7 = (char *)off_128A78;
  state_check_feature(256, dword_128A7C);
  check_abort_flag_3(v7 + 16, v3 + 76 + v2);
  v9 = *(uint8_t *)(v6 + 85);
  *(uint8_t *)(v6 + 85) = v9 & 0xFE;
  v10 = v9 << 30;
  if ( (v9 & 2) != 0 )
  {
    v11 = (uint8_t)(v7[91] - 1);
    v7[91] = v11;
    if ( !v11 && (v7[88] & 0x40) != 0 )
    {
      ke_event_schedule(dword_128A88, v8, v10);
      rf_tx_packet(*((uint32_t *)v7 + 20));
    }
  }
  v12 = v2 + 1320 * a1;
  *(uint8_t *)(v12 + 85) = 0;
  *(uint32_t *)(v12 + 72) = 0;
  v13 = v4[16];
  v14 = (uint8_t)(v4[25] - 1);
  v4[25] = v14;
  if ( v13 )
  {
    if ( v4[27] == *(uint8_t *)(v12 + 107) )
    {
      lookup_conn_table(v2 + v3);
      v14 = v4[25];
      v4[27] = -1;
      if ( v14 )
        return remove_entry_by_owner((int)v4);
    }
    else
    {
      v15 = (uint8_t *)off_128A80;
      while ( 1 )
      {
        if ( v15[24] != 255 )
        {
          v16 = v15[27];
          if ( v16 != 255 )
            break;
        }
        v15 += 28;
        if ( (uint8_t *)((char *)off_128A80 + 84) == v15 )
          goto LABEL_10;
      }
      v26 = (uint32_t *)(v2 + 1320 * v16);
      if ( (uint8_t *)v26[18] == v4 )
      {
LABEL_10:
        if ( !v14 )
          goto LABEL_26;
        return remove_entry_by_owner((int)v4);
      }
      if ( v14 )
      {
        scan_state_process(v26);
        LOBYTE(v14) = v4[25];
        if ( (uint8_t)v14 )
          return remove_entry_by_owner((int)v4);
      }
      else
      {
        lookup_conn_table((int)v26);
        v14 = v4[25];
        if ( v4[25] )
          return remove_entry_by_owner((int)v4);
      }
    }
LABEL_26:
    check_abort_flag_3(dword_128A94, v4);
    v4[16] = v14;
    v23 = *v1;
    v24 = (uint8_t)(v7[90] - 1);
    v7[90] = v24;
    if ( *v23 < 0 && v24 > 1 )
    {
      mmio_irq_clear(dword_128A98, dword_128A8C, 3210);
      v24 = (uint8_t)v7[90];
    }
    if ( v24 )
    {
      zero_struct(dword_128A9C);
      v25 = dword_128AA0;
      v22 = dword_128AA0 + 5280;
      do
      {
        *(uint8_t *)(v25 + 85) &= ~1u;
        v25 += 1320;
      }
      while ( v22 != v25 );
      if ( !*((uint32_t *)v7 + 20) )
        hci_acl_buf_alloc();
    }
    if ( *((uint8_t **)v7 + 10) != v4 )
    {
      if ( *((uint8_t **)v7 + 11) != v4 )
        goto LABEL_30;
      v27 = v4[24];
      v28 = v27 + 1;
      if ( v27 == 2 )
      {
        if ( *((uint8_t *)off_128A80 + 24) != 255 )
        {
          v28 = 0;
          v29 = 0;
          goto LABEL_57;
        }
        v28 = 1;
      }
      else
      {
        v29 = 8 * v28;
        if ( *((uint8_t *)off_128A80 + 28 * v28 + 24) != 255 )
          goto LABEL_57;
        v28 = v27 + 2;
        if ( v27 == 1 )
          v28 = 0;
      }
      v29 = 8 * v28;
      if ( *((uint8_t *)off_128A80 + 28 * v28 + 24) == 255 )
      {
        v30 = 0;
LABEL_51:
        v31 = dword_128AA4;
        *((uint32_t *)v7 + 11) = v30;
        ke_event_schedule(v31, v30, v29);
        goto LABEL_30;
      }
LABEL_57:
      v30 = (char *)off_128A80 + 4 * (v29 - v28);
      goto LABEL_51;
    }
    v17 = (uint8_t)v7[90];
    *((uint32_t *)v7 + 10) = 0;
    if ( !v17 || (v18 = *((char **)v7 + 11)) != 0 )
    {
LABEL_30:
      if ( !v4[25] )
        goto LABEL_21;
      return remove_entry_by_owner((int)v4);
    }
    ke_event_schedule(dword_128A84, v22, 0);
    v19 = v4[24];
    v20 = v19 + 1;
    if ( v19 == 2 )
    {
      if ( *((uint8_t *)off_128A80 + 24) != 255 )
      {
        v20 = 0;
        goto LABEL_61;
      }
      v20 = 1;
    }
    else
    {
      if ( *((uint8_t *)off_128A80 + 28 * v20 + 24) != 255 )
        goto LABEL_61;
      v20 = v19 + 2;
      if ( v19 == 1 )
        v20 = 0;
    }
    if ( *((uint8_t *)off_128A80 + 28 * v20 + 24) == 255 )
    {
LABEL_19:
      set_tx_buffer((int)v18);
      v14 = v4[25];
      goto LABEL_20;
    }
LABEL_61:
    v18 = (char *)off_128A80 + 28 * v20;
    goto LABEL_19;
  }
LABEL_20:
  if ( v14 )
    return remove_entry_by_owner((int)v4);
LABEL_21:
  lookup_7byte_channel(v4[24]);
  return remove_entry_by_owner((int)v4);
}

