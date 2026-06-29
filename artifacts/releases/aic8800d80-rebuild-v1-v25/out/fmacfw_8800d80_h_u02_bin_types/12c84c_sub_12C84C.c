// sub_12C84C @ 0x12c84c, size 106 bytes
int  sub_12C84C(int a1)
{
  __int16 v1; // r3
  unsigned __int16 *v4; // r0

  v1 = *(uint16_t *)(a1 - 6);
  if ( **(__int16 **)off_12C8B8 >= 0 || (unsigned __int8)v1 <= 0xEu )
  {
    if ( (unsigned __int8)v1 <= 0xCu )
    {
      sub_12D108(dword_12C8BC);
      return sub_12CFC4(0x4000000);
    }
  }
  else
  {
    sub_12F32C(dword_12C8C4, dword_12C8C0, 183);
  }
  sub_12E948(dword_12C8C8, *(unsigned __int16 *)(a1 - 8), *(unsigned __int16 *)(a1 - 4));
  v4 = (unsigned __int16 *)(a1 - 12);
  if ( *(uint8_t *)off_12C8CC )
    return sub_12CA88(v4);
  else
    return sub_12F3EC(v4);
}

