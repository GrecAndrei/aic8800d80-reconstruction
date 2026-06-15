// v23 annotated: sub_132320 @ 0x132320
// Original: 132320_sub_132320.c
// Primary struct: <unclustered>
//
// sub_132320 @ 0x132320, size 76 bytes
BOOL __fastcall sub_132320(int a1, int a2)
{
  unsigned __int8 *v2; // r8
  unsigned int v3; // r6
  unsigned int v4; // r5
  int v7; // r3
  int v8; // r2
  int v9; // r3
  unsigned int v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r2
  unsigned int v14; // r3
  unsigned int v16; // r2
  unsigned int v17; // r2
  unsigned int v18; // r1

  v2 = (unsigned __int8 *)off_132458;
  v3 = *((unsigned __int8 *)off_132458 + 373);
  v4 = *((unsigned __int8 *)off_132458 + 372);
  if ( (*(_BYTE *)off_132450 & 8) == 0 )
  {
    sub_12E948(dword_132454);
    v3 = v3 != 0;
  }
  v7 = *(_DWORD *)(a1 + 4);
  if ( (v7 & 0x20) != 0 )
  {
    v8 = *(unsigned __int8 *)(a1 + 258);
    v9 = v8 >> 1;
    if ( (v8 & 0x10) != 0 )
    {
      v10 = 4;
    }
    else
    {
      if ( (v9 & 4) == 0 )
      {
        if ( (v9 & 2) != 0 )
        {
          v11 = (*(_BYTE *)(a1 + 260) & 8) != 0;
          v10 = 2;
        }
        else
        {
          v10 = (v8 >> 1) & 1;
          v11 = (*(_BYTE *)(a1 + 260) & 8) != 0;
        }
LABEL_7:
        v4 = v2[116];
        LOWORD(v12) = *(_WORD *)(a1 + 208);
        if ( v4 >= v11 )
          LOBYTE(v4) = v11;
LABEL_9:
        v13 = v3;
        if ( v3 >= v10 )
          v13 = v10;
        *(_BYTE *)(a1 + 0x134) = v13;
        v14 = *(unsigned __int8 *)(a2 + 165);
        if ( v14 == 4 )
          JUMPOUT(0x132418);
LABEL_12:
        if ( v14 >= v13 )
          v14 = v13;
        if ( v14 == 4 )
          JUMPOUT(0x13241C);
        goto LABEL_15;
      }
      v10 = 3;
    }
    v11 = (*(unsigned __int8 *)(a1 + 260) >> 3) & (*(unsigned __int8 *)(a1 + 265) >> 7);
    goto LABEL_7;
  }
  if ( (v7 & 4) != 0 )
  {
    v16 = *(_DWORD *)(a1 + 240);
    if ( (v16 & 0xC) == 4 )
    {
      v10 = 3;
    }
    else if ( (v16 & 0xC) == 8 )
    {
      v10 = 4;
    }
    else
    {
      v10 = 2;
    }
    v17 = (v16 >> 8) & 7;
    if ( v17 > 4 )
      JUMPOUT(0x132420);
    LOWORD(v12) = *(_WORD *)(a1 + 208);
    if ( v4 >= v17 )
      LOBYTE(v4) = v17;
    goto LABEL_9;
  }
  v12 = *(unsigned __int16 *)(a1 + 208);
  v18 = (v12 >> 8) & 3;
  if ( (v12 & 2) != 0 )
  {
    v13 = v3;
    if ( v3 )
      v13 = 1;
    *(_BYTE *)(a1 + 0x134) = v13;
    v14 = *(unsigned __int8 *)(a2 + 165);
    if ( v4 >= v18 )
      v4 = (v12 >> 8) & 3;
    if ( v14 != 4 )
      goto LABEL_12;
    LOBYTE(v14) = v13;
    if ( v13 >= 2 )
      LOBYTE(v14) = 2;
  }
  else
  {
    *(_BYTE *)(a1 + 0x134) = 0;
    if ( v4 >= v18 )
      v4 = (v12 >> 8) & 3;
    LOBYTE(v14) = v12 & 2;
  }
LABEL_15:
  *(_BYTE *)(a1 + 0x135) = v14;
  *(_BYTE *)(a1 + 0x138) = v4;
  return (v12 & 0xC) != 12;
}

