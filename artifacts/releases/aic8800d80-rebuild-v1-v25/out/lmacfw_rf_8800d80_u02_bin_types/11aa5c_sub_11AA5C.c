// sub_11AA5C @ 0x11aa5c, size 34 bytes
unsigned __int8 * sub_11AA5C(unsigned __int8 *result)
{
  unsigned int v1; // r2
  unsigned __int8 *v2; // r3
  uint8_t *v3; // r4

  v1 = *result;
  if ( v1 <= 2 )
  {
    v2 = (unsigned __int8 *)off_11AA80;
    v3 = off_11AA88;
    *(uint8_t *)off_11AA84 = v1;
    *v3 = v1;
    return (unsigned __int8 *)sub_102E84(v2[36], v2[37], v1);
  }
  return result;
}

