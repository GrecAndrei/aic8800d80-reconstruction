// fwstruct annotate: 126fd8_sub_126FD8.c
// sub_126FD8 @ 0x126fd8, size 104 bytes
int __fastcall sub_126FD8(char a1)
{
  _BYTE *v1; // r4
  int v3; // r0
  int v4; // r2
  signed int v5; // r3

  v1 = off_127040;
  if ( *((_BYTE *)off_127040 + 1) )
  {
    v3 = *((char *)off_127040 + 3);
    v4 = v3;
  }
  else
  {
    sub_10DE98();
    v4 = (int)COERCE_FLOAT(sub_10DEF0());
    v3 = (char)v4;
  }
  v1[4] = a1;
  v1[6] = a1;
  if ( v4 > 29 )
    v5 = (unsigned int)(((unsigned int)dword_127048 * (unsigned __int64)(unsigned int)(v4 - 30)) >> 32) >> 3;
  else
    v5 = ((int)((unsigned __int64)(dword_127044 * (__int64)(v4 - 40)) >> 32) >> 2) - ((v4 - 40) >> 31);
  if ( v5 >= 8 )
    v5 = 8;
  if ( v5 < -7 )
    LOBYTE(v5) = -7;
  v1[2] = v5;
  return sub_126F10(v3);
}

