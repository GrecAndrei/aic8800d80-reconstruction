// rf_lmac_dispatch_n5a8 @ 0x125f58, size 130 bytes
// Doc: rf_lmac_dispatch_n5a8 [ipc]: Branch on argument value 1, likely LMAC task dispatcher
// rf_lmac_dispatch_n5a8 [ipc]: Branch on argument value 1, likely LMAC task dispatcher
int __fastcall rf_lmac_dispatch_n5a8(int a1, int a2)
{
  unsigned __int8 *v3; // r1
  int v5; // r0
  int v6; // [sp+4h] [bp-4h]

  if ( a1 <= 1 )
  {
    msg_parse(dword_125FF8);
    return -1;
  }
  else if ( sub_1288C0(*(_DWORD *)(a2 + 4)) == 2 )
  {
    v3 = *(unsigned __int8 **)(a2 + 4);
    if ( v3 && rf_state_load((unsigned __int8 **)dword_125FDC, v3) )
    {
      msg_parse(dword_125FE4);
      v6 = *(_DWORD *)(a2 + 4);
      v5 = sub_1288C0(v6);
      sub_1282E8(dword_125FE8, v6, v5);
      msg_parse(dword_125FEC, dword_125FE8);
      if ( (*(_DWORD *)off_125FF0 & 0x2000000) == 0 )
        sub_114874(dword_125FE8);
      return 0;
    }
    else
    {
      msg_parse(dword_125FE0);
      return 0;
    }
  }
  else
  {
    msg_parse(dword_125FF4);
    return -1;
  }
}

