// fwstruct annotate: 1018a8_sub_1018A8.c
// sub_1018A8 @ 0x1018a8, size 36 bytes
int sub_1018A8()
{
  char *v0; // r2
  int v1; // r1

  v0 = (char *)off_1018CC;
  v1 = *(_DWORD *)off_1018CC;
  *(_DWORD *)off_1018D0 = *(_DWORD *)off_1018CC;
  if ( (v1 & 0x1000) == 0 )
    return sub_12E948(dword_1018D4, v1, v0);
  *(_DWORD *)&v0[-8] &= ~0x1000u;
  return sub_12CFC4(16);
}

