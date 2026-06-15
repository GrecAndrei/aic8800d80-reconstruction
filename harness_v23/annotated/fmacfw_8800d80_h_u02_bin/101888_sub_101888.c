// v23 annotated: sub_101888 @ 0x101888
// Original: 101888_sub_101888.c
// Primary struct: <unclustered>
//
// sub_101888 @ 0x101888, size 24 bytes
int __fastcall sub_101888(int result, int a2, int a3)
{
  if ( (*(_DWORD *)off_1018A0 & 8) != 0 )
  {
    result = sub_11EC18(result, a2, a3, *(_DWORD *)off_1018A0 << 28);
    *(_DWORD *)off_1018A4 = 8;
  }
  return result;
}

