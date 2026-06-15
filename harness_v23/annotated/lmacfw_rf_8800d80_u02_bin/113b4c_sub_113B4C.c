// v23 annotated: sub_113B4C @ 0x113b4c
// Original: 113b4c_sub_113B4C.c
// Primary struct: <unclustered>
//
// sub_113B4C @ 0x113b4c, size 14 bytes
// Doc: sub_1213B4C [util]: Calls helper and returns a 4-bit field extracted at bit 13 (ubfx r0,r0,0xd,4)
// sub_1213B4C [util]: Calls helper and returns a 4-bit field extracted at bit 13 (ubfx r0,r0,0xd,4)
unsigned int sub_113B4C()
{
  return ((unsigned int)sub_113A44(1u) >> 13) & 0xF;
}

