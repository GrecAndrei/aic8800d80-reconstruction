// sub_12DFB0 @ 0x12dfb0, size 30 bytes
int  sub_12DFB0(int a1, __int16 a2)
{
  return dword_12DFD0
       & ((((32 * (*(unsigned __int8 *)(a1 + 5) ^ (*(unsigned __int8 *)(a1 + 5) >> 4))) & 0x1E0) + (a2 & 0x1FF)) << 22)
       | 0x3F0000;
}

