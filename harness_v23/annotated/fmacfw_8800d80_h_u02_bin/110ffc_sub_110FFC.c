// v23 annotated: sub_110FFC @ 0x110ffc
// Original: 110ffc_sub_110FFC.c
// Primary struct: mmio_clock_gate (cluster 1, 26 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// sub_110FFC @ 0x110ffc, size 28 bytes
_DWORD *__fastcall sub_110FFC(_DWORD *result, int a2, int a3, unsigned __int16 a4, int a5)
{
  result[2] = dword_111018 & result[2] | a4 | (a5 << 31);
  *result = a2;
  result[1] = a3;
  return result;
}

