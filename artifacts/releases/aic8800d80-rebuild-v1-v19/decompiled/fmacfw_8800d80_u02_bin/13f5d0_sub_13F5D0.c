// sub_13F5D0 @ 0x13f5d0, size 452 bytes
int __fastcall sub_13F5D0(int a1, int a2)
{
  unsigned __int16 *v2; // r5
  unsigned __int16 *v3; // r9
  unsigned __int16 *v5; // r2
  int v6; // r6
  unsigned __int16 *v7; // r7
  _WORD *v8; // r1
  int v9; // t1
  __int64 v10; // r2
  int v11; // r1
  unsigned __int16 v12; // r1
  int v13; // r3
  int v14; // r2
  _DWORD *v15; // r1
  _DWORD *v16; // r2
  int v17; // r3
  unsigned __int16 v18; // r8
  int v19; // r11
  int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r1
  int v23; // r3
  int v24; // r3
  int result; // r0
  int v26; // r3
  int v27; // t1
  int v28; // t1
  int v29; // r2
  _BYTE v31[8]; // [sp+8h] [bp-34h] BYREF
  _DWORD v32[11]; // [sp+10h] [bp-2Ch] BYREF

  v2 = (unsigned __int16 *)(a1 + 136);
  v3 = (unsigned __int16 *)v31;
  v5 = (unsigned __int16 *)(a1 + 136);
  v6 = a1;
  v7 = (unsigned __int16 *)(a1 + 144);
  v8 = v31;
  do
  {
    v9 = *v5++;
    *v8++ = *(_WORD *)(a1 + 12 * v9 + 10);
  }
  while ( v5 != v7 );
  if ( *(_WORD *)(a1 + 146) )
  {
    HIDWORD(v10) = ((unsigned int)((*(unsigned __int16 *)(a1 + 144) << 16) / *(unsigned __int16 *)(a1 + 146)
                                 + 3 * *(_DWORD *)(a1 + 148)) >> 2)
                 & 0x1FFFFFF;
    LODWORD(v10) = 0;
    *(_QWORD *)(a1 + 144) = v10;
  }
  sub_13E270((unsigned __int16 *)(a1 + 124));
  v11 = *(unsigned __int16 *)(a1 + 184);
  if ( *(_WORD *)(a1 + 124) )
  {
    if ( !*(_WORD *)(a1 + 184) )
    {
LABEL_26:
      v29 = *(unsigned __int16 *)(a1 + 190);
      result = 0;
      *(_WORD *)(a1 + 124) = 0;
      *(_WORD *)(a1 + 126) = 0;
      if ( v29 != 0xFFFF )
        return sub_13E4E0(a1);
      return result;
    }
    v12 = v11 - 1;
    v13 = a1;
    while ( 1 )
    {
      v14 = *(unsigned __int16 *)(v13 + 4);
      *(_BYTE *)(v13 + 14) = 1;
      v13 += 12;
      if ( v14 )
        break;
      if ( v13 == a1 + 12 + 12 * v12 )
        goto LABEL_26;
    }
    *(_WORD *)(a1 + 124) = 0;
    *(_WORD *)(a1 + 126) = 0;
  }
  else
  {
    *(_WORD *)(a1 + 126) = 0;
    if ( !v11 )
    {
      if ( *(unsigned __int16 *)(a1 + 190) == 0xFFFF )
        goto LABEL_18;
LABEL_29:
      result = sub_13E4E0(a1);
      goto LABEL_23;
    }
    v12 = v11 - 1;
  }
  v15 = &v32[v12 + 1];
  v16 = v32;
  v17 = a1;
  do
  {
    *v16++ = 0;
    *(_BYTE *)(v17 + 14) = 1;
    v17 += 12;
  }
  while ( v16 != v15 );
  if ( *(unsigned __int16 *)(a1 + 190) != 0xFFFF )
    goto LABEL_29;
  v18 = 0;
  do
  {
    v19 = v18;
    sub_13E270((unsigned __int16 *)(a1 + 12 * v18 + 4));
    v20 = (unsigned __int8)v18++;
    v21 = sub_13F4B0(a1, v20, 1);
    v22 = *(unsigned __int16 *)(a1 + 184);
    v32[v19] = v21;
  }
  while ( v22 > v18 );
LABEL_18:
  sub_13E1D0(a1, (int)v32);
  sub_13CFF0(a1, v32);
  if ( !a2 )
  {
    v23 = *(unsigned __int16 *)(a1 + 184);
    *(_BYTE *)(a1 + 166) |= 0x40u;
    if ( v23 )
    {
      v24 = a1 + 12 + 12 * (unsigned __int16)(v23 - 1);
      do
      {
        *(_WORD *)(v6 + 4) = a2;
        *(_WORD *)(v6 + 6) = a2;
        v6 += 12;
      }
      while ( v6 != v24 );
    }
  }
  result = 0;
LABEL_23:
  while ( 1 )
  {
    v27 = *v2++;
    v26 = v27;
    v28 = *v3++;
    if ( *(unsigned __int16 *)(a1 + 12 * v26 + 10) != v28 )
      break;
    if ( v2 == v7 )
      return result;
  }
  return 1;
}

