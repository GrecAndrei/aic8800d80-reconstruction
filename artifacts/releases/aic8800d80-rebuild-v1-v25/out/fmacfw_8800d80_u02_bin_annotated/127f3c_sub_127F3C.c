// fwstruct annotate: 127f3c_sub_127F3C.c
// sub_127F3C @ 0x127f3c, size 464 bytes
BOOL __fastcall sub_127F3C(int a1, int a2, int a3)
{
  _BYTE *v3; // r11
  int *v4; // r4
  int v8; // r3
  int v9; // r2
  int v10; // r7
  int v11; // r10
  int v12; // r1
  int v13; // r4
  int v15; // r1
  int v16; // r3
  char v17; // r2
  int v18; // r3
  char v19; // r3
  int v20; // r2
  int v21; // [sp+4h] [bp-8h]

  v3 = off_128114;
  v4 = *((int **)off_128114 + 4);
  if ( v4 )
  {
    v8 = v4[1];
    v9 = *(_DWORD *)(a1 + 72);
    v10 = *((_DWORD *)off_128114 + 10);
    v21 = v9;
    if ( v8 == a2 )
    {
LABEL_9:
      v13 = 0;
      if ( (unsigned __int8)v3[90] > 1u )
        goto LABEL_13;
LABEL_10:
      *(_BYTE *)(a1 + 85) |= 2u;
      ++v3[91];
      return v10 != v21;
    }
    v11 = dword_128118;
    while ( v8 - a2 < 0 )
    {
      v12 = *((unsigned __int8 *)v4 + 8);
      if ( v12 == *(unsigned __int8 *)(a1 + 107) )
      {
        sub_12EA88(v11, v12, v9);
        sub_12D2E8(v3 + 16, v4);
        *((_BYTE *)v4 + 9) &= ~1u;
      }
      v4 = (int *)*v4;
      if ( !v4 )
        break;
      v8 = v4[1];
      if ( v8 == a2 )
        goto LABEL_9;
    }
  }
  else
  {
    v10 = *((_DWORD *)off_128114 + 10);
    v21 = *(_DWORD *)(a1 + 72);
  }
  v13 = 1;
  if ( (unsigned __int8)v3[90] <= 1u )
    goto LABEL_10;
LABEL_13:
  if ( *(unsigned __int8 *)(a1 + 86) != 255 )
  {
    sub_127958(a1, a2);
    if ( v13 )
      goto LABEL_31;
    goto LABEL_25;
  }
  if ( !*(_BYTE *)(a1 + 1224) )
  {
    if ( v13 )
    {
      *(_BYTE *)(a1 + 85) |= 4u;
      return v10 != v21;
    }
    goto LABEL_26;
  }
  v15 = dword_12810C;
  v16 = *(unsigned __int8 *)(a1 + 1225);
  if ( *(_BYTE *)(dword_12810C + 140 * v16 + 112) != 1 )
  {
    if ( v13 )
    {
      v17 = *(_BYTE *)(a1 + 85);
LABEL_18:
      *(_BYTE *)(a1 + 85) = v17 | 4;
LABEL_19:
      if ( *(_BYTE *)(v15 + 140 * v16 + 112) == 1 )
      {
        v18 = *(_DWORD *)(a1 + 80);
        if ( v18 != a3 && v18 - a3 - 50 < 0 && a3 - v18 - 50 < 0 )
          *(_DWORD *)(a1 + 80) = a3;
      }
      return v10 != v21;
    }
    goto LABEL_26;
  }
  v17 = *(_BYTE *)(a1 + 85);
  if ( (v17 & 0x10) != 0 )
  {
    sub_125E78((_DWORD *)a1);
    *(_BYTE *)(a1 + 85) &= ~0x10u;
    if ( v13 )
      goto LABEL_31;
LABEL_25:
    if ( !*(_BYTE *)(a1 + 1224) || *(_BYTE *)(dword_12810C + 140 * *(unsigned __int8 *)(a1 + 1225) + 112) != 1 )
    {
LABEL_26:
      sub_12D2E8(dword_128110, a1 + 76);
      v19 = *(_BYTE *)(a1 + 85) & 0xFE;
LABEL_27:
      *(_BYTE *)(a1 + 85) = v19 | 2;
      ++v3[91];
      return v10 != v21;
    }
LABEL_36:
    sub_126584(a1, a3, 0);
    v19 = *(_BYTE *)(a1 + 85) | 8;
    goto LABEL_27;
  }
  if ( (*(_BYTE *)(a1 + 85) & 0x40) == 0 )
  {
    if ( v13 )
      goto LABEL_18;
    goto LABEL_36;
  }
  sub_1278C8(a1);
  if ( !v13 )
    goto LABEL_25;
LABEL_31:
  v20 = *(unsigned __int8 *)(a1 + 1224);
  *(_BYTE *)(a1 + 85) |= 4u;
  if ( v20 )
  {
    v15 = dword_12810C;
    v16 = *(unsigned __int8 *)(a1 + 1225);
    goto LABEL_19;
  }
  return v10 != v21;
}

