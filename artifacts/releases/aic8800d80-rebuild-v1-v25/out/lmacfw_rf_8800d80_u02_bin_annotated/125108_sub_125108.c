// fwstruct annotate: 125108_sub_125108.c
// sub_125108 @ 0x125108, size 42 bytes
int __fastcall sub_125108(int a1, int a2)
{
  unsigned __int8 v2; // r0

  if ( a1 <= 1 )
  {
    msg_parse(dword_125138);
    return 1;
  }
  else
  {
    v2 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
    sub_123FB4(v2);
    msg_parse(dword_125134);
    return 0;
  }
}

