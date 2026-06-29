// sub_138E1C @ 0x138e1c, size 132 bytes
uint32_t * sub_138E1C(int a1, __int16 a2)
{
  void *v2; // r6
  __int16 v4; // r5
  int v5; // r2
  int v6; // r1
  int v7; // r3
  unsigned int v8; // r3
  unsigned int v9; // r3

  v2 = off_138EA4;
  v4 = a2;
  if ( *((unsigned __int8 *)off_138EA0 + 16) == 255 )
  {
    v7 = (*((unsigned __int8 *)off_138EA4 + 10) << 8)
       | (*((unsigned __int8 *)off_138EA4 + 9) << 16)
       | *(uint32_t *)(a1 + 96);
    if ( (a2 & 0x80) == 0 )
    {
      v8 = (*((unsigned __int8 *)off_138EA4 + 10) << 8)
         | (*((unsigned __int8 *)off_138EA4 + 9) << 16)
         | *(uint32_t *)(a1 + 96) & 0xFFFFFF7D
         | 2;
      if ( (a2 & 1) != 0 )
        goto LABEL_6;
LABEL_10:
      v9 = v8 & 0xFFFFFFBF;
      goto LABEL_7;
    }
    v6 = a2 & 1;
  }
  else
  {
    v5 = *((unsigned __int8 *)off_138EA4 + 10);
    if ( v5 == 255 )
    {
      v6 = 0;
      v4 = 128;
    }
    else
    {
      v6 = a2 & 1;
      v4 |= 0x80u;
    }
    v7 = (v5 << 8) | (*((unsigned __int8 *)off_138EA4 + 9) << 16) | *(uint32_t *)(a1 + 96);
  }
  v8 = v7 | 0x82;
  if ( !v6 )
    goto LABEL_10;
LABEL_6:
  v9 = v8 | 0x40;
LABEL_7:
  *(uint32_t *)(a1 + 96) = v9;
  *((uint8_t *)v2 + 50) = 0;
  rf_bus_setup_n39a_ea44(a1);
  return sub_138AD4(a1, v4, *((uint32_t *)v2 + 16));
}

