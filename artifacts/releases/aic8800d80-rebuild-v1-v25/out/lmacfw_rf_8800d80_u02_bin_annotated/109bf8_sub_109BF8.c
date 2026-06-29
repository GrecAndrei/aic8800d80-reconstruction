// fwstruct annotate: 109bf8_sub_109BF8.c
// sub_109BF8 @ 0x109bf8, size 300 bytes
int *__fastcall sub_109BF8(
        int a1,
        int *a2,
        int a3,
        int a4,
        int a5,
        unsigned __int8 a6,
        int a7,
        int a8,
        int a9,
        int a10,
        __int64 *a11)
{
  _DWORD *v11; // r4
  int v15; // r1
  unsigned __int8 v16; // r10
  int *v17; // r5
  int *v18; // r2
  int *v19; // r3
  int v20; // r0
  int *v21; // r4
  int v22; // t1
  int v23; // r6
  int v24; // t1
  int v25; // r1
  int v26; // t1
  int *result; // r0
  _DWORD *v28; // r3
  int v29; // r1
  _DWORD *v30; // r2
  _DWORD *v31; // r0
  _DWORD *v32; // r1
  int v33; // r5
  int *v34; // r3
  int v35; // t1
  _BYTE v36[20]; // [sp+18h] [bp-14h] BYREF

  v11 = off_109D24;
  *(_DWORD *)off_109D24 |= 0x400u;
  v15 = dword_109D28;
  *v11 &= ~0x400u;
  v16 = a4;
  sub_11F74C(1, v15, a1, a4);
  if ( a5 )
  {
    rf_calib_setup_n3d8((int)a2, 1, dword_100000, dword_100000, 0, 1);
    return (int *)sub_1099BC(24, (int)a2, 1, (int)v36);
  }
  else
  {
    if ( a8 == 1 )
    {
      rf_calib_setup_n3d8((int)a2, 1, dword_100000, dword_100000, 0, 0);
      sub_1099BC(24, (int)a2, 0, (int)v36);
      v30 = (_DWORD *)dword_109D2C;
      v31 = (_DWORD *)dword_109D30;
      v32 = (_DWORD *)dword_109D34;
      v33 = dword_109D2C + 128;
      v34 = a2;
      do
      {
        v35 = *v34++;
        *v30++ = v35;
        *v31++ = v34[31];
        *v32++ = v34[95];
      }
      while ( v30 != (_DWORD *)v33 );
    }
    else
    {
      v17 = (int *)dword_109D2C;
      v18 = (int *)dword_109D30;
      v19 = (int *)dword_109D34;
      v20 = dword_109D2C + 128;
      v21 = a2;
      do
      {
        v22 = *v17++;
        *v21++ = v22;
        v24 = *v18++;
        v23 = v24;
        v21[31] = v24;
        v26 = *v19++;
        v25 = v26;
        v21[95] = v26;
        v21[63] = v23;
      }
      while ( v17 != (int *)v20 );
      rf_phy_process_handler(a2, v25, a9, a10, a11);
    }
    lmac_rf_behavioral_handler(16, 32, (float *)a2, a3, v16, 1, a6, a1, a7);
    result = sub_10397C(a3);
    v28 = off_109D38;
    v29 = dword_109D3C;
    *(_DWORD *)off_109D38 &= ~0x200u;
    *v28 |= 0x200u;
    *v28 &= ~0x200u;
    a2[129] = v29;
    a2[131] = v29;
  }
  return result;
}

