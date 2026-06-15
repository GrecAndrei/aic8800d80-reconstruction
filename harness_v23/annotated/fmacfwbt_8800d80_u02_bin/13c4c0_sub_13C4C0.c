// v23 annotated: sub_13C4C0 @ 0x13c4c0
// Original: 13c4c0_sub_13C4C0.c
// Primary struct: <unclustered>
//
// sub_13C4C0 @ 0x13c4c0, size 70 bytes
int __fastcall sub_13C4C0(int a1, int a2)
{
  int result; // r0
  unsigned int v3; // r4

  result = 696 * a1 + 12 * a2 + dword_13C50C;
  v3 = *(unsigned __int8 *)(result + 452);
  if ( **(__int16 **)off_13C508 < 0 && v3 > 0x20 )
    result = sub_12F694(dword_13C51C, dword_13C518, 1152);
  *(_DWORD *)(dword_13C510 + 32 * v3 + 8) = *((_DWORD *)off_13C514 + 4);
  return result;
}

