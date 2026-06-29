// fwstruct annotate: 124e34_sub_124E34.c
// sub_124E34 @ 0x124e34, size 38 bytes
int __fastcall sub_124E34(int a1, int a2)
{
  unsigned __int8 v2; // r0

  if ( a1 <= 1 )
  {
    msg_parse(dword_124E5C);
    return -1;
  }
  else
  {
    v2 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
    sub_102E48(v2);
    return 0;
  }
}

