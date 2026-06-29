// sub_10F7E4 @ 0x10f7e4, size 492 bytes
unsigned int  sub_10F7E4(int *a1, int a2, unsigned int a3)
{
  unsigned int result; // r0
  int v6; // r2
  unsigned int v7; // r3
  int *v8; // r8
  uint32_t *v9; // r9
  int v10; // r7
  int *v11; // r11
  int v12; // r4
  unsigned int v13; // r5
  int v14; // r6
  uint32_t *v15; // r5
  uint32_t *v16; // r10
  int v17; // r3
  int v18; // r3
  int v19; // r3
  uint32_t *v20; // r7
  int v21; // r5
  unsigned int v22; // r3
  int v23; // r2
  unsigned int v24; // r3
  int v25; // [sp+0h] [bp-24h]
  int v26; // [sp+4h] [bp-20h]
  unsigned int v27; // [sp+8h] [bp-1Ch]
  unsigned int v28; // [sp+Ch] [bp-18h]
  char v29; // [sp+10h] [bp-14h]

  result = *a1;
  v28 = result;
  if ( a3 )
  {
    v6 = result % a3;
    v7 = a3;
    if ( v6 )
    {
      v7 = a3 - v6;
      if ( a3 - v6 <= 3 )
        v7 += a3;
    }
    v28 = result + v7 - 4;
  }
  if ( !*((uint8_t *)a1 + 8) )
    return result;
  v8 = (int *)off_10F9E0;
  v9 = off_10F9E4;
  v25 = 0;
  v10 = 0;
  v11 = a1;
  while ( 2 )
  {
    result = *(unsigned __int16 *)(a2 + 4 * v10);
    v12 = 0;
    v13 = *(unsigned __int16 *)(a2 + 4 * v10 + 2);
    v14 = v11[3] + 12 * v10;
    *(uint32_t *)v14 = 0;
    *(uint16_t *)(v14 + 4) = 0;
    if ( !v13 )
      goto LABEL_6;
    v26 = result + 4;
    *(uint16_t *)(v14 + 2) = v13;
    v27 = v13;
    *(uint16_t *)(v14 + 4) = result;
    v15 = (uint32_t *)(v28 + 4);
    v16 = nullptr;
    v29 = v10;
    do
    {
      v20 = v16;
      v16 = v15;
      if ( *v8 <= (unsigned int)v15 && *v8 + v8[1] >= (unsigned int)v15
        || *v9 <= (unsigned int)v15 && *v9 + v9[1] >= (unsigned int)v15 )
      {
        *((uint8_t *)v15 - 4) = v29;
        v17 = *v8;
        if ( *v8 > (unsigned int)v15 )
          goto LABEL_22;
      }
      else
      {
        sub_10DAE4(dword_10F9D0, v15);
        v17 = *v8;
        if ( *v8 > (unsigned int)v15 )
          goto LABEL_22;
      }
      if ( v17 + v8[1] >= (unsigned int)v15 )
        goto LABEL_12;
LABEL_22:
      if ( *v9 <= (unsigned int)v15 && *v9 + v9[1] >= (unsigned int)v15 )
      {
LABEL_12:
        *((uint8_t *)v15 - 3) = 85;
        v18 = *v8;
        if ( *v8 > (unsigned int)v15 )
          goto LABEL_25;
        goto LABEL_13;
      }
      sub_10DAE4(dword_10F9D4, v15);
      v18 = *v8;
      if ( *v8 > (unsigned int)v15 )
        goto LABEL_25;
LABEL_13:
      if ( v18 + v8[1] >= (unsigned int)v15 )
        goto LABEL_14;
LABEL_25:
      if ( *v9 <= (unsigned int)v15 && *v9 + v9[1] >= (unsigned int)v15 )
      {
LABEL_14:
        *((uint8_t *)v15 - 2) = 0;
        v19 = *v8;
        if ( *v8 > (unsigned int)v15 )
          goto LABEL_28;
        goto LABEL_15;
      }
      sub_10DAE4(dword_10F9D8, v15);
      v19 = *v8;
      if ( *v8 > (unsigned int)v15 )
        goto LABEL_28;
LABEL_15:
      if ( v19 + v8[1] >= (unsigned int)v15 )
        goto LABEL_16;
LABEL_28:
      if ( *v9 <= (unsigned int)v15 && *v9 + v9[1] >= (unsigned int)v15 )
      {
LABEL_16:
        *v15 = v20;
        goto LABEL_17;
      }
      sub_10DAE4(dword_10F9DC, v15);
LABEL_17:
      ++v12;
      ++*(uint16_t *)v14;
      v15 = (uint32_t *)((char *)v15 + v26);
    }
    while ( v27 > (unsigned __int16)v12 );
    v21 = (unsigned __int16)(v27 - 1);
    v22 = v28 + v21 * v26;
    result = v28 + v26 + v21 * v26;
    v28 = result;
    *(uint32_t *)(v14 + 8) = v22 + 4;
    if ( a3 )
    {
      v23 = result % a3;
      v24 = a3;
      if ( result % a3 )
      {
        v24 = a3 - v23;
        if ( a3 - v23 <= 3 )
          v24 += a3;
      }
      v28 = result + v24 - 4;
    }
LABEL_6:
    v10 = (unsigned __int8)++v25;
    if ( *((unsigned __int8 *)v11 + 8) > (unsigned int)(unsigned __int8)v25 )
      continue;
    return result;
  }
}

