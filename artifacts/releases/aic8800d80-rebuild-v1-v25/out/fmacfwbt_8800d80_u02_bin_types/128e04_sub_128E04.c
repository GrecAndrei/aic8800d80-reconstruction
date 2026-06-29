// sub_128E04 @ 0x128e04, size 66 bytes
int  sub_128E04(int a1, int a2)
{
  int result; // r0
  uint8_t *v4; // r5
  int v5; // r3

  result = sub_128D50(a1, a2, dword_128E48);
  if ( result )
  {
    v4 = off_128E50;
    v5 = *((unsigned __int8 *)off_128E4C + 2);
    *((uint8_t *)off_128E50 + 28) = 0;
    if ( v5 )
      *(uint32_t *)off_128E54 |= 0x80000000;
    if ( v4[8] )
      --v4[8];
    result = timestamp_remove_058(dword_128E58);
    v4[29] = 0;
    *(uint32_t *)(a1 + 4) &= 0xFFFFFDF9;
  }
  return result;
}

