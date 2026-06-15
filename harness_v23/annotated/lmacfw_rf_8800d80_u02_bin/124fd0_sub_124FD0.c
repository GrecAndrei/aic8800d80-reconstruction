// v23 annotated: sub_124FD0 @ 0x124fd0
// Original: 124fd0_sub_124FD0.c
// Primary struct: <unclustered>
//
// sub_124FD0 @ 0x124fd0, size 42 bytes
int __fastcall sub_124FD0(int a1, int a2)
{
  unsigned __int8 v2; // r0

  if ( a1 <= 1 )
  {
    msg_parse(dword_125000);
    return 1;
  }
  else
  {
    v2 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0xAu);
    mmio_field_set_l2h2(v2);
    msg_parse(dword_124FFC);
    return 0;
  }
}

