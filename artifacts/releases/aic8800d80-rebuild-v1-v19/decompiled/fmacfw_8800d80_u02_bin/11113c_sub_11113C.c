// sub_11113C @ 0x11113c, size 28 bytes
// Doc: sub_121113C [util]: Pack bitfield value from fields (mask OR shift OR shift31)
// sub_121113C [util]: Pack bitfield value from fields (mask OR shift OR shift31)
_DWORD *__fastcall sub_11113C(_DWORD *result, int a2, int a3, unsigned __int16 a4, int a5)
{
  result[2] = dword_111158 & result[2] | a4 | (a5 << 31);
  *result = a2;
  result[1] = a3;
  return result;
}

