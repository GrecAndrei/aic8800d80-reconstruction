// fwstruct annotate: 1250d4_sub_1250D4.c
// sub_1250D4 @ 0x1250d4, size 42 bytes
int __fastcall sub_1250D4(int a1, int a2)
{
  unsigned __int8 v2; // r0

  if ( a1 <= 1 )
  {
    msg_parse(dword_125104);
    return 1;
  }
  else
  {
    v2 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
    sub_123FDC(v2);
    msg_parse(dword_125100);
    return 0;
  }
}

