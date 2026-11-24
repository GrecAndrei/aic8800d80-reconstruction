// sub_1111CC @ 0x1111cc, size 124 bytes
int __fastcall sub_1111CC(int a1)
{
  int *v1; // r3
  int v2; // r2
  int v3; // r1
  int v4; // r1

  v1 = (int *)off_111248;
  v2 = a1 & 0x3FFFFF;
  v3 = *(_DWORD *)off_111248 & 0x3FFFFF;
  if ( (a1 & 0x400000) != 0 )
  {
    *(_DWORD *)off_111248 = v3 | 0x800000;
    *v1 = v3;
    *v1 = v2;
    v4 = v2 | 0x800000;
  }
  else
  {
    *(_DWORD *)off_111248 = v3 | 0x400000;
    v4 = v2 | 0x400000;
  }
  *v1 = v4;
  *v1 = v2 | 0xC00000;
  return sub_10DAE4(dword_11124C, *(_DWORD *)off_111248 & 0x3FFFFF);
}

