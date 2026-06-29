// sub_12E1D8 @ 0x12e1d8, size 30 bytes
int  sub_12E1D8(int a1, __int16 a2)
{
  return dword_12E1F8
       & ((((32 * (*(unsigned __int8 *)(a1 + 5) ^ (*(unsigned __int8 *)(a1 + 5) >> 4))) & 0x1E0) + (a2 & 0x1FF)) << 22)
       | 0x3F0000;
}

