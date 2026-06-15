// sub_125F58 @ 0x125f58, size 130 bytes
int __fastcall sub_125F58(int a1, int a2)
{
  unsigned __int8 *v3; // r1
  int v5; // r0
  int v6; // [sp+4h] [bp-4h]

  if ( a1 <= 1 )
  {
    sub_11F504(dword_125FF8);
    return -1;
  }
  else if ( sub_1288C0(*(_DWORD *)(a2 + 4)) == 2 )
  {
    v3 = *(unsigned __int8 **)(a2 + 4);
    if ( v3 && sub_1247A4((unsigned __int8 **)dword_125FDC, v3) )
    {
      sub_11F504(dword_125FE4);
      v6 = *(_DWORD *)(a2 + 4);
      v5 = sub_1288C0(v6);
      sub_1282E8(dword_125FE8, v6, v5);
      sub_11F504(dword_125FEC, dword_125FE8);
      if ( (*(_DWORD *)off_125FF0 & 0x2000000) == 0 )
        sub_114874(dword_125FE8);
      return 0;
    }
    else
    {
      sub_11F504(dword_125FE0);
      return 0;
    }
  }
  else
  {
    sub_11F504(dword_125FF4);
    return -1;
  }
}

