// v23 annotated: sub_125CBC @ 0x125cbc
// Original: 125cbc_sub_125CBC.c
// Primary struct: <unclustered>
//
// sub_125CBC @ 0x125cbc, size 18 bytes
int __fastcall sub_125CBC(int a1)
{
  _BYTE *v1; // r3
  int v2; // r2

  v1 = off_125CD0;
  v2 = *((_DWORD *)off_125CD0 + 1);
  *(_DWORD *)off_125CD0 = a1;
  if ( !v2 )
    return sub_125C68(a1);
  v1[10] = 1;
  return a1;
}

