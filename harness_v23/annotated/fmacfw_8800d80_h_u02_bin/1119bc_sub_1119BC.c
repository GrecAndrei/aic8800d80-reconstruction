// v23 annotated: sub_1119BC @ 0x1119bc
// Original: 1119bc_sub_1119BC.c
// Primary struct: <unclustered>
//
// sub_1119BC @ 0x1119bc, size 88 bytes
int __fastcall sub_1119BC(int result, int a2)
{
  int *v2; // r4
  int v3; // r5
  int v4; // r3
  char v5; // r2
  _DWORD *v6; // r2

  v2 = (int *)off_111A18;
  v3 = *(_DWORD *)off_111A14;
  v4 = *(_DWORD *)off_111A18;
  *((_WORD *)off_111A1C + 5) = a2;
  if ( a2 == 64 )
    v5 = -54;
  else
    v5 = -50;
  *(_DWORD *)v4 = -1073741824;
  *(_DWORD *)(v4 + 4) = v3;
  *(_BYTE *)(v4 + 3) = v5;
  *(_WORD *)v4 = a2;
  if ( result && a2 )
  {
    result = sub_143630(v3, result, a2);
    v4 = *v2;
  }
  v6 = off_111A20;
  *(_BYTE *)(v4 + 3) &= 0x3Fu;
  v6[578] = v6[578];
  v6[581] = v4;
  v6[576] |= 0x84000000;
  return result;
}

