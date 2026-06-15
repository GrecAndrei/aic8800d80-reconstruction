// sub_109E48 @ 0x109e48, size 300 bytes
// Doc: sub_1209E48 [bt]: BT/FMAC init routine enabling a control bit at 0x4033b610
// sub_1209E48 [bt]: BT/FMAC init routine enabling a control bit at 0x4033b610
int *__fastcall sub_109E48(
        int a1,
        int *a2,
        int a3,
        unsigned __int8 a4,
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

  v11 = off_109F74;
  *(_DWORD *)off_109F74 |= 0x400u;
  v15 = dword_109F78;
  *v11 &= ~0x400u;
  feature_guard_sdio(1, v15);
  if ( a5 )
  {
    sub_104858((int)a2, 1, dword_100000, dword_100000, 0, 1);
    return (int *)sub_109C0C(24, (int)a2, 1, (int)v36);
  }
  else
  {
    if ( a8 == 1 )
    {
      sub_104858((int)a2, 1, dword_100000, dword_100000, 0, 0);
      sub_109C0C(24, (int)a2, 0, (int)v36);
      v30 = (_DWORD *)dword_109F7C;
      v31 = (_DWORD *)dword_109F80;
      v32 = (_DWORD *)dword_109F84;
      v33 = dword_109F7C + 128;
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
      v17 = (int *)dword_109F7C;
      v18 = (int *)dword_109F80;
      v19 = (int *)dword_109F84;
      v20 = dword_109F7C + 128;
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
      sub_104C38(a2, v25, a9, a10, a11);
    }
    scan_chan_meas_12051e0(16, 32, (float *)a2, a3, a4, 1, a6, a1, a7);
    result = mac_init_set_bits(a3);
    v28 = off_109F88;
    v29 = dword_109F8C;
    *(_DWORD *)off_109F88 &= ~0x200u;
    *v28 |= 0x200u;
    *v28 &= ~0x200u;
    a2[129] = v29;
    a2[131] = v29;
  }
  return result;
}

