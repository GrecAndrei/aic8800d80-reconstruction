// sub_113B5C @ 0x113b5c, size 26 bytes
unsigned int  sub_113B5C(int a1)
{
  host_reg_wait_set(1u, (a1 << 13) & 0x1E000);
  return ((unsigned int)sub_113A44(1u) >> 13) & 0xF;
}

