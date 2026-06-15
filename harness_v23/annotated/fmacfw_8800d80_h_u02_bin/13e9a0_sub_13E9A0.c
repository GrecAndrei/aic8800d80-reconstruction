// v23 annotated: sub_13E9A0 @ 0x13e9a0
// Original: 13e9a0_sub_13E9A0.c
// Primary struct: <unclustered>
//
// sub_13E9A0 @ 0x13e9a0, size 42 bytes
unsigned int __fastcall sub_13E9A0(unsigned int result)
{
  unsigned int v1; // r2

  v1 = *(_DWORD *)(*(_DWORD *)(result + 76) + 4);
  if ( (v1 & 0x810000) != 0 )
    return sub_13E494(result, BYTE1(v1) + 1, (HIWORD(v1) & 1) + BYTE1(v1), 0, 0);
  return result;
}

