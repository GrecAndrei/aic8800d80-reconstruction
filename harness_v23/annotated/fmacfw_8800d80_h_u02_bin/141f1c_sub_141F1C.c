// v23 annotated: sub_141F1C @ 0x141f1c
// Original: 141f1c_sub_141F1C.c
// Primary struct: <unclustered>
//
// sub_141F1C @ 0x141f1c, size 64 bytes
int __fastcall sub_141F1C(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r3

  v3 = 0;
  v4 = dword_141F5C;
  do
  {
    if ( (*(_WORD *)v4 & 1) != 0
      && *(unsigned __int8 *)(v4 + 47) == a2
      && *(unsigned __int8 *)(v4 + 46) == a1
      && *(unsigned __int8 *)(v4 + 2) == a3 )
    {
      return dword_141F5C + 72 * v3;
    }
    ++v3;
    v4 += 72;
  }
  while ( v3 != 8 );
  return 0;
}

