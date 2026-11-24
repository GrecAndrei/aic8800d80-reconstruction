// sub_13EAE0 @ 0x13eae0, size 42 bytes
// Doc: misc_bit_extract_helper [util]: Extracts and combines bit fields from input value
// misc_bit_extract_helper [util]: Extracts and combines bit fields from input value
unsigned int __fastcall sub_13EAE0(unsigned int result)
{
  unsigned int v1; // r2

  v1 = *(_DWORD *)(*(_DWORD *)(result + 76) + 4);
  if ( (v1 & 0x810000) != 0 )
    return sub_13E5D4(result, BYTE1(v1) + 1, (HIWORD(v1) & 1) + BYTE1(v1), 0, 0);
  return result;
}

