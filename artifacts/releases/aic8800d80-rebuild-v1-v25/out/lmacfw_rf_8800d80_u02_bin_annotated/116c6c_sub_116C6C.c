// fwstruct annotate: 116c6c_sub_116C6C.c
// sub_116C6C @ 0x116c6c, size 30 bytes
int sub_116C6C()
{
  _BYTE *v0; // r4
  unsigned int *v1; // r2
  int v2; // r3
  int result; // r0

  v0 = off_116C8C;
  if ( *((_BYTE *)off_116C8C + 10) )
    result = j_nullsub_6();
  v1 = (unsigned int *)off_116C90;
  v2 = *(_DWORD *)off_116C90;
  v0[10] = v0[11];
  *v1 = v2 & 0xFFFFFEFF;
  return result;
}

