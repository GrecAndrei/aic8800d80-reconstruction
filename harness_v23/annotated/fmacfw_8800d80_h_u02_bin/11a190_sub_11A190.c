// v23 annotated: sub_11A190 @ 0x11a190
// Original: 11a190_sub_11A190.c
// Primary struct: <unclustered>
//
// sub_11A190 @ 0x11a190, size 22 bytes
int __fastcall sub_11A190(int result)
{
  char v1; // r3

  v1 = *(_BYTE *)(result + 14) - 1;
  *(_BYTE *)(result + 14) = v1;
  if ( !v1 )
    return sub_12D108(*(_DWORD *)(result + 340));
  return result;
}

