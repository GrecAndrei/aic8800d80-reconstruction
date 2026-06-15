// v23 annotated: sub_11113C @ 0x11113c
// Original: 11113c_sub_11113C.c
// Primary struct: mmio_clock_gate (cluster 1, 21 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// sub_11113C @ 0x11113c, size 28 bytes
// Doc: sub_121113C [util]: Pack bitfield value from fields (mask OR shift OR shift31)
// sub_121113C [util]: Pack bitfield value from fields (mask OR shift OR shift31)
_DWORD *__fastcall sub_11113C(_DWORD *result, int a2, int a3, unsigned __int16 a4, int a5)
{
  result[2] = dword_111158 & result[2] | a4 | (a5 << 31);
  *result = a2;
  result[1] = a3;
  return result;
}

