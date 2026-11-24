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


extern uint32_t dword_11E434;
extern uint32_t dword_11E440;
extern uint32_t dword_11E444;
extern uint32_t dword_11E454;
extern uint32_t off_11E41C;
extern uint32_t off_11E420;
extern uint32_t off_11E424;
extern uint32_t off_11E42C;
extern uint32_t off_11E430;
extern uint32_t off_11E438;
extern uint32_t off_11E43C;
extern uint32_t off_11E448;
extern uint32_t off_11E44C;
extern uint32_t off_11E450;
extern uint32_t off_11E4B4;
extern uint32_t off_11E4B8;

// tx_packet_start @ 0x11e188, size 810 bytes
int  tx_packet_start(int a1, int a2, int a3, uint16_t a4, int a5, int a6)
{
  uint32_t *v6; // r8
  uint8_t **v7; // r7
  int v8; // r12
  uint8_t *v9; // r5
  int v11; // r3
  int v14; // r3
  uint32_t *v15; // r0
  int v16; // r3
  int *v18; // r5
  uint32_t *v19; // r8
  uint8_t v20; // r7
  uint32_t *v21; // r0
  uint16_t *v22; // r5
  int *v23; // r9
  int v24; // r10
  int v25; // cc
  int v26; // r0
  uint32_t *v27; // r0
  int v28; // r1
  int v29; // r3
  int v30; // r0
  uint8_t *v31; // r1
  int v32; // r2
  char v33; // r10
  int v34; // r2
  int v35; // r3
  uint8_t *v36; // r5
  int v37; // r2
  int *v38; // r9
  int v39; // r0
  int v40; // r3
  int v41; // r2
  uint32_t *v42; // r0
  int v43; // r7
  int v44; // r2
  int v45; // r12
  int v46; // r2
  int *v47; // r4
  int v48; // r0
  int v49; // r3
  int v50; // r2
  int a4a; // [sp+Eh] [bp-Eh] BYREF
  int a1a[2]; // [sp+14h] [bp-8h] BYREF

  v7 = (uint8_t **)off_11E41C;
  v8 = *(uint32_t *)(a1 + 28);
  v9 = *(uint8_t **)off_11E41C;
  a1a[0] = v8;
  LOWORD(a4a) = a4;
  v11 = *v9;
  if ( v11 != 2 )
    goto LABEL_2;
  v22 = off_11E42C;
  if ( *((uint32_t *)off_11E42C + 2057) )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_11E430 = 1;
    }
    v23 = (int *)off_11E450;
    v24 = dword_11E454;
    v25 = (uint16_t)v22[4122] > 0x186u;
    ++*(uint32_t *)off_11E450;
    v26 = dword_11E434;
    if ( v25 )
      v22[4122] = 0;
    v27 = list_pop(v26);
    v28 = *(uint32_t *)off_11E438;
    v29 = (uint16_t)v22[4122];
    v6 = v27;
    v30 = *(uint32_t *)off_11E438 + 8 * v29;
    *((uint16_t *)v6 + 6) = v29;
    *(uint32_t *)(v30 + 4) = a1 + 48;
    *(uint32_t *)(v28 + 8 * v29) = v24;
    v31 = off_11E43C;
    v6[1] = v30;
    v32 = *v23;
    v33 = *((uint8_t *)v22 + 3074) + 1;
    LOBYTE(v30) = v31[3] + 1;
    v22[4122] = v29 + 1;
    *((uint8_t *)v22 + 3074) = v33;
    v31[3] = v30;
    if ( v32 )
    {
      v34 = v32 - 1;
      v35 = *(uint32_t *)off_11E430;
      *v23 = v34;
      if ( !v34 )
      {
        if ( v35 )
          __enable_irq();
      }
    }
    v11 = **v7;
    if ( v11 == 2 )
    {
      rx_packet_handler(a1a, a2, &a4a);
      v14 = **v7;
      if ( v14 != 2 )
        goto LABEL_5;
LABEL_25:
      v36 = off_11E43C;
      if ( !*((uint8_t *)off_11E43C + 2) )
        goto LABEL_6;
      v37 = v6[1];
      v6[2] = *(uint16_t *)off_11E43C + 58;
      *(uint8_t *)(v37 + 3) &= 0x3Fu;
      *((uint8_t *)v6 + 14) = v36[3];
      *v6 = 0;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_11E430 = 1;
      }
      v38 = (int *)off_11E450;
      v39 = dword_11E440;
      ++*(uint32_t *)off_11E450;
      wlan_ioctl_handler_1(v39, v6);
      rf_is_idle();
      if ( *v38 )
      {
        v40 = *v38 - 1;
        v41 = *(uint32_t *)off_11E430;
        *v38 = v40;
        if ( !v40 )
        {
          if ( v41 )
            __enable_irq();
        }
      }
      *(uint32_t *)v36 = 0;
      *((uint32_t *)v36 + 1) = 0;
      v14 = **v7;
