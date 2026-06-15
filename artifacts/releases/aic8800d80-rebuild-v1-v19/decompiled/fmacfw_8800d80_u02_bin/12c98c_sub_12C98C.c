// sub_12C98C @ 0x12c98c, size 106 bytes
int __fastcall sub_12C98C(int a1)
{
  __int16 v1; // r3
  unsigned __int16 *v4; // r0

  v1 = *(_WORD *)(a1 - 6);
  if ( **(__int16 **)off_12C9F8 >= 0 || (unsigned __int8)v1 <= 0xEu )
  {
    if ( (unsigned __int8)v1 <= 0xCu )
    {
      sub_12D248(dword_12C9FC);
      return sub_12D104(0x4000000);
    }
  }
  else
  {
    sub_12F46C(dword_12CA04, dword_12CA00, 183);
  }
  sub_12EA88(dword_12CA08, *(unsigned __int16 *)(a1 - 8), *(unsigned __int16 *)(a1 - 4));
  v4 = (unsigned __int16 *)(a1 - 12);
  if ( *(_BYTE *)off_12CA0C )
    return sub_12CBC8(v4);
  else
    return sub_12F52C(v4);
}

