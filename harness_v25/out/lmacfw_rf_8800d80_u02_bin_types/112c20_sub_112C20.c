// sub_112C20 @ 0x112c20, size 130 bytes
int  sub_112C20(int a1, unsigned int a2)
{
  uint8_t *v2; // r4
  uint8_t *v3; // r6
  uint32_t *v4; // r7
  int v5; // r0
  int v6; // r2

  v2 = off_112CA4;
  if ( *(uint8_t *)off_112CA4 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = off_112CA8;
  if ( *(uint8_t *)off_112CA8 )
  {
    sub_10DA6C(dword_112CB8, dword_112CB4, *(unsigned __int8 *)off_112CA8);
    return -3;
  }
  else
  {
    v4 = off_112CAC;
    *(uint8_t *)off_112CA8 = 1;
    v4[716] &= 0xE007FFFF;
    v5 = sub_111950(1, a1, a2);
    v6 = v5;
    if ( v5 )
    {
      sub_10DA6C(dword_112CBC, dword_112CB4, v5);
      return -1;
    }
    else
    {
      *(uint8_t *)off_112CB0 = 1;
      if ( *v2 )
      {
        sub_1116BC(nullptr, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v6;
}

