// fwstruct annotate: 10c360_tx_phy_config.c
// tx_phy_config @ 0x10c360, size 546 bytes
// Doc: tx_phy_config [tx]: Configures TX PHY parameters (rate, mode, bandwidth) for a frame.
// tx_phy_config [tx]: Configures TX PHY parameters (rate, mode, bandwidth) for a frame.
int *__fastcall tx_phy_config(int *result, unsigned int a2, int a3, int a4)
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
  int v18; // r0
  int v19; // r8
  int v20; // r0
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
  feature_guard_check(0x2000, dword_10C5B0);
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
    v15 = sub_1429D4(v12);
    v16 = sub_142AA8(v15, HIDWORD(v15), 0, dword_10C5C8);
    v17 = sub_142CFC(v13, HIDWORD(v13), v16, HIDWORD(v16));
    v18 = sub_142AA8(v17, HIDWORD(v17), 0, dword_10C5CC);
    v19 = math_round(v18);
    v20 = sub_142CFC(LODWORD(v14), HIDWORD(v14), 0, dword_10C5C8);
    v21 = math_round(v20);
    v22 = v19;
    v23 = v21;
    *(_DWORD *)off_10C5E8 = sub_14302C(v22) & 0x7FFFFFFF;
    *(_DWORD *)off_10C5D0 = dword_10C5D4 & (sub_14302C(v23) << 13) | *(_DWORD *)off_10C5D0 & dword_10C5D8;
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
      v24 = (unsigned __int16 *)off_10C5E0;
      v25 = *(_DWORD *)(dword_10C5DC + 4);
      v26 = *(_DWORD *)(dword_10C5DC + 8);
      v27 = dword_10C5DC + 72;
      v37[0] = *(_DWORD *)dword_10C5DC;
      v37[1] = v25;
      v37[2] = v26;
      crypto_hw_power_up_3b6c();
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
      LODWORD(v31) = dword_10C5E4;
      *((_BYTE *)v24 + 12) = 0;
      *((_BYTE *)v24 + 20) = 0;
      *((_BYTE *)v24 + 28) = 0;
      *((_BYTE *)v24 + 36) = 0;
      *((_BYTE *)v24 + 44) = 0;
      *((_BYTE *)v24 + 52) = 0;
      sub_10B010((unsigned int *)v31, (_BYTE *)(a2 + 125), (int)v24);
      phy_rx_process_bulk(v37, dword_10C5E4, a2 + 104, a2 + 125, v24, 6, 1, v36, 0, 0, &v38);
      *((_BYTE *)v24 + 4) = 0;
      *((_BYTE *)v24 + 12) = 0;
      *((_BYTE *)v24 + 20) = 0;
      *((_BYTE *)v24 + 28) = 0;
      *((_BYTE *)v24 + 36) = 0;
      *((_BYTE *)v24 + 44) = 0;
      *((_BYTE *)v24 + 52) = 0;
      return (int *)sub_103C14();
    }
  }
  return result;
}

