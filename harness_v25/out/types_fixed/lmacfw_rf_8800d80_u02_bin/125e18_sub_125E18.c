// sub_125E18 @ 0x125e18, size 178 bytes
int __fastcall sub_125E18(int a1, int a2)
{
  unsigned __int8 *v3; // r1
  unsigned __int8 *v5; // r1
  int v6; // r0
  int v7; // r0
  int v8; // [sp+4h] [bp-4h]

  if ( a1 <= 1 )
  {
    sub_11F504(dword_125EE8);
    return -1;
  }
  else
  {
    if ( sub_1288C0(*(_DWORD *)(a2 + 4)) == 1 || sub_1288C0(*(_DWORD *)(a2 + 4)) == 2 )
    {
      if ( sub_1288C0(*(_DWORD *)(a2 + 4)) == 1 )
      {
        v3 = *(unsigned __int8 **)(a2 + 4);
        if ( !v3 || !sub_1247A4((unsigned __int8 **)dword_125ECC, v3) )
        {
LABEL_7:
          sub_11F504(dword_125ED0);
          return 0;
        }
      }
      else
      {
        if ( sub_1288C0(*(_DWORD *)(a2 + 4)) != 2 )
          return 0;
        v5 = *(unsigned __int8 **)(a2 + 4);
        if ( !v5 || !sub_1247A4((unsigned __int8 **)dword_125ED4, v5) )
          goto LABEL_7;
      }
      sub_11F504(dword_125ED8);
      v8 = *(_DWORD *)(a2 + 4);
      v6 = sub_1288C0(v8);
      sub_1282E8(dword_125EDC, v8, v6);
      sub_11F504(dword_125EE0, dword_125EDC);
      if ( (*(_DWORD *)off_125EE4 & 0x2000000) == 0 )
        sub_114844(dword_125EDC);
      return 0;
    }
    v7 = sub_1288C0(*(_DWORD *)(a2 + 4));
    sub_11F504(dword_125EEC, v7);
    return -1;
  }
}

