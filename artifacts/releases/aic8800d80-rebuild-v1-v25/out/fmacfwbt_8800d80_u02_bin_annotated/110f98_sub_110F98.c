// fwstruct annotate: 110f98_sub_110F98.c
// sub_110F98 @ 0x110f98, size 28 bytes
_DWORD *__fastcall sub_110F98(_DWORD *result, int a2, int a3, unsigned __int16 a4, int a5)
{
  result[2] = dword_110FB4 & result[2] | a4 | (a5 << 31);
  *result = a2;
  result[1] = a3;
  return result;
}

