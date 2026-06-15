// v23 annotated: sub_113418 @ 0x113418
// Original: 113418_sub_113418.c
// Primary struct: <unclustered>
//
// sub_113418 @ 0x113418, size 172 bytes
int __fastcall sub_113418(int a1, int a2, int a3)
{
  unsigned __int8 *v3; // r5
  char v4; // r3
  _BYTE *v5; // r4
  int v6; // r3
  int v7; // r5
  int v8; // r7
  int v9; // r6
  int v10; // r8
  int v11; // r3
  int v13; // r4

  v3 = (unsigned __int8 *)off_1134C4;
  if ( a3 )
    v4 = 3;
  else
    v4 = 2;
  *(_BYTE *)off_1134C4 = v4;
  if ( *v3 == 2 )
  {
    v5 = off_1134C8;
    v6 = *(unsigned __int8 *)off_1134C8;
    *v3 = 0;
    if ( v6 )
    {
      v7 = dword_1134CC;
      v8 = dword_1134D0;
      v9 = dword_1134CC - 8;
      do
      {
        while ( 1 )
        {
          v10 = *(_DWORD *)(*(_DWORD *)(sub_12D190(v7) + 4) + 4);
          --*v5;
          sub_12D108(v9);
          v11 = *(unsigned __int8 *)(v10 + 2) >> 4;
          if ( v11 )
            break;
          ++*(_WORD *)off_1134D4;
          a1 = sub_12CFC4(128);
          if ( !*v5 )
            goto LABEL_12;
        }
        if ( v11 == 1 )
        {
          a1 = sub_10FEC8((_DWORD *)v10);
        }
        else
        {
          sub_10DAE4(v8);
          a1 = sub_12E9D8(v10, 32, 1, 0);
        }
      }
      while ( *v5 );
    }
LABEL_12:
    sub_113374(a1, a2);
    return 1;
  }
  else
  {
    v13 = a1;
    sub_10DAE4(dword_1134D8, *v3);
    sub_114088(dword_1134DC, v13, a2, *v3);
    return 1;
  }
}

