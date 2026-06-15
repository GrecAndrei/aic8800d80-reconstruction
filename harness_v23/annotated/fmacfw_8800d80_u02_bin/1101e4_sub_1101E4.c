// v23 annotated: sub_1101E4 @ 0x1101e4
// Original: 1101e4_sub_1101E4.c
// Primary struct: <unclustered>
//
// sub_1101E4 @ 0x1101e4, size 52 bytes
int sub_1101E4()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = off_110218;
  result = sub_12D240(dword_11021C);
  if ( *(_WORD *)(*(_DWORD *)v0 + 2) )
  {
    v2 = dword_110220;
    v3 = dword_11021C;
    v4 = 0;
    do
    {
      sub_10FB28(v2, 0xCu);
      result = sub_12D248(v3);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(_DWORD *)v0 + 2) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

