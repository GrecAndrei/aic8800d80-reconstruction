// sub_128C38 @ 0x128c38, size 76 bytes
int  sub_128C38(int a1, int a2)
{
  int result; // r0
  uint8_t *v4; // r3
  int v5; // r2
  int v6; // r2
  int v7; // r1
  int v8; // r0

  result = sub_128B2C(a1, a2, dword_128C84);
  if ( result )
  {
    v4 = off_128C8C;
    v5 = *((unsigned __int8 *)off_128C88 + 2);
    *((uint8_t *)off_128C8C + 28) = 1;
    if ( v5 )
      *(uint32_t *)off_128C90 &= ~0x80000000;
    if ( v4[8] )
      --v4[8];
    v6 = *((uint32_t *)off_128C98 + 4);
    v7 = *(unsigned __int16 *)(*(uint32_t *)off_128C94 + 54);
    v8 = dword_128C9C;
    *((uint32_t *)v4 + 5) = a1;
    v4[29] = 4;
    result = timestamp_update(v8, v7 + v6);
    *(uint32_t *)(a1 + 4) |= 0x200u;
  }
  return result;
}

