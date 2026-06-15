// v23 annotated: sub_133AF0 @ 0x133af0
// Original: 133af0_sub_133AF0.c
// Primary struct: <unclustered>
//
// sub_133AF0 @ 0x133af0, size 414 bytes
int sub_133AF0()
{
  _BYTE *v0; // r6
  int v1; // r7
  int v2; // r5
  int v3; // r8
  int v4; // r4
  int v5; // r9
  int v6; // r3
  unsigned int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r6
  int v12; // r0
  __int16 v13; // r2
  int v14; // r3
  int v15; // r10
  _DWORD *v16; // r1
  int v17; // r2
  int v18; // r0
  int v19; // [sp+18h] [bp-Ch] BYREF
  _DWORD v20[2]; // [sp+1Ch] [bp-8h] BYREF

  v0 = off_133C94;
  v1 = *((_DWORD *)off_133C94 + 4);
  if ( **(__int16 **)off_133C90 < 0 && sub_12CD48(6u) != 2 )
    sub_12F32C(dword_133CA4, dword_133CA0, 344);
  v2 = *(unsigned __int8 *)(v1 + 61);
  v3 = dword_133CA8;
  v4 = 1320 * v2;
  v5 = dword_133CA8 + 1320 * v2;
  if ( *(int *)(v5 + 472) < 0 )
  {
    if ( sub_13465C(v20) )
    {
      sub_134CC4(1);
    }
    else
    {
      v11 = sub_12C7EC(10, 0, 6, 0x20u);
      sub_128748(*(unsigned __int8 *)(v1 + 61), LOBYTE(v20[0]));
      *(_DWORD *)v11 = 0;
      *(_BYTE *)(v11 + 25) = *(_BYTE *)(v1 + 61);
      v12 = *(_DWORD *)(v5 + 368);
      v13 = *(_WORD *)(v5 + 372);
      *(_BYTE *)(v11 + 26) = 0;
      *(_BYTE *)(v11 + 29) = *(_BYTE *)(v5 + 407);
      *(_BYTE *)(v11 + 30) = *(_BYTE *)(v5 + 408);
      v14 = *(_DWORD *)(v5 + 472);
      *(_DWORD *)(v11 + 18) = v12;
      v15 = v14 & 2;
      *(_WORD *)(v11 + 22) = v13;
      if ( (v14 & 2) != 0 )
      {
        v15 = v14 & 4;
        if ( (v14 & 4) != 0 )
        {
          v18 = sub_12DE60(v4 + 368 + v3);
          v14 = *(_DWORD *)(v5 + 472);
          v16 = (_DWORD *)(v4 + 280 + v3);
          v15 = v18;
        }
        else
        {
          v16 = nullptr;
        }
        v17 = v14 & 8;
        if ( (v14 & 8) != 0 )
          v17 = v4 + 292 + v3;
        sub_132518(v4 + 248 + v3, v16, v17, (_WORD *)(v11 + 16), (int *)(v11 + 8), (int *)(v11 + 4), (char *)(v11 + 24));
      }
      *(_DWORD *)(v11 + 12) = v15;
      sub_12C84C(v11);
      sub_12CBF4(6u, 3);
    }
    v9 = *(_DWORD *)(v1 + 48);
    v10 = v3 + 1320 * v2;
    *(_DWORD *)(v10 + 1208) = v9;
    if ( (v9 & 4) != 0 )
    {
      *(_DWORD *)(v10 + 472) &= 0xFFFFFFF1;
      return 0;
    }
    return 0;
  }
  v6 = (unsigned __int8)v0[32];
  if ( v0[32] )
  {
    sub_134CC4(1);
    return 0;
  }
  v19 = (unsigned __int8)v0[32];
  v20[0] = v6;
  sub_134334(&v19, v20);
  if ( *(_BYTE *)off_133C98 != 1 && *((_BYTE *)off_133C9C + 3) != 1 )
  {
    *((_BYTE *)off_133C9C + 32) = 2;
LABEL_7:
    sub_134480(v19, v20[0], 1);
    return 0;
  }
  v8 = (unsigned __int8)(*((_BYTE *)off_133C9C + 32) + 1);
  *((_BYTE *)off_133C9C + 32) = v8;
  if ( v8 > 1 )
    goto LABEL_7;
  sub_134480(v19, v20[0], 0);
  return 0;
}

