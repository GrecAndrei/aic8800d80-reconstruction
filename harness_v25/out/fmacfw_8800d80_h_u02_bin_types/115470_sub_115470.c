// sub_115470 @ 0x115470, size 118 bytes
int  sub_115470(int a1, int a2)
{
  uint32_t *v2; // r4
  int v3; // r3
  int v4; // r2
  int v5; // r3
  int v6; // r5
  int i; // r2
  int result; // r0
  int v9; // r0
  void *v10; // r2

  v2 = off_1154E8;
  v3 = *((uint32_t *)off_1154E8 + 65);
  v4 = v3 << 27;
  if ( (v3 & 0x10) == 0 )
    goto LABEL_6;
  v5 = *(uint32_t *)off_1154EC;
  if ( (dword_1154F0 & *(uint32_t *)off_1154EC) == 0 )
  {
    v6 = dword_1154F4 & v5;
    if ( (v5 & 0x40000000) != 0 )
    {
      v9 = sub_11446C(0);
      v10 = off_1154FC;
      *(uint32_t *)off_1154FC = 0x40000000;
      v2[97] = 16;
      if ( v6 < 0 )
        sub_11441C(v9, 0x40000000, (int)v10);
      goto LABEL_6;
    }
    if ( v6 < 0 )
    {
      sub_11441C(0, a2, v4);
      if ( !*((uint8_t *)off_1154F8 + 3) )
      {
LABEL_6:
        for ( i = 0; ; ++i )
        {
          result = *(uint32_t *)(4 * i - 536813056) & *(uint32_t *)(4 * i - 536813312);
          if ( i == 1 )
          {
            if ( (result & 0xFFFFFFEF) != 0 )
              return 1;
          }
          else
          {
            if ( result )
              return 1;
            if ( i == 2 )
              return result;
          }
        }
      }
    }
  }
  return 1;
}

