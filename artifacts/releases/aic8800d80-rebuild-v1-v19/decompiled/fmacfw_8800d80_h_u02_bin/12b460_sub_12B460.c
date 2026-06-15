// sub_12B460 @ 0x12b460, size 530 bytes
unsigned int __fastcall sub_12B460(unsigned int result)
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
  int v10; // r0
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
  unsigned int *v22; // r7
  int v23; // r0

  v1 = off_12B688;
  v2 = (unsigned __int8)*(_DWORD *)off_12B688;
  if ( result != v2 )
  {
    v3 = dword_12B68C;
    v4 = dword_12B690;
    v5 = dword_12B6C0;
    *(_DWORD *)off_12B6BC = ((0xF0 / result) << 8) & 0xF00 | *(_DWORD *)off_12B6BC & 0xFFFFF0FF;
    *v1 = *v1 & 0xFFFFFF00 | result;
    *v1 = v3 & ((result * ((*v1 >> 8) & 0x3FF) / v2) << 8) | *v1 & 0xFFFC00FF;
    v6 = result;
    *v1 = v4 & ((result * ((*v1 >> 18) & 0x3FF) / v2) << 18) | *v1 & v5;
    if ( result == 240 )
    {
      v21 = sub_1424DC(dword_12B680);
      *v1 = v4 & (sub_142EEC(v21) << 18) | *v1 & v5;
      v22 = (unsigned int *)off_12B69C;
      v23 = sub_1424DC(0);
      *v22 = dword_12B6A0 & (sub_142EEC(v23) << 20) | *v22 & 0xC00FFFFF;
    }
    else
    {
      v7 = sub_142894(result);
      v8 = sub_142968(v7, HIDWORD(v7), dword_12B678, dword_12B67C);
      v9 = sub_142F2C(v8);
      v10 = sub_1428B8(LODWORD(v9));
      v11 = sub_1424DC(v10);
      *v1 = v4 & (sub_142EEC(v11) << 18) | *v1 & v5;
    }
    v12 = (unsigned int *)off_12B69C;
    *(_DWORD *)off_12B694 = dword_12B698 & ((v6 * (unsigned __int16)(*(_DWORD *)off_12B694 >> 8) / v2) << 8)
                          | *(_DWORD *)off_12B694 & 0xFF0000FF;
    *v12 = dword_12B6A0 & ((v6 * ((*v12 >> 20) & 0x3FF) / v2) << 20) | *v12 & 0xC00FFFFF;
    *v12 = (v6 * (*v12 & 0x3FF) / v2) & 0x3FF | *v12 & 0xFFFFFC00;
    if ( v6 <= 0x1D )
    {
      v12[1] |= 3u;
    }
    else
    {
      v13 = *(_DWORD *)off_12B6A4 & 0xFFFFFFFC;
      if ( v6 > 0x3B )
        v14 = v13 | 1;
      else
        v14 = v13 | 2;
      *(_DWORD *)off_12B6A4 = v14;
    }
    v15 = off_12B6A8;
    v16 = dword_12B698;
    v17 = dword_12B6AC;
    v18 = (unsigned int *)off_12B6B0;
    *(_DWORD *)off_12B6A8 = dword_12B698 & ((v6 * (unsigned __int16)(*(_DWORD *)off_12B6A8 >> 8) / v2) << 8)
                          | *(_DWORD *)off_12B6A8 & dword_12B6AC;
    *v18 = v16 & ((v6 * (unsigned __int16)(*v18 >> 8) / v2) << 8) | v17 & *v18;
    v19 = (unsigned int *)off_12B6B4;
    v20 = dword_12B6A0;
    v15[2] = (unsigned __int16)v15[2] | (v6 << 19);
    *v19 = v20 & ((v6 * ((*v19 >> 20) & 0x3FF) / v2) << 20) | *v19 & 0xC00FFFFF;
    result = *v19 & 0x3FF;
    *v19 = (v6 * result / v2) & 0x3FF | *v19 & 0xFFFFFC00;
  }
  return result;
}

