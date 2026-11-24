// sub_126440 @ 0x126440, size 44 bytes
int __fastcall sub_126440(_DWORD *a1)
{
  int v1; // r3
  int v2; // r2

  v1 = dword_12646C;
  while ( 1 )
  {
    if ( *(unsigned __int8 *)(v1 + 24) != 255 )
    {
      v2 = *(unsigned __int8 *)(v1 + 27);
      if ( v2 != 255 )
        break;
    }
    v1 += 28;
    if ( v1 == dword_12646C + 84 )
      return 0;
  }
  *a1 = dword_126470 + 1320 * v2;
  return 1;
}

