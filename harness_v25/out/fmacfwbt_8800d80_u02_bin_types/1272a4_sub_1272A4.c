// sub_1272A4 @ 0x1272a4, size 44 bytes
int sub_1272A4()
{
  char v0; // r3
  int result; // r0

  if ( *((uint8_t *)off_1272D0 + 89) )
  {
    v0 = *((uint8_t *)off_1272D0 + 89) - 1;
    *((uint8_t *)off_1272D0 + 89) = v0;
    if ( !v0 && *(uint8_t *)off_1272D4 == 1 )
    {
      *(uint8_t *)off_1272D4 = 0;
      fw_init_or_check_1221d44();
      return sub_12726C();
    }
  }
  return result;
}

