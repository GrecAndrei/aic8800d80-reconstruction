// sub_10DB64 @ 0x10db64, size 42 bytes
int  sub_10DB64(int result)
{
  uint32_t *v1; // r1

  if ( result <= 7 )
  {
    v1 = off_10DB90;
    dword_40504080[result] &= 0xFFFFFFF0;
    result = (1 << result) | v1[1];
    v1[1] = result;
  }
  return result;
}

