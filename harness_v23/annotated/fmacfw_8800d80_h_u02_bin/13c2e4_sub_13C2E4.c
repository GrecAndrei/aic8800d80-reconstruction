// v23 annotated: sub_13C2E4 @ 0x13c2e4
// Original: 13c2e4_sub_13C2E4.c
// Primary struct: <unclustered>
//
// sub_13C2E4 @ 0x13c2e4, size 70 bytes
int __fastcall sub_13C2E4(int a1, int a2)
{
  int result; // r0
  unsigned int v3; // r4

  result = 696 * a1 + 12 * a2 + dword_13C330;
  v3 = *(unsigned __int8 *)(result + 452);
  if ( **(__int16 **)off_13C32C < 0 && v3 > 0x20 )
    result = sub_12F32C(dword_13C340, dword_13C33C, 1152);
  *(_DWORD *)(dword_13C334 + 32 * v3 + 8) = *((_DWORD *)off_13C338 + 4);
  return result;
}

