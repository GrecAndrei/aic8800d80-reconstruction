// fwstruct annotate: 126f28_sub_126F28.c
// sub_126F28 @ 0x126f28, size 250 bytes
int __fastcall sub_126F28(int a1)
{
  _DWORD *v1; // r6
  int *v2; // r4
  int v3; // r7
  int v4; // r5
  _DWORD *v5; // r2
  _BYTE *v6; // r1
  int v7; // r8
  int v8; // r7
  _BYTE *v9; // r10
  int v10; // r9
  int v11; // r0
  char v12; // r11
  int v13; // r4
  int v14; // r5
  int v15; // r4

  v1 = off_127028;
  v2 = *((int **)off_127024 + 2);
  v3 = *((unsigned __int8 *)off_127028 + 89);
  nullsub_8(a1);
  v4 = v1[10];
  if ( !v4 )
    return 0;
  v5 = off_12702C;
  v6 = off_127030;
  *(_DWORD *)off_12702C |= 4u;
  v7 = v3;
  if ( v6[2] )
    v5[250] |= 0x80000000;
  if ( v2 )
  {
    v8 = dword_127034;
    v9 = off_127038;
    v10 = dword_12703C;
    do
    {
      while ( 1 )
      {
        if ( v4 == v2[18] && !*((_BYTE *)v2 + 106) )
        {
          if ( *((_BYTE *)v2 + 108) )
          {
            v11 = *((unsigned __int8 *)v2 + 116);
            if ( v11 != 255 && (!*((_BYTE *)v2 + 1224) || *(_BYTE *)(v10 + 140 * *((unsigned __int8 *)v2 + 1225) + 133)) )
              break;
          }
        }
        v2 = (int *)*v2;
        if ( !v2 )
          goto LABEL_16;
      }
      v12 = *(_BYTE *)(v4 + 16);
      *(_BYTE *)(v4 + 16) = 6;
      if ( !sub_1194CC(v11, v8, 0) )
      {
        ++v7;
        *v9 = 1;
      }
      *(_BYTE *)(v4 + 16) = v12;
      v2 = (int *)*v2;
    }
    while ( v2 );
LABEL_16:
    LOBYTE(v3) = v7;
  }
  v13 = *((unsigned __int8 *)v1 + 89);
  v14 = v1[11];
  *((_BYTE *)v1 + 89) = v3;
  v15 = v7 - v13;
  if ( !v14 )
  {
    rf_misc_init_n_xxx();
    if ( v7 )
    {
      v15 = 0;
      --*((_BYTE *)v1 + 89);
      return v15;
    }
    return 0;
  }
  if ( !v15 )
    return v15;
  *(_BYTE *)(v14 + 16) = 3;
  rf_misc_init_n_xxx();
  return v15;
}

