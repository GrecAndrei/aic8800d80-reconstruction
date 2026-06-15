// v23 annotated: sub_1155B0 @ 0x1155b0
// Original: 1155b0_sub_1155B0.c
// Primary struct: <unclustered>
//
// sub_1155B0 @ 0x1155b0, size 118 bytes
int __fastcall sub_1155B0(int a1, int a2)
{
  _DWORD *v2; // r4
  int v3; // r3
  int v4; // r2
  int v5; // r3
  int v6; // r5
  int i; // r2
  int result; // r0
  int v9; // r0
  void *v10; // r2

  v2 = off_115628;
  v3 = *((_DWORD *)off_115628 + 65);
  v4 = v3 << 27;
  if ( (v3 & 0x10) == 0 )
    goto LABEL_6;
  v5 = *(_DWORD *)off_11562C;
  if ( (dword_115630 & *(_DWORD *)off_11562C) == 0 )
  {
    v6 = dword_115634 & v5;
    if ( (v5 & 0x40000000) != 0 )
    {
      v9 = sub_1145AC(0);
      v10 = off_11563C;
      *(_DWORD *)off_11563C = 0x40000000;
      v2[97] = 16;
      if ( v6 < 0 )
        sub_11455C(v9, 0x40000000, (int)v10);
      goto LABEL_6;
    }
    if ( v6 < 0 )
    {
      sub_11455C(0, a2, v4);
      if ( !*((_BYTE *)off_115638 + 3) )
      {
LABEL_6:
        for ( i = 0; ; ++i )
        {
          result = *(_DWORD *)(4 * i - 536813056) & *(_DWORD *)(4 * i - 536813312);
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

