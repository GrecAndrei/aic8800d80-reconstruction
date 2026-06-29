// fwstruct annotate: 122b8c_sub_122B8C.c
// sub_122B8C @ 0x122b8c, size 90 bytes
int __fastcall sub_122B8C(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r3
  int v7; // r2
  int v8; // r2
  int v9; // r1

  v5 = sub_12CB54(118, a4, a3, 12);
  v6 = dword_122BE8 + 696 * *a2;
  v7 = *(unsigned __int8 *)(v6 + 34);
  if ( v7 == 255 )
    goto LABEL_4;
  v8 = dword_122BEC + 1320 * v7;
  v9 = *(unsigned __int8 *)(v8 + 106);
  *(_DWORD *)v5 = *(_DWORD *)(*(_DWORD *)(v6 + 336) + 20);
  *(_DWORD *)(v5 + 4) = 0;
  if ( !v9 )
  {
    *(_BYTE *)(v5 + 8) = *(_BYTE *)(v8 + 142);
LABEL_4:
    sub_12CBB4(v5);
    return 0;
  }
  *(_BYTE *)(v5 + 8) = *(_BYTE *)(v6 + 689);
  sub_12CBB4(v5);
  return 0;
}

