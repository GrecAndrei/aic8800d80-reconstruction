// debug_if_check_40320038 @ 0x101924, size 18 bytes
// Doc: debug_if_check_40320038 [util]: Check debug interface status register at 0x40320038 and load status string
// debug_if_check_40320038 [util]: Check debug interface status register at 0x40320038 and load status string
int __fastcall debug_if_check_40320038(int a1, int a2, int a3)
{
  int result; // r0

  if ( *(_DWORD *)off_101938 << 28 )
    return msg_parse(dword_101940, dword_10193C, a3);
  return result;
}

