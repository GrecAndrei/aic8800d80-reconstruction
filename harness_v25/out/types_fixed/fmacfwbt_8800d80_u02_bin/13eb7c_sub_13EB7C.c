// sub_13EB7C @ 0x13eb7c, size 42 bytes
// Doc: bitfield_pack_u16_to_u32 [util]: Pack u16 bitfield into u32 with bit extraction
// bitfield_pack_u16_to_u32 [util]: Pack u16 bitfield into u32 with bit extraction
unsigned int __fastcall sub_13EB7C(unsigned int result)
{
  unsigned int v1; // r2

  v1 = *(_DWORD *)(*(_DWORD *)(result + 76) + 4);
  if ( (v1 & 0x810000) != 0 )
    return sub_13E670(result, BYTE1(v1) + 1, (HIWORD(v1) & 1) + BYTE1(v1), 0, 0);
  return result;
}

