// fwstruct annotate: 1119a4_sub_1119A4.c
// sub_1119A4 @ 0x1119a4, size 48 bytes
int *__fastcall sub_1119A4(int a1)
{
  int v2; // r0
  int v3; // r5
  int *result; // r0
  int (__fastcall *v5)(_DWORD, _DWORD, int); // r3

  v2 = dword_1119D4 + 16 * (a1 - 1);
  v3 = *(unsigned __int8 *)(v2 + 11);
  result = sub_100200((int *)v2, 0, 0x10u);
  if ( v3 )
  {
    v5 = *(int (__fastcall **)(_DWORD, _DWORD, int))(dword_1119D8 + 4 * (a1 + 13));
    if ( v5 )
      return (int *)v5(0, 0, 1);
  }
  return result;
}

