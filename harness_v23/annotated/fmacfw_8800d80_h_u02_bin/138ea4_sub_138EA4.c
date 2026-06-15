// v23 annotated: sub_138EA4 @ 0x138ea4
// Original: 138ea4_sub_138EA4.c
// Primary struct: <unclustered>
//
// sub_138EA4 @ 0x138ea4, size 672 bytes
int __fastcall sub_138EA4(unsigned int a1, int a2, int a3)
{
  _WORD *v3; // r6
  char v5; // r5
  int v7; // r10
  int v8; // r9
  int v9; // r7
  _DWORD *v10; // r4
  int v11; // r2
  __int16 v13; // r2
  char v14; // r1
  _DWORD *v15; // r3
  int v16; // r1
  int v17; // r3
  __int64 v18; // r2
  int v19; // r0
  int v20; // r0
  unsigned int v21; // r5
  __int16 v22; // r3
  __int16 v23; // r6
  __int16 v24; // r1
  _DWORD *v25; // r0
  int v26; // r3
  _DWORD *v27; // r0
  _BYTE v28[24]; // [sp+8h] [bp-18h] BYREF

  v3 = off_139144;
  v5 = a2;
  if ( a3 )
  {
    v7 = *((unsigned __int8 *)off_139144 + 7);
    v8 = *(_WORD *)off_139144 & 0x400;
    if ( (*(_WORD *)off_139144 & 0x400) == 0 )
      goto LABEL_3;
LABEL_14:
    v10 = *((_DWORD **)off_139144 + 22);
    v11 = *((unsigned __int16 *)off_139144 + 2);
    v9 = *((unsigned __int8 *)off_139144 + 6);
    if ( v10 )
      goto LABEL_7;
LABEL_15:
    if ( v9 )
      return 0;
    v10 = sub_12D190(dword_139148);
    if ( !v10 )
    {
      v27 = sub_12D190(dword_139154);
      v10 = v27;
      if ( **(__int16 **)off_13915C < 0 && !v27 )
        sub_12F32C(dword_139164, dword_139160, 1111);
      sub_138890(0, 4, v10[5]);
    }
    v13 = v3[2];
    *((_BYTE *)v10 + 6) = v5;
    *((_BYTE *)v10 + 7) = v7;
    *((_BYTE *)v10 + 8) = 1;
    *((_BYTE *)v10 + 4) = 0;
    v14 = *((_BYTE *)v3 + 8);
    v15 = off_13914C;
    v10[4] = 0;
    *((_BYTE *)v10 + 9) = v14;
    v16 = v15[4];
    v17 = dword_139150;
    *((_WORD *)v10 + 5) = v13;
    v10[14] = v17;
    v10[15] = v10;
    sub_124BFC((int)(v10 + 13), v16 + 100000);
    if ( (v3[24] & 1) != 0 )
      sub_138C64(a1, (int)(v10 + 7), 1, 0);
    *(_DWORD *)(a1 + 96) &= ~0x20u;
    sub_138B74(a1, 1);
    HIDWORD(v18) = *((_DWORD *)v3 + 16);
    LODWORD(v18) = *((_DWORD *)v3 + 7);
    v19 = dword_139154;
    *((_QWORD *)v10 + 2) = v18;
    *((_BYTE *)v10 + 5) = *((_BYTE *)v3 + 49);
    *((_WORD *)v10 + 6) = *(_WORD *)(a1 + 48);
    sub_12D108(v19, v10);
    goto LABEL_20;
  }
  v8 = *(_WORD *)off_139144 & 0x400;
  v7 = 0;
  if ( (*(_WORD *)off_139144 & 0x400) != 0 )
    goto LABEL_14;
LABEL_3:
  v9 = *((unsigned __int8 *)off_139144 + 6);
  if ( *((_BYTE *)off_139144 + 6) )
  {
    v10 = *((_DWORD **)off_139144 + 22);
    v11 = *((unsigned __int16 *)off_139144 + 2);
    if ( !v10 )
      return *((_DWORD *)off_139144 + 22);
LABEL_7:
    while ( *((unsigned __int8 *)v10 + 6) != a2
         || *((unsigned __int8 *)v10 + 7) != v7
         || *((unsigned __int16 *)v10 + 5) != v11 )
    {
      v10 = (_DWORD *)*v10;
      if ( !v10 )
        goto LABEL_15;
    }
    if ( *((unsigned __int8 *)v10 + 8) != v9 )
      return 0;
    v21 = (unsigned __int16)(*(_WORD *)(a1 + 48) - *((unsigned __int8 *)v10 + 9));
    v22 = *((_WORD *)v10 + 6) + v21;
    *((_BYTE *)v10 + 8) = v9 + 1;
    *((_WORD *)v10 + 6) = v22;
    if ( (v3[24] & 1) != 0 )
    {
      if ( sub_138C64(a1, (int)(v10 + 7), 0, v8 == 0) )
      {
        v26 = *(_DWORD *)(a1 + 96);
        if ( !v8 )
        {
          *((_WORD *)v10 + 6) -= 8;
          *(_DWORD *)(a1 + 96) = v26 & 0xFFFFFF9F | 0x40;
          sub_11E188(a1, v21, v10[4], *((unsigned __int8 *)v10 + 9), 0, 0);
          v10[4] += v21;
          v23 = 1;
          goto LABEL_30;
        }
        *(_DWORD *)(a1 + 96) = v26 & 0xFFFFFF9F | 0x40;
        sub_11E188(a1, v21, v10[4], *((unsigned __int8 *)v10 + 9), 0, 0);
        v10[4] += v21;
LABEL_20:
        v10[6] = *((_DWORD *)off_13914C + 4);
        return 1;
      }
      v23 = 4;
    }
    else
    {
      v23 = 1;
    }
    *(_DWORD *)(a1 + 96) = *(_DWORD *)(a1 + 96) & 0xFFFFFF9F | 0x40;
    sub_11E188(a1, v21, v10[4], *((unsigned __int8 *)v10 + 9), 0, 0);
    v10[4] += v21;
    if ( !v8 )
    {
LABEL_30:
      if ( *((_BYTE *)v10 + 5) )
        v24 = 24;
      else
        v24 = 8;
      v25 = sub_138890(0, v24, v10[5]);
      if ( v25 )
        v25[18] = *((unsigned __int16 *)v10 + 6);
      sub_138890(0, v23, v10[5]);
      sub_124CF4((int)(v10 + 13));
      sub_12D1A8(dword_139154, v10);
      sub_12D108(dword_139148, v10);
      goto LABEL_20;
    }
    goto LABEL_20;
  }
  if ( (*((_BYTE *)off_139144 + 48) & 1) != 0 )
  {
    if ( !sub_138C64(a1, (int)v28, 1, 1) )
      return v9;
    *(_WORD *)(a1 + 48) -= 8;
  }
  v20 = dword_139158 + 1320 * *((unsigned __int8 *)v3 + 10);
  if ( *(_BYTE *)(v20 + 1227)
    && sub_138968((unsigned __int8 *)(v20 + 107), (_DWORD *)(v20 + 1228), *(char **)(*(_DWORD *)(a1 + 28) + 8), a3) == 1 )
  {
    return v9;
  }
  sub_138B74(a1, 3);
  return 1;
}

