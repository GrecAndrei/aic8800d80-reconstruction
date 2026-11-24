// sub_110B44 @ 0x110b44, size 28 bytes
_DWORD *__fastcall sub_110B44(_DWORD *result, int a2, int a3, unsigned __int16 a4, int a5)
{
  *(_DWORD *)(result + 0x8) = dword_110B60 & *(_DWORD *)(result + 0x8) | a4 | (a5 << 31);
  *result = a2;
  *(_DWORD *)(result + 0x4) = a3;
  return result;
}

