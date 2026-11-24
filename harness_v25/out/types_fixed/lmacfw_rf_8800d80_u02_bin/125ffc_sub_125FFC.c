// sub_125FFC @ 0x125ffc, size 88 bytes
int __fastcall sub_125FFC(int a1, int a2, int a3)
{
  unsigned __int8 *(_DWORD *)(v4 + 0x20); // [sp+4h] [bp-8h] BYREF

  if ( (*(_DWORD *)off_126054 & 0x2000000) != 0 )
  {
    sub_11F504(dword_126060, dword_12605C, a3, HIBYTE(*(_DWORD *)off_126054) & 2);
    return 0;
  }
  else
  {
    *(_WORD *)v4 = 0;
    sub_114868((int)v4);
    if ( *(_DWORD *)(v4 + 0x0) == 255 || *(_DWORD *)(v4 + 0x4) == 255 )
    {
      sub_11F504(dword_126058);
      return 0;
    }
    else
    {
      sub_11F504(dword_126060, v4);
      return 0;
    }
  }
}

