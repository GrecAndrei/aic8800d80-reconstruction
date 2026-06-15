// sub_11CD24 @ 0x11cd24, size 376 bytes
void sub_11CD24()
{
  _DWORD *v0; // r2
  _DWORD *v1; // r7
  int v2; // r3
  int v3; // r6
  int v4; // r8
  int v5; // r3
  int v6; // r4
  int v7; // r3
  int v8; // r0
  _DWORD *v9; // r1
  unsigned int v10; // r3
  _DWORD *v11; // r4
  __int16 **v12; // r9
  int v13; // r5
  int v14; // r3
  int v15; // r2
  unsigned int v16; // r1
  _DWORD *v17; // r3
  int v18; // r2
  int v19; // r1
  bool v20; // nf
  _DWORD *v21; // r1
  int v22; // r2

  v0 = off_11CEA0;
  *(_DWORD *)off_11CE9C = 0x100000;
  while ( (*v0 & 0x300000) != 0 )
    ;
  v1 = off_11CEA4;
  v2 = *((_DWORD *)off_11CEA4 + 52);
  *(_DWORD *)off_11CEA8 = 0x100000;
  if ( (v2 & 1) != 0 )
  {
    v3 = *((unsigned __int8 *)v1 + 190);
    v4 = dword_11CECC;
    v5 = dword_11CECC + 84 * v3;
    if ( *(_BYTE *)(v5 + 26) )
    {
LABEL_5:
      v6 = v4 + 84 * v3;
      *(_WORD *)(*(_DWORD *)(v6 + 36) + 8) |= 0x10u;
      sub_12D4F8(v6 + 28);
      sub_12D32C(*(_DWORD *)(dword_11CEAC + 4 * v3));
      *(_BYTE *)(v6 + 26) = 0;
      *(_DWORD *)(v6 + 36) = 0;
    }
    else
    {
      v11 = *(_DWORD **)(v5 + 12);
      if ( (v11[9] & 0x200000) != 0 )
      {
        v22 = *(_DWORD *)(*(_DWORD *)(v5 + 20) + 68);
        if ( v22 == v11[17] )
          *(_DWORD *)(v5 + 20) = **(_DWORD **)(v22 + 324);
      }
      v12 = (__int16 **)off_11CED0;
      v13 = v4 + 84 * v3;
      while ( 1 )
      {
        if ( **v12 < 0 && !v11 )
          sub_12F694(dword_11CEBC, dword_11CEB8, 2094);
        v14 = v11[19];
        v15 = v11[9];
        v16 = *(_DWORD *)(v14 + 72) | 0x80400000;
        *(_DWORD *)(v14 + 72) = v16;
        if ( (v15 & 0x200000) == 0 )
          break;
        sub_11BFF4((int)v11, v16);
        v11 = *(_DWORD **)(v13 + 12);
        if ( *(_BYTE *)(v13 + 26) )
          goto LABEL_5;
      }
      sub_11CA18((int)v11, v16);
    }
    v7 = (int)&v1[7 * v3];
    if ( !*(_BYTE *)(v7 + 46) )
    {
      v8 = *(_DWORD *)(v7 + 36);
      if ( v8 )
        sub_116AF4(v8, v3, *(unsigned __int8 *)(v7 + 46), v7);
      v1[7 * v3 + 9] = 0;
    }
    v9 = off_11CEB4;
    *(_DWORD *)off_11CEB0 &= ~0x40u;
    *v9 = 64;
    v10 = v1[52] & 0xFFFFFFFE;
    --*(_BYTE *)(v4 + 84 * v3 + 80);
    v1[52] = v10;
    sub_11AC28(v3);
  }
  else if ( (v2 & 2) != 0 )
  {
    v1[52] = v2 & 0xFFFFFFFD;
  }
  else
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_11CEC0 = 1;
    }
    v17 = off_11CEC4;
    v18 = *(_DWORD *)off_11CEC4;
    v19 = *(_DWORD *)off_11CEC4 + 1;
    v20 = (*(_DWORD *)off_11CEC8 & 0x1000) != 0;
    *(_DWORD *)off_11CEC4 = v19;
    if ( v20 )
      v1[52] |= 4u;
    if ( v19 )
    {
      v21 = off_11CEC0;
      *v17 = v18;
      if ( !v18 )
      {
        if ( *v21 )
          __enable_irq();
      }
    }
  }
}

