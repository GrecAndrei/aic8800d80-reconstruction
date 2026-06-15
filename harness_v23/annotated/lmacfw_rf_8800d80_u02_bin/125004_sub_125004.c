// v23 annotated: sub_125004 @ 0x125004
// Original: 125004_sub_125004.c
// Primary struct: <unclustered>
//
// sub_125004 @ 0x125004, size 42 bytes
int __fastcall sub_125004(int a1, int a2)
{
  unsigned __int8 v2; // r0

  if ( a1 <= 1 )
  {
    msg_parse(dword_125034);
    return 1;
  }
  else
  {
    v2 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
    sub_123F78(v2);
    msg_parse(dword_125030);
    return 0;
  }
}

