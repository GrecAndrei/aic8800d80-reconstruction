// fwstruct annotate: 11182c_sub_11182C.c
// sub_11182C @ 0x11182c, size 48 bytes
int *__fastcall sub_11182C(int a1)
{
  int v2; // r0
  int v3; // r5
  int *result; // r0
  int (__fastcall *v5)(_DWORD, _DWORD, int); // r3

  v2 = dword_11185C + 16 * (a1 - 1);
  v3 = *(unsigned __int8 *)(v2 + 8);
  result = sub_100200((int *)v2, 0, 0x10u);
  if ( v3 )
  {
    result = (int *)dword_111860;
    v5 = *(int (__fastcall **)(_DWORD, _DWORD, int))(dword_111860 + 4 * a1 + 32);
    if ( v5 )
      return (int *)v5(0, 0, 1);
  }
  return result;
}

