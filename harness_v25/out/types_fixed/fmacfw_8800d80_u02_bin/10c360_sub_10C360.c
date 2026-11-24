// sub_10C360 @ 0x10c360, size 546 bytes
int *__fastcall sub_10C360(int *result, unsigned int a2, int a3, int a4)
{
  int v4; // r6
  int v7; // r7
  int v8; // r10
  int v9; // r3
  int v10; // r3
  unsigned int v11; // r0
  int v12; // r0
  __int64 v13; // r8
  double v14; // d8
  __int64 v15; // r0
  unsigned int v16; // r0
  unsigned int v17; // r1
  __int64 v18; // r0
  __int64 v19; // r0
  __int64 v20; // r8
  __int64 v21; // r0
  __int64 v22; // r2
  __int64 v23; // r0
  __int64 v24; // r8
  unsigned __int16 *v25; // r6
  int v26; // r1
  int v27; // r2
  int v28; // r5
  __int64 v29; // r0
  int v30; // r2
  int v31; // r3
  __int64 v32; // r0
  int v33; // r2
  int v34; // r3
  int v35; // r2
  int v36; // r3
  int v37; // [sp+Ch] [bp-58h]
  _DWORD *(_DWORD *)(v38 + 0xc); // [sp+24h] [bp-40h] BYREF
  __int64 v39; // [sp+30h] [bp-34h] BYREF
  int v40; // [sp+38h] [bp-2Ch]
  int v41; // [sp+3Ch] [bp-28h]
  __int64 v42; // [sp+40h] [bp-24h]
  int v43; // [sp+48h] [bp-1Ch]
  int v44; // [sp+4Ch] [bp-18h]
  int v45; // [sp+50h] [bp-14h]
  int v46; // [sp+54h] [bp-10h]
  int v47; // [sp+58h] [bp-Ch]
  int v48; // [sp+5Ch] [bp-8h]

  v4 = *result;
  v7 = (unsigned __int8)*result >> 6;
  if ( !a3 )
  {
    if ( !a4 )
      return result;
    goto LABEL_3;
  }
  v8 = *(_DWORD *)(result + 0x4);
  feature_guard_check(0x2000, dword_10C5B0, *result, v8);
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
  while ( !*(_DWORD *)off_10C5B4 )
    ;
  if ( v7 )
  {
    v11 = (*(_DWORD *)off_10C5B8 >> 5) & 0x1F;
    if ( (*(_DWORD *)off_10C5B8 & 0x400) != 0 )
      v11 *= 2;
    if ( (*(_DWORD *)off_10C5BC & 0x80000) != 0 && (*(_DWORD *)off_10C5BC & 0x40000) != 0 )
      v11 >>= 1;
    v12 = *(unsigned __int8 *)off_10C5C4 * v11;
    *(_DWORD *)off_10C5C0 &= ~1u;
    if ( (unsigned __int8)v4 >> 7 )
    {
      v13 = *(_QWORD *)&dword_10C5A0;
      v14 = dbl_10C598;
    }
    else
    {
      v13 = *(_QWORD *)&dword_10C590;
      v14 = dbl_10C588;
    }
    LODWORD(v15) = sub_1429D4(v12);
    v16 = sub_142AA8(v15, 0, dword_10C5C8);
    LODWORD(v18) = sub_142CFC(v13, HIDWORD(v13), v16, v17);
    LODWORD(v19) = sub_142AA8(v18, 0, dword_10C5CC);
    v20 = math_round(v19);
    LODWORD(v21) = sub_142CFC(LODWORD(v14), HIDWORD(v14), 0, dword_10C5C8);
    v22 = math_round(v21);
    v23 = v20;
    v24 = v22;
    *(_DWORD *)off_10C5E8 = sub_14302C(v23, SHIDWORD(v23)) & 0x7FFFFFFF;
    *(_DWORD *)off_10C5D0 = dword_10C5D4 & (sub_14302C(v24, SHIDWORD(v24)) << 13) | *(_DWORD *)off_10C5D0 & dword_10C5D8;
  }
  crypto_hw_power_up_3b6c();
  sub_10A9A8((unsigned __int8)v4, a2, v8, (unsigned __int16)v4 >> 12, BYTE1(v4) & 0xF, 0);
  result = (int *)sub_103C14();
  *(_DWORD *)off_10C5B4 = 1;
  if ( a4 )
  {
LABEL_3:
    if ( ((*(_DWORD *)off_10C5A8 & 0x8000000) == 0 || (*(_DWORD *)off_10C5AC & 0x400) != 0) && !v7 )
    {
      v25 = (unsigned __int16 *)off_10C5E0;
      v26 = *(_DWORD *)(dword_10C5DC + 4);
      v27 = *(_DWORD *)(dword_10C5DC + 8);
      v28 = dword_10C5DC + 72;
      *(_DWORD *)(v38 + 0x0) = *(_DWORD *)dword_10C5DC;
      *(_DWORD *)(v38 + 0x4) = v26;
      *(_DWORD *)(v38 + 0x8) = v27;
      crypto_hw_power_up_3b6c();
      v29 = *(_QWORD *)v28;
      v30 = *(_DWORD *)(v28 + 8);
      v31 = *(_DWORD *)(v28 + 12);
      v28 += 16;
      v39 = v29;
      v40 = v30;
      v41 = v31;
      v32 = *(_QWORD *)v28;
      v33 = *(_DWORD *)(v28 + 8);
      v34 = *(_DWORD *)(v28 + 12);
      v28 += 16;
      v42 = v32;
      v43 = v33;
      v44 = v34;
      HIDWORD(v32) = *(_DWORD *)(v28 + 4);
      v35 = *(_DWORD *)(v28 + 8);
      v36 = *(_DWORD *)(v28 + 12);
      v45 = *(_DWORD *)v28;
      v46 = HIDWORD(v32);
      v47 = v35;
      v48 = v36;
      *((_BYTE *)v25 + 4) = 0;
      LODWORD(v32) = dword_10C5E4;
      *((_BYTE *)v25 + 12) = 0;
      *((_BYTE *)v25 + 20) = 0;
      *((_BYTE *)v25 + 28) = 0;
      *((_BYTE *)v25 + 36) = 0;
      *((_BYTE *)v25 + 44) = 0;
      *((_BYTE *)v25 + 52) = 0;
      sub_10B010((unsigned int *)v32, (_BYTE *)(a2 + 125), (int)v25);
      phy_rx_process_bulk(v38, dword_10C5E4, a2 + 104, a2 + 125, v25, 6, 1, v37, 0, 0, &v39);
      *((_BYTE *)v25 + 4) = 0;
      *((_BYTE *)v25 + 12) = 0;
      *((_BYTE *)v25 + 20) = 0;
      *((_BYTE *)v25 + 28) = 0;
      *((_BYTE *)v25 + 36) = 0;
      *((_BYTE *)v25 + 44) = 0;
      *((_BYTE *)v25 + 52) = 0;
      return (int *)sub_103C14();
    }
  }
  return result;
}
