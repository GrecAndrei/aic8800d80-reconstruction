// sub_11113C @ 0x11113c, size 28 bytes
// Doc: sub_121113C [util]: Pack bitfield value from fields (mask OR shift OR shift31)
// sub_121113C [util]: Pack bitfield value from fields (mask OR shift OR shift31)
_DWORD *__fastcall sub_11113C(_DWORD *result, int a2, int a3, unsigned __int16 a4, int a5)
{
  *(_DWORD *)(result + 0x8) = dword_111158 & *(_DWORD *)(result + 0x8) | a4 | (a5 << 31);
  *result = a2;
  *(_DWORD *)(result + 0x4) = a3;
  return result;
}

