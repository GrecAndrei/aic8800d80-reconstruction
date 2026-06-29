// sub_125CBC @ 0x125cbc, size 18 bytes
int  sub_125CBC(int a1)
{
  uint8_t *v1; // r3
  int v2; // r2

  v1 = off_125CD0;
  v2 = *((uint32_t *)off_125CD0 + 1);
  *(uint32_t *)off_125CD0 = a1;
  if ( !v2 )
    return sub_125C68(a1);
  v1[10] = 1;
  return a1;
}

