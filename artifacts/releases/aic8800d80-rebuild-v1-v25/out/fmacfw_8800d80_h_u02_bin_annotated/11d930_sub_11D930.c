// fwstruct annotate: 11d930_sub_11D930.c
// sub_11D930 @ 0x11d930, size 356 bytes
int __fastcall sub_11D930(int a1)
{
  _DWORD *v1; // r7
  _BYTE *v2; // r9
  int v3; // r8
  int v4; // r6
  int i; // r5
  int v6; // r3
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r2
  int v12; // r3
  int v13; // r4
  int result; // r0
  int v15; // r1
  int v16; // r2
  void (__fastcall *v17)(_DWORD); // r2
  void *v18; // r3
  _DWORD *v19; // r5
  int v20; // [sp+14h] [bp-8h]

  v1 = off_11DA94;
  v2 = off_11DAB4;
  v3 = dword_11DAC0;
  v4 = a1;
  for ( i = 0; ; ++i )
  {
    v13 = sub_11E9B8(a1);
    *v1 = 0x10000;
    result = sub_12D00C(0x80000);
    if ( !v13 )
      break;
    if ( !v4 )
    {
      v6 = (unsigned __int8)v2[192];
      if ( v2[192] )
      {
        v6 = *(_DWORD *)off_11DA98;
        if ( *(_DWORD *)off_11DA98 > 0x80000u || i > 31 )
          return sub_12CFC4(0x80000);
      }
      else if ( i > 3 )
      {
        return sub_12CFC4(0x80000);
      }
    }
    v7 = sub_12F3F8(result, v15, v16, v6);
    if ( !v7 || (v7 = sub_13A3C4(v7, v8, v9, v10)) == 0 )
    {
      v18 = off_11DAAC;
      *((_BYTE *)off_11DAAC + 69) = 1;
      sub_13A3C4(v7, v8, 1, v18);
      return sub_12EB90(1024, dword_11DAB0);
    }
    v11 = *(_DWORD *)(v13 + 20);
    if ( v11 != v3 )
      sub_12E948(dword_11DAA0, v13, v11);
    sub_11E9F4(v13);
    a1 = sub_11D1E0(v13);
    if ( a1 )
    {
      if ( a1 != 1 )
        goto LABEL_10;
    }
    else
    {
      a1 = sub_139E1C(v13);
      if ( a1 )
        goto LABEL_10;
    }
    a1 = sub_11E960(v13);
LABEL_10:
    v12 = **(unsigned __int8 **)off_11DAA4;
    switch ( v12 )
    {
      case 2:
        goto LABEL_22;
      case 4:
        if ( !*(_DWORD *)off_11DAA8 || *(_DWORD *)(*(_DWORD *)off_11DAA8 + 12) != v13 || (*(_BYTE *)(v13 + 16) & 1) == 0 )
        {
LABEL_22:
          a1 = sub_11D864();
          continue;
        }
        v20 = *(_DWORD *)off_11DAA8;
        sub_12D190(off_11DAA8);
        v17 = *(void (__fastcall **)(_DWORD))(v20 + 4);
        *(_BYTE *)(v20 + 16) = 0;
        if ( v17 )
          v17(*(_DWORD *)(v20 + 8));
        a1 = sub_11DF74(v13);
        break;
      case 3:
        a1 = sub_11D7AC();
        break;
    }
  }
  if ( *((_BYTE *)off_11DAB4 + 192) )
  {
    v19 = off_11DAB8;
    if ( *((_BYTE *)off_11DAB8 + 33) )
    {
      result = sub_110EDC(*((_DWORD *)off_11DAB8 + 4), *((_DWORD *)off_11DAB8 + 5), *((_DWORD *)off_11DAB8 + 6));
      v19[5] = 0;
      v19[7] = 0;
      v19[4] = 0;
      v19[6] = 0;
      *((_BYTE *)v19 + 33) = 0;
    }
  }
  *(_DWORD *)off_11DABC |= 0x10000u;
  return result;
}

