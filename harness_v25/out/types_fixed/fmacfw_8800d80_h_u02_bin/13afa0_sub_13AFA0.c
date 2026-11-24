// sub_13AFA0 @ 0x13afa0, size 636 bytes
int __fastcall sub_13AFA0(int a1, int a2, unsigned int a3)
{
  int v3; // r3
  int v6; // r5
  unsigned int v7; // r6
  unsigned int v9; // r7
  int v10; // r8
  unsigned int v11; // r2
  int v12; // r11
  unsigned int v13; // r7
  unsigned int v14; // r10
  int v15; // r8
  int v16; // r9
  int v17; // r3
  int v18; // r8
  unsigned int v19; // r8
  __int16 v20; // r3
  unsigned int v21; // r2
  unsigned int v22; // r7
  int v23; // r0
  unsigned int v24; // r1
  int v25; // r2
  int v26; // r3
  int v27; // r5
  int v28; // r3
  int v29; // [sp+14h] [bp-10h]
  _DWORD *v30; // [sp+14h] [bp-10h]
  _DWORD *v31; // [sp+1Ch] [bp-8h]

  v3 = *(unsigned __int8 *)(a2 + 13);
  v6 = a2 + 12;
  v7 = a3 >> 8;
  if ( v3 == 1 )
  {
    v9 = *(unsigned __int16 *)(a2 + 17);
    if ( sub_12CD48(a3) != 2 )
      return 0;
    v10 = dword_13B228;
    sub_12C5FC(0x2000, a3);
    v11 = v10 + 32 * v7;
    v12 = 32 * v7;
    if ( *(unsigned __int8 *)(v11 + 23) != *(unsigned __int8 *)(v6 + 2)
      || *(_BYTE *)(v11 + 22) != ((v9 >> 2) & 0xF)
      || *(_WORD *)(v6 + 3) )
    {
      sub_13B8E4(v7);
      sub_12D108(dword_13B21C, (_DWORD *)(v10 + v12));
      sub_12CBF4(a3, 0);
      return 0;
    }
    if ( *(unsigned __int16 *)(v11 + 20) > v9 >> 6 )
      *(_WORD *)(v11 + 20) = v9 >> 6;
    v25 = *((unsigned __int8 *)off_13B24C + 377);
    v26 = v10 + v12;
    if ( v25 != 1 )
    {
      if ( v25 != 2 )
      {
        *(_BYTE *)(v26 + 24) = v9 & 1;
LABEL_38:
        v23 = *(unsigned __int8 *)(a2 + 7);
        v24 = v7;
LABEL_31:
        sub_13BC20(v23, v24);
        sub_12CBF4(a3, 3);
        return 0;
      }
      LOBYTE(v25) = 0;
    }
    *(_BYTE *)(v26 + 24) = v25;
    goto LABEL_38;
  }
  if ( v3 == 2 )
  {
    if ( sub_12CD48(a3) != 4 )
    {
      if ( sub_12CD48(a3) == 1 || sub_12CD48(a3) == 3 )
      {
        sub_12CBF4(a3, 4);
        v30 = (_DWORD *)(dword_13B228 + 32 * v7);
        if ( v7 > 0xF )
        {
          sub_12D1A8(dword_13B234, (_DWORD *)(dword_13B228 + 32 * v7));
          sub_12D108(dword_13B238, v30);
        }
        else
        {
          sub_12D1A8(dword_13B22C, (_DWORD *)(dword_13B228 + 32 * v7));
          sub_12D108(dword_13B230, v30);
        }
        sub_13BC64(*(unsigned __int8 *)(a2 + 7), v7);
        return 0;
      }
      *(_DWORD *)(696 * *(unsigned __int8 *)(dword_13B228 + 32 * v7 + 16)
                + 12 * *(unsigned __int8 *)(dword_13B228 + 32 * v7 + 22)
                + dword_13B23C
                + 448) = *((_DWORD *)off_13B240 + 4);
      sub_13BAE8(v7);
    }
    return 0;
  }
  if ( *(_BYTE *)(a2 + 13) )
    return 0;
  v13 = *(unsigned __int16 *)(a2 + 15);
  v14 = (v13 >> 2) & 0xF;
  if ( v14 > 8 )
    return 0;
  v15 = *(unsigned __int8 *)off_13B220;
  if ( *(_BYTE *)off_13B220 )
    return 0;
  v16 = *(unsigned __int8 *)(a2 + 7);
  v29 = *(unsigned __int8 *)(a2 + 14);
  sub_12EB90(2048, dword_13B224, (v13 >> 2) & 0xF);
  if ( !sub_121820(v16, (v13 >> 2) & 0xF) )
  {
    if ( sub_12CD48(a3) == 4 )
      return 2;
    v18 = dword_13B228;
    v31 = (_DWORD *)(dword_13B228 + 32 * v7);
    if ( sub_12D210((_DWORD **)dword_13B244, v31) )
      sub_12D1A8(dword_13B244, v31);
    v19 = v18 + 32 * v7;
    *(_BYTE *)(v19 + 22) = v14;
    *(_BYTE *)(v19 + 16) = v16;
    *(_BYTE *)(v19 + 23) = v29;
    *(_BYTE *)(v19 + 18) = (v13 & 2) != 0;
    *(_BYTE *)(v19 + 17) = 0;
    v20 = *(_WORD *)(v6 + 5);
    v21 = *(unsigned __int16 *)(v6 + 7);
    *(_WORD *)(v19 + 14) = v20;
    v22 = v13 >> 6;
    if ( v22 >= 0x40 )
      LOWORD(v22) = 64;
    *(_WORD *)(v19 + 20) = v22;
    *(_WORD *)(v19 + 12) = v21 >> 4;
    *(_DWORD *)(v19 + 4) = 0;
    if ( !v20 )
      *(_WORD *)(v19 + 14) = *(_WORD *)(*(_DWORD *)off_13B248 + 2);
    v23 = (unsigned __int16)v16;
    v24 = v7;
    goto LABEL_31;
  }
  if ( sub_12CD48(a3) == 1 )
  {
    v27 = dword_13B228 + 32 * v7;
    v28 = v13 >> 6;
    if ( v13 >> 6 >= 0x40 )
      v28 = 64;
    if ( *(unsigned __int16 *)(v27 + 20) == v28 )
    {
      v17 = v15;
    }
    else
    {
      sub_12CBF4(a3, 4);
      sub_12D1A8(dword_13B22C, (_DWORD *)v27);
      sub_12D108(dword_13B230, (_DWORD *)v27);
      sub_13BC64((unsigned __int16)v16, v7);
      v17 = 37;
    }
  }
  else
  {
    v17 = 37;
  }
  sub_13B558(v16, 0, 1, v29, v13, v17, 0);
  return 0;
}

