// sub_124A50 @ 0x124a50, size 46 bytes
int  sub_124A50(int a1, int a2)
{
  int v2; // r4

  if ( a1 <= 1 )
  {
    msg_parse(dword_124A84);
    return 1;
  }
  else
  {
    v2 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
    sub_123F4C((unsigned __int16)v2);
    msg_parse(dword_124A80, v2);
    return 0;
  }
}

