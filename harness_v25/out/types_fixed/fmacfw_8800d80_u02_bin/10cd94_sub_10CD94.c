// sub_10CD94 @ 0x10cd94, size 48 bytes
int sub_10CD94()
{
  _DWORD *v0; // r4
  int *v1; // r7
  _DWORD *v2; // r6
  int v3; // r0
  int result; // r0

  v0 = off_10CDC4;
  if ( (*(_DWORD *)off_10CDC4 & 2) != 0 )
  {
    v1 = (int *)off_10CDC8;
    v2 = off_10CDCC;
    do
    {
      v3 = *v1;
      *v2 = 2;
      sub_10CCB0((_WORD *)(v3 + 4));
    }
    while ( (*v0 & 2) != 0 );
  }
  result = sub_12D14C(0x8000000);
  *(_DWORD *)off_10CDD0 = 2;
  return result;
}

