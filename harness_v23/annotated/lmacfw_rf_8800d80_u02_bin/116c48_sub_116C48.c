// v23 annotated: sub_116C48 @ 0x116c48
// Original: 116c48_sub_116C48.c
// Primary struct: <unclustered>
//
// sub_116C48 @ 0x116c48, size 30 bytes
int sub_116C48()
{
  _BYTE *v0; // r4
  unsigned int v1; // r2
  unsigned int v2; // r3
  int result; // r0

  v0 = off_116C68;
  v1 = *((unsigned __int8 *)off_116C68 + 11);
  v2 = (unsigned __int8)(*((_BYTE *)off_116C68 + 10) + 1);
  *((_BYTE *)off_116C68 + 10) = v2;
  if ( v1 < v2 )
  {
    result = j_nullsub_6();
    v0[10] = 0;
  }
  return result;
}

