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

extern uint32_t dword_131E34;
extern uint32_t dword_131E30;
extern uint32_t off_131E44;
extern uint32_t off_131E3C;
extern uint32_t dword_131E38;
extern uint32_t dword_131E40;
extern uint32_t off_131F34;
extern uint32_t dword_131F24;
extern uint32_t off_131F28;
extern uint32_t dword_131F2C;
extern uint32_t dword_131F30;

// ke_msg_alloc @ 0x131a60, size 1220 bytes
int  ke_msg_alloc(int a1, int a2, int16_t a3, int16_t a4)
{
  uint8_t *v5; // r4
  int v6; // r0
  int v7; // r9
  int v8; // r2
  int v9; // r5
  int v10; // r8
  int v11; // r2
  char v12; // r1
  int16_t v13; // r0
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
  uint32_t *v30; // r1
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
  int v58; // r0
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
  int v69; // r0
  int v70; // r1
  uint32_t *v71; // r3
  int v72; // r2
  int v73; // [sp+10h] [bp-44h]
  int v74; // [sp+14h] [bp-40h]
  int v75; // [sp+18h] [bp-3Ch]
  int v76; // [sp+18h] [bp-3Ch]
  int v77; // [sp+18h] [bp-3Ch]
  uint8_t *v78; // [sp+18h] [bp-3Ch]
  char v79; // [sp+1Ch] [bp-38h]
  char v80; // [sp+24h] [bp-30h] BYREF
  char v81; // [sp+25h] [bp-2Fh] BYREF
  int16_t v82; // [sp+26h] [bp-2Eh] BYREF
  int v83; // [sp+28h] [bp-2Ch] BYREF
  int v84; // [sp+2Ch] [bp-28h] BYREF
  uint32_t v85[4]; // [sp+30h] [bp-24h] BYREF
  int16_t v86; // [sp+40h] [bp-14h]
  int v87; // [sp+42h] [bp-12h]
  int16_t v88; // [sp+46h] [bp-Eh]
  char v89; // [sp+48h] [bp-Ch]
  char v90; // [sp+49h] [bp-Bh]
  char v91; // [sp+4Dh] [bp-7h]
  char v92; // [sp+4Eh] [bp-6h]

  v83 = 0;
  v84 = 0;
  v5 = (uint8_t *)ke_msg_alloc(5128, a4, a3, 3u);
  v82 = 0;
  v80 = 0;
  v6 = clear_flag();
  v7 = *(uint8_t *)(a2 + 129);
  v8 = *(uint32_t *)(a2 + 120);
  v73 = v6;
  v9 = v8 & 2;
  v74 = 1320 * v7;
  if ( (v8 & 2) == 0 )
  {
    v12 = *(uint8_t *)(a2 + 129);
    goto LABEL_8;
  }
  v9 = v8 & 4;
  if ( (v8 & 4) != 0 )
  {
    v10 = a2 + 52;
    v36 = *(uint8_t *)(dword_131E34 + 1320 * v7 + 106);
    if ( v36 == 2 )
    {
      v59 = v74 + 100;
    }
    else
    {
      if ( v36 == 3 )
      {
        v61 = extract_9bit_field(a2);
        v8 = *(uint32_t *)(a2 + 120);
        v9 = v61;
        goto LABEL_4;
      }
      if ( *(uint8_t *)(dword_131E34 + 1320 * v7 + 106) )
      {
        v9 = 0;
        goto LABEL_4;
      }
      v59 = v74 + 368;
    }
    v60 = mac_hash_calc(v59 + dword_131E34, *(uint16_t *)(a2 + 124));
    v8 = *(uint32_t *)(a2 + 120);
    v9 = v60;
    goto LABEL_4;
  }
  v10 = 0;
LABEL_4:
  v11 = v8 & 0x20;
  if ( v11 )
    v11 = a2 + 64;
  util_init_outputs(a2 + 20, v10, v11, &v82, &v83, &v84, &v80);
  v12 = *(uint8_t *)(a2 + 129);
LABEL_8:
  v87 = *(uint32_t *)a2;
  v13 = *(uint16_t *)(a2 + 4);
  v90 = v12;
  v85[3] = v9;
  v85[0] = 0;
  v91 = 0;
  v92 = 0;
  v88 = v13;
  v86 = v82;
  v85[2] = v83;
  v85[1] = v84;
  v89 = v80;
  v14 = call_fw_handler((int)v85, v5, &v81);
  v5[1] = v14;
  if ( v14 )
    goto LABEL_24;
  v15 = *v5;
  v16 = *(uint32_t *)(a2 + 120);
  v17 = *(uint32_t *)(a2 + 10);
  v18 = *(uint32_t *)(a2 + 14);
  v19 = *(uint8_t *)(a2 + 18);
  v20 = dword_131E30 + 696 * v15;
  *(uint32_t *)(v20 + 192) = *(uint32_t *)(a2 + 6);
  *(uint32_t *)(v20 + 196) = v17;
  *(uint32_t *)(v20 + 200) = v18;
  *(uint8_t *)(v20 + 204) = v19;
  if ( (v16 & 0x40) != 0 )
    *(uint32_t *)(v20 + 4) |= 0x40u;
  if ( (v16 & 1) != 0
    && (v21 = (uint32_t *)(dword_131E30 + 696 * v15), v75 = v21[1], v21[1] = v75 | 1, (v16 & 2) != 0)
    && (v79 = *((uint8_t *)off_131E44 + 374), v14 = v79 & 1, (v79 & 1) != 0) )
  {
    v37 = *(uint32_t *)(a2 + 24);
    v38 = *(uint32_t *)(a2 + 28);
    v39 = *(uint32_t *)(a2 + 32);
    v21[52] = *(uint32_t *)(a2 + 20);
    v21[53] = v37;
    v21[54] = v38;
    v21[55] = v39;
    v40 = *(uint32_t *)(a2 + 40);
    v41 = *(uint32_t *)(a2 + 44);
    v42 = *(uint32_t *)(a2 + 48);
    v21[56] = *(uint32_t *)(a2 + 36);
    v21[57] = v40;
    v21[58] = v41;
    v21[59] = v42;
    v21[1] = v75 | 3;
    if ( (v16 & 0x20) != 0 && (v79 & 4) != 0 )
    {
      v43 = *(uint32_t *)(a2 + 68);
      v44 = *(uint32_t *)(a2 + 72);
      v45 = *(uint32_t *)(a2 + 76);
      v21[63] = *(uint32_t *)(a2 + 64);
      v21[64] = v43;
      v21[65] = v44;
      v21[66] = v45;
      v46 = *(uint32_t *)(a2 + 84);
      v47 = *(uint32_t *)(a2 + 88);
      v48 = *(uint32_t *)(a2 + 92);
      v21[67] = *(uint32_t *)(a2 + 80);
      v21[68] = v46;
      v21[69] = v47;
      v21[70] = v48;
      v49 = *(uint32_t *)(a2 + 100);
      v50 = *(uint32_t *)(a2 + 104);
      v51 = *(uint32_t *)(a2 + 108);
      v21[71] = *(uint32_t *)(a2 + 96);
      v21[72] = v49;
      v21[73] = v50;
      v21[74] = v51;
      v52 = *(uint32_t *)(a2 + 112);
      v53 = *(uint32_t *)(a2 + 116);
      v21[1] = v75 | 0x23;
      v21[75] = v52;
      v21[76] = v53;
      if ( (v79 & 8) != 0 )
      {
        arm_timer(v20);
        v16 = *(uint32_t *)(a2 + 120);
      }
    }
    if ( (v16 & 4) != 0 )
    {
      v54 = *(uint32_t *)(dword_131E30 + 696 * v15 + 4);
      if ( (*((uint8_t *)off_131E44 + 374) & 2) != 0 || (v54 & 0x20) != 0 )
      {
        v55 = *(uint32_t *)(a2 + 56);
        v56 = *(uint32_t *)(a2 + 60);
        v57 = (uint32_t *)(dword_131E30 + 696 * v15);
        v57[60] = *(uint32_t *)(a2 + 52);
        v57[61] = v55;
        v57[62] = v56;
        v57[1] = v54 | 4;
      }
    }
    v22 = dword_131E34;
    v58 = rf_check_status(v20, v74 + 248 + dword_131E34);
    v16 = *(uint32_t *)(a2 + 120);
    v14 = v58;
  }
  else
  {
    v22 = dword_131E34;
  }
  if ( (v16 & 8) != 0 )
    *(uint32_t *)(dword_131E30 + 696 * v15 + 4) |= 8u;
  v23 = dword_131E30 + 696 * v15;
  *(uint8_t *)(v23 + 310) = *(uint8_t *)(a2 + 126);
  v24 = *(uint8_t *)(a2 + 127);
  *(uint16_t *)(v23 + 32) = *(uint16_t *)(a2 + 124);
  *(uint8_t *)(v23 + 311) = v24;
  v76 = v23;
  stub_ret(v20);
  if ( (*(uint32_t *)(a2 + 120) & 0x10) != 0 && *(char *)(a2 + 128) >= 0 )
  {
    bt_get_conn_entry(*(uint8_t *)(v76 + 35), *(uint8_t *)(a2 + 128) & 3, *(uint8_t *)(a2 + 128) >> 4);
    if ( !v14 )
      goto LABEL_19;
  }
  else if ( !v14 )
  {
    goto LABEL_19;
  }
  bt_get_conn_entry(*(uint8_t *)(dword_131E30 + 696 * v15 + 35), 255, 0);
LABEL_19:
  v25 = v22 + 1320 * v7;
  v26 = *(uint16_t *)(v25 + 236);
  v27 = dword_131E30 + 696 * v15;
  v28 = *(uint32_t *)(v25 + 1208) & 1;
  v29 = *(uint8_t *)(v27 + 350);
  *(uint32_t *)(v27 + 680) = v20;
  *(uint8_t *)(v27 + 52) = 2 - v28;
  v30 = off_131E3C;
  *(uint32_t *)(v27 + 676) = dword_131E38;
  *(uint16_t *)(v27 + 56) = __rev16(v26);
  *(uint8_t *)(v27 + 350) = v29 | 0x10;
  *(uint8_t *)(v27 + 688) = 1;
  v77 = v27;
  unknown_worker(696 * v15 + 672 + dword_131E30, dword_131E40 + v30[4]);
  v5[2] = v73;
  if ( v73 )
  {
    v31 = *(uint8_t *)(v25 + 234);
    *(uint8_t *)(v77 + 36) = v73;
    if ( !v31 )
    {
      v32 = (uint8_t)(*(uint8_t *)(v25 + 107) + 32);
      v33 = (uint8_t *)(dword_131E30 + 696 * v32);
      if ( v33[36] != 1 )
      {
        v34 = v33[35];
        v33[36] = 1;
        if ( v34 <= 0x1F )
        {
          v62 = (uint8_t *)ke_msg_alloc(73, 13, 0, 2u);
          *v62 = v32;
          v62[1] = 1;
          ke_msg_send((int)v62);
          if ( v33[36] || v33[35] > 0x1Fu )
          {
            LOBYTE(v31) = *(uint8_t *)(v25 + 234);
          }
          else
          {
            v63 = (int *)off_131F34;
            v78 = v5;
            v64 = v33;
            v65 = (uint32_t *)(dword_131F24 - 664 + 8 * (87 * (int16_t)v32 + 78));
            v66 = (uint32_t *)(v22 + 8 * (165 * v33[34] + 159));
            v67 = 696 * v32 + dword_131F24;
            v68 = v22 + 1320 * v33[34];
            do
            {
              if ( *((uint32_t *)v64 + 146) )
              {
                if ( (__get_CPSR() & 1) == 0 )
                {
                  __disable_irq();
                  *(uint32_t *)off_131F28 = 1;
                }
                v69 = dword_131F2C;
                ++*v63;
                event_dispatch(v69);
                list_next(v65 - 10, v66 - 10);
                *(uint64_t *)(v68 + 1232) = *((uint64_t *)v64 + 73);
                zero_8_bytes(v65 - 10);
                v70 = *v63 - 1;
                if ( *v63 )
                {
                  v71 = off_131F28;
                  *v63 = v70;
                  if ( !v70 )
                  {
                    if ( *v71 )
                      __enable_irq();
                  }
                }
              }
              v72 = *((uint32_t *)v64 + 156);
              v68 += 8;
              v64 += 8;
              if ( v72 )
              {
                event_dispatch(dword_131F30);
                list_next(v66, v65);
                zero_8_bytes(v65);
              }
              v65 += 2;
              v66 += 2;
            }
            while ( (uint32_t *)v67 != v65 );
            v5 = v78;
            unknown_func_12d104(512);
            LOBYTE(v31) = *(uint8_t *)(v22 + 1320 * v7 + 234);
          }
        }
      }
    }
    *(uint8_t *)(v22 + 1320 * v7 + 234) = v31 + 1;
    llc_get_evt_ptr((uint8_t *)(v74 + v22));
  }
LABEL_24:
  ke_msg_send((int)v5);
  return 0;
}

