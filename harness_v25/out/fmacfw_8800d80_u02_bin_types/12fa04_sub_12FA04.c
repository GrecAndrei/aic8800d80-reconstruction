// sub_12FA04 @ 0x12fa04, size 32 bytes
int sub_12FA04()
{
  uint32_t *v0; // r4
  int v1; // r6
  int v2; // r5

  v0 = (uint32_t *)dword_12FA24;
  v1 = dword_12FA28;
  v2 = dword_12FA24 + 112;
  do
  {
    if ( v0[1] )
      sub_10DC24(v1, *v0);
    v0 += 4;
  }
  while ( v0 != (uint32_t *)v2 );
  return 0;
}

