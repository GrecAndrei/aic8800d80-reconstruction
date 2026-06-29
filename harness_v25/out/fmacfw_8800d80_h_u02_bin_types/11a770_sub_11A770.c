// sub_11A770 @ 0x11a770, size 68 bytes
int  sub_11A770(int result, int a2)
{
  int v2; // r3
  int v3; // r2
  int v4; // r3
  unsigned int v5; // r3

  v2 = *(uint32_t *)(result + 60);
  if ( v2 < 0 )
  {
    v3 = *(uint32_t *)(result + 36);
    if ( **(__int16 **)off_11A7B4 < 0 && (v4 = v2 << 15, v4 >= 0) )
    {
      return sub_12F2C8(dword_11A7BC, dword_11A7B8, 3371, v4);
    }
    else
    {
      v5 = *(uint32_t *)(v3 + 20) & 0xFFFE3FFF | 0x4000;
      *(uint32_t *)(result + 60) = 0;
      *(uint32_t *)(v3 + 20) = v5;
      return sub_116574(result, a2, v3, v5);
    }
  }
  return result;
}

