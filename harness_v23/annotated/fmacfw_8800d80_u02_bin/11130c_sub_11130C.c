// v23 annotated: sub_11130C @ 0x11130c
// Original: 11130c_sub_11130C.c
// Primary struct: <unclustered>
//
// sub_11130C @ 0x11130c, size 124 bytes
int __fastcall sub_11130C(int a1)
{
  int *v1; // r3
  int v2; // r2
  int v3; // r1
  int v4; // r1

  v1 = (int *)off_111388;
  v2 = a1 & 0x3FFFFF;
  v3 = *(_DWORD *)off_111388 & 0x3FFFFF;
  if ( (a1 & 0x400000) != 0 )
  {
    *(_DWORD *)off_111388 = v3 | 0x800000;
    *v1 = v3;
    *v1 = v2;
    v4 = v2 | 0x800000;
  }
  else
  {
    *(_DWORD *)off_111388 = v3 | 0x400000;
    v4 = v2 | 0x400000;
  }
  *v1 = v4;
  *v1 = v2 | 0xC00000;
  return sub_10DC24(dword_11138C, *(_DWORD *)off_111388 & 0x3FFFFF);
}

