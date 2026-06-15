// v23 annotated: sub_126764 @ 0x126764
// Original: 126764_sub_126764.c
// Primary struct: <unclustered>
//
// sub_126764 @ 0x126764, size 226 bytes
_DWORD *__fastcall sub_126764(int a1)
{
  int v2; // r1
  int v3; // r2
  int v4; // r3
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r1
  int v9; // r2
  int v10; // r3
  _DWORD *result; // r0
  int v12; // r4
  _DWORD *v13; // r1
  _DWORD *v14; // r4
  _DWORD *v15; // r3
  _QWORD *v16; // r5
  int v17; // r2
  _DWORD *v18; // r2
  _DWORD *v19; // r1
  _DWORD *v20; // r4
  _QWORD *v21; // r5
  __int64 v22; // [sp+8h] [bp-38h] BYREF
  int v23; // [sp+10h] [bp-30h]
  int v24; // [sp+14h] [bp-2Ch]
  int v25; // [sp+18h] [bp-28h]
  int v26; // [sp+1Ch] [bp-24h]
  int v27; // [sp+20h] [bp-20h]
  int v28; // [sp+24h] [bp-1Ch]
  int v29; // [sp+28h] [bp-18h]
  int v30; // [sp+2Ch] [bp-14h]
  int v31; // [sp+30h] [bp-10h]
  int v32; // [sp+34h] [bp-Ch]
  int v33; // [sp+38h] [bp-8h]
  int v34; // [sp+3Ch] [bp-4h]
  _QWORD vars0[2]; // [sp+40h] [bp+0h] BYREF

  v2 = *(_DWORD *)(dword_126848 + 4);
  v3 = *(_DWORD *)(dword_126848 + 8);
  v4 = *(_DWORD *)(dword_126848 + 12);
  v23 = *(_DWORD *)dword_126848;
  v24 = v2;
  v25 = v3;
  v26 = v4;
  v5 = *(_DWORD *)(dword_126848 + 20);
  v6 = *(_DWORD *)(dword_126848 + 24);
  v7 = *(_DWORD *)(dword_126848 + 28);
  v27 = *(_DWORD *)(dword_126848 + 16);
  v28 = v5;
  v29 = v6;
  v30 = v7;
  v8 = *(_DWORD *)(dword_126848 + 36);
  v9 = *(_DWORD *)(dword_126848 + 40);
  v10 = *(_DWORD *)(dword_126848 + 44);
  v31 = *(_DWORD *)(dword_126848 + 32);
  v32 = v8;
  v33 = v9;
  v34 = v10;
  if ( !a1 )
  {
    result = (_DWORD *)msg_parse(dword_126868);
    v18 = off_126858;
    *(_DWORD *)off_126854 |= 0x80000000;
    *v18 |= 0x80000000;
    return result;
  }
  if ( a1 > 3 )
    return (_DWORD *)msg_parse(dword_12684C, a1);
  get_cached_1828f8(&v22, 0);
  v12 = BYTE1(v22);
  result = (_DWORD *)msg_parse(dword_126850, a1, WORD2(v22), WORD1(v22), BYTE1(v22));
  if ( !v12 )
  {
    v19 = off_126858;
    v20 = off_12685C;
    result = off_126860;
    *(_DWORD *)off_126854 &= ~0x80000000;
    v15 = off_126864;
    v21 = &vars0[a1 - 1];
    *v19 &= ~0x80000000;
    *v20 = *((_DWORD *)v21 - 12);
    v17 = *((_DWORD *)v21 - 11);
    goto LABEL_8;
  }
  if ( v12 == 1 )
  {
    v13 = off_126858;
    v14 = off_12685C;
    result = off_126860;
    *(_DWORD *)off_126854 &= ~0x80000000;
    v15 = off_126864;
    *v13 &= ~0x80000000;
    v16 = &vars0[a1];
    *v14 = *((_DWORD *)v16 - 8);
    v17 = *((_DWORD *)v16 - 7);
LABEL_8:
    *result = v17;
    *v15 |= 2u;
    *v15 |= 1u;
  }
  return result;
}

