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


extern uint32_t dword_13204C;
extern uint32_t dword_132050;
extern uint32_t dword_13205C;
extern uint32_t dword_132140;
extern uint32_t off_132054;
extern uint32_t off_132060;
extern uint32_t off_132144;
extern uint32_t off_132150;

// rf_test_tx_cmd @ 0x131c7c, size 1220 bytes
int  rf_test_tx_cmd(int a1, int *a2, int a3, int a4)
{
  uint8_t *v5; // r4
  int v6; // r0
  int v7; // r9
  int v8; // r2
  int v9; // r5
  int *v10; // r8
  int *v11; // r2
  char v12; // r1
  uint16_t v13; // r0
  int v14; // r10
  int v15; // r8
  int v16; // r12
  int v17; // r1
  int v18; // r2
  char v19; // r5
  int v20; // r7
  uint32_t *v21; // lr
  int v22; // r5
  int v23; // r3
  char v24; // r1
  int v25; // r6
  unsigned int v26; // r0
  int v27; // r3
  char v28; // r1
  char v29; // r12
  volatile unsigned int v30; // r7
  int v31; // r1
  int v32; // r11
  uint8_t *v33; // r7
  unsigned int v34; // r3
  int v36; // r3
  int v37; // r1
  int v38; // r2
  int v39; // r3
  int v40; // r1
  int v41; // r2
  int v42; // r3
  int v43; // r1
  int v44; // r2
  int v45; // r3
  int v46; // r1
  int v47; // r2
  int v48; // r3
  int v49; // r1
  int v50; // r2
  int v51; // r3
  int v52; // r0
  int v53; // r1
  int v54; // lr
  int v55; // r1
  int v56; // r2
  uint32_t *v57; // r3
  BOOL v58; // r0
  int v59; // r0
  int v60; // r0
  int v61; // r0
  uint8_t *v62; // r0
  int *v63; // r8
  uint8_t *v64; // r10
  uint32_t *v65; // r4
  uint32_t *v66; // r6
  int v67; // r11
  int v68; // r7
  int v69; // r1
  uint32_t *v70; // r3
  int v71; // r2
  uint32_t *result; // [sp+10h] [bp-44h]
  int v73; // [sp+14h] [bp-40h]
  int v74; // [sp+18h] [bp-3Ch]
  int v75; // [sp+18h] [bp-3Ch]
  int v76; // [sp+18h] [bp-3Ch]
  uint8_t *v77; // [sp+18h] [bp-3Ch]
  char v78; // [sp+1Ch] [bp-38h]
  char a7; // [sp+24h] [bp-30h] BYREF
  char a3a; // [sp+25h] [bp-2Fh] BYREF
  uint16_t a4a; // [sp+26h] [bp-2Eh] BYREF
  int a5; // [sp+28h] [bp-2Ch] BYREF
  int v83; // [sp+2Ch] [bp-28h] BYREF
  uint8_t a1a[4]; // [sp+30h] [bp-24h] BYREF
  int v85; // [sp+34h] [bp-20h]
  int v86; // [sp+38h] [bp-1Ch]
  int v87; // [sp+3Ch] [bp-18h]
  uint16_t v88; // [sp+40h] [bp-14h]
  int v89; // [sp+42h] [bp-12h]
  uint16_t v90; // [sp+46h] [bp-Eh]
  char v91; // [sp+48h] [bp-Ch]
  char v92; // [sp+49h] [bp-Bh]
  char v93; // [sp+4Dh] [bp-7h]
  char v94; // [sp+4Eh] [bp-6h]

  a5 = 0;
  v83 = 0;
  v5 = (uint8_t *)bt_buf_alloc(5128, a4, a3, 3);
  a4a = 0;
  a7 = 0;
  v6 = rf_clear_flag();
  v7 = *((uint8_t *)a2 + 129);
  v8 = a2[30];
  result = (uint32_t *)v6;
  v9 = v8 & 2;
  v73 = 1320 * v7;
  if ( (v8 & 2) == 0 )
  {
    v12 = *((uint8_t *)a2 + 129);
    goto LABEL_8;
  }
  v9 = v8 & 4;
  if ( (v8 & 4) != 0 )
  {
    v10 = a2 + 13;
    v36 = *(uint8_t *)(dword_132050 + 1320 * v7 + 106);
    if ( v36 == 2 )
    {
      v59 = v73 + 100;
    }
    else
    {
      if ( v36 == 3 )
      {
        v61 = extract_chan_bits((int)a2);
        v8 = a2[30];
        v9 = v61;
        goto LABEL_4;
      }
      if ( *(uint8_t *)(dword_132050 + 1320 * v7 + 106) )
      {
        v9 = 0;
        goto LABEL_4;
      }
      v59 = v73 + 368;
    }
    v60 = pack_chan_bits(v59 + dword_132050, *((uint16_t *)a2 + 62));
    v8 = a2[30];
    v9 = v60;
    goto LABEL_4;
  }
  v10 = nullptr;
LABEL_4:
  v11 = (int *)(v8 & 0x20);
  if ( v11 )
    v11 = a2 + 16;
  llm_parse_adv_pdu((int)(a2 + 5), v10, (int)v11, &a4a, &a5, &v83, &a7);
  v12 = *((uint8_t *)a2 + 129);
LABEL_8:
  v89 = *a2;
  v13 = *((uint16_t *)a2 + 2);
  v92 = v12;
  v87 = v9;
  *(uint32_t *)a1a = 0;
  v93 = 0;
  v94 = 0;
  v90 = v13;
  v88 = a4a;
  v86 = a5;
  v85 = v83;
  v91 = a7;
  v14 = buffer_alloc(a1a, v5, &a3a);
  v5[1] = v14;
  if ( v14 )
    goto LABEL_24;
  v15 = *v5;
  v16 = a2[30];
  v17 = *(int *)((char *)a2 + 10);
  v18 = *(int *)((char *)a2 + 14);
  v19 = *((uint8_t *)a2 + 18);
  v20 = dword_13204C + 696 * v15;
  *(uint32_t *)(v20 + 192) = *(int *)((char *)a2 + 6);
  *(uint32_t *)(v20 + 196) = v17;
  *(uint32_t *)(v20 + 200) = v18;
  *(uint8_t *)(v20 + 204) = v19;
  if ( (v16 & 0x40) != 0 )
    *(uint32_t *)(v20 + 4) |= 0x40u;
  if ( (v16 & 1) != 0
    && (v21 = (uint32_t *)(dword_13204C + 696 * v15), v74 = v21[1], v21[1] = v74 | 1, (v16 & 2) != 0)
    && (v78 = *((uint8_t *)off_132060 + 374), v14 = v78 & 1, (v78 & 1) != 0) )
  {
    v37 = a2[6];
    v38 = a2[7];
    v39 = a2[8];
    v21[52] = a2[5];
    v21[53] = v37;
    v21[54] = v38;
    v21[55] = v39;
    v40 = a2[10];
    v41 = a2[11];
    v42 = a2[12];
    v21[56] = a2[9];
    v21[57] = v40;
    v21[58] = v41;
    v21[59] = v42;
    v21[1] = v74 | 3;
    if ( (v16 & 0x20) != 0 && (v78 & 4) != 0 )
    {
      v43 = a2[17];
      v44 = a2[18];
      v45 = a2[19];
      v21[63] = a2[16];
      v21[64] = v43;
      v21[65] = v44;
      v21[66] = v45;
      v46 = a2[21];
      v47 = a2[22];
      v48 = a2[23];
      v21[67] = a2[20];
      v21[68] = v46;
      v21[69] = v47;
      v21[70] = v48;
      v49 = a2[25];
      v50 = a2[26];
      v51 = a2[27];
      v21[71] = a2[24];
      v21[72] = v49;
      v21[73] = v50;
      v21[74] = v51;
      v52 = a2[28];
      v53 = a2[29];
      v21[1] = v74 | 0x23;
      v21[75] = v52;
      v21[76] = v53;
      if ( (v78 & 8) != 0 )
      {
        configure_dma(v20);
        v16 = a2[30];
      }
    }
    if ( (v16 & 4) != 0 )
    {
      v54 = *(uint32_t *)(dword_13204C + 696 * v15 + 4);
      if ( (*((uint8_t *)off_132060 + 374) & 2) != 0 || (v54 & 0x20) != 0 )
      {
        v55 = a2[14];
        v56 = a2[15];
        v57 = (uint32_t *)(dword_13204C + 696 * v15);
        v57[60] = a2[13];
        v57[61] = v55;
        v57[62] = v56;
        v57[1] = v54 | 4;
      }
    }
    v22 = dword_132050;
    v58 = llm_get_adv_addr(v20, v73 + 248 + dword_132050);
    v16 = a2[30];
    v14 = v58;
  }
  else
  {
    v22 = dword_132050;
  }
  if ( (v16 & 8) != 0 )
    *(uint32_t *)(dword_13204C + 696 * v15 + 4) |= 8u;
  v23 = dword_13204C + 696 * v15;
  *(uint8_t *)(v23 + 310) = *((uint8_t *)a2 + 126);
  v24 = *((uint8_t *)a2 + 127);
  *(uint16_t *)(v23 + 32) = *((uint16_t *)a2 + 62);
  *(uint8_t *)(v23 + 311) = v24;
  v75 = v23;
  llm_adv_pdu_build_cmd(v20);
  if ( (a2[30] & 0x10) != 0 && *((char *)a2 + 128) >= 0 )
  {
    rf_config_chan_table(*(uint8_t *)(v75 + 35), a2[32] & 3, *((uint8_t *)a2 + 128) >> 4);
    if ( !v14 )
      goto LABEL_19;
  }
  else if ( !v14 )
  {
    goto LABEL_19;
  }
  rf_config_chan_table(*(uint8_t *)(dword_13204C + 696 * v15 + 35), 0xFFu, 0);
LABEL_19:
  v25 = v22 + 1320 * v7;
  v26 = *(uint16_t *)(v25 + 236);
  v27 = dword_13204C + 696 * v15;
  v28 = *(uint32_t *)(v25 + 1208) & 1;
  v29 = *(uint8_t *)(v27 + 350);
  *(uint32_t *)(v27 + 680) = v20;
  *(uint8_t *)(v27 + 52) = 2 - v28;
  *(uint32_t *)(v27 + 676) = off_132054;
  *(uint16_t *)(v27 + 56) = __rev16(v26);
  *(uint8_t *)(v27 + 350) = v29 | 0x10;
  *(uint8_t *)(v27 + 688) = 1;
  v30 = (*(volatile uint32_t *)0x40501010u);
  v76 = v27;
  ke_event_lock((uint32_t *)(696 * v15 + 672 + dword_13204C), dword_13205C + v30);
  v5[2] = (uint8_t)result;
  if ( result )
  {
    v31 = *(uint8_t *)(v25 + 234);
    *(uint8_t *)(v76 + 36) = (uint8_t)result;
    if ( !v31 )
    {
      v32 = (uint8_t)(*(uint8_t *)(v25 + 107) + 32);
      v33 = (uint8_t *)(dword_13204C + 696 * v32);
      if ( v33[36] != 1 )
      {
        v34 = v33[35];
        v33[36] = 1;
        if ( v34 <= 0x1F )
        {
          v62 = (uint8_t *)bt_buf_alloc(73, 13, 0, 2);
          *v62 = v32;
          v62[1] = 1;
          hci_evt_send((int)v62);
          if ( v33[36] || v33[35] > 0x1Fu )
          {
            LOBYTE(v31) = *(uint8_t *)(v25 + 234);
          }
          else
          {
            v63 = (int *)off_132150;
            v77 = v5;
            v64 = v33;
            v65 = (uint32_t *)(dword_132140 - 664 + 8 * (87 * (uint16_t)v32 + 78));
            v66 = (uint32_t *)(v22 + 8 * (165 * v33[34] + 159));
            v67 = 696 * v32 + dword_132140;
            v68 = v22 + 1320 * v33[34];
            do
            {
              if ( *((uint32_t *)v64 + 146) )
              {
                if ( (__get_CPSR() & 1) == 0 )
                {
                  __disable_irq();
                  *(uint32_t *)off_132144 = 1;
                }
                ++*v63;
                ke_event_schedule_1(aCatTobe);
                list_merge(v65 - 10, v66 - 10);
                *(uint64_t *)(v68 + 1232) = *((uint64_t *)v64 + 73);
                zero_struct(v65 - 10);
                v69 = *v63 - 1;
                if ( *v63 )
                {
                  v70 = off_132144;
                  *v63 = v69;
                  if ( !v69 )
                  {
                    if ( *v70 )
                      __enable_irq();
                  }
                }
              }
              v71 = *((uint32_t *)v64 + 156);
              v68 += 8;
              v64 += 8;
              if ( v71 )
              {
                ke_event_schedule_1(aCatPs);
                list_merge(v66, v65);
                zero_struct(v65);
              }
              v65 += 2;
              v66 += 2;
            }
            while ( (uint32_t *)v67 != v65 );
            v5 = v77;
            set_system_flag_1(512);
            LOBYTE(v31) = *(uint8_t *)(v22 + 1320 * v7 + 234);
          }
        }
      }
    }
    *(uint8_t *)(v22 + 1320 * v7 + 234) = v31 + 1;
    bt_conn_get_entry(v73 + v22);
  }
LABEL_24:
  hci_evt_send((int)v5);
  return 0;
}
