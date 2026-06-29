// fwstruct annotate: 11d694_sub_11D694.c
// sub_11D694 @ 0x11d694, size 30 bytes
int sub_11D694()
{
  _BYTE *v0; // r4
  unsigned int *v1; // r2
  int v2; // r3
  int result; // r0

  v0 = off_11D6B4;
  if ( *((_BYTE *)off_11D6B4 + 10) )
    result = j_nullsub_6();
  v1 = (unsigned int *)off_11D6B8;
  v2 = *(_DWORD *)off_11D6B8;
  v0[10] = v0[11];
  *v1 = v2 & 0xFFFFFEFF;
  return result;
}

