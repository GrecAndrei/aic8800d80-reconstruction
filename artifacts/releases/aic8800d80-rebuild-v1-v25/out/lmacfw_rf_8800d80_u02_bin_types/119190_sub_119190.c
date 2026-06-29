// sub_119190 @ 0x119190, size 36 bytes
int  sub_119190(int result, int a2, int a3)
{
  int v3; // r4

  v3 = result;
  if ( (a2 & 0x800000) != 0 )
  {
    *(uint8_t *)(result + 116) = 0;
  }
  else
  {
    sub_11F74C(1024, dword_1191B4, a3, a2 << 8);
    return sub_119170(v3);
  }
  return result;
}

