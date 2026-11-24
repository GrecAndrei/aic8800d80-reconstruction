// sub_124F60 @ 0x124f60, size 50 bytes
int __fastcall sub_124F60(int a1, int a2)
{
  int v2; // r4

  if ( a1 <= 1 )
  {
    msg_parse(dword_124F98);
    return 1;
  }
  else
  {
    v2 = (unsigned __int8)parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
    sub_123F64(v2);
    if ( v2 )
      msg_parse(dword_124F94);
    return 0;
  }
}

