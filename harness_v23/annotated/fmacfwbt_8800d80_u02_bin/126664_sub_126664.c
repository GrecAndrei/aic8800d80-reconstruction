// v23 annotated: sub_126664 @ 0x126664
// Original: 126664_sub_126664.c
// Primary struct: <unclustered>
//
// sub_126664 @ 0x126664, size 44 bytes
int __fastcall sub_126664(_DWORD *a1)
{
  int v1; // r3
  int v2; // r2

  v1 = dword_126690;
  while ( 1 )
  {
    if ( *(unsigned __int8 *)(v1 + 24) != 255 )
    {
      v2 = *(unsigned __int8 *)(v1 + 27);
      if ( v2 != 255 )
        break;
    }
    v1 += 28;
    if ( v1 == dword_126690 + 84 )
      return 0;
  }
  *a1 = dword_126694 + 1320 * v2;
  return 1;
}

