// v23 annotated: sub_122958 @ 0x122958
// Original: 122958_sub_122958.c
// Primary struct: <unclustered>
//
// sub_122958 @ 0x122958, size 90 bytes
int __fastcall sub_122958(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r3
  int v7; // r2
  int v8; // r2
  int v9; // r1

  v5 = sub_12C92C(118, a4, a3, 12);
  v6 = dword_1229B4 + 696 * *a2;
  v7 = *(unsigned __int8 *)(v6 + 34);
  if ( v7 == 255 )
    goto LABEL_4;
  v8 = dword_1229B8 + 1320 * v7;
  v9 = *(unsigned __int8 *)(v8 + 106);
  *(_DWORD *)v5 = *(_DWORD *)(*(_DWORD *)(v6 + 336) + 20);
  *(_DWORD *)(v5 + 4) = 0;
  if ( !v9 )
  {
    *(_BYTE *)(v5 + 8) = *(_BYTE *)(v8 + 142);
LABEL_4:
    sdio_buffer_prepare_n_4e8(v5);
    return 0;
  }
  *(_BYTE *)(v5 + 8) = *(_BYTE *)(v6 + 689);
  sdio_buffer_prepare_n_4e8(v5);
  return 0;
}