LABEL_5:
      if ( v14 == 1 )
      {
        v18 = (int *)off_11E424;
        if ( *((uint8_t *)off_11E424 + 32) )
        {
          v42 = mmio_read_0();
          v43 = (int)v42;
          if ( v42 )
          {
            if ( *((uint8_t *)v18 + 32) )
            {
              v44 = *v18;
              v45 = v18[1] + 1;
              v42[2] = (v45 << 24) & 0x7F000000 | v42[2] & 0x80FFFFFF;
              v18[1] = v45;
              tx_desc_set_control(v42, a1 + 48, v44, 0x3Au, 0);
              v46 = LOBYTE(((uint32_t *)(uintptr_t)off_11E448)[48]);
              v18[3] += 58;
              if ( v46 )
                op_mode_get(v43);
              else
                memmove(v43, v18[1], v18[2]);
              *(uint8_t *)off_11E44C |= 1u;
              v18[1] = 0;
              v18[3] = 0;
              *v18 = 0;
              v18[2] = 0;
              *((uint8_t *)v18 + 32) = 0;
              goto LABEL_6;
            }
          }
          else
          {
            *(uint8_t *)(a1 + 16) |= 1u;
            alloc_tx_event("partial no tx_dscr_hdr\r\n");
            *((uint8_t *)v18 + 32) = 0;
          }
        }
        check_feature_flag(1024, "partial no tx_dscr_hdr!!\r\n");
        v19 = (uint32_t *)*v18;
        *(uint8_t *)(a1 + 16) |= 1u;
        if ( v19 && v18[1] )
        {
          v20 = 0;
          do
          {
            v21 = v19;
            v19 = (uint32_t *)v19[1];
            mmio_write_0(v21);
            ++v20;
          }
          while ( v20 < (unsigned int)v18[1] );
        }
        v18[1] = 0;
        v18[3] = 0;
        *v18 = 0;
        v18[2] = 0;
      }
LABEL_6:
      ble_get_rssi(a1, a1a[0]);
      v15 = off_11E420;
      *(uint32_t *)(a1 + 4) = a5;
      v16 = v15[14];
      *(uint32_t *)(a1 + 8) = a6;
      if ( v16 )
        return wlan_ioctl_handler_1((int)(v15 + 14), (uint32_t *)a1);
      else
        return wlan_ioctl_handler_1(dword_11E444, (uint32_t *)a1);
    }
LABEL_2:
    if ( v11 == 1 )
      rx_packet_process_2(a1a, a2, &a4a);
    else
      rx_packet_parse_1(a1a, a2, a3, &a4a, 0);
    v14 = **v7;
    if ( v14 != 2 )
      goto LABEL_5;
    goto LABEL_25;
  }
  *(uint8_t *)(a1 + 16) |= 1u;
  ble_get_rssi(a1, v8);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11E4B4 = 1;
  }
  v47 = (int *)off_11E4B8;
  ++*(uint32_t *)off_11E4B8;
  v48 = rf_is_idle();
  if ( *v47 )
  {
    v49 = *v47 - 1;
    v50 = *(uint32_t *)off_11E4B4;
    *v47 = v49;
    if ( !v49 )
    {
      if ( v50 )
        __enable_irq();
    }
  }
  return debug_printf("rxl err, no buf %d\n", v48);
}
