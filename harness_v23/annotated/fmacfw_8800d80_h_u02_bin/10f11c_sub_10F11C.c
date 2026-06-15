// v23 annotated: sub_10F11C @ 0x10f11c
// Original: 10f11c_sub_10F11C.c
// Primary struct: <unclustered>
//
// sub_10F11C @ 0x10f11c, size 52 bytes
int sub_10F11C()
{
  _BYTE *v0; // r3
  int result; // r0
  int v2; // r1
  void *v3; // r2

  if ( *((_BYTE *)off_10F150 + 362) )
  {
    *(_BYTE *)off_10F154 = 0;
  }
  else
  {
    v0 = off_10F154;
    *(_DWORD *)off_10F154 = dword_10F158;
    v2 = dword_10F15C;
    v3 = off_10F160;
    v0[7] = -62;
    *((_DWORD *)v0 + 2) = 1000;
    *((_WORD *)v0 + 2) = 1752;
    *((_DWORD *)v0 + 4) = v2;
    *((_DWORD *)v0 + 8) = v3;
    return 1752;
  }
  return result;
}

