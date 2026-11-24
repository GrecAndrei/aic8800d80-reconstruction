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


extern uint32_t dword_133594;
extern uint32_t off_13340C;
extern uint32_t off_133428;

// rx_process_packet_1 @ 0x132fb8, size 1500 bytes
int  rx_process_packet_1(int a1, uint16_t a2, int a3)
{
  int v4; // r3
  int v5; // r6
  int v6; // r0
  int v7; // r7
  uint8_t *v8; // r4
  unsigned int v9; // r8
  uint8_t *v10; // r9
  uint16_t v11; // r11
  int v12; // r6
  uint8_t *v13; // r11
  uint8_t *v14; // s17
  uint8_t *v15; // r2
  uint8_t *v16; // r1
  int v17; // r0
  int v18; // r6
  int v19; // r3
  int v20; // r1
  uint16_t v21; // r3
  uint16_t **v22; // r10
  int v23; // r2
  int v24; // r0
  int v25; // r2
  uint16_t v26; // r3
  int v27; // r1
  unsigned int v28; // r3
  unsigned int v29; // r6
  int v30; // r2
  unsigned int v31; // r3
  int v32; // r2
  unsigned int v33; // r12
  int v34; // r3
  char v35; // r0
  int v36; // r1
  unsigned int v37; // r2
  int v38; // r3
  char v39; // r0
  int v40; // r0
  int v41; // r1
  int v42; // r0
  int v43; // r2
  char v44; // lr
  int v45; // r0
  int v46; // r1
  char v47; // lr
  unsigned int v48; // r1
  int v49; // r11
  int *v50; // r4
  int v51; // r0
  int v52; // t1
  uint8_t *v53; // r0
  char v54; // r2
  uint16_t v55; // r3
  uint8_t *v56; // r0
  int v57; // r0
  unsigned int v58; // r3
  int v59; // r3
  int v60; // r0
  int *v61; // r0
  unsigned int v62; // r2
  int v63; // r3
  int v64; // r3
  uint8_t *v65; // r0
  int v66; // r0
  uint64_t v67; // kr00_8
  unsigned int v68; // [sp+4h] [bp-20h]
  int v69; // [sp+8h] [bp-1Ch]
  uint8_t *a2a; // [sp+Ch] [bp-18h]
  uint8_t *a2c; // [sp+Ch] [bp-18h]
  uint8_t *a2b; // [sp+Ch] [bp-18h]
  int a1a; // [sp+14h] [bp-10h]
  uint8_t *a1b; // [sp+14h] [bp-10h]
  uint8_t v76[5]; // [sp+1Fh] [bp-5h] BYREF

  v4 = *(uint32_t *)(a1 + 468);
  v5 = *(uint8_t *)(a1 + 464);
  v6 = *(uint8_t *)(a1 + 412);
  v7 = *(uint16_t *)(a1 + 462);
  v8 = *(uint8_t **)(a1 + 240);
  v9 = *(uint8_t *)(a1 + 413);
  v69 = v5;
  *(uint16_t *)(a1 + 462) = 0;
  v68 = v4 & 0xFF000000;
  v10 = (uint8_t *)(a3 + 36);
  v11 = a2 - 36;
  if ( v6 )
    goto LABEL_2;
  v12 = v11;
  v53 = check_one_12dbe0(v10, v11);
  if ( !v53 )
    goto LABEL_2;
  v54 = v53[2];
  v55 = *(uint16_t *)(a1 + 462) & 0xFFF8;
  if ( (v54 & 1) != 0 )
    v55 |= 1u;
  *(uint16_t *)(a1 + 462) = v55;
  if ( (v54 & 4) != 0 )
    *(uint16_t *)(a1 + 462) |= 4u;
  else
LABEL_2:
    v12 = v11;
  if ( (*(uint32_t *)(a1 + 472) & 1) != 0 )
  {
    v49 = *(uint8_t *)(a1 + 106);
    if ( !*(uint8_t *)(a1 + 106) )
    {
      ll_get_conn_state((int)v10, v12, a1 + 440, v76);
      if ( v76[0] )
      {
        a2b = v8;
        v50 = (int *)(a1 + 440);
        do
        {
          v51 = ke_msg_alloc(26, 0, 5, 8);
          v52 = *v50++;
          *(uint32_t *)v51 = v52;
          *(uint8_t *)(v51 + 5) = v49;
          *(uint8_t *)(v51 + 6) = *(uint8_t *)(a1 + 107);
          ++v49;
          *(uint8_t *)(v51 + 4) = 0;
          ke_msg_send_2(v51);
        }
        while ( v49 != 4 );
        v8 = a2b;
      }
    }
  }
  v13 = off_133428;
  if ( (*((uint8_t *)off_133428 + 374) & 1) == 0 )
  {
    v14 = (uint8_t *)(*((uint8_t *)off_133428 + 374) & 1);
    a2a = v14;
LABEL_6:
    scan_interval_update((int)v14, a2a, a1 + 248);
    goto LABEL_7;
  }
  v14 = check_one_12deb8(v10, v12);
  if ( (v13[374] & 6) != 0 )
  {
    check_one_12def8(v10, v12);
    a2a = v56;
    if ( !*(uint8_t *)(a1 + 106) )
    {
      v65 = check_one_12dc20(v10, v12);
      if ( v65
        && (*(uint32_t *)(dword_133594 + 696 * *(uint8_t *)(a1 + 116) + 4) & 0x24) != 0
        && (v65[2] & 0x80u) == 0 )
      {
        bt_get_conn_entry(*(uint8_t *)(a1 + 116), v65[2] & 3, v65[2] >> 4);
      }
      if ( (*(uint32_t *)(a1 + 472) & 8) != 0 )
      {
        a1b = (uint8_t *)ke_msg_alloc(109, 0, 5, 2);
        ll_get_phy_tx_power((int)v10, v12, a1b);
        ke_msg_send_2((int)a1b);
        ll_get_adv_state((int)v10, v12, a1 + 348, v76);
        if ( v76[0] )
        {
          v66 = ke_msg_alloc(107, 0, 5, 16);
          v67 = *(uint64_t *)(a1 + 352);
          *(uint32_t *)v66 = *(uint32_t *)(a1 + 348);
          *(uint32_t *)(v66 + 12) = *(uint32_t *)(a1 + 360);
          *(uint64_t *)(v66 + 4) = v67;
          ke_msg_send_2(v66);
        }
      }
    }
    if ( (v13[374] & 4) == 0 )
      goto LABEL_6;
    v57 = ll_get_access_addr((int)v10, v12, a1 + 248);
    if ( v57 )
    {
      v58 = *(uint32_t *)(a1 + 468);
      a1a = (v58 >> 4) & 0x3FF;
      if ( *(uint8_t *)(a1 + 106) == 2 )
      {
        v59 = v58 | 0x10000;
        *(uint32_t *)(a1 + 468) = v59;
        *(uint32_t *)(v57 + 3) = v59;
      }
      if ( !a1a )
        goto LABEL_116;
    }
    else
    {
      LOWORD(a1a) = 1023;
    }
    v60 = ke_msg_alloc(111, 0, 5, 4);
    *(uint16_t *)v60 = a1a;
    *(uint8_t *)(v60 + 2) = *(uint8_t *)(a1 + 107);
    ke_msg_send_2(v60);
LABEL_116:
    if ( (*(uint32_t *)(a1 + 468) & 0xFF000000) != v68 )
    {
      v61 = (int *)ke_msg_alloc(113, 0, 5, 4);
      v62 = *(uint32_t *)(a1 + 468);
      v63 = HIBYTE(v62) & 0x3F;
      if ( (v62 & 0x40000000) != 0 )
        v64 = v63 | 0x300;
      else
        v64 = v63 | 0x100;
      *v61 = v64;
      ke_msg_send_2((int)v61);
    }
    goto LABEL_6;
  }
  scan_interval_update((int)v14, nullptr, a1 + 248);
LABEL_7:
  v15 = (uint8_t *)(uint8_t)rx_packet_handler_2((int)v10, v12, v76, a1 + 1212);
  if ( v15 )
  {
    if ( *(uint8_t *)(a1 + 106) )
    {
      if ( *(uint8_t *)(a1 + 106) == 2 )
        *(uint8_t *)(a1 + 231) = (uint8_t)v15;
    }
    else
    {
      v16 = (uint8_t *)*(uint8_t *)(a1 + 146);
      if ( *(uint8_t *)(a1 + 146)
        || *(uint8_t *)(a1 + 148)
        && v76[0] == 1
        && (a2c = v15,
            hci_send_cmd_0x59(*(uint8_t *)(a1 + 107), (char)v16),
            v16 = (uint8_t *)*(uint8_t *)(a1 + 146),
            v15 = a2c,
            *(uint8_t *)(a1 + 146)) )
      {
        if ( v15 != v16 )
          *(uint8_t *)(a1 + 148) = 1;
      }
      *(uint8_t *)(a1 + 146) = (uint8_t)v15;
    }
  }
  v17 = call_config_setter((int)v10, v12, a1 + 248);
  if ( *(uint8_t *)(a1 + 464) != v69 )
    v17 = rf_temperature_comp(a1);
  if ( *(uint8_t *)(a1 + 413) > v9 )
  {
    if ( !*(uint32_t *)(a1 + 72) )
      send_msg(a3, 32, 1, 0);
    v18 = ke_msg_alloc(59, 0, 5, 12);
    v19 = *(uint32_t *)(a1 + 72);
    if ( **(uint16_t **)off_13340C < 0 && !v19 )
    {
      mmio_clear_register((int)aVifChanCtxtNul, (int)aMeChanCtxtUpda, 70);
      v19 = *(uint32_t *)(a1 + 72);
    }
    *(uint8_t *)v18 = *(uint8_t *)(v19 + 24);
    v20 = *(uint32_t *)(a1 + 416);
    v21 = *(uint16_t *)(a1 + 420);
    *(uint32_t *)(v18 + 2) = *(uint32_t *)(a1 + 412);
    *(uint32_t *)(v18 + 6) = v20;
    *(uint16_t *)(v18 + 10) = v21;
    v17 = (int)ke_msg_send_2(v18);
  }
  if ( v8 )
  {
    v22 = (uint16_t **)off_13340C;
    while ( 1 )
    {
      v23 = *(uint16_t *)(a1 + 462);
      if ( v23 != v7 )
      {
        event_dispatch("curr=%x, bss=%x\r\n", v7, v23);
        v24 = (uint8_t)v8[35];
        v25 = *(uint16_t *)(a1 + 462) << 29;
        v26 = (uint8_t)v8[350] | 2;
        v27 = 0;
        v8[350] = v26;
        if ( v25 >= 0 )
          v26 = 1024;
        *((uint32_t *)v8 + 86) = 0;
        if ( v25 >= 0 )
        {
          *((uint16_t *)v8 + 174) = v26;
          v27 = 1;
        }
        else
        {
          *((uint16_t *)v8 + 174) = 0;
        }
        v17 = ble_ll_conn_sm_validate(v24, v27);
      }
      v28 = *(uint8_t *)(a1 + 413);
      if ( v28 != v9 )
        break;
LABEL_48:
      if ( (*(uint32_t *)(a1 + 468) & 0xFF000000) != v68 && (*((uint32_t *)v8 + 1) & 0x20) != 0 )
        v8[350] |= 0x40u;
      v8 = *(uint8_t **)v8;
      if ( !v8 )
        return v17;
    }
    v29 = (uint8_t)v8[308];
    if ( v28 == 4 )
    {
      if ( v29 <= 3 )
      {
        if ( v29 >= 2 )
          v29 = 2;
LABEL_38:
        if ( (uint8_t)v8[309] != v29 )
        {
          v30 = *((uint32_t *)v8 + 1);
          v31 = v30 & 0x20;
          if ( (v30 & 0x20) != 0 )
          {
            if ( **v22 < 0 && (v13[374] & 4) == 0 )
              mmio_clear_register((int)aLocalCapaHe, (int)aMePolTblBwUpd, 463);
            v32 = 14;
            v33 = 7;
            do
            {
              v34 = ((int)*((uint16_t *)v8 + 135) >> v32) & 3;
              v35 = v33 - 1;
              v32 -= 2;
              if ( v34 != 3 )
                break;
              v33 = (uint8_t)(v33 - 1);
            }
            while ( v35 );
            v36 = 14;
            v37 = 7;
            while ( 1 )
            {
              v38 = ((int)*((uint16_t *)v13 + 40) >> v36) & 3;
              v39 = v37 - 1;
              v36 -= 2;
              if ( v38 != 3 )
                break;
              v37 = (uint8_t)(v37 - 1);
              if ( !v39 )
                goto LABEL_47;
            }
            if ( v37 >= v33 )
              v37 = v33;
          }
          else if ( (v30 & 4) != 0 )
          {
            if ( **v22 < 0 && (v13[374] & 2) == 0 )
            {
              mmio_clear_register((int)aLocalCapaVht, (int)aMePolTblBwUpd, 476);
              v31 = 0;
            }
            v41 = 14;
            v42 = 7;
            while ( 1 )
            {
              v43 = ((int)*((uint16_t *)v8 + 122) >> v41) & 3;
              v44 = v42 - 1;
              v41 -= 2;
              if ( v43 != 3 )
                break;
              v42 = (uint8_t)(v42 - 1);
              if ( !v44 )
                goto LABEL_62;
            }
            v31 = v42;
LABEL_62:
            v45 = 14;
            v37 = 7;
            while ( 1 )
            {
              v46 = ((int)*((uint16_t *)v13 + 28) >> v45) & 3;
              v47 = v37 - 1;
              v45 -= 2;
              if ( v46 != 3 )
                break;
              v37 = (uint8_t)(v37 - 1);
              if ( !v47 )
                goto LABEL_47;
            }
            if ( v37 >= v31 )
              LOBYTE(v37) = v31;
            v37 = (uint8_t)v37;
          }
          else
          {
            if ( **v22 < 0 && (v13[374] & 1) == 0 )
              mmio_clear_register((int)aLocalCapaHt, (int)aMePolTblBwUpd, 487);
            if ( v8[214] )
            {
              v48 = 3;
            }
            else if ( v8[213] )
            {
              v48 = 2;
            }
            else
            {
              v48 = (uint8_t)v8[212];
              if ( v8[212] )
                v48 = 1;
            }
            if ( v13[18] )
            {
              v37 = 3;
            }
            else if ( v13[17] )
            {
              v37 = 2;
            }
            else
            {
              v37 = (uint8_t)v13[16];
              if ( v13[16] )
                v37 = 1;
            }
            if ( v37 >= v48 )
              v37 = v48;
          }
LABEL_47:
          v40 = (uint8_t)v8[35];
          v8[309] = v29;
          v17 = ble_ll_conn_sm_get_by_handle(v40, v29, v37);
          v8[350] |= 8u;
        }
        goto LABEL_48;
      }
    }
    else
    {
      if ( v28 >= v29 )
        v28 = (uint8_t)v8[308];
      if ( v28 != 4 )
      {
        v29 = (uint8_t)v28;
        goto LABEL_38;
      }
    }
    v29 = 3;
    goto LABEL_38;
  }
  return v17;
}
