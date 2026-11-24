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


extern uint32_t dword_10C3E8;
extern uint32_t dword_10C73C;
extern uint32_t dword_10C77C;
extern uint32_t dword_10C780;
extern uint32_t dword_10C790;
extern uint32_t dword_10C798;
extern uint32_t dword_10CA74;
extern uint32_t dword_10CBBC;
extern uint32_t dword_10CBCC;
extern uint32_t off_10C3D8;
extern uint32_t off_10C3DC;
extern uint32_t off_10C3E0;
extern uint32_t off_10C3E4;
extern uint32_t off_10C3EC;
extern uint32_t off_10C3F0;
extern uint32_t off_10C3F4;
extern uint32_t off_10C3F8;
extern uint32_t off_10C71C;
extern uint32_t off_10C720;
extern uint32_t off_10C724;
extern uint32_t off_10C72C;
extern uint32_t off_10C734;
extern uint32_t off_10C738;
extern uint32_t off_10C744;
extern uint32_t off_10C748;
extern uint32_t off_10C74C;
extern uint32_t off_10C750;
extern uint32_t off_10C754;
extern uint32_t off_10C758;
extern uint32_t off_10C75C;
extern uint32_t off_10C760;
extern uint32_t off_10C764;
extern uint32_t off_10C768;
extern uint32_t off_10C76C;
extern uint32_t off_10C770;
extern uint32_t off_10C774;
extern uint32_t off_10C778;
extern uint32_t off_10C784;
extern uint32_t off_10C794;
extern uint32_t off_10C79C;
extern uint32_t off_10C7A0;
extern uint32_t off_10C7A4;
extern uint32_t off_10CA68;
extern uint32_t off_10CA6C;
extern uint32_t off_10CA70;
extern uint32_t off_10CA78;
extern uint32_t off_10CA7C;
extern uint32_t off_10CA80;
extern uint32_t off_10CA84;
extern uint32_t off_10CA88;
extern uint32_t off_10CA90;
extern uint32_t off_10CA94;
extern uint32_t off_10CA98;
extern uint32_t off_10CA9C;
extern uint32_t off_10CAA4;
extern uint32_t off_10CAA8;
extern uint32_t off_10CAAC;
extern uint32_t off_10CBC8;
extern uint32_t off_10CBD4;
extern uint32_t off_10CBD8;
extern uint32_t off_10CBDC;

