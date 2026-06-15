// sub_10F25C @ 0x10f25c, size 52 bytes
int sub_10F25C()
{
  _BYTE *v0; // r3
  int result; // r0
  int v2; // r1
  void *v3; // r2

  if ( *((_BYTE *)off_10F290 + 362) )
  {
    *(_BYTE *)off_10F294 = 0;
  }
  else
  {
    v0 = off_10F294;
    *(_DWORD *)off_10F294 = dword_10F298;
    v2 = dword_10F29C;
    v3 = off_10F2A0;
    v0[7] = -62;
    *((_DWORD *)v0 + 2) = 1000;
    *((_WORD *)v0 + 2) = 1752;
    *((_DWORD *)v0 + 4) = v2;
    *((_DWORD *)v0 + 8) = v3;
    return 1752;
  }
  return result;
}

