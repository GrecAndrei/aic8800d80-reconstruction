// sub_1133B4 @ 0x1133b4, size 172 bytes
int  sub_1133B4(int a1, int a2, int a3)
{
  unsigned __int8 *v3; // r5
  char v4; // r3
  uint8_t *v5; // r4
  int v6; // r3
  int v7; // r5
  int v8; // r7
  int v9; // r6
  int v10; // r8
  int v11; // r3
  int v13; // r4

  v3 = (unsigned __int8 *)off_113460;
  if ( a3 )
    v4 = 3;
  else
    v4 = 2;
  *(uint8_t *)off_113460 = v4;
  if ( *v3 == 2 )
  {
    v5 = off_113464;
    v6 = *(unsigned __int8 *)off_113464;
    *v3 = 0;
    if ( v6 )
    {
      v7 = dword_113468;
      v8 = dword_11346C;
      v9 = dword_113468 - 8;
      do
      {
        while ( 1 )
        {
          v10 = *(uint32_t *)(*(uint32_t *)(sub_12D4F8(v7) + 4) + 4);
          --*v5;
          sub_12D470(v9);
          v11 = *(unsigned __int8 *)(v10 + 2) >> 4;
          if ( v11 )
            break;
          ++*(uint16_t *)off_113470;
          a1 = sub_12D32C(128);
          if ( !*v5 )
            goto LABEL_12;
        }
        if ( v11 == 1 )
        {
          a1 = sub_10FE60((uint32_t *)v10);
        }
        else
        {
          sub_10DA7C(v8);
          a1 = sub_12ED40(v10, 32, 1, 0);
        }
      }
      while ( *v5 );
    }
LABEL_12:
    sub_113310(a1, a2);
    return 1;
  }
  else
  {
    v13 = a1;
    sub_10DA7C(dword_113474, *v3);
    sub_114024(dword_113478, v13, a2, *v3);
    return 1;
  }
}

