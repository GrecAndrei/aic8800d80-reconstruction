// v23 annotated: sub_13E3A0 @ 0x13e3a0
// Original: 13e3a0_sub_13E3A0.c
// Primary struct: <unclustered>
//
// sub_13E3A0 @ 0x13e3a0, size 242 bytes
int __fastcall sub_13E3A0(int a1)
{
  char v1; // r6
  int v2; // r5
  int v3; // r4
  unsigned int v4; // r0
  int v5; // r7
  int v6; // r3
  unsigned int v7; // r2
  unsigned __int16 v8; // r0
  int v9; // r0
  int v10; // r3
  int v12; // r2
  int v13; // r3

  v1 = *(_BYTE *)(a1 + 166);
  v2 = v1 & 0x10;
  v3 = a1;
  if ( (v1 & 0x10) != 0 )
  {
    v4 = *(unsigned __int16 *)(a1 + 184);
    if ( !v4 )
    {
      *(_WORD *)(v3 + 3070) = *(_WORD *)(v3 + 190);
      *(_WORD *)(v3 + 3068) = 0;
      *(_DWORD *)(v3 + 136) = 16711935;
      *(_WORD *)(v3 + 140) = 255;
      goto LABEL_10;
    }
    v5 = *(unsigned __int16 *)(v3 + 190);
    v6 = 0;
    while ( 1 )
    {
      v7 = (unsigned __int8)(v6 + 1);
      if ( *(unsigned __int16 *)(v3 + 12 * v6 + 10) == v5 )
        break;
      v6 = (unsigned __int8)(v6 + 1);
      if ( v7 >= v4 )
      {
        if ( v7 == v4 )
        {
          v8 = v4 - 1;
          v13 = v3 + 12 * (unsigned __int8)v8;
          *(_WORD *)(v13 + 10) = v5;
          *(_WORD *)(v13 + 8) = 0;
          *(_WORD *)(v3 + 136) = (unsigned __int8)v8;
          *(_WORD *)(v3 + 138) = (unsigned __int8)v8;
          *(_WORD *)(v3 + 140) = (unsigned __int8)v8;
LABEL_8:
          v9 = v3 + 12 + 12 * v8;
          v10 = v3;
          do
          {
            *(_WORD *)(v10 + 4) = 0;
            *(_WORD *)(v10 + 6) = 0;
            v10 += 12;
          }
          while ( v9 != v10 );
LABEL_10:
          *(_BYTE *)(v3 + 166) = v1 & 0xCF | 0x20;
          *(_BYTE *)(v3 + 154) = 0;
          return 1;
        }
LABEL_7:
        *(_WORD *)(v3 + 136) = v7;
        *(_WORD *)(v3 + 138) = v7;
        *(_WORD *)(v3 + 140) = v7;
        v8 = v4 - 1;
        goto LABEL_8;
      }
    }
    LOWORD(v7) = v6;
    goto LABEL_7;
  }
  sub_13E130((unsigned __int16 *)(a1 + 12 * *(unsigned __int8 *)(a1 + 136) + 4));
  if ( !*(_WORD *)(v3 + 184) )
    return v2;
  v12 = v3 + 12 + 12 * (unsigned __int16)(*(_WORD *)(v3 + 184) - 1);
  do
  {
    *(_WORD *)(v3 + 4) = 0;
    *(_WORD *)(v3 + 6) = 0;
    v3 += 12;
  }
  while ( v3 != v12 );
  return v1 & 0x10;
}

