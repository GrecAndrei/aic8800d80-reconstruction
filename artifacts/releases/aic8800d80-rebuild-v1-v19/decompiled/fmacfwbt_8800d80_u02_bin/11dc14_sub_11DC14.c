// sub_11DC14 @ 0x11dc14, size 30 bytes
int sub_11DC14()
{
  _BYTE *v0; // r4
  unsigned int *v1; // r2
  int v2; // r3
  int result; // r0

  v0 = off_11DC34;
  if ( *((_BYTE *)off_11DC34 + 10) )
    result = j_nullsub_6();
  v1 = (unsigned int *)off_11DC38;
  v2 = *(_DWORD *)off_11DC38;
  v0[10] = v0[11];
  *v1 = v2 & 0xFFFFFEFF;
  return result;
}

