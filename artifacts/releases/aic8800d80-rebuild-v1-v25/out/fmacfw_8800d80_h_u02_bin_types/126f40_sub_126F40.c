// sub_126F40 @ 0x126f40, size 44 bytes
int sub_126F40()
{
  char v0; // r3
  int result; // r0

  if ( *((uint8_t *)off_126F6C + 89) )
  {
    v0 = *((uint8_t *)off_126F6C + 89) - 1;
    *((uint8_t *)off_126F6C + 89) = v0;
    if ( !v0 && *(uint8_t *)off_126F70 == 1 )
    {
      *(uint8_t *)off_126F70 = 0;
      sub_1219A4();
      return sub_126F08();
    }
  }
  return result;
}

