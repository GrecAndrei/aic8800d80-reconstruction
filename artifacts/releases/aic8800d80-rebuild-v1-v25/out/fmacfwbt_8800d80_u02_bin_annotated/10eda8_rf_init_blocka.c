// fwstruct annotate: 10eda8_rf_init_blocka.c
// rf_init_blocka @ 0x10eda8, size 430 bytes
// Doc: rf_init_blocka [rf]: RF initialization block A: setup core with size 0x100/0x108 and enable
// rf_init_blocka [rf]: RF initialization block A: setup core with size 0x100/0x108 and enable
int rf_init_blocka()
{
  int result; // r0

  rf_reg_write_guard(1879048192, 256, 264, 1);
  rf_reg_write_guard(dword_10EF58, 0x8000000, 0x8000000, 1);
  rf_reg_write_guard(dword_10EF5C, 21, 31, 1);
  rf_reg_write_guard(dword_10EF68, dword_10EF64, dword_10EF60, 1);
  rf_reg_write_guard(dword_10EF6C, 2560, 2560, 1);
  rf_reg_write_guard(dword_10EF70, 255, 255, 1);
  rf_reg_write_guard(dword_10EF74, 0, 100663296, 1);
  rf_reg_write_guard(dword_10EF78, 0, 983040, 1);
  rf_reg_write_guard(dword_10EF7C, 96, 96, 1);
  rf_reg_write_guard(dword_10EF80, 256, 256, 1);
  rf_reg_write_guard(dword_10EF84, 469762048, 469762048, 1);
  rf_reg_write_guard(dword_10EF88, 104, 252, 1);
  rf_reg_write_guard(dword_10EF8C, 6, 6, 1);
  rf_reg_write_guard(dword_10EF90, 320, 992, 1);
  rf_reg_write_guard(dword_10EF9C, dword_10EF98, dword_10EF94, 1);
  rf_reg_write_guard(dword_10EFA0, 0x400000, 15728640, 1);
  rf_reg_write_guard(dword_10EFA4, 16, 63, 1);
  rf_reg_write_guard(dword_10EFA8, 0, 60, 1);
  rf_reg_write_guard(dword_10EFAC, 0, 256, 1);
  rf_reg_write_guard(dword_10EFB0, 2048, 16128, 1);
  result = rf_reg_write_guard(dword_10EFB4, 1, 1, 1);
  if ( **(_BYTE **)off_10EFB8 == 1 )
  {
    sub_10EC30(dword_10EFC0, dword_10EFBC, 1);
    sub_10EC30(dword_10EFC8, dword_10EFC4, 1);
    rf_reg_write_guard(dword_10EFB4, 0x100000, 0x100000, 1);
    result = rf_reg_write_guard(dword_10EFCC, 2, 31, 1);
    if ( !*((_BYTE *)off_10EFD0 + 375) )
    {
      rf_reg_write_guard(dword_10EFD4, 1, 1, 1);
      rf_reg_write_guard(dword_10EFAC, 256, 256, 1);
      rf_reg_write_guard(dword_10EFB0, 0x2000, 16128, 1);
      rf_reg_write_guard(dword_10EF74, 2359296, 16515072, 1);
      return rf_reg_write_guard(dword_10EFB4, 256, 256, 1);
    }
  }
  return result;
}

