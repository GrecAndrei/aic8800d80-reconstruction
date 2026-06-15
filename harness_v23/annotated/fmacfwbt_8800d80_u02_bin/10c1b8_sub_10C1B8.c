// v23 annotated: sub_10C1B8 @ 0x10c1b8
// Original: 10c1b8_sub_10C1B8.c
// Primary struct: <unclustered>
//
// sub_10C1B8 @ 0x10c1b8, size 546 bytes
int *__fastcall sub_10C1B8(int *result, unsigned int a2, int a3, int a4)
{
  int v4; // r6
  int v7; // r7
  int v8; // r10
  unsigned int v9; // r3
  unsigned int v10; // r3
  unsigned int v11; // r0
  int v12; // r0
  __int64 v13; // r8
  double v14; // d8
  __int64 v15; // r0
  __int64 v16; // r0
  __int64 v17; // r0
  __int64 v18; // r0
  int v19; // r8
  __int64 v20; // r0
  int v21; // r2
  int v22; // r0
  int v23; // r8
  unsigned __int16 *v24; // r6
  int v25; // r1
  int v26; // r2
  int v27; // r5
  __int64 v28; // r0
  int v29; // r2
  int v30; // r3
  __int64 v31; // r0
  int v32; // r2
  int v33; // r3
  int v34; // r2
  int v35; // r3
  int v36; // [sp+Ch] [bp-58h]
  _DWORD v37[3]; // [sp+24h] [bp-40h] BYREF
  __int64 v38; // [sp+30h] [bp-34h] BYREF
  int v39; // [sp+38h] [bp-2Ch]
  int v40; // [sp+3Ch] [bp-28h]
  __int64 v41; // [sp+40h] [bp-24h]
  int v42; // [sp+48h] [bp-1Ch]
  int v43; // [sp+4Ch] [bp-18h]
  int v44; // [sp+50h] [bp-14h]
  int v45; // [sp+54h] [bp-10h]
  int v46; // [sp+58h] [bp-Ch]
  int v47; // [sp+5Ch] [bp-8h]

  v4 = *result;
  v7 = (unsigned __int8)*result >> 6;
  if ( !a3 )
  {
    if ( !a4 )
      return result;
    goto LABEL_3;
  }
  v8 = result[1];
  feature_guard_sdio(0x2000, dword_10C408);
  v9 = a2 - 2;
  do
  {
    *(_WORD *)(v9 + 2) = -32640;
    v9 += 2;
  }
  while ( a2 + 30 != v9 );
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  v10 = a2 + 36;
  do
  {
    *(_DWORD *)(v10 + 4) = 0;
    v10 += 4;
  }
  while ( a2 + 100 != v10 );
  while ( !*(_DWORD *)off_10C40C )
    ;
  if ( v7 )
  {
    v11 = (*(_DWORD *)off_10C410 >> 5) & 0x1F;
    if ( (*(_DWORD *)off_10C410 & 0x400) != 0 )
      v11 *= 2;
    if ( (*(_DWORD *)off_10C414 & 0x80000) != 0 && (*(_DWORD *)off_10C414 & 0x40000) != 0 )
      v11 >>= 1;
    v12 = *(unsigned __int8 *)off_10C41C * v11;
    *(_DWORD *)off_10C418 &= ~1u;
    if ( (unsigned __int8)v4 >> 7 )
    {
      v13 = *(_QWORD *)&dword_10C3F8;
      v14 = dbl_10C3F0;
    }
    else
    {
      v13 = *(_QWORD *)&dword_10C3E8;
      v14 = dbl_10C3E0;
    }
    v15 = sub_142A70(v12);
    v16 = sub_142B44(v15, HIDWORD(v15), 0, dword_10C420);
    v17 = sub_142D98(v13, HIDWORD(v13), v16, HIDWORD(v16));
    v18 = sub_142B44(v17, HIDWORD(v17), 0, dword_10C424);
    v19 = sub_1426B8(v18, HIDWORD(v18));
    v20 = sub_142D98(LODWORD(v14), HIDWORD(v14), 0, dword_10C420);
    v21 = sub_1426B8(v20, HIDWORD(v20));
    v22 = v19;
    v23 = v21;
    *(_DWORD *)off_10C440 = sub_1430C8(v22) & 0x7FFFFFFF;
    *(_DWORD *)off_10C428 = dword_10C42C & (sub_1430C8(v23) << 13) | *(_DWORD *)off_10C428 & dword_10C430;
  }
  crypto_hw_power_up_39c4();
  rf_init_hw_setup((unsigned __int8)v4, a2, v8, (unsigned __int16)v4 >> 12, BYTE1(v4) & 0xF, 0);
  result = (int *)crypto_hw_reset();
  *(_DWORD *)off_10C40C = 1;
  if ( a4 )
  {
LABEL_3:
    if ( ((*(_DWORD *)off_10C400 & 0x8000000) == 0 || (*(_DWORD *)off_10C404 & 0x400) != 0) && !v7 )
    {
      v24 = (unsigned __int16 *)off_10C438;
      v25 = *(_DWORD *)(dword_10C434 + 4);
      v26 = *(_DWORD *)(dword_10C434 + 8);
      v27 = dword_10C434 + 72;
      v37[0] = *(_DWORD *)dword_10C434;
      v37[1] = v25;
      v37[2] = v26;
      crypto_hw_power_up_39c4();
      v28 = *(_QWORD *)v27;
      v29 = *(_DWORD *)(v27 + 8);
      v30 = *(_DWORD *)(v27 + 12);
      v27 += 16;
      v38 = v28;
      v39 = v29;
      v40 = v30;
      v31 = *(_QWORD *)v27;
      v32 = *(_DWORD *)(v27 + 8);
      v33 = *(_DWORD *)(v27 + 12);
      v27 += 16;
      v41 = v31;
      v42 = v32;
      v43 = v33;
      HIDWORD(v31) = *(_DWORD *)(v27 + 4);
      v34 = *(_DWORD *)(v27 + 8);
      v35 = *(_DWORD *)(v27 + 12);
      v44 = *(_DWORD *)v27;
      v45 = HIDWORD(v31);
      v46 = v34;
      v47 = v35;
      *((_BYTE *)v24 + 4) = 0;
      LODWORD(v31) = dword_10C43C;
      *((_BYTE *)v24 + 12) = 0;
      *((_BYTE *)v24 + 20) = 0;
      *((_BYTE *)v24 + 28) = 0;
      *((_BYTE *)v24 + 36) = 0;
      *((_BYTE *)v24 + 44) = 0;
      *((_BYTE *)v24 + 52) = 0;
      sub_10AE68((unsigned int *)v31, (_BYTE *)(a2 + 125), (int)v24);
      sub_10B288(v37, dword_10C43C, a2 + 104, a2 + 125, v24, 6, 1, v36, 0, 0, &v38);
      *((_BYTE *)v24 + 4) = 0;
      *((_BYTE *)v24 + 12) = 0;
      *((_BYTE *)v24 + 20) = 0;
      *((_BYTE *)v24 + 28) = 0;
      *((_BYTE *)v24 + 36) = 0;
      *((_BYTE *)v24 + 44) = 0;
      *((_BYTE *)v24 + 52) = 0;
      return (int *)crypto_hw_reset();
    }
  }
  return result;
}

