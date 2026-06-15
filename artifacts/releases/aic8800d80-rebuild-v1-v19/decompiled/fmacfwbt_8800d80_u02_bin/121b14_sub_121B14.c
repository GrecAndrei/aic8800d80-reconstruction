// sub_121B14 @ 0x121b14, size 90 bytes
unsigned int sub_121B14()
{
  __int16 **v0; // r0
  int v1; // r3
  int *v2; // r4
  int v3; // r2
  unsigned int result; // r0
  _DWORD *v5; // r2

  v0 = (__int16 **)off_121B74;
  v1 = dword_121B78;
  *(_DWORD *)off_121B70 &= ~2u;
  v2 = (int *)off_121B7C;
  v3 = **v0;
  *(_DWORD *)off_121B7C = v1;
  if ( v3 < 0 && *(_DWORD *)off_121B90 << 28 )
  {
    sub_12F6C4(dword_121B98, dword_121B94, 472);
    v1 = *v2;
  }
  *(_DWORD *)off_121B80 = v1 | v2[1];
  result = sub_11E4C0(0);
  v5 = off_121B88;
  *(_DWORD *)off_121B84 = dword_121B8C;
  *v5 &= 0xFFFBFFFE;
  return result;
}

