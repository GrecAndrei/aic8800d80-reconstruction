// mmio_flag_check_40500000 @ 0x125ffc, size 88 bytes
// Doc: mmio_flag_check_40500000 [mmio]: Read MMIO word at 0x40500000 and test bit1 flag
// mmio_flag_check_40500000 [mmio]: Read MMIO word at 0x40500000 and test bit1 flag
int  mmio_flag_check_40500000(int a1, int a2, int a3)
{
  unsigned __int8 v4[8]; // [sp+4h] [bp-8h] BYREF

  if ( (*(uint32_t *)off_126054 & 0x2000000) != 0 )
  {
    msg_parse(dword_126060, dword_12605C, a3, HIBYTE(*(uint32_t *)off_126054) & 2);
    return 0;
  }
  else
  {
    *(uint16_t *)v4 = 0;
    sub_114868((int)v4);
    if ( v4[0] == 255 || v4[1] == 255 )
    {
      msg_parse(dword_126058);
      return 0;
    }
    else
    {
      msg_parse(dword_126060, v4);
      return 0;
    }
  }
}

