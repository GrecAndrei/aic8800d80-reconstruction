// fwstruct annotate: 128748_sub_128748.c
// sub_128748 @ 0x128748, size 530 bytes
int __fastcall sub_128748(int a1, int a2)
{
  __int16 **v2; // r10
  int v3; // r8
  int v4; // r7
  int v7; // r6
  int v8; // r9
  int v9; // r1
  _BYTE *v10; // r11
  int v11; // r3
  int v12; // r2
  _BYTE *v13; // r3
  int v14; // r2
  int v15; // r3
  int v16; // r2
  int result; // r0
  int v18; // r3
  char v19; // r0
  __int16 *v20; // r3
  unsigned int v21; // r2
  int v22; // r3
  int v23; // r3
  int v24; // r1

  v2 = (__int16 **)off_12898C;
  v3 = dword_128968;
  v4 = dword_12895C;
  v7 = dword_128968 + 28 * a2;
  if ( **(__int16 **)off_12898C >= 0
    || *(_DWORD *)(dword_12895C + 1320 * a1 + 72) && (sub_12F32C(dword_128974, dword_128970, 3061), **v2 >= 0) )
  {
    v8 = 8 * a2;
  }
  else
  {
    v8 = 8 * a2;
    if ( *(unsigned __int8 *)(v3 + 28 * a2 + 24) == 255 )
      sub_12F32C(dword_128978, dword_128970, 3062);
  }
  v9 = v3 + 4 * (v8 - a2);
  v10 = off_128990;
  v11 = v4 + 1320 * a1;
  v12 = (unsigned __int8)(*(_BYTE *)(v9 + 25) + 1);
  *(_BYTE *)(v9 + 25) = v12;
  *(_DWORD *)(v11 + 72) = v7;
  *(_BYTE *)(v11 + 85) = 0;
  if ( v12 == 1 )
  {
    v19 = v10[90];
    *(_BYTE *)(v9 + 16) = 1;
    v20 = *v2;
    v21 = (unsigned __int8)(v19 + 1);
    v10[90] = v21;
    if ( *v20 < 0 && v21 > 2 )
    {
      sub_12F32C(dword_128980, dword_128970, 3082);
      v21 = (unsigned __int8)v10[90];
    }
    if ( v21 == 2 )
    {
      sub_12D100(dword_128988);
      v23 = dword_12895C;
      v24 = dword_12895C + 5280;
      do
      {
        *(_BYTE *)(v23 + 85) &= ~1u;
        v23 += 1320;
      }
      while ( v24 != v23 );
    }
    sub_12D108(dword_12897C);
    if ( (v10[88] & 0xC) != 0 )
    {
      v22 = *((_DWORD *)v10 + 8);
      if ( **v2 < 0 && !v22 )
      {
        sub_12F32C(dword_128984, dword_128970, 3097);
        v22 = 0;
      }
      *(_DWORD *)(v22 + 8) = v7;
    }
    else if ( *((_DWORD *)v10 + 11) )
    {
      *((_DWORD *)v10 + 11) = v7;
    }
    else
    {
      sub_126F8C(v7);
    }
  }
  sub_12EB90(256, dword_128960);
  v13 = (_BYTE *)(v4 + 1320 * a1);
  v14 = (unsigned __int8)v13[1224];
  v13[86] = -1;
  if ( v14 && *(_BYTE *)(dword_128964 + 140 * (unsigned __int8)v13[1225] + 112) == 1 )
  {
    v13[85] |= 0x10u;
  }
  else
  {
    v15 = dword_128968;
    while ( 1 )
    {
      if ( *(unsigned __int8 *)(v15 + 24) != 255 )
      {
        v16 = *(unsigned __int8 *)(v15 + 27);
        if ( v16 != 255 )
          break;
      }
      v15 += 28;
      if ( dword_128968 + 84 == v15 )
        goto LABEL_10;
    }
    if ( *(_DWORD *)(v4 + 1320 * v16 + 72) != v7 )
      *(_BYTE *)(v4 + 1320 * a1 + 85) |= 0x10u;
  }
LABEL_10:
  result = sub_128408(v7);
  v18 = *((unsigned __int8 *)off_12896C + 16);
  if ( v18 != a1 && v18 != 255 )
    return sub_128994(a2);
  return result;
}

