// v23 annotated: sub_1017C0 @ 0x1017c0
// Original: 1017c0_sub_1017C0.c
// Primary struct: mmio_clock_gate (cluster 1, 25 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// sub_1017C0 @ 0x1017c0, size 404 bytes
void __noreturn sub_1017C0()
{
  if ( **(__int16 **)off_101954 < 0
    && (unsigned __int8)BYTE2(*(_DWORD *)off_1019A8) + 10 * (HIBYTE(*(_DWORD *)off_1019A8) + 2) != 32 )
  {
    sub_1219C4(dword_1019B0, dword_1019AC, 6119);
  }
  sub_1005F4();
}

