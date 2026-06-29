// sub_1250A0 @ 0x1250a0, size 42 bytes
int  sub_1250A0(int a1, int a2)
{
  unsigned __int8 v2; // r0

  if ( a1 <= 1 )
  {
    msg_parse(dword_1250D0);
    return 1;
  }
  else
  {
    v2 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
    sub_123FA0(v2);
    msg_parse(dword_1250CC);
    return 0;
  }
}

