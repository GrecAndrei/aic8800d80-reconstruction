// sub_111404 @ 0x111404, size 88 bytes
int __fastcall sub_111404(int result, int a2)
{
  int *v2; // r4
  int v3; // r5
  int v4; // r3
  char v5; // r2
  _DWORD *v6; // r2

  v2 = (int *)off_111460;
  v3 = *(_DWORD *)off_11145C;
  v4 = *(_DWORD *)off_111460;
  *((_WORD *)off_111464 + 5) = a2;
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
    result = sub_1282E8(v3, result, a2);
    v4 = *v2;
  }
  v6 = off_111468;
  *(_BYTE *)(v4 + 3) &= 0x3Fu;
  v6[578] = v6[578];
  v6[581] = v4;
  v6[576] |= 0x84000000;
  return result;
}

