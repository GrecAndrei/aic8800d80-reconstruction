// v23 annotated: sub_111800 @ 0x111800
// Original: 111800_sub_111800.c
// Primary struct: <unclustered>
//
// sub_111800 @ 0x111800, size 48 bytes
int *__fastcall sub_111800(int a1)
{
  int v2; // r0
  int v3; // r5
  int *result; // r0
  int (__fastcall *v5)(_DWORD, _DWORD, int); // r3

  v2 = dword_111830 + 16 * (a1 - 1);
  v3 = *(unsigned __int8 *)(v2 + 11);
  result = sub_100200((int *)v2, 0, 0x10u);
  if ( v3 )
  {
    v5 = *(int (__fastcall **)(_DWORD, _DWORD, int))(dword_111834 + 4 * (a1 + 13));
    if ( v5 )
      return (int *)v5(0, 0, 1);
  }
  return result;
}

