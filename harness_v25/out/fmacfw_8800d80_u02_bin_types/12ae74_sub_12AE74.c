// sub_12AE74 @ 0x12ae74, size 128 bytes
// Doc: sub_122AE74 [unknown]: Unknown helper, compares value against 0x1f
// sub_122AE74 [unknown]: Unknown helper, compares value against 0x1f
int  sub_12AE74(int a1, unsigned int a2, int a3)
{
  int result; // r0
  int v4; // r1
  unsigned int v5; // r3
  int v6; // r1
  unsigned int v7; // r2
  int v8; // r2

  if ( a2 <= 0x1F )
  {
    if ( a3 )
    {
      result = dword_12AEF4 + 32 * a1;
      v4 = 3 * a2 + dword_12AEF8;
      v5 = *(unsigned __int8 *)(v4 + 2);
      ++*(uint32_t *)(result + 20);
      if ( v5 <= 2 )
        *(uint8_t *)(v4 + 2) = v5 + 1;
    }
    else
    {
      result = dword_12AEF4 + 32 * a1;
      v6 = 3 * a2 + dword_12AEF8;
      v7 = *(unsigned __int8 *)(v6 + 1);
      ++*(uint32_t *)(result + 16);
      if ( v7 <= 2 )
        *(uint8_t *)(v6 + 1) = v7 + 1;
    }
  }
  else
  {
    if ( a3 )
    {
      v8 = **(__int16 **)off_12AEFC;
      ++*(uint32_t *)(dword_12AEF4 + 32 * a1 + 20);
      if ( v8 < 0 )
        sub_12F46C(dword_12AF04, dword_12AF00, 365);
      __und(0xFFu);
    }
    result = dword_12AEF4 + 32 * a1;
    ++*(uint32_t *)(result + 16);
  }
  return result;
}

