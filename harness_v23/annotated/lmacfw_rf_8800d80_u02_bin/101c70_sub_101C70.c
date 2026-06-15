// v23 annotated: sub_101C70 @ 0x101c70
// Original: 101c70_sub_101C70.c
// Primary struct: <unclustered>
//
// sub_101C70 @ 0x101c70, size 324 bytes
int __fastcall sub_101C70(unsigned int a1, signed int a2, int a3)
{
  unsigned int v3; // r4
  char *v4; // r2
  char v5; // r2
  int v6; // r3
  int v7; // r7
  int v8; // r5
  char v9; // r1
  int v10; // r3
  char *v12; // r3
  int v13; // r0
  int v14; // r3
  bool v15; // cc
  int v16; // r0
  int v17; // r1
  int v18; // r5

  v3 = *(unsigned __int16 *)(a3 + 4);
  if ( !*(_BYTE *)a3 )
  {
    if ( a1 <= 1 )
    {
      v5 = *((_BYTE *)off_101DB4 + a2 + 198);
      if ( !a1 && (unsigned int)a2 <= 3 )
      {
        v7 = 0;
        goto LABEL_13;
      }
      v6 = 9;
    }
    else
    {
      v4 = (char *)off_101DB4 + a2;
      if ( a1 > 4 )
        v5 = v4[220];
      else
        v5 = v4[210];
      v6 = 2;
    }
    if ( v6 < a2 )
      a1 = 3;
    else
      a1 = 6;
    if ( v6 < a2 )
      v7 = 1;
    else
      v7 = 2;
LABEL_13:
    if ( v3 <= 0x97B )
    {
      v8 = 0;
    }
    else if ( v3 > 0x994 )
    {
      v8 = 2;
    }
    else
    {
      v8 = 1;
    }
    v9 = *(_BYTE *)(*(_DWORD *)off_101DB8 + v8 + a1) + *(_BYTE *)(dword_101DBC + v7 + 8) + *(_BYTE *)off_101DC0;
    v10 = v9;
    if ( *((_BYTE *)off_101DB4 + 396) )
      v5 += *(_BYTE *)(*(_DWORD *)off_101DC4 + v8);
    goto LABEL_19;
  }
  v12 = (char *)off_101DB4 + a2;
  if ( a1 <= 1 )
  {
    v5 = v12[232];
    v13 = 11;
    v14 = 7;
  }
  else
  {
    if ( a1 > 4 )
      v5 = v12[254];
    else
      v5 = v12[244];
    v13 = 7;
    v14 = 4;
  }
  if ( v14 >= a2 )
  {
    v16 = 0;
    v17 = 0;
  }
  else
  {
    v15 = v13 < a2;
    if ( v13 < a2 )
      v16 = 6;
    else
      v16 = 12;
    if ( v15 )
      v17 = 1;
    else
      v17 = 2;
  }
  if ( v3 > 0x1666 )
  {
    v18 = 5;
  }
  else if ( v3 > 0x1616 )
  {
    v18 = 4;
  }
  else if ( v3 > 0x15C6 )
  {
    v18 = 3;
  }
  else if ( v3 <= 0x1571 )
  {
    v18 = v3 > 0x1486;
  }
  else
  {
    v18 = 2;
  }
  v9 = *(_BYTE *)(*(_DWORD *)off_101DC8 + v18 + v16) + *(_BYTE *)(dword_101DBC + v17 + 11) + *((_BYTE *)off_101DC0 + 1);
  v10 = v9;
  if ( *((_BYTE *)off_101DB4 + 396) )
    v5 += *(_BYTE *)(*(_DWORD *)off_101DCC + v18);
LABEL_19:
  if ( (v9 & 1) != 0 )
    --v10;
  return (char)(v10 / 2 + v5);
}

