// sub_12EB18 @ 0x12eb18, size 404 bytes
unsigned int  sub_12EB18(unsigned int result, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r9
  unsigned int v6; // r5
  unsigned int v7; // r7
  int v8; // r8
  int v9; // r10
  unsigned __int16 *v10; // r6
  unsigned int v11; // r11
  int v12; // r1
  int v13; // r0
  int v14; // r10
  uint8_t *v15; // r11
  int v16; // r4
  unsigned int v17; // r8
  unsigned int v19; // r8
  int v20; // r0
  int v21; // r10
  unsigned int v22; // r8
  unsigned int v23; // r6
  unsigned int v24; // [sp+Ch] [bp-10h]
  int v26; // [sp+14h] [bp-8h]

  if ( !a2 )
    return result;
  v4 = a3;
  if ( a3 != 4 && (unsigned int)(a3 - 1) > 1 )
    return result;
  v5 = dword_12ECC0;
  v24 = a2 * a3;
  v6 = -a3 & result;
  while ( 1 )
  {
    sub_12EA88(dword_12ECAC, v6);
    v7 = v24;
    if ( v24 >= 0x10 )
      v7 = 16;
    if ( ((v6 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      if ( !v24 )
        return (unsigned int)sub_10D7B4((uint8_t *)dword_12ECB8);
      v21 = dword_12ECB0;
      v22 = 0;
      while ( 1 )
      {
        v23 = sub_10ED6C();
        if ( v4 == 4 )
          break;
        if ( v4 == 2 )
        {
          v22 += 4;
          sub_12EA88(dword_12ECBC, (unsigned __int16)v23, HIWORD(v23), BYTE2(v23));
          v6 += 4;
          if ( v7 <= v22 )
          {
LABEL_40:
            a4 = 0;
            goto LABEL_31;
          }
        }
        else
        {
          sub_12EA88(v5);
LABEL_36:
          v22 += 4;
          v6 += 4;
          if ( v7 <= v22 )
            goto LABEL_40;
        }
      }
      sub_12EA88(v21, v23, BYTE1(v23), BYTE2(v23));
      goto LABEL_36;
    }
    if ( v24 )
      break;
    if ( a4 )
    {
      v10 = (unsigned __int16 *)v6;
      goto LABEL_20;
    }
LABEL_31:
    result = (unsigned int)sub_10D7B4((uint8_t *)dword_12ECB8);
    v24 -= v7;
    if ( !v24 )
      return result;
  }
  v8 = dword_12ECC4;
  v9 = dword_12ECC8;
  v10 = (unsigned __int16 *)v6;
  v11 = 0;
  do
  {
    while ( 1 )
    {
      v13 = v8;
      if ( v4 != 4 )
        break;
      v11 += 4;
      sub_12EA88(dword_12ECB0, *(uint32_t *)v10);
      v10 += 2;
      if ( v7 <= v11 )
        goto LABEL_18;
    }
    if ( v4 == 2 )
      v12 = *v10;
    else
      v12 = *(unsigned __int8 *)v10;
    if ( v4 == 2 )
      v13 = v9;
    v11 += v4;
    sub_12EA88(v13, v12);
    v10 = (unsigned __int16 *)((char *)v10 + v4);
  }
  while ( v7 > v11 );
LABEL_18:
  if ( !a4 )
    goto LABEL_30;
  if ( v24 > 0xF )
  {
    sub_10D7B4((uint8_t *)dword_12ECB4);
    goto LABEL_26;
  }
LABEL_20:
  v14 = v4 - 1;
  v26 = v4;
  v15 = (uint8_t *)dword_12ECCC;
  v16 = 0;
  v17 = 16 - v7;
  do
  {
    while ( (v14 & v16++) != 0 )
    {
      sub_10D7B4(v15);
      if ( v17 == v16 )
        goto LABEL_25;
    }
    sub_10D79C(32);
    sub_10D7B4(v15);
  }
  while ( v17 != v16 );
LABEL_25:
  v4 = v26;
  sub_10D7B4((uint8_t *)dword_12ECB4);
  if ( v24 )
  {
LABEL_26:
    v19 = 0;
    do
    {
      v20 = *(unsigned __int8 *)(v6 + v19);
      if ( (unsigned int)(v20 - 31) > 0x5F )
        v20 = 46;
      ++v19;
      sub_10D79C(v20);
    }
    while ( v7 > v19 );
LABEL_30:
    v6 = (unsigned int)v10;
    goto LABEL_31;
  }
  return (unsigned int)sub_10D7B4((uint8_t *)dword_12ECB8);
}

