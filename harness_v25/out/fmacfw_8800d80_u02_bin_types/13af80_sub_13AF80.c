// sub_13AF80 @ 0x13af80, size 270 bytes
// Doc: sub_123AF80 [util]: Helper processing a struct with header fields (channel, flags) and linked list traversal
// sub_123AF80 [util]: Helper processing a struct with header fields (channel, flags) and linked list traversal
int  sub_13AF80(int a1, int a2)
{
  int v2; // r5
  int v3; // r3
  __int16 v5; // r0
  int v6; // r3
  int v8; // r6
  int v9; // r0
  char v10; // r0
  int v11; // r3
  int result; // r0
  int v13; // r1
  int v14; // r3

  v2 = *(uint32_t *)(a1 + 76);
  v3 = *(unsigned __int16 *)(a1 + 32);
  v5 = *(uint16_t *)(a1 + 30);
  v6 = 16 * v3;
  v8 = *(uint32_t *)(v2 + 4) & 0x800000;
  *(uint32_t *)(v2 + 4) = v6;
  if ( (v5 & 8) != 0 )
  {
    if ( (v5 & 0x20) != 0 )
    {
      if ( v8 )
      {
        if ( (v5 & 0x200) == 0 )
          goto LABEL_19;
LABEL_5:
        if ( **(__int16 **)off_13B090 >= 0 )
          goto LABEL_6;
        goto LABEL_27;
      }
      sub_13A4D8();
      if ( (*(uint16_t *)(a1 + 30) & 0x200) != 0 )
        goto LABEL_5;
LABEL_9:
      if ( *(unsigned __int8 *)(a1 + 27) == 255 )
        goto LABEL_10;
      goto LABEL_20;
    }
    if ( (v5 & 0x200) != 0 )
    {
      if ( **(__int16 **)off_13B090 >= 0 )
        goto LABEL_6;
LABEL_27:
      v9 = *(unsigned __int8 *)(a1 + 29);
      if ( v9 != 255 )
        goto LABEL_7;
      sub_12F46C(dword_13B09C, dword_13B098, 1325);
LABEL_6:
      v9 = *(unsigned __int8 *)(a1 + 29);
LABEL_7:
      rf_chan_table_lookup_8f48(v9, 23, 0, 0);
      *(uint8_t *)(dword_13B094 + 696 * *(unsigned __int8 *)(a1 + 29) + 54) = 0;
    }
LABEL_8:
    if ( !v8 )
      goto LABEL_9;
    goto LABEL_18;
  }
  if ( (v5 & 0x200) == 0 )
    goto LABEL_8;
  *(uint8_t *)(dword_13B094 + 696 * *(unsigned __int8 *)(a1 + 29) + 54) = 0;
  if ( !v8 )
    goto LABEL_9;
LABEL_18:
  v6 = *(uint32_t *)(v2 + 4);
LABEL_19:
  *(uint32_t *)(v2 + 4) = v6 | 8;
  if ( *(unsigned __int8 *)(a1 + 27) == 255 )
  {
LABEL_10:
    v10 = 1;
    if ( (*(uint32_t *)(a1 + 36) & 0x200000) != 0 )
      goto LABEL_11;
    goto LABEL_17;
  }
LABEL_20:
  v13 = v8;
  if ( v8 )
    v13 = 1;
  v10 = sub_13C294(a1, v13, a2);
  v14 = *(uint32_t *)(a1 + 36);
  if ( (v14 & 0x200000) == 0 )
  {
LABEL_17:
    *(uint8_t *)(v2 + 1) = 1;
    goto LABEL_11;
  }
  if ( (v14 & 0x380000) != 0x380000 )
    *(uint8_t *)(v2 + 1) = 0;
LABEL_11:
  v11 = *(uint32_t *)(v2 + 4);
  *(uint8_t *)v2 = v10;
  result = v11 & 2;
  *(uint32_t *)(v2 + 4) = v11 | 1;
  if ( (v11 & 2) != 0 )
    return *(unsigned __int8 *)(dword_13B094 + 696 * *(unsigned __int8 *)(a1 + 29) + 48) == 0;
  return result;
}

