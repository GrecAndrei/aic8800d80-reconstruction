// mmio_flag_check_40500000 @ 0x125ffc, size 88 bytes
// Doc: mmio_flag_check_40500000 [mmio]: Read MMIO word at 0x40500000 and test bit1 flag
// mmio_flag_check_40500000 [mmio]: Read MMIO word at 0x40500000 and test bit1 flag
int __fastcall mmio_flag_check_40500000(int a1, int a2, int a3)
{
  unsigned __int8 *(_DWORD *)(v4 + 0x20); // [sp+4h] [bp-8h] BYREF

  if ( (*(_DWORD *)off_126054 & 0x2000000) != 0 )
  {
    msg_parse(dword_126060, dword_12605C, a3, HIBYTE(*(_DWORD *)off_126054) & 2);
    return 0;
  }
  else
  {
    *(_WORD *)v4 = 0;
    sub_114868((int)v4);
    if ( *(_DWORD *)(v4 + 0x0) == 255 || *(_DWORD *)(v4 + 0x4) == 255 )
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

