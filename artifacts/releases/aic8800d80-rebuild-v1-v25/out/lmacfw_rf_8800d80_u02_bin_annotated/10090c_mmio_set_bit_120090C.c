// fwstruct annotate: 10090c_mmio_set_bit_120090C.c
// mmio_set_bit_120090C @ 0x10090c, size 52 bytes
// Doc: mmio_set_bit_120090C [mmio]: Set MMIO bit in control register
// mmio_set_bit_120090C [mmio]: Set MMIO bit in control register
int __fastcall mmio_set_bit_120090C(int a1, unsigned int a2)
{
  unsigned int *v2; // r5
  int v3; // r0
  unsigned int v4; // r4
  int result; // r0
  unsigned int v6; // [sp+4h] [bp-8h] BYREF

  v2 = (unsigned int *)off_100940;
  v3 = sub_1007B4(a1, a2, &v6);
  v4 = *v2;
  *v2 |= 0x4000000u;
  result = sub_1006C0(v3, dword_100944, 96, v6);
  *v2 = v4 & 0xFBFFFFFF;
  return result;
}

