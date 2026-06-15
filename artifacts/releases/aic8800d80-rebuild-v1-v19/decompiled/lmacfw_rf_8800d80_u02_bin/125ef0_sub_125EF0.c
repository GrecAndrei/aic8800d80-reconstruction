// sub_125EF0 @ 0x125ef0, size 88 bytes
int __fastcall sub_125EF0(int a1, int a2, int a3)
{
  unsigned __int8 v4[8]; // [sp+4h] [bp-8h] BYREF

  if ( (*(_DWORD *)off_125F48 & 0x2000000) != 0 )
  {
    sub_11F504(dword_125F54, dword_125F50, a3, HIBYTE(*(_DWORD *)off_125F48) & 2);
    return 0;
  }
  else
  {
    *(_WORD *)v4 = 0;
    sub_114838((int)v4);
    if ( v4[0] == 255 || v4[1] == 255 )
    {
      sub_11F504(dword_125F4C);
      return 0;
    }
    else
    {
      sub_11F504(dword_125F54, v4);
      return 0;
    }
  }
}

