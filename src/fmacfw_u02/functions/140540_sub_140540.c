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

extern uint32_t dword_140858;
extern uint32_t dword_14085C;
extern uint32_t dword_140860;
extern uint32_t off_140854;
extern uint32_t off_140ACC;
extern uint32_t off_140AD0;
extern uint32_t dword_140AE0;
extern uint32_t dword_140ADC;
extern uint32_t off_140868;
extern uint32_t dword_140AD8;
extern uint32_t dword_140AD4;
extern uint32_t off_140864;
extern uint32_t dword_140870;
extern uint32_t dword_14086C;
extern uint32_t dword_140874;

// ble_ll_adv_event_start @ 0x140540, size 1418 bytes
// Doc: sub_1240540 [util]: Helper setting up 9-register save frame, branches on input flag.
// sub_1240540 [util]: Helper setting up 9-register save frame, branches on input flag.
uint32_t * ble_ll_adv_event_start(int a1, int a2, int a3, int a4)
{
  int v4; // r11
  int v5; // r0
  uint16_t *v8; // r5
  int v9; // r1
  int16_t v10; // r3
  int v11; // r3
  uint8_t *v12; // r1
  int v13; // r10
  int v14; // r3
  uint32_t *result; // r0
  int v16; // r3
  int v17; // r3
  int v18; // r6
  int v19; // r2
  int v20; // r1
  unsigned int v21; // r4
  int v22; // r3
  unsigned int v23; // r5
  int v24; // r2
  int v25; // r5
  uint64_t v26; // kr00_8
  char *v27; // r3
  char v28; // t1
  int16_t v29; // r4
  int16_t v30; // r4
  void *v31; // r0
  int v32; // r2
  unsigned int v33; // r3
  int v34; // r0
  uint16_t v35; // r3
  int v36; // r5
  int v37; // r12
  char *v38; // r2
  char *v39; // r3
  char v40; // t1
  int v41; // r3
  int v42; // r6
  char *v43; // r7
  uint8_t *v44; // r11
  int v45; // r10
  char v46; // r8
  unsigned int v47; // r5
  uint8_t *v48; // r1
  uint8_t *v49; // r0
  int v50; // r2
  unsigned int v51; // r0
  unsigned int v52; // r1
  int v53; // r3
  int v54; // r3
  int v55; // r8
  int v56; // r2
  int v57; // r8
  uint8_t *v58; // r7
  int v59; // r0
  int v60; // r11
  unsigned int i; // r6
  int v62; // [sp+4h] [bp-20h]
  unsigned int v63; // [sp+8h] [bp-1Ch]
  int v64; // [sp+Ch] [bp-18h]
  uint8_t *v65; // [sp+10h] [bp-14h]
  int v66; // [sp+14h] [bp-10h]
  unsigned int v67; // [sp+18h] [bp-Ch]
  int v68; // [sp+1Ch] [bp-8h]

  v4 = a1;
  v5 = *(uint32_t *)(a1 + 72);
  v8 = (uint16_t *)(v5 + 108);
  if ( a2 )
  {
    v17 = dword_140858;
    v18 = dword_14085C;
    *(uint8_t *)(v5 + 109) = 0;
    *(uint8_t *)(v5 + 110) = 0;
    *(uint8_t *)(v5 + 111) = 0;
    *(uint8_t *)(v5 + 108) = -48;
    v19 = dword_140860;
    *(uint16_t *)(v5 + 112) = *(uint16_t *)(696 * *(uint8_t *)(v17 + 6488) + v18);
    *(uint16_t *)(v5 + 114) = *(uint16_t *)(v18 + 696 * *(uint8_t *)(v17 + 6488) + 2);
    *(uint16_t *)(v5 + 116) = *(uint16_t *)(v18 + 696 * *(uint8_t *)(v17 + 6488) + 4);
    *(uint16_t *)(v5 + 118) = *(uint16_t *)(1320 * *(uint8_t *)(v17 + 6489) + v19);
    *(uint16_t *)(v5 + 120) = *(uint16_t *)(v19 + 1320 * *(uint8_t *)(v17 + 6489) + 2);
    *(uint16_t *)(v5 + 122) = *(uint16_t *)(v19 + 1320 * *(uint8_t *)(v17 + 6489) + 4);
    v20 = 1320 * *(uint8_t *)(v17 + 6489);
    if ( *(uint8_t *)(v19 + v20 + 6) == 2 )
    {
      *(uint16_t *)(v5 + 124) = *(uint16_t *)(v20 + v19);
      v9 = 208;
      *(uint16_t *)(v5 + 126) = *(uint16_t *)(v19 + 1320 * *(uint8_t *)(v17 + 6489) + 2);
      *(uint16_t *)(v5 + 128) = *(uint16_t *)(v19 + 1320 * *(uint8_t *)(v17 + 6489) + 4);
    }
    else
    {
      v9 = 208;
      *(uint16_t *)(v5 + 124) = *(uint16_t *)(696 * *(uint8_t *)(v17 + 6488) + v18);
      *(uint16_t *)(v5 + 126) = *(uint16_t *)(v18 + 696 * *(uint8_t *)(v17 + 6488) + 2);
      *(uint16_t *)(v5 + 128) = *(uint16_t *)(v18 + 696 * *(uint8_t *)(v17 + 6488) + 4);
    }
  }
  else
  {
    v9 = *(uint16_t *)(v5 + 108);
  }
  v10 = *((uint16_t *)off_140854 + 254) + 1;
  *((uint16_t *)off_140854 + 254) = v10;
  *(uint16_t *)(v5 + 130) = 16 * v10;
  if ( get_channel_tx_power(v4, v9, 5) == 1 )
  {
    ll_conn_window_calc(v4, v8, 24);
    v24 = *(uint8_t *)(v4 + 51);
    v11 = v24 + 24;
    v64 = v24 + 27;
  }
  else
  {
    v64 = 27;
    v11 = 24;
  }
  v12 = (char *)v8 + v11;
  *((uint8_t *)v8 + v11) = 5;
  v12[1] = 1;
  v12[2] = *(uint8_t *)a4;
  v13 = (int)v8 + v11 + 3;
  if ( a3 )
  {
    v12[3] = 39;
    v12[4] = 3;
    v12[5] = *(uint8_t *)(a4 + 1);
    v12[6] = a3;
    v12[7] = *(uint8_t *)(a4 + 2);
    v14 = v11 + 8;
  }
  else
  {
    v62 = 0;
    v63 = (uint16_t)(512 - v64);
    v66 = v4;
    do
    {
      v21 = (uint16_t)(v63 - 5);
      if ( *(uint8_t *)(a4 + 2) == 5 )
      {
        v32 = *(uint32_t *)off_140ACC;
        if ( *(uint32_t *)off_140ACC )
        {
          if ( v21 <= 0x19 )
            break;
          v33 = (uint16_t)(v63 - 31);
          if ( *(uint8_t *)(a4 + 32) )
          {
            if ( v33 <= 2 )
              break;
            v33 = (uint16_t)(v63 - 34);
          }
          if ( *(uint8_t *)(a4 + 4) )
          {
            if ( v33 <= 3 )
              break;
            v34 = *(uint16_t *)(v32 + 24);
            v35 = v33 - 4;
            v36 = v35;
            if ( *(uint16_t *)(v32 + 24) )
            {
              v55 = *(uint16_t *)(v32 + 26);
              v56 = v32 + 64;
              v57 = v55 - v34;
              v58 = (uint8_t *)(v56 + v34);
              if ( *(uint8_t *)(a4 + 4) == 1 )
              {
                v59 = *(uint8_t *)(v56 + v34);
                v60 = v58[2];
                for ( i = (uint8_t)(v58[1] + 2);
                      !ble_ll_hci_vendor_cmd(v59, v60, a4) || i > 0xD9;
                      i = (uint8_t)(v58[1] + 2) )
                {
                  v57 -= i;
                  v58 += i;
                  if ( !v57 )
                    goto LABEL_90;
                  v59 = *v58;
                }
              }
              if ( v57 )
              {
                if ( v58[1] + 3 >= v36 )
                  break;
              }
              else
              {
LABEL_90:
                if ( **(int16_t **)off_140AD0 < 0 )
                  call_shared_handler(dword_140AE0, dword_140ADC, 1043);
              }
            }
            else if ( v35 <= 0xDu )
            {
              break;
            }
          }
        }
      }
      *(uint8_t *)v13 = 39;
      *(uint8_t *)(v13 + 2) = *(uint8_t *)(a4 + 1);
      *(uint8_t *)(v13 + 3) = 0;
      v22 = *(uint8_t *)(a4 + 2);
      *(uint8_t *)(v13 + 4) = v22;
      if ( v22 == 5 )
      {
        v25 = *(uint32_t *)off_140868;
        ++*(uint32_t *)(a4 + 92);
        v65 = (uint8_t *)(v13 + 5);
        if ( !v25 )
        {
          *(uint8_t *)(v13 + 1) = 3;
          if ( **(int16_t **)off_140AD0 >= 0 )
          {
            v13 += 5;
            v63 = (uint16_t)(v63 - 5);
            v23 = 5;
            goto LABEL_14;
          }
          v23 = 5;
          goto LABEL_73;
        }
        *(uint8_t *)(v13 + 5) = *(uint8_t *)(v25 + 19);
        *(uint8_t *)(v13 + 6) = *(uint8_t *)(v25 + 16);
        v26 = *(uint64_t *)(a4 + 40);
        *(uint16_t *)(v13 + 15) = *(uint16_t *)(a4 + 48);
        *(uint64_t *)(v13 + 7) = v26;
        *(uint8_t *)(v13 + 17) = *(uint8_t *)(v25 + 18);
        *(uint8_t *)(v13 + 18) = rf_cal_code_idx(*(char *)(v25 + 20));
        *(uint8_t *)(v13 + 19) = -1;
        v27 = (char *)(v25 + 6);
        do
        {
          v28 = *v27++;
          v27[v13 + 13 - v25] = v28;
        }
        while ( v27 != (char *)(v25 + 12) );
        *(uint8_t *)(v13 + 26) = *(uint8_t *)(v25 + 17);
        *(uint32_t *)(v13 + 27) = *(uint32_t *)(v25 + 12);
        v29 = 257;
        if ( v63 <= 0x101 )
          v29 = v63;
        v65 = (uint8_t *)(v13 + 31);
        if ( *(uint8_t *)(a4 + 32) )
          v30 = v29 - 34;
        else
          v30 = v29 - 31;
        if ( !*(uint8_t *)(a4 + 4) )
        {
          *(uint16_t *)(v25 + 24) = *(uint16_t *)(v25 + 26);
          goto LABEL_29;
        }
        *v65 = 1;
        v67 = (uint16_t)(v30 - 6);
        v37 = v13 + 33;
        if ( *(uint16_t *)(v25 + 24) <= 0xBu )
        {
          if ( **(int16_t **)off_140AD0 < 0 && (uint16_t)(v30 - 6) <= 0xBu )
            mmio_clear_register(dword_140AD8, dword_140AD4, 1149);
          v38 = (char *)(v25 + 64);
          do
          {
            v39 = v38 - 31;
            v40 = *v38++;
            v39[v13 - v25] = v40;
          }
          while ( v38 != (char *)(v25 + 76) );
          *(uint16_t *)(v25 + 24) = 12;
          v67 = (uint16_t)(v30 - 18);
          v37 = v13 + 45;
        }
        if ( *(uint8_t *)(a4 + 4) == 1 && !*(uint32_t *)(a4 + 8) && !*(uint32_t *)(a4 + 20) )
        {
          *(uint16_t *)(v25 + 24) = *(uint16_t *)(v25 + 26);
          goto LABEL_66;
        }
        v41 = *(uint16_t *)(v25 + 24);
        LOWORD(v42) = *(uint16_t *)(v25 + 26) - v41;
        v43 = (char *)(v25 + 64 + v41);
        if ( !(uint16_t)v42 )
          goto LABEL_66;
        v68 = v13;
        v44 = (uint8_t *)v37;
        v45 = v25;
        while ( 1 )
        {
          v46 = *v43;
          v47 = (uint8_t)(v43[1] + 2);
          if ( ble_ll_hci_vendor_cmd((uint8_t)*v43, (uint8_t)v43[2], a4) && v47 <= 0xD9 )
          {
            if ( (uint8_t)v47 > v67 )
            {
LABEL_71:
              v25 = v45;
              v37 = (int)v44;
              v13 = v68;
LABEL_66:
              *(uint8_t *)(v13 + 32) = -2 - (uint8_t)v65 + v37;
              *(uint8_t *)v37 = 2;
              *(uint8_t *)(v37 + 1) = 2;
              v50 = *(uint8_t *)(v25 + 22);
              v51 = *(uint16_t *)(v25 + 24);
              v52 = *(uint16_t *)(v25 + 26);
              v53 = *(uint8_t *)(a4 + 1);
              *(uint8_t *)(v25 + 22) = v50 + 1;
              v54 = v53 | (v50 << 8);
              if ( v51 < v52 )
              {
                *(uint16_t *)(v37 + 2) = ~((unsigned int)~(v54 << 17) >> 17);
                v65 = (uint8_t *)(v37 + 4);
LABEL_30:
                if ( *(uint8_t *)(a4 + 32) )
                {
                  *v65 = -92;
                  v65[1] = 1;
                  v65[2] = ble_ll_adv_chk_active();
                  v65 += 3;
                }
                v23 = (unsigned int)&v65[-v13];
                *(uint8_t *)(v13 + 1) = (uint8_t)v65 - v13 - 2;
                v21 = (uint16_t)(v63 - ((uint16_t)v65 - v13));
                if ( **(int16_t **)off_140864 < 0 && v63 < v23 )
                {
                  v13 = (int)v65;
                  mmio_clear_register(dword_140870, dword_14086C, 1287);
                  v63 = v21;
                  goto LABEL_14;
                }
LABEL_73:
                v13 = (int)v65;
                v63 = v21;
                goto LABEL_14;
              }
              *(uint16_t *)(v37 + 2) = v54;
              v65 = (uint8_t *)(v37 + 4);
LABEL_29:
              v31 = off_140868;
              *(uint16_t *)(v25 + 4) = 3;
              cmd_handler_c((int)v31, (uint32_t *)v25);
              goto LABEL_30;
            }
            if ( v47 )
            {
              v48 = v44;
              v49 = (uint8_t *)(v43 - v44);
              v44 += v47;
              while ( 1 )
              {
                *v48++ = v46;
                if ( v44 == v48 )
                  break;
                v46 = v48[(uint32_t)v49];
              }
            }
            v67 = (uint16_t)(v67 - (uint8_t)v47);
          }
          v42 = (uint16_t)(v42 - (uint8_t)v47);
          v43 += v47;
          *(uint16_t *)(v45 + 24) += (uint8_t)v47;
          if ( !v42 )
            goto LABEL_71;
        }
      }
      *(uint8_t *)(v13 + 1) = 3;
      v63 = (uint16_t)(v63 - 5);
      v13 += 5;
      v23 = 5;
LABEL_14:
      v62 += v23;
    }
    while ( !ble_ll_adv_chk_active() && v21 > 4 );
    v4 = v66;
    if ( **(int16_t **)off_140864 < 0 && !v62 )
      call_shared_handler(dword_140874, dword_14086C, 1298);
    v14 = v62 + v64;
  }
  result = *(uint32_t **)(v4 + 76);
  v16 = v14 + *(uint8_t *)(v4 + 53);
  result[8] = result[7] - 1 + v16;
  result[9] = v16 + 4;
  return result;
}

