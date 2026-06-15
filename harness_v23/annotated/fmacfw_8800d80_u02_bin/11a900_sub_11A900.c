// v23 annotated: sub_11A900 @ 0x11a900
// Original: 11a900_sub_11A900.c
// Primary struct: <unclustered>
//
// sub_11A900 @ 0x11a900, size 58 bytes
int __fastcall sub_11A900(int result)
{
  int v1; // r5
  int v2; // r1
  char v3; // r3
  int v4; // r4

  v1 = dword_11A93C;
  v2 = *(_DWORD *)(dword_11A93C + 84 * result + 40);
  if ( v2 )
  {
    v3 = *(_BYTE *)(v2 + 14) - 1;
    v4 = result;
    *(_BYTE *)(v2 + 14) = v3;
    if ( !v3 )
      sub_12D248(*(_DWORD *)(v2 + 340));
    *(_DWORD *)(v1 + 84 * v4 + 40) = 0;
    return 84;
  }
  return result;
}