// sub_10C2E4 @ 0x10c2e4, size 2260 bytes
int sub_10C2E4()
{
  uint8_t *v0; // r0
  int *v1; // r2
  uint32_t *v2; // r3
  int v3; // r5
  uint32_t *v4; // r4
  int *v5; // r10
  int v6; // r1
  uint32_t *v7; // r3
  uint32_t *v8; // r1
  int v9; // r0
  uint32_t *v10; // r3
  uint32_t *v11; // r1
  uint32_t *v12; // r4
  unsigned int v13; // r0
  int v14; // r1
  int v15; // r4
  int v16; // r3
  int v17; // r4
  uint8_t *v18; // r8
  uint32_t *v19; // r9
  uint8_t *v20; // r7
  int v21; // r5
  int v22; // r0
  int v23; // r8
  uint32_t *v24; // r9
  int v25; // r4
  int i; // r5
  int v27; // r0
  uint8_t *v28; // r1
  int j; // r3
  int v30; // r2
  unsigned int v31; // r1
  unsigned int v32; // r0
  uint32_t *v33; // r4
  uint32_t *v34; // r3
  uint32_t *v35; // r2
  int *v36; // r3
  int *v37; // r1
  int *v38; // r2
  uint8_t *v39; // r10
  int v40; // r5
  int v41; // r0
  uint16_t *v42; // r7
  int v43; // r2
  int v44; // r0
  int result; // r0
  uint32_t *v46; // r3
  uint32_t *v47; // r1
  int *v48; // r2
  int v49; // r1
  int *v50; // r3
  int *v51; // r1
  int *v52; // r2
  int v53; // r3
  int v54; // r0
  int *v55; // r5
  uint8_t *v56; // r4
  unsigned int v57; // r0
  uint8_t *v58; // r7
  unsigned int v59; // r3
  int *v60; // r7
  int v61; // r0
  uint8_t *v62; // r10
  uint32_t *v63; // r3
  uint32_t *v64; // r1
  uint8_t *v65; // r3
  char v66; // r1
  char v67; // r2
  _UNKNOWN **v68; // r9
  int v69; // r7
  uint32_t *v70; // r6
  int v71; // r9
  uint8_t *v72; // r11
  uint8_t *v73; // r8
  int v74; // r5
  char v75; // t1
  int v76; // r1
  int v77; // r5
  _UNKNOWN **v78; // r9
  int v79; // r11
  uint8_t *v80; // r6
  uint32_t *v81; // r4
  int *v82; // r7
  uint8_t *v83; // r9
  int v84; // r5
  char v85; // t1
  int v86; // r3
  uint8_t *v87; // [sp+8h] [bp-A4h]
  int *v88; // [sp+8h] [bp-A4h]
  uint8_t *v89; // [sp+Ch] [bp-A0h]
  uint8_t a1[2]; // [sp+12h] [bp-9Ah] BYREF
  int v91; // [sp+14h] [bp-98h] BYREF
  int v92; // [sp+18h] [bp-94h] BYREF
  int v93; // [sp+1Ch] [bp-90h]
  int v94; // [sp+20h] [bp-8Ch]
  uint8_t v95[136]; // [sp+24h] [bp-88h] BYREF

  v0 = off_10C3DC;
  *((uint32_t *)off_10C3D8 + 64) = 8;
  if ( !v0[2] )
    *((uint32_t *)off_10C3E0 + 2) = *((uint32_t *)off_10C3E0 + 2) & 0xFFF9FFFF | 0x20000;
  v1 = (int *)off_10C3E0;
  while ( (*((uint32_t *)off_10C3E0 + 12) & 0x22) != 2 )
    ;
  v2 = off_10C3E4;
  v3 = dword_10C3E8;
  v4 = off_10C3D8;
  v5 = off_10C3F8;
  *((uint32_t *)off_10C3E0 + 2) = *((uint32_t *)off_10C3E0 + 2) & 0xFFFE73FE | 0x18401;
  *v2 = 6;
  v1[21] = v1[21] & 0x37F | 0x80 | v1[21] & v3;
  v4[81] = 16;
  v6 = *((uint8_t *)v5 + 177);
  *v1 = *v1 & 0x37F | 0x80 | v3 & *v1;
  if ( v6 && (v1[12] & 0x40) == 0 && (v1[12] & 4) != 0 )
  {
    v52 = (int *)off_10CA80;
    v53 = v5[42] | 0x2000000;
    *(uint8_t *)off_10CA7C = 1;
    *v52 = v53;
    v4[14] |= 0x10u;
  }
  else
  {
    *(uint32_t *)off_10C3EC = v5[42];
  }
  if ( v0[2] )
  {
    if ( **(uint8_t **)off_10C3F0 == 2 )
    {
      v63 = off_10CAA4;
      v64 = off_10CAA8;
      *((uint32_t *)off_10CAA4 + 20) |= 0x40000u;
      v64[7] &= ~0x100u;
      v63[9] = v63[9] & 0xFFFFFF00 | 0x60;
      v63[9] = v63[9] & 0xFFFF00FF | 0xDF00;
LABEL_11:
      sub_10D4C8();
      if ( !*(uint32_t *)off_10C3F4 )
        goto LABEL_15;
      goto LABEL_12;
    }
    v7 = off_10C3E0;
    **(uint8_t **)off_10C3F0 = 2;
    v8 = off_10C3D8;
    v9 = (uint8_t)v0[2];
    v7[20] |= 0x40000u;
    v8[7] &= ~0x100u;
    v7[9] = v7[9] & 0xFFFFFF00 | 0x60;
    v7[9] = v7[9] & 0xFFFF00FF | 0xDF00;
    if ( v9 )
      goto LABEL_11;
  }
  else
  {
    v10 = off_10C71C;
    v11 = off_10C720;
    *((uint32_t *)off_10C71C + 20) |= 0x40000u;
    v11[7] &= ~0x100u;
    v10[9] = v10[9] & 0xFFFFFF00 | 0x60;
    v10[9] = v10[9] & 0xFFFF00FF | 0xDF00;
  }
  sub_10D474();
  if ( *(uint32_t *)off_10C724 )
  {
LABEL_12:
    sub_10F1E0();
    sub_10E798();
    sub_10E4D8();
  }
LABEL_15:
  v12 = off_10C720;
  sub_10300C();
  v12[4] |= 2u;
  sub_103334();
  a1[0] = 0;
  a1[1] = 0;
  if ( (*v12 & 0x2000000) == 0 )
  {
    *(uint32_t *)v95 = 0;
    if ( sub_114558((int)v95) )
    {
      v13 = a1[0];
    }
    else
    {
      v13 = v95[0];
      a1[0] = v95[0];
      a1[1] = v95[1];
    }
    if ( v13 )
      goto LABEL_19;
LABEL_60:
    sub_10F170(15);
    goto LABEL_22;
  }
  sub_113B88(a1);
  sub_113BE8(&a1[1]);
  v13 = a1[0];
  if ( !a1[0] )
    goto LABEL_60;
LABEL_19:
  if ( v13 > 0x1F )
  {
    v13 = 31;
    a1[0] = 31;
  }
  sub_10F170(v13);
  sub_10DA6C("set xtal_cap 0x%x\n", a1[0]);
LABEL_22:
  v14 = a1[1];
  if ( a1[1] )
  {
    if ( a1[1] <= 0x3Fu )
    {
      v15 = (a1[1] << 18) & 0xFC0000;
    }
    else
    {
      v14 = 63;
      a1[1] = 63;
      v15 = 16515072;
    }
    *(uint32_t *)off_10C72C = *(uint32_t *)off_10C72C & 0xFF03FFFF | v15;
    sub_10DA6C("set xtal_cap_fine 0x%x\n", v14);
  }
  v16 = *(uint8_t *)off_10C734;
  if ( (v16 == 7 || v16 == 193) && !sub_113B4C() )
  {
    v57 = sub_113B5C(3);
    if ( v57 != 3 )
      sub_10DA6C("sdio_cfg error: %x\n", v57);
  }
  v17 = HIBYTE(*(uint32_t *)off_10C720) & 2;
  if ( v17 )
  {
    v18 = (uint8_t *)dword_10C790;
    v19 = off_10C794;
    v20 = off_10C738;
    v21 = 0;
    do
    {
      v22 = sub_113DF8(v21, *v19 + 3 * v21);
      ++v21;
      if ( v22 != 546 )
        v20[1] |= 1u;
      *v18 = v22 & 0xF;
      v18[1] = (uint8_t)v22 >> 4;
      v18[2] = BYTE1(v22) & 0xF;
      v18 += 3;
    }
    while ( v21 != 3 );
    v23 = dword_10C798;
    v24 = off_10C79C;
    v25 = dword_10C73C;
    for ( i = 0; i != 3; ++i )
    {
      v27 = sub_113F3C(i, *v24 + 6 * i);
      if ( v27 != v25 )
        v20[1] |= 1u;
      v28 = (uint8_t *)v23;
      for ( j = 0; j != 24; j += 4 )
      {
        v30 = v27 >> j;
        *v28++ = v30 & 0xF;
      }
      v23 += 6;
    }
    v31 = 31 - __clz(sub_114208());
    *v20 = v31;
  }
  else
  {
    v93 = 0;
    v94 = 0;
    v92 = 0;
    if ( sub_114570((int)&v92) )
    {
      v58 = off_10CA90;
    }
    else
    {
      v77 = dword_10CBCC;
      v78 = off_10CBDC;
      sub_10DA6C(aFlTxpwrOfst24g);
      v79 = 0;
      v88 = &v92;
      v80 = (uint8_t *)v77;
      v81 = v78;
      do
      {
        sub_10DA6C("\r\n  [%d] =", v79);
        v82 = v88;
        v83 = v80;
        v84 = 0;
        do
        {
          v85 = *(uint8_t *)v82;
          v82 = (int *)((char *)v82 + 1);
          *(uint8_t *)(*v81 + v84 + 3 * v79) = v85;
          v86 = *v81 + v84++;
          sub_10DA6C(" %d", *(char *)(v86 + 3 * v79));
          *v83++ = 15;
        }
        while ( v84 != 3 );
        ++v79;
        v88 = (int *)((char *)v88 + 3);
        v80 += 3;
      }
      while ( v79 != 3 );
      v58 = off_10CBD4;
      v17 = 0;
      sub_10DA6C((const char *)off_10CBC8);
      v58[1] |= 1u;
    }
    memset(v95, 0, 20);
    if ( !sub_114588((int)v95) )
    {
      v68 = off_10CBD8[0];
      sub_10DA6C(aFlTxpwrOfst5g);
      v89 = v58;
      v69 = dword_10CBBC;
      v87 = v95;
      v70 = v68;
      v71 = 0;
      do
      {
        sub_10DA6C("\r\n  [%d] =", v71);
        v72 = v87;
        v73 = (uint8_t *)v69;
        v74 = 0;
        do
        {
          v75 = *v72++;
          *(uint8_t *)(*v70 + v17 + v74) = v75;
          v76 = *(char *)(*v70 + v17 + v74++);
          sub_10DA6C(" %d", v76);
          *v73++ = 15;
        }
        while ( v74 != 6 );
        v17 += 6;
        ++v71;
        v87 += 6;
        v69 += 6;
      }
      while ( v17 != 18 );
      v58 = v89;
      sub_10DA6C((const char *)off_10CBC8);
      v89[1] |= 1u;
    }
    if ( sub_1145DC((int)&v91) )
    {
      v31 = -1;
      *v58 = -1;
    }
    else
    {
      v59 = (char)v91;
      *v58 = v91;
      v31 = v59;
    }
  }
  sub_10DA6C("cal_ver=%d\n", v31);
  if ( *((uint8_t *)v5 + 372) )
  {
    if ( (*(uint32_t *)off_10C720 & 0x2000000) != 0 )
    {
      if ( sub_1141CC() )
      {
        v54 = sub_11413C();
        v55 = (int *)off_10CA84;
        v56 = off_10CA88;
        *(uint8_t *)off_10CA88 = *((uint8_t *)off_10CA84 + v54);
        v56[1] = *((uint8_t *)v55 + sub_11414C());
        v56[2] = *((uint8_t *)v55 + sub_11415C());
      }
    }
    else
    {
      *(uint32_t *)v95 = 0;
      if ( !sub_1145B8((int)v95) )
      {
        v65 = off_10CA88;
        v66 = *((uint8_t *)off_10CA84 + v95[1]);
        v67 = *((uint8_t *)off_10CA84 + v95[2]);
        *(uint8_t *)off_10CA88 = *((uint8_t *)off_10CA84 + v95[0]);
        v65[1] = v66;
        v65[2] = v67;
      }
    }
  }
  v32 = sub_1141DC();
  v33 = off_10C744;
  if ( v32 )
    *(uint32_t *)off_10C744 |= 1u;
  if ( sub_1141F8() )
    *v33 |= 2u;
  *(uint32_t *)off_10C748 &= 0xFFFFFFC7;
  if ( (*(uint8_t *)off_10C734 & 0xC0) == 0xC0 )
  {
    v34 = off_10C750;
    *off_10C74C = off_10C754;
    v35 = (uint32_t *)off_10C758;
    *v34 = off_10C75C;
    v36 = (int *)off_10C760;
    v37 = off_10C764;
    *v35 = off_10C760;
    v38 = (int *)off_10C768[0];
    *v37 = (int)v36;
    *v38 = (int)off_10C76C;
  }
  sub_102D4C(0, 0, 0x10u, off_10C770);
  sub_102D4C(0, 16, 0x10u, off_10C774);
  if ( (*v33 & 2) == 0 )
  {
    v60 = (int *)off_10CA94;
    sub_102D4C(0, 32, 0x10u, (int)off_10CA94[2]);
    sub_102D4C(0, 48, 0x10u, v60[1]);
    sub_102D4C(0, 64, 0x10u, *v60);
    sub_102D4C(1, 0, 0x10u, *(uint32_t *)off_10CA98);
    sub_102D4C(1, 16, 0x10u, *(uint32_t *)off_10CA9C);
  }
  sub_100D18();
  sub_1033C4(1);
  sub_100C3C(0);
  sub_1033C4(0);
  if ( (*(uint8_t *)off_10C734 & 0xC0) != 0xC0 && (v5[98] & 4) != 0 )
  {
    v48 = (int *)off_10CA70;
    v49 = dword_10CA74;
    ((uint32_t *)(uintptr_t)off_10CA70)[13] = dword_10CA74;
    v49 += 36;
    v48[14] = v49;
    v49 -= 37;
    v48[109] = v49;
    v49 += 27;
    v48[110] = v49;
    v49 -= 25;
    v48[204] = v49;
    v49 += 17;
    v48[205] = v49;
    v49 += 16;
    v48[206] = v49;
    v49 += 25;
    v48[15] = v49;
    v48[111] = v49;
    v48[207] = v49;
    v48[303] = v49;
    v48[399] = v49;
    v48[495] = v49;
    v49 -= 48;
    v50 = (int *)off_10CA78;
    v48[300] = v49;
    v48[396] = v49;
    v48[492] = v49;
    v49 += 16;
    v48[301] = v49;
    v48[397] = v49;
    v48[493] = v49;
    v49 += 16;
    v48[302] = v49;
    v48[398] = v49;
    v48[494] = v49;
    v51 = v50 + 1896;
    do
    {
      v50[318] |= 0x8000u;
      v50 += 316;
    }
    while ( v51 != v50 );
  }
  v39 = off_10C7A0;
  v40 = dword_10C77C;
  *(uint32_t *)off_10C778 |= 0x8000000u;
  v92 = 3983;
  v93 = v40;
  *v39 = 2;
  sub_10C1B4(0, 2437, (int)&v92, (int)v95);
  *v39 = 0;
  sub_102E84(0, 0, 0);
  sub_10C1EC(0, 2437, (int)&v92, (int)v95, 1u, 0);
  if ( (*v33 & 2) == 0 )
  {
    v62 = off_10CAAC;
    v92 = 3855;
    *(uint8_t *)off_10CAAC = 2;
    sub_10C1B4(1, 5250, (int)&v92, (int)v95);
    sub_10C1B4(1, 5500, (int)&v92, (int)v95);
    sub_10C1B4(1, 5700, (int)&v92, (int)v95);
    *v62 = 0;
    sub_102E84(1, 0, 0);
    sub_10C1EC(1, 5700, (int)&v92, (int)v95, 1u, 0);
    sub_10C1EC(1, 5250, (int)&v92, (int)v95, 1u, 0);
    sub_10C1EC(1, 5500, (int)&v92, (int)v95, 1u, 0);
  }
  v41 = sub_126E54();
  v42 = off_10C784;
  v43 = ((int)(((uint64_t)(dword_10C780 * (uint64_t)(4 * (v41 - 35))) >> 32) + 4 * (v41 - 35)) >> 2)
      - ((4 * (v41 - 35)) >> 31)
      + 120;
  *(uint16_t *)off_10C7A4 = v43;
  *v42 = v43;
  sub_11F504("Init T=%d C, ipa_target=%d\n", v41, v43);
  if ( (*v33 & 2) == 0 )
  {
    v61 = sub_10ED50((int)&v91);
    sub_10DA6C("cal_ipa_5g offset=%d, cgm=%d\n", v61, v91);
  }
  v44 = sub_10EE7C();
  sub_10DA6C("cal_ipa_24g offset=%d\n", v44);
  sub_10C1EC(1, 5500, (int)&v92, (int)v95, 0, 1u);
  result = sub_101E18(0, 2437, 0x985u, 0, 0, 0);
  v46 = off_10CA68;
  v47 = off_10CA6C;
  *(uint32_t *)off_10CA68 |= 0x20000u;
  *v46 |= 0x10000u;
  *v47 |= 1u;
  return result;
}
