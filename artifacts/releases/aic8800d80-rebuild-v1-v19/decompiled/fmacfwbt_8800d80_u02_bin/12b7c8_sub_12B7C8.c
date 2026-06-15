// sub_12B7C8 @ 0x12b7c8, size 530 bytes
// Doc: sub_122B7C8 [unknown]: unknown behavioral stub in fmac firmware bluetooth variant
// sub_122B7C8 [unknown]: unknown behavioral stub in fmac firmware bluetooth variant
unsigned int __fastcall sub_12B7C8(unsigned int result)
{
  _DWORD *v1; // r6
  unsigned int v2; // r5
  int v3; // r2
  int v4; // r7
  int v5; // r8
  unsigned int v6; // r4
  __int64 v7; // r0
  int v8; // r0
  float v9; // r0
  __int64 v10; // r0
  int v11; // r0
  unsigned int *v12; // r2
  unsigned int v13; // r3
  int v14; // r3
  _DWORD *v15; // r6
  int v16; // r2
  int v17; // r0
  unsigned int *v18; // r1
  unsigned int *v19; // r2
  int v20; // r1
  int v21; // r0
  int v22; // r0
  int v23; // r1
  unsigned int *v24; // r7
  int v25; // r0

  v1 = off_12B9F0;
  v2 = (unsigned __int8)*(_DWORD *)off_12B9F0;
  if ( result != v2 )
  {
    v3 = dword_12B9F4;
    v4 = dword_12B9F8;
    v5 = dword_12BA28;
    *(_DWORD *)off_12BA24 = ((0xF0 / result) << 8) & 0xF00 | *(_DWORD *)off_12BA24 & 0xFFFFF0FF;
    *v1 = *v1 & 0xFFFFFF00 | result;
    *v1 = v3 & ((result * ((*v1 >> 8) & 0x3FF) / v2) << 8) | *v1 & 0xFFFC00FF;
    v6 = result;
    *v1 = v4 & ((result * ((*v1 >> 18) & 0x3FF) / v2) << 18) | *v1 & v5;
    if ( result == 240 )
    {
      v21 = sub_1426B8(dword_12B9E8, dword_12B9EC);
      v22 = sub_1430C8(v21);
      v23 = dword_12BA20;
      *v1 = v4 & (v22 << 18) | *v1 & v5;
      v24 = (unsigned int *)off_12BA04;
      v25 = sub_1426B8(0, v23);
      *v24 = dword_12BA08 & (sub_1430C8(v25) << 20) | *v24 & 0xC00FFFFF;
    }
    else
    {
      v7 = sub_142A70(result);
      v8 = sub_142B44(v7, HIDWORD(v7), dword_12B9E0, dword_12B9E4);
      v9 = sub_143108(v8);
      v10 = sub_142A94(LODWORD(v9));
      v11 = sub_1426B8(v10, HIDWORD(v10));
      *v1 = v4 & (sub_1430C8(v11) << 18) | *v1 & v5;
    }
    v12 = (unsigned int *)off_12BA04;
    *(_DWORD *)off_12B9FC = dword_12BA00 & ((v6 * (unsigned __int16)(*(_DWORD *)off_12B9FC >> 8) / v2) << 8)
                          | *(_DWORD *)off_12B9FC & 0xFF0000FF;
    *v12 = dword_12BA08 & ((v6 * ((*v12 >> 20) & 0x3FF) / v2) << 20) | *v12 & 0xC00FFFFF;
    *v12 = (v6 * (*v12 & 0x3FF) / v2) & 0x3FF | *v12 & 0xFFFFFC00;
    if ( v6 <= 0x1D )
    {
      v12[1] |= 3u;
    }
    else
    {
      v13 = *(_DWORD *)off_12BA0C & 0xFFFFFFFC;
      if ( v6 > 0x3B )
        v14 = v13 | 1;
      else
        v14 = v13 | 2;
      *(_DWORD *)off_12BA0C = v14;
    }
    v15 = off_12BA10;
    v16 = dword_12BA00;
    v17 = dword_12BA14;
    v18 = (unsigned int *)off_12BA18;
    *(_DWORD *)off_12BA10 = dword_12BA00 & ((v6 * (unsigned __int16)(*(_DWORD *)off_12BA10 >> 8) / v2) << 8)
                          | *(_DWORD *)off_12BA10 & dword_12BA14;
    *v18 = v16 & ((v6 * (unsigned __int16)(*v18 >> 8) / v2) << 8) | v17 & *v18;
    v19 = (unsigned int *)off_12BA1C;
    v20 = dword_12BA08;
    v15[2] = (unsigned __int16)v15[2] | (v6 << 19);
    *v19 = v20 & ((v6 * ((*v19 >> 20) & 0x3FF) / v2) << 20) | *v19 & 0xC00FFFFF;
    result = *v19 & 0x3FF;
    *v19 = (v6 * result / v2) & 0x3FF | *v19 & 0xFFFFFC00;
  }
  return result;
}

