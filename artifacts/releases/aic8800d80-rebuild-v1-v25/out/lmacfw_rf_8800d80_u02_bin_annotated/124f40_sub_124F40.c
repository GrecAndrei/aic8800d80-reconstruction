// fwstruct annotate: 124f40_sub_124F40.c
// sub_124F40 @ 0x124f40, size 28 bytes
// Doc: sub_1224F42 [rf]: RF register read wrapper and event post
// sub_1224F42 [rf]: RF register read wrapper and event post
int __fastcall sub_124F40(int a1, int a2)
{
  unsigned __int8 v2; // r0

  v2 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0);
  sub_124150(v2);
  msg_parse(dword_124F5C);
  return 0;
}

