// fwstruct annotate: 10f198_sub_10F198.c
// sub_10F198 @ 0x10f198, size 90 bytes
int sub_10F198()
{
  _BYTE *v0; // r6
  int v1; // r5
  int v2; // r4
  int v3; // r0
  int result; // r0

  v0 = off_10F1F8;
  v1 = (char)(*((_BYTE *)off_10F1F8 + 5) + (*(_BYTE *)off_10F1F4 & 3));
  v2 = *((char *)off_10F1F8 + 7) - v1;
  if ( v2 < -62 )
    LOBYTE(v2) = -62;
  sub_102B80(v2);
  v3 = dword_10F1FC;
  v0[7] = v2;
  result = sub_12EA88(v3, (char)v2, v1);
  if ( (char)v2 >= -61 )
    return sub_124D3C(v0 + 12, *((_DWORD *)off_10F200 + 4) + 30000 * *((unsigned __int16 *)v0 + 4));
  v0[11] = 0;
  return result;
}

