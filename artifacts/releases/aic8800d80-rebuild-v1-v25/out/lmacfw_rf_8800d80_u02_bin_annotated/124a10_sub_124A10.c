// fwstruct annotate: 124a10_sub_124A10.c
// sub_124A10 @ 0x124a10, size 52 bytes
int __fastcall sub_124A10(int a1, int a2)
{
  int v2; // r3

  if ( a1 <= 1 )
  {
    msg_parse(dword_124A48);
    return 1;
  }
  else
  {
    v2 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
    if ( (unsigned int)(v2 - 1) <= 0x30 )
    {
      msg_parse(dword_124A4C);
      return 1;
    }
    else
    {
      *(_DWORD *)off_124A44 = v2;
      return 0;
    }
  }
}

