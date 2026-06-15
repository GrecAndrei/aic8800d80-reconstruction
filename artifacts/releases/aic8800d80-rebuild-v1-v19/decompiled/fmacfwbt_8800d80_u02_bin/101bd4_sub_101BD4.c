// sub_101BD4 @ 0x101bd4, size 420 bytes
int __fastcall sub_101BD4(unsigned int a1, signed int a2, unsigned __int8 *a3)
{
  int v3; // r6
  unsigned int v4; // r7
  bool v5; // cc
  char *v6; // r0
  int v7; // r2
  int v8; // r5
  int v9; // r12
  int v10; // r4
  int v11; // r0
  char v12; // r8
  unsigned int v13; // r4
  unsigned int v14; // r0
  char *v16; // r2
  int v17; // r0
  int v18; // r2
  int v19; // r12
  int v20; // r4
  int v21; // r0
  int v22; // r0
  int v23; // r3

  v3 = *a3;
  v4 = *((unsigned __int16 *)a3 + 2);
  if ( !*a3 )
  {
    if ( a1 <= 1 )
    {
      v8 = *((char *)off_101D78 + a2 + 198);
      if ( !a1 && (unsigned int)a2 <= 3 )
      {
        v9 = *a3;
        v10 = v9;
        goto LABEL_12;
      }
      v7 = 9;
    }
    else
    {
      v5 = a1 > 4;
      v6 = (char *)off_101D78 + a2;
      v7 = 2;
      if ( v5 )
        v8 = v6[220];
      else
        v8 = v6[210];
    }
    if ( v7 < a2 )
      v9 = 3;
    else
      v9 = 6;
    if ( v7 < a2 )
      v10 = 1;
    else
      v10 = 2;
LABEL_12:
    if ( v4 <= 0x97B )
    {
      v11 = 0;
    }
    else if ( v4 > 0x994 )
    {
      v11 = 2;
    }
    else
    {
      v11 = 1;
    }
    v12 = *(_BYTE *)(*(_DWORD *)off_101D7C + v11 + v9) + *(_BYTE *)(dword_101D80 + v10 + 8) + *(_BYTE *)off_101D84;
    v13 = v12;
    if ( *((_BYTE *)off_101D78 + 396) )
      v8 = (char)(*(_BYTE *)(*(_DWORD *)off_101D88 + v11) + v8);
    goto LABEL_18;
  }
  v16 = (char *)off_101D78 + a2;
  if ( a1 <= 1 )
  {
    v8 = v16[232];
    v17 = 11;
    v18 = 7;
  }
  else
  {
    if ( a1 > 4 )
      v8 = v16[254];
    else
      v8 = v16[244];
    v17 = 7;
    v18 = 4;
  }
  if ( v18 >= a2 )
  {
    v19 = 0;
    v20 = 0;
  }
  else
  {
    if ( v17 < a2 )
      v19 = 6;
    else
      v19 = 12;
    if ( v17 < a2 )
      v20 = 1;
    else
      v20 = 2;
  }
  if ( v4 > 0x1666 )
  {
    v21 = 5;
  }
  else if ( v4 > 0x1616 )
  {
    v21 = 4;
  }
  else if ( v4 > 0x15C6 )
  {
    v21 = 3;
  }
  else if ( v4 <= 0x1571 )
  {
    v21 = v4 > 0x1486;
  }
  else
  {
    v21 = 2;
  }
  v12 = *(_BYTE *)(*(_DWORD *)off_101D8C + v21 + v19) + *(_BYTE *)(dword_101D80 + v20 + 11) + *((_BYTE *)off_101D84 + 1);
  v13 = v12;
  if ( *((_BYTE *)off_101D78 + 396) )
    v8 = (char)(*(_BYTE *)(*(_DWORD *)off_101D90 + v21) + v8);
LABEL_18:
  if ( (*((_DWORD *)off_101D78 + 98) & 2) != 0 )
  {
    v22 = sub_132418(v3, v4);
    if ( v22 )
    {
      v23 = *(char *)(v22 + 4);
    }
    else
    {
      if ( **(__int16 **)off_101D94 < 0 )
        sub_12F6C4(dword_101DA0, dword_101D9C, 7022);
      sub_12ECB0(dword_101D98, v3, v4);
      v23 = 15;
    }
    if ( v8 >= v23 )
      LOBYTE(v8) = v23;
  }
  if ( (v12 & 1) != 0 )
    v14 = v13 - 1 + ((v13 - 1) >> 31);
  else
    v14 = v13 + (v13 >> 31);
  return (char)((v14 >> 1) + v8);
}

