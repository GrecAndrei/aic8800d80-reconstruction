// fwstruct annotate: 11d670_sub_11D670.c
// sub_11D670 @ 0x11d670, size 30 bytes
int sub_11D670()
{
  _BYTE *v0; // r4
  unsigned int v1; // r2
  unsigned int v2; // r3
  int result; // r0

  v0 = off_11D690;
  v1 = *((unsigned __int8 *)off_11D690 + 11);
  v2 = (unsigned __int8)(*((_BYTE *)off_11D690 + 10) + 1);
  *((_BYTE *)off_11D690 + 10) = v2;
  if ( v1 < v2 )
  {
    result = j_nullsub_6();
    v0[10] = 0;
  }
  return result;
}

