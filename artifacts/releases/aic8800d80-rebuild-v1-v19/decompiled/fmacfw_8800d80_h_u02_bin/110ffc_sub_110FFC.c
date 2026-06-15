// sub_110FFC @ 0x110ffc, size 28 bytes
_DWORD *__fastcall sub_110FFC(_DWORD *result, int a2, int a3, unsigned __int16 a4, int a5)
{
  result[2] = dword_111018 & result[2] | a4 | (a5 << 31);
  *result = a2;
  result[1] = a3;
  return result;
}

