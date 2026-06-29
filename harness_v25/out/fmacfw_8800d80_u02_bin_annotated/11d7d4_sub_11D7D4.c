// fwstruct annotate: 11d7d4_sub_11D7D4.c
// sub_11D7D4 @ 0x11d7d4, size 30 bytes
int sub_11D7D4()
{
  _BYTE *v0; // r4
  unsigned int *v1; // r2
  int v2; // r3
  int result; // r0

  v0 = off_11D7F4;
  if ( *((_BYTE *)off_11D7F4 + 10) )
    result = j_nullsub_6();
  v1 = (unsigned int *)off_11D7F8;
  v2 = *(_DWORD *)off_11D7F8;
  v0[10] = v0[11];
  *v1 = v2 & 0xFFFFFEFF;
  return result;
}

