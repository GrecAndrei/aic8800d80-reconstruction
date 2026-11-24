// sub_10EE10 @ 0x10ee10, size 430 bytes
int sub_10EE10()
{
  int result; // r0

  sub_10ECEC(1879048192, 256, 264, 1);
  sub_10ECEC(dword_10EFC0, 0x8000000, 0x8000000, 1);
  sub_10ECEC(dword_10EFC4, 21, 31, 1);
  sub_10ECEC(dword_10EFD0, dword_10EFCC, dword_10EFC8, 1);
  sub_10ECEC(dword_10EFD4, 2560, 2560, 1);
  sub_10ECEC(dword_10EFD8, 255, 255, 1);
  sub_10ECEC(dword_10EFDC, 0, 100663296, 1);
  sub_10ECEC(dword_10EFE0, 0, 983040, 1);
  sub_10ECEC(dword_10EFE4, 96, 96, 1);
  sub_10ECEC(dword_10EFE8, 256, 256, 1);
  sub_10ECEC(dword_10EFEC, 469762048, 469762048, 1);
  sub_10ECEC(dword_10EFF0, 104, 252, 1);
  sub_10ECEC(dword_10EFF4, 6, 102, 1);
  sub_10ECEC(dword_10EFF8, 320, 992, 1);
  sub_10ECEC(dword_10F004, dword_10F000, dword_10EFFC, 1);
  sub_10ECEC(dword_10F008, 0x400000, 15728640, 1);
  sub_10ECEC(dword_10F00C, 16, 63, 1);
  sub_10ECEC(dword_10F010, 0, 60, 1);
  sub_10ECEC(dword_10F014, 0, 256, 1);
  sub_10ECEC(dword_10F018, 2048, 16128, 1);
  result = sub_10ECEC(dword_10F01C, 1, 1, 1);
  if ( **(_BYTE **)off_10F020 == 1 )
  {
    sub_10EC98(dword_10F028, dword_10F024, 1);
    sub_10EC98(dword_10F030, dword_10F02C, 1);
    sub_10ECEC(dword_10F01C, 0x100000, 0x100000, 1);
    result = sub_10ECEC(dword_10F034, 2, 31, 1);
    if ( !*((_BYTE *)off_10F038 + 375) )
    {
      sub_10ECEC(dword_10F03C, 1, 1, 1);
      sub_10ECEC(dword_10F014, 256, 256, 1);
      sub_10ECEC(dword_10F018, 0x2000, 16128, 1);
      sub_10ECEC(dword_10EFDC, 2359296, 16515072, 1);
      return sub_10ECEC(dword_10F01C, 256, 256, 1);
    }
  }
  return result;
}

