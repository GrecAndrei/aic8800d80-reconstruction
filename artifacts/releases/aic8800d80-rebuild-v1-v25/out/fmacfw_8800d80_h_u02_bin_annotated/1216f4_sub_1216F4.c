// fwstruct annotate: 1216f4_sub_1216F4.c
// sub_1216F4 @ 0x1216f4, size 84 bytes
unsigned int sub_1216F4()
{
  __int16 **v0; // r0
  int v1; // r3
  int *v2; // r4
  int v3; // r2
  unsigned int result; // r0
  int v5; // r1
  _DWORD *v6; // r2

  v0 = (__int16 **)off_12174C;
  v1 = dword_121750;
  *(_DWORD *)off_121748 |= 2u;
  v2 = (int *)off_121754;
  v3 = **v0;
  *(_DWORD *)off_121754 = v1;
  if ( v3 < 0 && *(_DWORD *)off_121768 << 28 )
  {
    sub_12F35C(dword_121770, dword_12176C, 472);
    v1 = *v2;
  }
  *(_DWORD *)off_121758 = v1 | v2[1];
  result = sub_11DF40(0);
  v5 = dword_121760;
  v6 = off_121764;
  *(_DWORD *)off_12175C = dword_121760;
  *v6 |= v5;
  return result;
}

