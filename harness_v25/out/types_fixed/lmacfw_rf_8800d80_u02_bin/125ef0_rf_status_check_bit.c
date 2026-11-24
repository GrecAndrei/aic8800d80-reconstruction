// rf_status_check_bit @ 0x125ef0, size 88 bytes
// Doc: rf_status_check_bit [rf]: Check RF status register bit 0x02000000
// rf_status_check_bit [rf]: Check RF status register bit 0x02000000
int __fastcall rf_status_check_bit(int a1, int a2, int a3)
{
  unsigned __int8 *(_DWORD *)(v4 + 0x20); // [sp+4h] [bp-8h] BYREF

  if ( (*(_DWORD *)off_125F48 & 0x2000000) != 0 )
  {
    msg_parse(dword_125F54, dword_125F50, a3, HIBYTE(*(_DWORD *)off_125F48) & 2);
    return 0;
  }
  else
  {
    *(_WORD *)v4 = 0;
    sub_114838((int)v4);
    if ( *(_DWORD *)(v4 + 0x0) == 255 || *(_DWORD *)(v4 + 0x4) == 255 )
    {
      msg_parse(dword_125F4C);
      return 0;
    }
    else
    {
      msg_parse(dword_125F54, v4);
      return 0;
    }
  }
}

