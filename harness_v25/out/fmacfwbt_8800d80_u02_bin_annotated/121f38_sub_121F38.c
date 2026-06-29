// fwstruct annotate: 121f38_sub_121F38.c
// sub_121F38 @ 0x121f38, size 118 bytes
int __fastcall sub_121F38(int a1, _BYTE *a2, _BYTE *a3)
{
  int v6; // r4
  int v8; // r5
  int v9; // r9
  int v10; // r3
  _BYTE *v11; // r3

  v6 = sub_11F284((int *)a1, a2);
  if ( v6 )
    return v6;
  v8 = *(unsigned __int8 *)(a1 + 25);
  v9 = dword_121FB0 + 696 * (unsigned __int8)*a2;
  *(_BYTE *)(v9 + 669) = 0;
  *(_WORD *)(v9 + 670) = 0;
  *a3 = sub_1215A0((unsigned __int8)*a2, v8);
  v10 = *(_DWORD *)(v9 + 44);
  if ( v10 )
    sub_1215A0(*(unsigned __int8 *)(v10 + 35), *(unsigned __int8 *)(a1 + 25));
  v11 = (_BYTE *)(dword_121FB4 + 1320 * v8);
  if ( v11[106] )
    return v6;
  v11[116] = *a2;
  v11[117] = *(_BYTE *)(a1 + 29);
  v11[118] = *(_BYTE *)(a1 + 30);
  return 0;
}

