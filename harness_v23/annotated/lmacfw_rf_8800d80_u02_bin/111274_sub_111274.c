// v23 annotated: sub_111274 @ 0x111274
// Original: 111274_sub_111274.c
// Primary struct: <unclustered>
//
// sub_111274 @ 0x111274, size 48 bytes
int *__fastcall sub_111274(int a1)
{
  int v2; // r0
  int v3; // r5
  int *result; // r0
  int (__fastcall *v5)(_DWORD, _DWORD, int); // r3

  v2 = dword_1112A4 + 16 * (a1 - 1);
  v3 = *(unsigned __int8 *)(v2 + 8);
  result = sub_100200((int *)v2, 0, 0x10u);
  if ( v3 )
  {
    result = (int *)dword_1112A8;
    v5 = *(int (__fastcall **)(_DWORD, _DWORD, int))(dword_1112A8 + 4 * a1 + 32);
    if ( v5 )
      return (int *)v5(0, 0, 1);
  }
  return result;
}

