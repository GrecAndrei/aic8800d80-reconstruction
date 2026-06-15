// v23 annotated: sub_13013C @ 0x13013c
// Original: 13013c_sub_13013C.c
// Primary struct: <unclustered>
//
// sub_13013C @ 0x13013c, size 110 bytes
int __fastcall sub_13013C(int a1, int a2)
{
  unsigned int v4; // r0
  int v5; // r7
  unsigned int v6; // r6
  _DWORD *v7; // r4
  int v8; // r0

  if ( a1 == 1 )
  {
    rf_level_dump_05bc();
    return 0;
  }
  else
  {
    v4 = sub_12FB74(*(unsigned __int8 **)(a2 + 4), nullptr, 0);
    v5 = v4;
    if ( v4 )
      v5 = 1;
    v6 = v4;
    if ( a1 > 2 )
    {
      v7 = off_1301AC;
      v4 = sub_12FB74(*(unsigned __int8 **)(a2 + 8), nullptr, 0);
      if ( v4 > 0x7D0 )
        v7[91] = v4;
    }
    else
    {
      v7 = off_1301AC;
    }
    if ( *((unsigned __int8 *)v7 + 363) != v5 )
    {
      *((_BYTE *)v7 + 363) = v5;
      if ( v6 )
      {
        v8 = sub_130714(v4);
        sub_1307D0(v8);
      }
      else
      {
        bt_fmac_init_n_42e();
      }
    }
    sub_12ECB0(dword_1301B0, v5, v7[91]);
    return 0;
  }
}

