// sub_128B60 @ 0x128b60, size 64 bytes
int  sub_128B60(int a1, int a2)
{
  int result; // r0
  unsigned __int16 *v5; // r2
  char v6; // r3

  sub_12EB90(2, dword_128BA4);
  result = sub_1289EC(a1, a2, dword_128BA8);
  if ( result )
  {
    v5 = (unsigned __int16 *)off_128BAC;
    if ( !*((uint8_t *)off_128BAC + 8) || (v6 = *((uint8_t *)off_128BAC + 8) - 1, (*((uint8_t *)off_128BAC + 8) = v6) == 0) )
    {
      *(uint8_t *)v5 = 1;
      return sub_12C8D0(50, v5[1], 0);
    }
  }
  return result;
}

