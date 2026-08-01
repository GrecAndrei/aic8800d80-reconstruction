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

extern uint32_t off_130EC4;
extern uint32_t dword_130ED4;
extern uint32_t dword_130EC0;
extern uint32_t off_130ED0;
extern uint32_t dword_130F2C;
extern uint32_t off_130ECC;
extern uint32_t dword_130EC8;

// rf_calc_tx_power_offset @ 0x130a5c, size 1230 bytes
int  rf_calc_tx_power_offset(int a1, int a2, uint16_t *a3, int a4, uint32_t *a5, uint16_t *a6, int a7)
{
  int v8; // r5
  int16_t v9; // r7
  int v10; // r6
  int v12; // r0
  uint16_t *v13; // r3
  int v14; // r0
  uint8_t *v15; // r7
  int v16; // r2
  int16_t v17; // r9
  int v18; // r0
  int v19; // lr
  int v20; // r3
  unsigned int v21; // r1
  int v22; // r12
  int v23; // r3
  int v24; // r8
  char *v25; // r2
  char *v26; // r12
  char v27; // t1
  unsigned int v28; // r12
  int v29; // r3
  char *v30; // lr
  unsigned int v31; // r12
  char *v32; // r2
  char v33; // t1
  int16_t v34; // r0
  int v35; // r3
  char *v36; // r2
  char v37; // t1
  int v38; // r5
  int v39; // r3
  int v40; // r9
  int v41; // r2
  int v42; // r1
  int v43; // r2
  int v44; // r3
  uint8_t *v45; // r2
  char i; // r1
  char v47; // t1
  uint16_t *v48; // r10
  int v49; // r3
  uint8_t *v50; // r5
  int v51; // r2
  int v52; // r3
  int16_t v53; // r3
  char *v55; // r0
  char *v56; // r2
  char v57; // t1
  int v58; // r5
  int16_t v59; // r9
  char v60; // r0
  uint8_t *v61; // r3
  uint8_t *v62; // r3
  uint8_t *v63; // r3
  uint8_t *v64; // r3
  uint8_t *v65; // r3
  uint8_t *v66; // r10
  unsigned int v67; // r9
  char *v68; // r2
  int v69; // r1
  int v70; // r0
  int v71; // lr
  char v72; // r4
  int v73; // r3
  int v74; // r12
  unsigned int v75; // r11
  char v76; // r1
  char v77; // r3
  int16_t v78; // lr
  uint8_t *v79; // r2
  int v80; // r12
  uint8_t *v81; // r12
  int16_t v82; // r0
  int16_t v83; // [sp+4h] [bp-60h]
  int v84; // [sp+8h] [bp-5Ch]
  char v85; // [sp+Ch] [bp-58h]
  char *v86; // [sp+10h] [bp-54h]
  int v87; // [sp+14h] [bp-50h]
  int v88; // [sp+18h] [bp-4Ch]
  uint8_t *v89; // [sp+1Ch] [bp-48h] BYREF
  char v90; // [sp+23h] [bp-41h] BYREF
  uint32_t v91[2]; // [sp+24h] [bp-40h] BYREF
  uint8_t v92[2]; // [sp+2Ch] [bp-38h] BYREF
  int v93; // [sp+2Eh] [bp-36h]
  int16_t v94; // [sp+32h] [bp-32h]
  int v95; // [sp+54h] [bp-10h]

  v8 = a7;
  v9 = *(uint16_t *)(a7 + 56);
  v10 = *(uint16_t *)(a7 + 54);
  if ( !v9 )
    v9 = 5;
  v89 = (uint8_t *)a1;
  v12 = rf_chan_valid_check(a4);
  v13 = v89;
  v14 = v12 | (*(uint32_t *)(a2 + 224) >> 1) & 0x10;
  *((uint16_t *)v89 + 1) = v9;
  *v13 = v14;
  v84 = (uint16_t)v14;
  v15 = (uint8_t *)(a7 + 64);
  if ( a3 )
  {
    v13[2] = *a3;
    v13[3] = a3[1];
    v13[4] = a3[2];
    v16 = 5;
    v17 = 10;
  }
  else
  {
    v16 = 2;
    v17 = 4;
  }
  *a5 = &v13[v16];
  v18 = *(uint8_t *)(a2 + 126);
  v89 = &v13[v16];
  LOBYTE(v13[v16]) = 0;
  v19 = v18 + 2;
  v89[1] = v18;
  if ( v18 )
  {
    v20 = (int)v89;
    v55 = (char *)(v18 + 127 + a2);
    v56 = (char *)(a2 + 127);
    do
    {
      v57 = *v56++;
      v56[v20 - a2 - 126] = v57;
    }
    while ( v55 != v56 );
  }
  else
  {
    v20 = (int)v89;
  }
  v21 = *(uint8_t *)(a2 + 176);
  v89 = (uint8_t *)(v19 + v20);
  *(uint8_t *)(v19 + v20) = 1;
  v22 = v21;
  if ( v21 >= 8 )
    v22 = 8;
  v89[1] = v22;
  v23 = (int)v89;
  v24 = v22 + 2;
  v25 = (char *)(a2 + 177);
  if ( v21 )
  {
    v26 = (char *)(v22 + 177 + a2);
    do
    {
      v27 = *v25++;
      v25[v23 - a2 - 176] = v27;
    }
    while ( v25 != v26 );
  }
  v28 = *(uint8_t *)(a2 + 176);
  v83 = v17 + v19 + v24;
  v89 = (uint8_t *)(v24 + v23);
  if ( v28 > 8 )
  {
    *(uint8_t *)(v24 + v23) = 50;
    v89[1] = v28 - 8;
    v29 = (int)v89;
    v30 = (char *)(v28 + 177 + a2);
    v31 = v28 - 6;
    v32 = (char *)(a2 + 185);
    do
    {
      v33 = *v32++;
      v32[v29 - a2 - 184] = v33;
    }
    while ( v32 != v30 );
    v89 = (uint8_t *)(v29 + v31);
    v83 += v31;
  }
  if ( (v84 & 0x100) == 0 )
    goto LABEL_17;
  v61 = v89++;
  *v61 = 33;
  v62 = v89++;
  *v62 = 2;
  read_calibration_offsets(v91, &v90);
  if ( SLOBYTE(v91[0]) > *(char *)(a2 + 172) )
    LOBYTE(v91[0]) = *(uint8_t *)(a2 + 172);
  v63 = v89++;
  *v63 = v90;
  v64 = v89++;
  *v64 = v91[0];
  v65 = v89++;
  *v65 = 36;
  v86 = v89;
  v66 = v89 + 1;
  if ( *(uint8_t *)(a2 + 164) )
  {
    v67 = *((uint8_t *)off_130EC4 + 371);
    v87 = 4;
    v68 = (char *)off_130EC4 + 202;
  }
  else
  {
    v67 = *((uint8_t *)off_130EC4 + 370);
    v87 = 1;
    v68 = (char *)off_130EC4 + 118;
  }
  if ( v67 )
  {
    v69 = 0;
    v88 = a2;
    v85 = 0;
    v70 = 0;
    v71 = 0;
    v72 = 0;
    while ( 1 )
    {
      v73 = v68[3] & 2;
      if ( (v68[3] & 2) == 0 )
        break;
LABEL_62:
      if ( v67 <= (uint8_t)++v69 )
      {
        v8 = a7;
        v76 = v72;
        v77 = v85 + 2;
        a2 = v88;
        v78 = (uint8_t)(v85 + 2);
        goto LABEL_64;
      }
    }
    v74 = *(uint16_t *)v68;
    if ( v68[2] )
    {
      if ( v68[2] == 1 )
      {
        v80 = v74 - 4992;
        if ( (uint16_t)(v80 - 13) <= 0x370u )
        {
          v75 = (unsigned int)(((unsigned int)dword_130ED4 * (unsigned uint64_t)(unsigned int)(v80 - 8)) >> 32) >> 2;
          v73 = (uint8_t)v75;
          goto LABEL_58;
        }
      }
    }
    else if ( (unsigned int)(v74 - 2412) <= 0x48 )
    {
      if ( v74 == 2484 )
      {
        v73 = 14;
        v75 = 14;
      }
      else
      {
        v75 = (unsigned int)(((unsigned int)dword_130ED4 * (unsigned uint64_t)(unsigned int)(v74 - 2407)) >> 32) >> 2;
        v73 = (uint8_t)v75;
      }
LABEL_58:
      if ( !v70 )
      {
        v71 = v73;
        v72 = v73;
        v70 = 1;
        goto LABEL_61;
      }
      if ( v75 - v71 == v87 )
      {
        v70 = (uint8_t)(v70 + 1);
        v71 = v73;
LABEL_61:
        v68 += 6;
        goto LABEL_62;
      }
      goto LABEL_71;
    }
    if ( !v70 )
    {
      v71 = 0;
      v72 = 0;
      v70 = 1;
      goto LABEL_61;
    }
LABEL_71:
    v89 = v66 + 1;
    *v66 = v72;
    v81 = v89++;
    *v81 = v70;
    v85 += 2;
    v71 = v73;
    v70 = (uint8_t)(v70 + 2);
    v66 = v89;
    goto LABEL_61;
  }
  v77 = 2;
  LOBYTE(v70) = 0;
  v76 = 0;
  v78 = 2;
LABEL_64:
  v89 = v66 + 1;
  *v66 = v76;
  v79 = v89++;
  *v79 = v70;
  v83 += v78 + 6;
  *v86 = v77;
LABEL_17:
  v34 = rf_write_pattern_4605((int)&v89);
  v35 = (int)v89;
  if ( v10 )
  {
    v36 = (char *)(a7 + 64);
    do
    {
      v37 = *v36++;
      v36[v35 - v8 - 65] = v37;
    }
    while ( v36 != &v15[v10] );
  }
  v38 = *(uint32_t *)(a2 + 224);
  v39 = v35 + v10;
  v40 = (uint16_t)(v83 + v10 + v34);
  v89 = (uint8_t *)v39;
  LOBYTE(v41) = v38;
  if ( (v38 & 1) != 0 )
  {
    v42 = *(uint32_t *)(dword_130EC0 + 4);
    v43 = *(uint32_t *)(dword_130EC0 + 8);
    v91[0] = *(uint32_t *)dword_130EC0;
    v91[1] = v42;
    v92[1] = BYTE1(v43);
    v94 = 0;
    v93 = 0;
    v92[0] = 0;
    v44 = v39 - (uint32_t)v91;
    v45 = v91;
    for ( i = -35; ; i = v47 )
    {
      v45[v44] = i;
      if ( v45 == v92 )
        break;
      v47 = *++v45;
    }
    v40 = (uint16_t)(v40 + 9);
    v89 += 9;
    LOBYTE(v41) = v38;
  }
  if ( (v38 & 2) != 0 && (*((uint8_t *)off_130EC4 + 374) & 1) != 0 )
  {
    v82 = build_tx_packet((int *)&v89);
    v41 = *(uint32_t *)(a2 + 224);
    v40 = (uint16_t)(v82 + v40);
  }
  if ( (v41 & 4) != 0 )
  {
    v48 = (uint16_t *)off_130EC4;
    v49 = *((uint8_t *)off_130EC4 + 374);
    if ( (v49 & 2) != 0 )
    {
      v58 = *((uint8_t *)off_130EC4 + 373);
      if ( (*(uint8_t *)off_130ED0 & 8) != 0
        || (ke_event_schedule(dword_130F2C, v49 << 30), *((uint8_t *)v48 + 373) <= 1u) )
      {
        v59 = v40 + rf_write_pattern_bf0c((int)&v89);
        v60 = rf_get_chan_index(v48[28]);
        if ( v58 == 4 )
          LOBYTE(v58) = 3;
      }
      else
      {
        v59 = v40 + rf_write_pattern_bf0c((int)&v89);
        v60 = rf_get_chan_index(v48[28]);
        LOBYTE(v58) = 1;
      }
      *v89 = -57;
      v89[1] = 1;
      v89[2] = v58 | (16 * v60);
      v41 = *(uint32_t *)(a2 + 224);
      v40 = (uint16_t)(v59 + 3);
      v89 += 3;
    }
  }
  if ( (v41 & 8) != 0 && (*((uint8_t *)off_130EC4 + 374) & 4) != 0 )
    v40 = (uint16_t)((uint16_t)rf_write_pattern_ff23((int)&v89) + v40);
  v50 = parse_data_1(v15, v10);
  init_radio_params(v15, v10, v84, v91);
  if ( *(uint16_t *)(a2 + 228)
    && (!v50 && (v51 = v95 << 26, (v95 & 0x20) != 0) || (*(uint32_t *)(*((uint32_t *)off_130ECC + 4) + 48) & 0x40) != 0) )
  {
    state_check_feature(256, dword_130EC8, v51);
    *v89 = 54;
    v89[1] = 3;
    v52 = (int)v89;
    *((uint16_t *)v89 + 1) = *(uint16_t *)(a2 + 228);
    *(uint8_t *)(v52 + 4) = *(uint8_t *)(a2 + 230);
    v40 = (uint16_t)(v40 + 5);
    v53 = (uint16_t)v89 + 5;
  }
  else
  {
    v53 = (int16_t)v89;
  }
  *a6 = v53 - *(uint16_t *)a5;
  return v40;
}

