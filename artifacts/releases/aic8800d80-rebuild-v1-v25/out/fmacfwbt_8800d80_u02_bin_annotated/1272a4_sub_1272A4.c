// fwstruct annotate: 1272a4_sub_1272A4.c
// sub_1272A4 @ 0x1272a4, size 44 bytes
int sub_1272A4()
{
  char v0; // r3
  int result; // r0

  if ( *((_BYTE *)off_1272D0 + 89) )
  {
    v0 = *((_BYTE *)off_1272D0 + 89) - 1;
    *((_BYTE *)off_1272D0 + 89) = v0;
    if ( !v0 && *(_BYTE *)off_1272D4 == 1 )
    {
      *(_BYTE *)off_1272D4 = 0;
      fw_init_or_check_1221d44();
      return sub_12726C();
    }
  }
  return result;
}

