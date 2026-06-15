// v23 annotated: sub_1248A4 @ 0x1248a4
// Original: 1248a4_sub_1248A4.c
// Primary struct: mmio_clock_gate (cluster 1, 25 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// sub_1248A4 @ 0x1248a4, size 50 bytes
int sub_1248A4()
{
  _BYTE *v0; // r4
  int *v1; // r3
  int v2; // r2

  if ( !*(_BYTE *)off_1248D8 )
    *(_BYTE *)off_1248D8 = 1;
  v0 = off_1248DC;
  if ( *(_BYTE *)off_1248DC )
  {
    msg_parse(dword_1248EC);
    return 0;
  }
  else
  {
    timer_set_relative(144, *(unsigned __int8 *)off_1248DC, dword_1248E0);
    v1 = (int *)off_1248E4;
    v2 = dword_1248E8;
    *v0 = 1;
    *v1 = v2;
    return 0;
  }
}

