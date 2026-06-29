// sub_12537C @ 0x12537c, size 50 bytes
int  sub_12537C(int a1, int a2)
{
  BOOL v2; // r1
  int v3; // r0

  if ( a1 <= 1 )
  {
    msg_parse(dword_1253B8, *(uint32_t *)off_1253B0);
  }
  else
  {
    v2 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0) != 0;
    v3 = dword_1253B4;
    *(uint32_t *)off_1253B0 = v2;
    msg_parse(v3);
  }
  return 0;
}

