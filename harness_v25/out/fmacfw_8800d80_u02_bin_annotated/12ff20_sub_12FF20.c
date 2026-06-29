// fwstruct annotate: 12ff20_sub_12FF20.c
// sub_12FF20 @ 0x12ff20, size 110 bytes
int __fastcall sub_12FF20(int a1, int a2)
{
  unsigned int v4; // r0
  int v5; // r7
  unsigned int v6; // r6
  _DWORD *v7; // r4
  int inited; // r0

  if ( a1 == 1 )
  {
    sub_1303A0();
    return 0;
  }
  else
  {
    v4 = sub_12F958(*(unsigned __int8 **)(a2 + 4), nullptr, 0);
    v5 = v4;
    if ( v4 )
      v5 = 1;
    v6 = v4;
    if ( a1 > 2 )
    {
      v7 = off_12FF90;
      v4 = sub_12F958(*(unsigned __int8 **)(a2 + 8), nullptr, 0);
      if ( v4 > 0x7D0 )
        v7[91] = v4;
    }
    else
    {
      v7 = off_12FF90;
    }
    if ( *((unsigned __int8 *)v7 + 363) != v5 )
    {
      *((_BYTE *)v7 + 363) = v5;
      if ( v6 )
      {
        inited = fmac_init_state_load(v4);
        fmac_subhandler_n_05b4(inited);
      }
      else
      {
        fmac_post_init_n_42e();
      }
    }
    msg_parse(dword_12FF94, v5, v7[91]);
    return 0;
  }
}

