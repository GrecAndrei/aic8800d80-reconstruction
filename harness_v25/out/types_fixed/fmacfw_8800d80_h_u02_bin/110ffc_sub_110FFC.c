// sub_110FFC @ 0x110ffc, size 28 bytes
_DWORD *__fastcall sub_110FFC(_DWORD *result, int a2, int a3, unsigned __int16 a4, int a5)
{
  *(_DWORD *)(result + 0x8) = dword_111018 & *(_DWORD *)(result + 0x8) | a4 | (a5 << 31);
  *result = a2;
  *(_DWORD *)(result + 0x4) = a3;
  return result;
}

