// sub_124F9C @ 0x124f9c, size 42 bytes
int __fastcall sub_124F9C(int a1, int a2)
{
  unsigned __int8 v2; // r0

  if ( a1 <= 1 )
  {
    msg_parse(dword_124FCC);
    return 1;
  }
  else
  {
    v2 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
    rf_pll_config_patch_n_8c(v2);
    msg_parse(dword_124FC8);
    return 0;
  }
}

