// sub_126BC4 @ 0x126bc4, size 250 bytes
int __fastcall sub_126BC4(int a1)
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

  v1 = off_126CC4;
  v2 = *((int **)off_126CC0 + 2);
  v3 = *((unsigned __int8 *)off_126CC4 + 89);
  nullsub_8(a1);
  v4 = v1[10];
  if ( !v4 )
    return 0;
  v5 = off_126CC8;
  v6 = off_126CCC;
  *(_DWORD *)off_126CC8 |= 4u;
  v7 = v3;
  if ( v6[2] )
    v5[250] |= 0x80000000;
  if ( v2 )
  {
    v8 = dword_126CD0;
    v9 = off_126CD4;
    v10 = dword_126CD8;
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
      if ( !sub_118F4C(v11, v8, 0) )
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
    sub_120FA4();
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
  sub_120FA4();
  return v15;
}

