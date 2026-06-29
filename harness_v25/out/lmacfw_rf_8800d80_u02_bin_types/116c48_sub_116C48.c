// sub_116C48 @ 0x116c48, size 30 bytes
int sub_116C48()
{
  uint8_t *v0; // r4
  unsigned int v1; // r2
  unsigned int v2; // r3
  int result; // r0

  v0 = off_116C68;
  v1 = *((unsigned __int8 *)off_116C68 + 11);
  v2 = (unsigned __int8)(*((uint8_t *)off_116C68 + 10) + 1);
  *((uint8_t *)off_116C68 + 10) = v2;
  if ( v1 < v2 )
  {
    result = j_nullsub_6();
    v0[10] = 0;
  }
  return result;
}

