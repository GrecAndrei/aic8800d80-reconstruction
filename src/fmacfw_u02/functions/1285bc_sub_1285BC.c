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


extern uint32_t dword_128870;
extern uint32_t dword_128878;
extern uint32_t dword_12887C;
extern uint32_t off_128854;
extern uint32_t off_12885C;
extern uint32_t off_128884;

// sta_get_by_index @ 0x1285bc, size 664 bytes
int  sta_get_by_index(int a1)
{
  uint16_t **v1; // r9
  int v2; // r8
  int v3; // r10
  int v4; // r6
  int v6; // r5
  uint8_t *v7; // r7
  char v8; // r3
  int v9; // r3
  int v10; // r4
  int v11; // r3
  int v12; // r5
  uint8_t *v13; // r3
  int v14; // r0
  int v15; // r3
  uint32_t *v16; // r4
  int v17; // r2
  int v18; // r3
  uint16_t *v20; // r2
  unsigned int v21; // r3
  int v22; // r3
  int v23; // r1
  uint32_t *v24; // r0
  int v25; // r1
  int v26; // r3
  int v27; // r2
  char *v28; // r1

  v1 = (uint16_t **)off_128884;
  v2 = dword_12887C;
  v3 = 1320 * a1;
  v4 = *(uint32_t *)(dword_12887C + 1320 * a1 + 72);
  if ( **(uint16_t **)off_128884 < 0 && !v4 )
    mmio_clear_register((int)aCtxtNull, (int)aChanCtxtUnlink, 3149);
  v6 = v2 + 1320 * a1;
  v7 = (uint8_t *)off_128854;
  check_status_bits(
    256,
    "chan unlink: %d,%d,%d,%d,%d\r\n",
    *(uint8_t *)(v4 + 25),
    *((uint8_t *)off_128854 + 91),
    *((uint8_t *)off_128854 + 90),
    *(uint8_t *)(v6 + 85),
    *(uint8_t *)(v4 + 16));
  cmd_handler_c((int)(v7 + 16), (uint32_t *)(v3 + 76 + v2));
  v8 = *(uint8_t *)(v6 + 85);
  *(uint8_t *)(v6 + 85) = v8 & 0xFE;
  if ( (v8 & 2) != 0 )
  {
    v9 = (uint8_t)(v7[91] - 1);
    v7[91] = v9;
    if ( !v9 && (v7[88] & 0x40) != 0 )
    {
      event_dispatch(aUnlinkFixUntil);
      dma_setup_transfer(*((uint32_t *)v7 + 20));
    }
  }
  v10 = v2 + 1320 * a1;
  *(uint8_t *)(v10 + 85) = 0;
  *(uint32_t *)(v10 + 72) = 0;
  v11 = *(uint8_t *)(v4 + 16);
  v12 = (uint8_t)(*(uint8_t *)(v4 + 25) - 1);
  *(uint8_t *)(v4 + 25) = v12;
  if ( v11 )
  {
    if ( *(uint8_t *)(v4 + 27) == *(uint8_t *)(v10 + 107) )
    {
      lld_evt_update(v2 + v3);
      v12 = *(uint8_t *)(v4 + 25);
      *(uint8_t *)(v4 + 27) = -1;
      if ( v12 )
        return get_control_byte(v4);
    }
    else
    {
      v13 = (uint8_t *)off_12885C;
      while ( 1 )
      {
        if ( v13[24] != 255 )
        {
          v14 = v13[27];
          if ( v14 != 255 )
            break;
        }
        v13 += 28;
        if ( (uint8_t *)((char *)off_12885C + 84) == v13 )
          goto LABEL_10;
      }
      v24 = (uint32_t *)(v2 + 1320 * v14);
      if ( v24[18] == v4 )
      {
LABEL_10:
        if ( !v12 )
          goto LABEL_26;
        return get_control_byte(v4);
      }
      if ( v12 )
      {
        lld_evt_schedule(v24);
        LOBYTE(v12) = *(uint8_t *)(v4 + 25);
        if ( (uint8_t)v12 )
          return get_control_byte(v4);
      }
      else
      {
        lld_evt_update((int)v24);
        v12 = *(uint8_t *)(v4 + 25);
        if ( *(uint8_t *)(v4 + 25) )
          return get_control_byte(v4);
      }
    }
LABEL_26:
    cmd_handler_c(dword_128870, (uint32_t *)v4);
    *(uint8_t *)(v4 + 16) = v12;
    v20 = *v1;
    v21 = (uint8_t)(v7[90] - 1);
    v7[90] = v21;
    if ( *v20 < 0 && v21 > 1 )
    {
      mmio_clear_register((int)aChanEnvNbSched, (int)aChanCtxtUnlink, 3210);
      v21 = v7[90];
    }
    if ( v21 )
    {
      zero_8_bytes((uint32_t *)dword_128878);
      v22 = dword_12887C;
      v23 = dword_12887C + 5280;
      do
      {
        *(uint8_t *)(v22 + 85) &= ~1u;
        v22 += 1320;
      }
      while ( v23 != v22 );
      if ( !*((uint32_t *)v7 + 20) )
        ke_task_poll();
    }
    if ( *((uint32_t *)v7 + 10) != v4 )
    {
      if ( *((uint32_t *)v7 + 11) != v4 )
        goto LABEL_30;
      v25 = *(uint8_t *)(v4 + 24);
      v26 = v25 + 1;
      if ( v25 == 2 )
      {
        if ( *((uint8_t *)off_12885C + 24) != 255 )
        {
          v26 = 0;
          v27 = 0;
          goto LABEL_57;
        }
        v26 = 1;
      }
      else
      {
        v27 = 8 * v26;
        if ( *((uint8_t *)off_12885C + 28 * v26 + 24) != 255 )
          goto LABEL_57;
        v26 = v25 + 2;
        if ( v25 == 1 )
          v26 = 0;
      }
      v27 = 8 * v26;
      if ( *((uint8_t *)off_12885C + 28 * v26 + 24) == 255 )
      {
        v28 = nullptr;
LABEL_51:
        *((uint32_t *)v7 + 11) = v28;
        event_dispatch("unlink replace sw ctxt:%x\n", v28);
        goto LABEL_30;
      }
LABEL_57:
      v28 = (char *)off_12885C + 4 * (v27 - v26);
      goto LABEL_51;
    }
    v15 = v7[90];
    *((uint32_t *)v7 + 10) = 0;
    if ( !v15 || (v16 = *((uint32_t **)v7 + 11)) != nullptr )
    {
LABEL_30:
      if ( !*(uint8_t *)(v4 + 25) )
        goto LABEL_21;
      return get_control_byte(v4);
    }
    event_dispatch(aUnlinkSwChan);
    v17 = *(uint8_t *)(v4 + 24);
    v18 = v17 + 1;
    if ( v17 == 2 )
    {
      if ( *((uint8_t *)off_12885C + 24) != 255 )
      {
        v18 = 0;
        goto LABEL_61;
      }
      v18 = 1;
    }
    else
    {
      if ( *((uint8_t *)off_12885C + 28 * v18 + 24) != 255 )
        goto LABEL_61;
      v18 = v17 + 2;
      if ( v17 == 1 )
        v18 = 0;
    }
    if ( *((uint8_t *)off_12885C + 28 * v18 + 24) == 255 )
    {
LABEL_19:
      ctrl_register_handler(v16);
      v12 = *(uint8_t *)(v4 + 25);
      goto LABEL_20;
    }
LABEL_61:
    v16 = (uint32_t *)((char *)off_12885C + 28 * v18);
    goto LABEL_19;
  }
LABEL_20:
  if ( v12 )
    return get_control_byte(v4);
LABEL_21:
  wlc_validate_chip_queue(*(uint8_t *)(v4 + 24));
  return get_control_byte(v4);
}
