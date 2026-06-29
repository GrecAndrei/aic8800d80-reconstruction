// fwstruct annotate: 10a138_sub_10A138.c
// sub_10A138 @ 0x10a138, size 1512 bytes
int __fastcall sub_10A138(
        _DWORD *a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        __int64 *a11)
{
  _DWORD *v11; // r10
  int v13; // r1
  int v14; // r2
  float v15; // s20
  int v17; // r7
  unsigned int v19; // r3
  int v20; // r11
  unsigned int v21; // r0
  char *v22; // r7
  int v23; // r4
  int v24; // r1
  int v25; // r1
  float v26; // s21
  float v27; // s22
  float v28; // s17
  float v29; // s23
  float v30; // s15
  __int64 v31; // r0
  int v32; // r3
  bool v33; // cc
  int v34; // r1
  int v35; // r2
  int v36; // r1
  int result; // r0
  _DWORD *v38; // r3
  int v39; // [sp+20h] [bp-20h]
  int v40; // [sp+24h] [bp-1Ch]
  int v41; // [sp+2Ch] [bp-14h]
  int v42; // [sp+30h] [bp-10h]
  int *v43; // [sp+34h] [bp-Ch]
  int *v44; // [sp+38h] [bp-8h]
  unsigned int *v45; // [sp+3Ch] [bp-4h]
  _DWORD v46[3]; // [sp+40h] [bp+0h] BYREF
  int v47[132]; // [sp+4Ch] [bp+Ch] BYREF
  char v48; // [sp+25Ch] [bp+21Ch] BYREF
  int v49; // [sp+2BCh] [bp+27Ch]
  float v50; // [sp+2CCh] [bp+28Ch]
  _BYTE v51[1204]; // [sp+2D0h] [bp+290h] BYREF

  v11 = off_10A4B4;
  v13 = *(_DWORD *)(dword_10A468 + 4);
  v14 = *(_DWORD *)(dword_10A468 + 8);
  v46[0] = *(_DWORD *)dword_10A468;
  v46[1] = v13;
  v46[2] = v14;
  v15 = flt_10A46C;
  v43 = v46;
  *(_DWORD *)(a5 + 4 * a4) = 1;
  v45 = (unsigned int *)(a2 - 4);
  v41 = 1;
  v44 = (int *)(a5 + 4 * a4);
  v17 = 0;
  while ( 2 )
  {
    v19 = v45[1];
    ++v45;
    v20 = (unsigned __int8)v17;
    if ( !v19 )
    {
      feature_guard_check(1, dword_10A74C);
      feature_guard_check(1, dword_10A750);
      goto LABEL_28;
    }
    if ( !a4 && v17 == 1 )
    {
      feature_guard_check(1, dword_10A754);
      goto LABEL_29;
    }
    feature_guard_check(1, dword_10A470);
    v21 = *v45;
    v49 = 0;
    fw_init_vif_struct(v21, (int)v47, a4);
    feature_guard_check(1, dword_10A474);
    v39 = *v43;
    if ( v49 <= 0 )
      goto LABEL_27;
    v42 = v17;
    v40 = 0;
    v22 = &v48;
    do
    {
      v23 = *((_DWORD *)v22 + 16);
      while ( !*a1 )
        delay_us_0644(1);
      feature_guard_check(1, dword_10A478);
      sub_105BA0((int)v47, (int)v51, v20, v23, a4, 0);
      *v11 &= ~0x8000u;
      *v11 &= ~0x2000u;
      sub_109FF0(v23, v47, (int)v51, v20, 0, a4, a6, a7, a9, a10, a11);
      v24 = dword_10A47C;
      *v11 |= 0x8000u;
      *v11 |= 0x2000u;
      feature_guard_check(1, v24);
      while ( !a1[1] )
        delay_us_0644(1);
      feature_guard_check(1, dword_10A480);
      sub_105BA0((int)v47, (int)v51, v20, v23, a4, 1);
      *v11 &= ~0x8000u;
      *v11 &= ~0x2000u;
      sub_109FF0(v23, v47, (int)v51, v20, 1, a4, a6, 0, a9, a10, a11);
      v25 = dword_10A47C;
      *v11 |= 0x8000u;
      *v11 |= 0x2000u;
      feature_guard_check(1, v25);
      feature_guard_check(1, dword_10A488);
      feature_guard_check(1, dword_10A48C);
      feature_guard_check(1, dword_10A490);
      v26 = *(float *)&v47[128] / *(float *)&v47[129];
      v27 = *(float *)&v47[130] / *(float *)&v47[131];
      if ( v23 == 11 )
      {
        v28 = 3.0;
        v29 = 3.0;
      }
      else if ( (unsigned int)(v23 - 12) <= 1 )
      {
        v29 = flt_10A73C;
        v28 = 3.0;
      }
      else if ( v23 == 14 )
      {
        v29 = flt_10A740;
        v28 = 3.0;
      }
      else if ( v23 <= 7 )
      {
        v28 = v15;
        v29 = v15;
      }
      else
      {
        v28 = flt_10A494;
        v29 = flt_10A494;
      }
      feature_guard_check(1, dword_10A49C);
      feature_guard_check(1, dword_10A4A0);
      feature_guard_check(1, dword_10A4A4);
      feature_guard_check(1, dword_10A4A8);
      feature_guard_check(1, dword_10A4AC);
      if ( v29 >= v26 )
      {
        v30 = v50;
        if ( v50 < 2.0 )
          goto LABEL_19;
        v34 = dword_10A720;
        *(_DWORD *)v22 = 0;
        *((_DWORD *)v22 + 8) = 0;
        feature_guard_check(1, v34);
        feature_guard_check(1, dword_10A724);
        feature_guard_check(1, dword_10A728);
        feature_guard_check(1, dword_10A72C);
        feature_guard_check(1, dword_10A730);
        if ( v23 <= 10 && v42 == 1 )
        {
          v41 = 0;
          msg_parse(dword_10A734, v23, v35);
          *(_DWORD *)v22 = 1;
          *((_DWORD *)v22 + 8) = 1;
        }
      }
      else
      {
        if ( v28 < v27 )
        {
          v30 = v50;
LABEL_19:
          *(_DWORD *)v22 = 1;
          *((_DWORD *)v22 + 8) = 1;
          if ( v23 <= 8
            && v28 > v27
            && (v31 = sub_1429F8(LODWORD(v30)), sub_142FC8(v31, HIDWORD(v31), dword_10A460, dword_10A464))
            && v42 == 1 )
          {
            feature_guard_check(1, dword_10A720);
            feature_guard_check(1, dword_10A724);
            feature_guard_check(1, dword_10A728);
            feature_guard_check(1, dword_10A72C);
            feature_guard_check(1, dword_10A75C);
            feature_guard_check(1, dword_10A760);
            v41 = 0;
          }
          else
          {
            feature_guard_check(1, dword_10A4B0);
            v41 = 1;
          }
          goto LABEL_24;
        }
        v30 = v50;
        if ( v50 < 2.0 )
          goto LABEL_19;
        v36 = dword_10A738;
        *(_DWORD *)v22 = 1;
        *((_DWORD *)v22 + 8) = 0;
        feature_guard_check(1, v36);
        if ( v23 <= 8 && v42 == 1 )
        {
          if ( v50 > 2.0 )
          {
            feature_guard_check(1, dword_10A720);
            feature_guard_check(1, dword_10A724);
            feature_guard_check(1, dword_10A728);
            feature_guard_check(1, dword_10A72C);
            feature_guard_check(1, dword_10A75C);
            feature_guard_check(1, dword_10A760);
            v41 = 0;
            feature_guard_check(1, dword_10A734);
          }
          else
          {
            v41 = 1;
          }
        }
        else
        {
          v41 = 1;
        }
      }
LABEL_24:
      v39 &= *(_DWORD *)v22;
      v32 = *v44 & v41;
      v33 = v49 <= ++v40;
      *v43 = v39;
      v22 += 4;
      *v44 = v32;
    }
    while ( !v33 );
    v17 = v42;
LABEL_27:
    *v45 = *v45 & 0xFFFEFFFF | (v39 << 16);
LABEL_28:
    if ( v20 != 2 )
    {
LABEL_29:
      ++v17;
      ++v43;
      continue;
    }
    break;
  }
  while ( !a1[2] )
    delay_us_0644(1);
  result = feature_guard_check(1, dword_10A744);
  v38 = off_10A748;
  *(_DWORD *)off_10A748 &= ~0x200u;
  *v38 |= 0x200u;
  *v38 &= ~0x200u;
  return result;
}

