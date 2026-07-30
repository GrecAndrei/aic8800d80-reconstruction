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

extern uint32_t off_103560;
extern uint32_t off_10355C;
extern uint32_t off_103564;
extern uint32_t off_103568;
extern uint32_t dword_10356C;
extern uint32_t off_103570;
extern uint32_t off_103580;
extern uint32_t off_1038F0;
extern uint32_t off_1038EC;
extern uint32_t off_103574;
extern uint32_t off_103578;
extern uint32_t off_103A24;
extern uint32_t off_103A28;
extern uint32_t off_10357C;
extern uint32_t off_103898;
extern uint32_t off_10389C;
extern uint32_t off_1038A0;
extern uint32_t off_1038A4;
extern uint32_t off_1038A8;
extern uint32_t off_1038AC;
extern uint32_t dword_1038FC;
extern uint32_t dword_103900;
extern uint32_t off_103A48;
extern uint32_t dword_103A50;
extern uint32_t dword_103A44;
extern uint32_t dword_103A3C;
extern uint32_t off_103A4C;
extern uint32_t dword_103A40;
extern uint32_t off_103A34;
extern uint32_t dword_103A38;
extern uint32_t dword_1038B0;
extern uint32_t dword_1038F4;
extern uint32_t off_1038F8;
extern uint32_t off_103A30;
extern uint32_t dword_103A2C;
extern uint32_t dword_1038B8;
extern uint32_t off_1038BC;
extern uint32_t off_1038B4;
extern uint32_t dword_1038C4;
extern uint32_t off_1038C8;
extern uint32_t off_1038CC;

