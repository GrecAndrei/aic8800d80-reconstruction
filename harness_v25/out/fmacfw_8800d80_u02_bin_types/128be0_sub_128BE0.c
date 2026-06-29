// sub_128BE0 @ 0x128be0, size 66 bytes
int  sub_128BE0(int a1, int a2)
{
  int result; // r0
  uint8_t *v4; // r5
  int v5; // r3

  result = sub_128B2C(a1, a2, dword_128C24);
  if ( result )
  {
    v4 = off_128C2C;
    v5 = *((unsigned __int8 *)off_128C28 + 2);
    *((uint8_t *)off_128C2C + 28) = 0;
    if ( v5 )
      *(uint32_t *)off_128C30 |= 0x80000000;
    if ( v4[8] )
      --v4[8];
    result = timestamp_remove(dword_128C34);
    v4[29] = 0;
    *(uint32_t *)(a1 + 4) &= 0xFFFFFDF9;
  }
  return result;
}

