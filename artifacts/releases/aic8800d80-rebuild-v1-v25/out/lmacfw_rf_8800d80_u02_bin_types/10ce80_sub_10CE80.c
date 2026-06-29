// sub_10CE80 @ 0x10ce80, size 52 bytes
int sub_10CE80()
{
  int v0; // r4
  uint32_t *v1; // r2
  int result; // r0

  v0 = *(uint32_t *)off_10CEB4;
  if ( (*(uint32_t *)off_10CEB4 & 0x20) != 0 )
  {
    v1 = off_10CEBC;
    *(uint32_t *)off_10CEB8 = 32;
    *v1 = 32;
    result = sub_11E5E0(0x400000);
  }
  if ( (v0 & 2) != 0 )
  {
    result = sub_11E5E0(0x8000000);
    *(uint32_t *)off_10CEB8 = 2;
  }
  return result;
}

