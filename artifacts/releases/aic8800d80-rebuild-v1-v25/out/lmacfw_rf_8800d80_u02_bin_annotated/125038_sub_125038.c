// fwstruct annotate: 125038_sub_125038.c
// sub_125038 @ 0x125038, size 42 bytes
int __fastcall sub_125038(int a1, int a2)
{
  unsigned __int8 v2; // r0

  if ( a1 <= 1 )
  {
    msg_parse(dword_125068);
    return 1;
  }
  else
  {
    v2 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
    sub_123F8C(v2);
    msg_parse(dword_125064);
    return 0;
  }
}

