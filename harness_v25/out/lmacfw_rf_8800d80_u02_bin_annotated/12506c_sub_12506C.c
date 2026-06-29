// fwstruct annotate: 12506c_sub_12506C.c
// sub_12506C @ 0x12506c, size 42 bytes
int __fastcall sub_12506C(int a1, int a2)
{
  unsigned __int8 v2; // r0

  if ( a1 <= 1 )
  {
    msg_parse(dword_12509C);
    return 1;
  }
  else
  {
    v2 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
    sub_123FC8(v2);
    msg_parse(dword_125098);
    return 0;
  }
}

