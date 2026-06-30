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

extern uint32_t off_1385F8;
extern uint32_t off_138618;
extern uint32_t off_1385FC;
extern uint32_t dword_138600;
extern uint32_t off_138604;
extern uint32_t dword_138608;
extern uint32_t dword_13860C;
extern uint32_t off_138624;
extern uint32_t off_138664;
extern uint32_t off_138610;
extern uint32_t off_138614;
extern uint32_t dword_138620;
extern uint32_t dword_13861C;

// sub_1382DC @ 0x1382dc, size 902 bytes
// Doc: sub_12382DC [mac]: Initialize channel/scan context from global state struct
// sub_12382DC [mac]: Initialize channel/scan context from global state struct
uint32_t *sub_1382DC()
{
  uint8_t *v0; // r5
  unsigned int v1; // r1
  int v2; // r6
  int v3; // r7
  int v4; // r3
  int v5; // r4
  int v6; // r2
  int v7; // r0
  int v8; // r7
  uint64_t v9; // r0
  int v10; // r0
  int v11; // r8
  int v12; // r4
  int v13; // r1
  int v14; // r3
  int v15; // r2
  int v16; // r1
  int v17; // r10
  int *v18; // r3
  uint32_t *v19; // r2
  int v20; // r12
  int v21; // r4
  int v22; // r0
  uint8_t *v23; // lr
  unsigned int v24; // r1
  uint8_t *v25; // r4
  uint8_t *v26; // r6
  char *v27; // r3
  char *v28; // r2
  char *v29; // r2
  char *v30; // r12
  char v31; // t1
  uint8_t *v32; // r3
  uint8_t *v33; // r3
  char *v34; // r2
  uint8_t *v35; // r3
  int v36; // r8
  uint8_t *v37; // r3
  uint8_t *v38; // r12
  char v39; // t1
  uint8_t *v40; // r3
  uint8_t *v41; // r3
  int v42; // r2
  uint8_t *v43; // r8
  int v44; // r0
  uint8_t *v45; // r3
  uint8_t *v46; // r6
  uint8_t *v47; // r0
  char v48; // r3
  int v49; // r2
  uint16_t *v50; // r5
  int v51; // r2
  unsigned int v52; // r3
  int v54; // r2
  int v55; // r6
  char *v56; // r0
  uint8_t *v57; // r12
  char v58; // t1
  int v59; // r12
  uint8_t *v60; // r3
  uint8_t *v61; // lr
  uint8_t *v62; // r0
  char v63; // r2
  unsigned int v64; // [sp+4h] [bp-Ch]
  int v65; // [sp+Ch] [bp-4h] BYREF

  v0 = (uint8_t *)off_1385F8;
  v1 = *((uint8_t *)off_1385F8 + 3851);
  v2 = *(uint32_t *)off_1385F8;
  if ( v1 > 1 )
    return sub_1374C8(0);
  v3 = 0;
  while ( !*(uint8_t *)(v2 + 367) )
  {
LABEL_59:
    v3 = 1;
    if ( v1 == 1 )
    {
      *((uint8_t *)off_1385F8 + 3851) = 2;
      return sub_1374C8(0);
    }
    v1 = 1;
  }
  v4 = *(uint32_t *)off_1385F8;
  v5 = 0;
  while ( 1 )
  {
    v6 = *(uint8_t *)(v4 + 2);
    v4 += 6;
    if ( v6 == v1 )
      break;
    if ( ++v5 == *(uint8_t *)(v2 + 367) )
      goto LABEL_59;
  }
  if ( v3 )
    *((uint8_t *)off_1385F8 + 3851) = v1;
  v7 = sub_12C92C(2048, 2, 4, 0x178u);
  *(uint8_t *)(v7 + 366) = *(uint8_t *)(v2 + 366);
  v8 = v7;
  v9 = *(uint64_t *)(v2 + 352);
  *(uint32_t *)(v8 + 352) = v9;
  *(uint16_t *)(v8 + 356) = WORD2(v9);
  v10 = *(uint8_t *)(v2 + 368);
  *(uint8_t *)(v8 + 368) = v10;
  *(uint8_t *)(v8 + 369) = *(uint8_t *)(v2 + 369);
  *(uint32_t *)(v8 + 372) = *(uint32_t *)(v2 + 372);
  if ( v5 >= *(uint8_t *)(v2 + 367) )
  {
    v11 = v0[3851];
  }
  else
  {
    v11 = v0[3851];
    v12 = v2 + 6 * v5;
    v13 = 6 * *(uint8_t *)(v2 + 367) + v2;
    do
    {
      if ( *(uint8_t *)(v12 + 2) == v11 )
      {
        v14 = *(uint8_t *)(v8 + 367);
        v15 = 3 * v14;
        *(uint32_t *)(v8 + 2 * v15) = *(uint32_t *)v12;
        *(uint16_t *)(v8 + 2 * v15 + 4) = *(uint16_t *)(v12 + 4);
        *(uint8_t *)(v8 + 367) = v14 + 1;
      }
      v12 += 6;
    }
    while ( v12 != v13 );
  }
  if ( v10 )
  {
    v16 = 252;
    v17 = 33 * (int16_t)v10 + 252;
    do
    {
      v18 = (int *)(v2 + v16);
      v19 = (uint32_t *)(v8 + v16);
      do
      {
        v20 = *v18;
        v21 = v18[1];
        v22 = v18[2];
        v19[3] = v18[3];
        v18 += 4;
        *v19 = v20;
        v19[1] = v21;
        v19[2] = v22;
        v19 += 4;
      }
      while ( v18 != (int *)(v2 + v16 + 32) );
      v16 += 33;
      *(uint8_t *)v19 = *(uint8_t *)v18;
    }
    while ( v17 != v16 );
  }
  v23 = (uint8_t *)off_138618;
  v24 = *(uint16_t *)(*(uint32_t *)v0 + 364);
  v25 = off_1385FC;
  if ( v24 >= 0xC9 )
    v24 = 0;
  v26 = (uint8_t *)off_138618;
  if ( v11 == 1 )
  {
    v27 = (char *)dword_138600;
    v11 = 8;
  }
  else
  {
    v27 = (char *)dword_138600;
    if ( *(uint8_t *)(*(uint32_t *)v0 + 369) )
      v11 = 8;
    else
      v27 = (char *)(dword_138600 - 4);
    if ( !*(uint8_t *)(*(uint32_t *)v0 + 369) )
      v11 = 12;
  }
  v28 = (char *)off_138604;
  *((uint8_t *)off_138604 + 20) = 1;
  v29 = v28 + 21;
  v25[1] = 8;
  v30 = v27 + 8;
  do
  {
    v31 = *v27++;
    *++v29 = v31;
  }
  while ( v27 != v30 );
  v32 = (uint8_t *)dword_138608;
  v65 = dword_138608;
  if ( v24 )
  {
    v54 = *v23;
    if ( v54 == 10 )
    {
      v55 = (uint8_t)(v23[1] + 2);
      if ( v23[1] != 0xFE )
      {
        v56 = (char *)off_138618;
        v57 = (uint8_t *)(dword_138608 + v55);
        while ( 1 )
        {
          *v32++ = v54;
          if ( v57 == v32 )
            break;
          v58 = *++v56;
          LOBYTE(v54) = v58;
        }
        v32 = (uint8_t *)v65;
      }
      v65 = (int)&v32[v55];
      v24 = (uint16_t)(v24 - v55);
      v26 = &v23[v55];
    }
  }
  if ( v11 != 8 )
  {
    v33 = (uint8_t *)v65;
    v34 = (char *)dword_13860C;
    ++v65;
    *v33 = 50;
    v35 = (uint8_t *)v65;
    v36 = (uint8_t)(v11 - 8);
    ++v65;
    *v35 = v36;
    v37 = (uint8_t *)v65;
    v38 = (uint8_t *)(v65 + 4);
    do
    {
      v39 = *v34++;
      *v37++ = v39;
    }
    while ( v37 != v38 );
    v65 += v36;
  }
  if ( !v0[3851] )
  {
    v40 = (uint8_t *)v65++;
    *v40 = 3;
    v41 = (uint8_t *)v65++;
    *v41 = 1;
    ++v65;
  }
  if ( !v24 )
  {
    v43 = off_138624;
    v48 = *((uint8_t *)off_138624 + 374);
    if ( (v48 & 1) == 0 )
      goto LABEL_48;
    fmac_msg_init_header(&v65);
LABEL_74:
    v48 = v43[374];
LABEL_48:
    if ( v0[3851] == 1 )
      goto LABEL_44;
LABEL_49:
    if ( (v48 & 4) == 0 )
      goto LABEL_50;
    goto LABEL_46;
  }
  v42 = *v26;
  if ( v42 == 59 )
  {
    v44 = v65;
    v59 = (uint8_t)(v26[1] + 2);
    if ( v26[1] == 0xFE )
    {
      v43 = off_138664;
      if ( (*((uint8_t *)off_138664 + 374) & 1) == 0 )
        goto LABEL_40;
    }
    else
    {
      v60 = (uint8_t *)v65;
      v61 = &v26[-v65];
      v62 = (uint8_t *)(v65 + v59);
      while ( 1 )
      {
        *v60++ = v42;
        if ( v62 == v60 )
          break;
        LOBYTE(v42) = v60[(uint32_t)v61];
      }
      v43 = off_138624;
      v63 = *((uint8_t *)off_138624 + 374);
      v24 = (uint16_t)(v24 - v59);
      v26 += v59;
      v65 += v59;
      if ( (v63 & 1) == 0 )
      {
LABEL_69:
        if ( v24 )
        {
          v44 = v65;
          LOBYTE(v42) = *v26;
          goto LABEL_40;
        }
        goto LABEL_74;
      }
    }
LABEL_72:
    v64 = v24;
    fmac_msg_init_header(&v65);
    v24 = v64;
    goto LABEL_69;
  }
  v43 = off_138624;
  if ( (*((uint8_t *)off_138624 + 374) & 1) != 0 )
    goto LABEL_72;
  v44 = v65;
LABEL_40:
  v45 = (uint8_t *)v44;
  v46 = &v26[-v44];
  v47 = (uint8_t *)(v44 + v24);
  while ( 1 )
  {
    *v45++ = v42;
    if ( v47 == v45 )
      break;
    LOBYTE(v42) = v45[(uint32_t)v46];
  }
  v48 = v43[374];
  v49 = v0[3851];
  v65 += v24;
  if ( v49 != 1 )
    goto LABEL_49;
LABEL_44:
  if ( (v48 & 2) == 0 )
    goto LABEL_49;
  fmac_dbg_marker_set((int)&v65);
  if ( (v43[374] & 4) != 0 )
LABEL_46:
    mac_frame_hdr_init((int)&v65);
LABEL_50:
  v50 = (uint16_t *)off_138610;
  sub_143770(v65, (char *)off_138610 + 3, *(uint16_t *)off_138610);
  v51 = **(int16_t **)off_138614;
  v65 += *v50;
  v52 = v65 - (uint32_t)v25;
  if ( v51 < 0 && v52 > 0x12C )
  {
    sub_12F46C(dword_138620, dword_13861C, 182);
    LOWORD(v52) = v65 - (uint16_t)v25;
  }
  *(uint16_t *)(v8 + 364) = v52;
  *(uint32_t *)(v8 + 360) = 0;
  return (uint32_t *)sdio_buffer_prepare_n_4e8(v8);
}

