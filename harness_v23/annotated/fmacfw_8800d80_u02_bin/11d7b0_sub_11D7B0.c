// v23 annotated: sub_11D7B0 @ 0x11d7b0
// Original: 11d7b0_sub_11D7B0.c
// Primary struct: <unclustered>
//
// sub_11D7B0 @ 0x11d7b0, size 30 bytes
int sub_11D7B0()
{
  _BYTE *v0; // r4
  unsigned int v1; // r2
  unsigned int v2; // r3
  int result; // r0

  v0 = off_11D7D0;
  v1 = *((unsigned __int8 *)off_11D7D0 + 11);
  v2 = (unsigned __int8)(*((_BYTE *)off_11D7D0 + 10) + 1);
  *((_BYTE *)off_11D7D0 + 10) = v2;
  if ( v1 < v2 )
  {
    result = j_nullsub_6();
    v0[10] = 0;
  }
  return result;
}

