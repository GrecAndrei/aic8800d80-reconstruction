// v23 annotated: sub_125958 @ 0x125958
// Original: 125958_sub_125958.c
// Primary struct: <unclustered>
//
// sub_125958 @ 0x125958, size 18 bytes
int __fastcall sub_125958(int a1)
{
  _BYTE *v1; // r3
  int v2; // r2

  v1 = off_12596C;
  v2 = *((_DWORD *)off_12596C + 1);
  *(_DWORD *)off_12596C = a1;
  if ( !v2 )
    return sub_125904(a1);
  v1[10] = 1;
  return a1;
}

