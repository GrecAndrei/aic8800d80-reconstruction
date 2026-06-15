// v23 annotated: sub_139E30 @ 0x139e30
// Original: 139e30_sub_139E30.c
// Primary struct: <unclustered>
//
// sub_139E30 @ 0x139e30, size 336 bytes
int __fastcall sub_139E30(char *a1, char a2, int a3)
{
  char v4; // r3
  int v6; // r4
  char *v7; // r8
  int v8; // r7
  int v10; // r2
  int v11; // r3
  char *v12; // r5
  _DWORD *v13; // r1
  int v14; // r6
  unsigned int v15; // r3
  unsigned __int16 v16; // [sp+6h] [bp-2h] BYREF

  if ( *a1 >= 0 )
    v4 = 24;
  else
    v4 = 26;
  v16 = 0;
  if ( (a2 & 0x78) == 8 )
  {
    v4 += 8;
  }
  else if ( (a2 & 0x7C) == 4 )
  {
    v4 += 4;
  }
  v6 = (unsigned __int8)(v4 + 6);
  v7 = &a1[v6];
  sub_14380C(&v16, &a1[v6], 2);
  v8 = a1[4] & 1;
  if ( (a1[4] & 1) != 0 )
  {
    if ( v16 == 1544 )
      return v8;
    if ( v16 != 56710 )
      return 0;
  }
  else if ( v16 != 56710 )
  {
    if ( v16 == 8 )
    {
      v10 = (unsigned __int8)v7[11];
      if ( v10 == 2 )
      {
        sub_12ECB0(dword_139F84, (unsigned __int8)v7[10], 2, 8);
        return v8;
      }
      if ( v10 == 17 )
      {
        v12 = &a1[4 * (v7[2] & 0xF) + 2 + v6];
        if ( (unsigned __int8)*(v12 - 4) == 239
          && (unsigned __int8)*(v12 - 3) == 255
          && (unsigned __int8)*(v12 - 2) == 255
          && (unsigned __int8)*(v12 - 1) == 250 )
        {
          sub_12ECB0(dword_139F80, (unsigned __int8)v12[3] | ((unsigned __int8)v12[2] << 8));
          return v8;
        }
      }
    }
    return 1;
  }
  if ( v7[8] == 58 )
  {
    v11 = (unsigned __int8)v7[42];
    if ( v11 == 134 )
    {
      v13 = off_139F8C;
      v14 = dword_139F88 + 696 * a3;
      v15 = (unsigned __int8)v7[49] | ((unsigned __int8)v7[48] << 8);
      *(_WORD *)(v14 + 690) = _byteswap_ushort(*((_WORD *)v7 + 24));
      if ( (int)(*(_DWORD *)(v14 + 692) - v13[4] + dword_139F90 * (v15 >> 1)) < 0 )
      {
        *(_DWORD *)(v14 + 692) = v13[4];
        return 1;
      }
      return 0;
    }
    return v11 == 136 || v11 == 135 && ((unsigned __int8)v7[26] != 255 || v7[27] != 2);
  }
  return (unsigned __int8)(1 - v8);
}