// sub_1033F8 @ 0x1033f8, size 1580 bytes
void __noreturn sub_1033F8()
{
  uint8_t *v0; // r4
  int *v1; // r2
  uint32_t *v2; // r0
  int v3; // r1
  uint32_t *v4; // r5
  uint8_t **v5; // r5
  uint32_t *v6; // r1
  int v7; // r6
  uint32_t *v8; // r0
  uint32_t *v9; // r8
  int v10; // r2
  uint32_t *v11; // r3
  uint32_t *v12; // r1
  int v13; // r0
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int v17; // r0
  uint32_t *v18; // r3
  uint32_t *v19; // r1
  int v20; // r0
  uint32_t *v21; // r4
  uint32_t *v22; // r5
  uint8_t *v23; // r6
  int v24; // r9
  int i; // r4
  int v26; // r0
  uint32_t *v27; // r4
  int v28; // r9
  int v29; // r10
  int k; // r5
  int v31; // r0
  int v32; // r5
  int v33; // r10
  int v34; // r0
  int v35; // r9
  unsigned uint64_t v36; // kr00_8
  int v37; // zf
  uint8_t v38; // r2
  int v39; // r3
  unsigned int v40; // r1
  int v41; // r2
  int v42; // r0
  int v43; // r3
  int *v44; // r4
  int j; // r4
  uint8_t v46; // r2
  int *v47; // r2
  int v48; // r3
  int v49; // r1
  int v50; // r2
  int v51; // r6
  uint8_t *v52; // r6
  int v53; // r1
  int v54; // r2
  unsigned int v55; // r3
  int v56; // r0
  int v57; // r5
  uint8_t *v58; // r4
  uint32_t *v59; // r3
  uint32_t *v60; // r1
  uint8_t *v61; // r3
  char v62; // r1
  char v63; // r2
  uint32_t *v64; // r4
  int v65; // r10
  int v66; // r2
  int v67; // r11
  uint32_t *v68; // r6
  uint8_t *v69; // r4
  char *v70; // r7
  int n; // r5
  int v72; // t1
  int v73; // r3
  int v74; // r1
  uint32_t *v75; // r5
  int v76; // r9
  int v77; // r2
  uint32_t *v78; // r7
  int v79; // r11
  char *v80; // r10
  int m; // r4
  int v82; // t1
  int v83; // r1
  int v84; // r1
  uint8_t *v85; // [sp+4h] [bp-30h]
  uint8_t v86[4]; // [sp+Ch] [bp-28h] BYREF
  uint32_t v87[3]; // [sp+10h] [bp-24h] BYREF
  uint8_t v88[24]; // [sp+1Ch] [bp-18h] BYREF

  v0 = off_103560;
  *((uint32_t *)off_10355C + 64) = 8;
  if ( !v0[2] )
    *((uint32_t *)off_103564 + 2) = *((uint32_t *)off_103564 + 2) & 0xFFF9FFFF | 0x20000;
  v1 = (int *)off_103564;
  while ( (*((uint32_t *)off_103564 + 12) & 0x22) != 2 )
    ;
  v2 = off_103568;
  v3 = dword_10356C;
  v4 = off_10355C;
  *((uint32_t *)off_103564 + 2) = *((uint32_t *)off_103564 + 2) & 0xFFFE73FE | 0x18401;
  *v2 = 6;
  v1[21] = v1[21] & 0x37F | 0x80 | v1[21] & v3;
  v4[81] = 16;
  v5 = (uint8_t **)off_103570;
  *v1 = *v1 & 0x37F | 0x80 | *v1 & v3;
  if ( **v5 == 1 )
  {
    *v1 = *v1 & 0x3F7 | 8 | *v1 & v3;
    v1[21] = v3 & v1[21] | v1[21] & 0x3F7 | 8;
  }
  sub_10DD54();
  v6 = off_103564;
  v7 = dword_10356C;
  v8 = off_10355C;
  v9 = off_103580;
  *(uint32_t *)off_103564 = *(uint32_t *)off_103564 & 0x3EF | 0x10 | *(uint32_t *)off_103564 & dword_10356C;
  v6[21] = v6[21] & 0x3EF | 0x10 | v6[21] & v7;
  v8[22] &= 0xFFFFFFC1;
  v10 = *((uint8_t *)v9 + 177);
  v8[22] |= 0x26u;
  if ( v10 && (v6[12] & 0x40) == 0 && (v6[12] & 4) != 0 )
  {
    v47 = (int *)off_1038F0;
    v48 = v9[42] | 0x2000000;
    *(uint8_t *)off_1038EC = 1;
    *v47 = v48;
    v8[14] |= 0x10u;
  }
  else
  {
    *(uint32_t *)off_103574 = v9[42];
  }
  if ( v0[2] )
  {
    if ( **(uint8_t **)off_103578 == 2 )
    {
      v59 = off_103A24;
      v60 = off_103A28;
      *((uint32_t *)off_103A24 + 20) |= 0x40000u;
      v60[7] &= ~0x100u;
      v59[9] = v59[9] & 0xFFFFFF00 | 0x60;
      v59[9] = v59[9] & 0xFFFF00FF | 0xDF00;
LABEL_13:
      v14 = sub_10D4E8();
      v15 = sub_10D0E4(v14);
      if ( !*(uint32_t *)off_10357C )
        goto LABEL_17;
      goto LABEL_14;
    }
    v11 = off_103564;
    **(uint8_t **)off_103578 = 2;
    v12 = off_10355C;
    v13 = (uint8_t)v0[2];
    v11[20] |= 0x40000u;
    v12[7] &= ~0x100u;
    v11[9] = v11[9] & 0xFFFFFF00 | 0x60;
    v11[9] = v11[9] & 0xFFFF00FF | 0xDF00;
    if ( v13 )
      goto LABEL_13;
  }
  else
  {
    v18 = off_103898;
    v19 = off_10389C;
    *((uint32_t *)off_103898 + 20) |= 0x40000u;
    v19[7] &= ~0x100u;
    v18[9] = v18[9] & 0xFFFFFF00 | 0x60;
    v18[9] = v18[9] & 0xFFFF00FF | 0xDF00;
  }
  v20 = sub_10D494();
  v15 = sub_10D0E4(v20);
  if ( !*(uint32_t *)off_1038A0 )
  {
LABEL_17:
    v21 = off_10389C;
    sub_102ED0();
    v21[4] |= 2u;
    sub_1031D8();
    if ( (*v21 & 0x2000000) != 0 )
    {
      v22 = off_1038A4;
      v23 = off_1038A8;
      v24 = 1;
      for ( i = 0; i != 3; ++i )
      {
        v26 = sub_1147E0(i, *v22 + 3 * i);
        if ( v26 != 546 )
        {
          v23[1] |= 1u;
          v24 = 0;
        }
      }
      if ( v24 )
      {
        for ( j = 0; j != 3; ++j )
        {
          v88[0] = 0;
          if ( sub_1148FC(j, v88) <= 1 )
          {
            v46 = v88[0];
            *(uint8_t *)(*v22 + j) = v88[0];
            *(uint8_t *)(*v22 + j + 3) = v46;
            *(uint8_t *)(*v22 + j + 6) = v46;
          }
        }
      }
      v27 = off_1038AC;
      v28 = dword_1038FC;
      v29 = 1;
      for ( k = 0; k != 3; ++k )
      {
        v31 = sub_11485C(k, *v27 + 6 * k);
        if ( v31 != v28 )
        {
          v23[1] |= 1u;
          v29 = 0;
        }
      }
      if ( v29 )
      {
        v32 = 0;
        v33 = dword_103900;
        v88[0] = 0;
        v34 = 2;
        v35 = 4;
        do
        {
          v36 = (unsigned int)v33 * (unsigned uint64_t)(unsigned int)(2 * v32);
          v37 = v35 == HIDWORD(v36) >> 1;
          v35 = HIDWORD(v36) >> 1;
          if ( !v37 )
            v34 = sub_114944(HIDWORD(v36) >> 1, v88);
          if ( v34 <= 1 )
          {
            v38 = v88[0];
            *(uint8_t *)(*v27 + v32) = v88[0];
            v39 = *v27 + v32;
            *(uint8_t *)(v39 + 6) = v38;
            *(uint8_t *)(v39 + 12) = v38;
          }
          ++v32;
        }
        while ( v32 != 6 );
      }
      v40 = 31 - __clz(sub_114A6C());
      *v23 = v40;
    }
    else
    {
      memset(v87, 0, sizeof(v87));
      v51 = sub_114C00(v87);
      if ( v51 )
      {
        v52 = off_1038A8;
      }
      else
      {
        v75 = off_103A48;
        v76 = dword_103A50;
        sub_10DAE4(dword_103A44, v49, v50);
        v78 = v87;
        do
        {
          sub_10DAE4(dword_103A3C, v51, v77);
          v79 = 3 * v51;
          v80 = (char *)v78;
          for ( m = 0; m != 3; ++m )
          {
            v82 = *v80++;
            *(uint8_t *)(*v75 + v79 + m) = v82;
            v83 = *(char *)(*v75 + v79 + m);
            sub_10DAE4(v76, v83, v82);
          }
          ++v51;
          v78 = (uint32_t *)((char *)v78 + 3);
        }
        while ( v51 != 3 );
        v52 = off_103A4C;
        sub_10DAE4(dword_103A40, v84, v77);
        v52[1] |= 1u;
      }
      memset(v88, 0, 20);
      if ( !sub_114C0C(v88) )
      {
        v64 = off_103A34;
        v65 = dword_103A50;
        sub_10DAE4(dword_103A38, v53, v54);
        v67 = 0;
        v85 = v52;
        v68 = v64;
        v69 = v88;
        do
        {
          sub_10DAE4(dword_103A3C, v67, v66);
          v70 = (char *)v69;
          for ( n = 0; n != 6; ++n )
          {
            v72 = *v70++;
            *(uint8_t *)(*v68 + n + 6 * v67) = v72;
            v73 = *v68 + n;
            sub_10DAE4(v65, *(char *)(v73 + 6 * v67), v72);
          }
          ++v67;
          v69 += 6;
        }
        while ( v67 != 3 );
        v52 = v85;
        sub_10DAE4(dword_103A40, v74, v66);
        v85[1] |= 1u;
      }
      if ( sub_114C30(v86) )
      {
        v40 = -1;
        *v52 = -1;
      }
      else
      {
        v55 = v86[0];
        *v52 = v86[0];
        v40 = v55;
      }
    }
    v42 = sub_10DAE4(dword_1038B0, v40, v41);
    if ( *((uint8_t *)v9 + 372) )
    {
      if ( (*(uint32_t *)off_10389C & 0x2000000) != 0 )
      {
        if ( sub_114A30(v42) )
        {
          v56 = sub_1149C8();
          v57 = dword_1038F4;
          v58 = off_1038F8;
          *(uint8_t *)off_1038F8 = *(uint8_t *)(dword_1038F4 + v56);
          v58[1] = *(uint8_t *)(v57 + sub_1149DC());
          v58[2] = *(uint8_t *)(v57 + sub_1149F0());
        }
      }
      else
      {
        *(uint32_t *)v88 = 0;
        if ( !sub_114C18(v88) )
        {
          v61 = off_103A30;
          v62 = *(uint8_t *)(dword_103A2C + v88[1]);
          v63 = *(uint8_t *)(dword_103A2C + v88[2]);
          *(uint8_t *)off_103A30 = *(uint8_t *)(dword_103A2C + v88[0]);
          v61[1] = v62;
          v61[2] = v63;
        }
      }
    }
    v43 = dword_1038B8;
    v44 = (int *)off_1038BC;
    *(uint32_t *)off_1038B4 &= 0xFFFFFFC7;
    sub_102E08(0, 0, 0x10u, v43);
    sub_102E08(0, 16, 0x10u, dword_1038C4);
    sub_102E08(0, 32, 0x10u, v44[2]);
    sub_102E08(0, 48, 0x10u, v44[1]);
    sub_102E08(0, 64, 0x10u, *v44);
    sub_102E08(1, 0, 0x10u, *(uint32_t *)off_1038C8);
    sub_102E08(1, 16, 0x10u, *(uint32_t *)off_1038CC);
    sub_100EE8();
    sub_10327C();
  }
LABEL_14:
  v16 = sub_10EE10(v15);
  v17 = sub_10E420(v16);
  sub_10E160(v17);
  goto LABEL_17;
}

