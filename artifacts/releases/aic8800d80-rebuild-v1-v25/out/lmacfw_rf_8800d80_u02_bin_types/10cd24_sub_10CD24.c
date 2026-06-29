// sub_10CD24 @ 0x10cd24, size 52 bytes
int sub_10CD24()
{
  int v0; // r4
  int result; // r0
  int *v2; // r2
  uint8_t *v3; // r3
  uint32_t *v4; // r2

  v0 = *(uint32_t *)off_10CD58 & 0xF00;
  if ( v0 )
  {
    result = sub_11E5E0(0x10000);
    v2 = (int *)off_10CD5C;
    v3 = off_10CD64;
    *(uint32_t *)off_10CD60 = v0;
    *v2 = v0;
    if ( *v3 )
    {
      v4 = off_10CD68;
      v3[1] = 1;
      *v4 |= 1u;
    }
  }
  return result;
}

