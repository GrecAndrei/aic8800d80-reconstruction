// sub_121A94 @ 0x121a94, size 84 bytes
unsigned int sub_121A94()
{
  __int16 **v0; // r0
  int v1; // r3
  int *v2; // r4
  int v3; // r2
  unsigned int result; // r0
  int v5; // r1
  _DWORD *v6; // r2

  v0 = (__int16 **)off_121AEC;
  v1 = dword_121AF0;
  *(_DWORD *)off_121AE8 |= 2u;
  v2 = (int *)off_121AF4;
  v3 = **v0;
  *(_DWORD *)off_121AF4 = v1;
  if ( v3 < 0 && *(_DWORD *)off_121B08 << 28 )
  {
    sub_12F6C4(dword_121B10, dword_121B0C, 472);
    v1 = *v2;
  }
  *(_DWORD *)off_121AF8 = v1 | v2[1];
  result = sub_11E4C0(0);
  v5 = dword_121B00;
  v6 = off_121B04;
  *(_DWORD *)off_121AFC = dword_121B00;
  *v6 |= v5;
  return result;
}

