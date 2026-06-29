// sub_113210 @ 0x113210, size 130 bytes
int  sub_113210(int a1, unsigned int a2)
{
  uint8_t *v2; // r4
  uint8_t *v3; // r6
  uint32_t *v4; // r7
  int v5; // r0
  int v6; // r2

  v2 = off_113294;
  if ( *(uint8_t *)off_113294 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = off_113298;
  if ( *(uint8_t *)off_113298 )
  {
    sub_10DAE4(dword_1132A8, dword_1132A4, *(unsigned __int8 *)off_113298);
    return -3;
  }
  else
  {
    v4 = off_11329C;
    *(uint8_t *)off_113298 = 1;
    v4[716] &= 0xE007FFFF;
    v5 = sub_111F08(1, a1, a2);
    v6 = v5;
    if ( v5 )
    {
      sub_10DAE4(dword_1132AC, dword_1132A4, v5);
      return -1;
    }
    else
    {
      *(uint8_t *)off_1132A0 = 1;
      if ( *v2 )
      {
        sub_111C74(nullptr, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v6;
}

