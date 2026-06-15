// util_sub_f0b4 @ 0x10f0b4, size 52 bytes
// Doc: util_sub_f0b4 [util]: Generic utility function
// util_sub_f0b4 [util]: Generic utility function
int util_sub_f0b4()
{
  _BYTE *v0; // r3
  int result; // r0
  int v2; // r1
  int v3; // r2

  if ( *((_BYTE *)off_10F0E8 + 362) )
  {
    *(_BYTE *)off_10F0EC = 0;
  }
  else
  {
    v0 = off_10F0EC;
    *(_DWORD *)off_10F0EC = dword_10F0F0;
    v2 = dword_10F0F4;
    v3 = dword_10F0F8;
    v0[7] = -62;
    *((_DWORD *)v0 + 2) = 1000;
    *((_WORD *)v0 + 2) = 1752;
    *((_DWORD *)v0 + 4) = v2;
    *((_DWORD *)v0 + 8) = v3;
    return 1752;
  }
  return result;
}

