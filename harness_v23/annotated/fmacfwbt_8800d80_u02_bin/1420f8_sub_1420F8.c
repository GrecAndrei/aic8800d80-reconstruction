// v23 annotated: sub_1420F8 @ 0x1420f8
// Original: 1420f8_sub_1420F8.c
// Primary struct: <unclustered>
//
// sub_1420F8 @ 0x1420f8, size 64 bytes
int __fastcall sub_1420F8(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r3

  v3 = 0;
  v4 = dword_142138;
  do
  {
    if ( (*(_WORD *)v4 & 1) != 0
      && *(unsigned __int8 *)(v4 + 47) == a2
      && *(unsigned __int8 *)(v4 + 46) == a1
      && *(unsigned __int8 *)(v4 + 2) == a3 )
    {
      return dword_142138 + 72 * v3;
    }
    ++v3;
    v4 += 72;
  }
  while ( v3 != 8 );
  return 0;
}

