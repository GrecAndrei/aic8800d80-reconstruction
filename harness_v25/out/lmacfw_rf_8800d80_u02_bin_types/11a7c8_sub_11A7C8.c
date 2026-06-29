// sub_11A7C8 @ 0x11a7c8, size 242 bytes
int  sub_11A7C8(unsigned __int8 *a1)
{
  uint8_t *v1; // r2
  int v2; // r3
  unsigned __int8 v4; // r0
  unsigned __int8 v5; // r4
  unsigned __int8 v6; // r1
  void *v7; // r1
  int v8; // r11
  uint32_t *v9; // r10
  uint32_t *v10; // r9
  int v11; // r8
  int v12; // r7
  unsigned __int8 *v13; // r6
  int i; // r4
  int v15; // r3
  int v16; // t1
  int v17; // r2

  v1 = off_11A8BC;
  v2 = a1[16];
  *((uint8_t *)off_11A8BC + 360) = a1[17];
  v1[361] = a1[18];
  v4 = a1[21];
  v1[356] = v4;
  v5 = a1[22];
  v1[357] = v5;
  v6 = a1[23];
  v1[358] = v6;
  v1[359] = v6 + v4 + v5;
  if ( a1[19] )
    *(uint32_t *)off_11A8C0 |= 0x10u;
  else
    *(uint32_t *)off_11A8C0 &= ~0x10u;
  v7 = off_11A8C0;
  if ( a1[20] )
    *(uint32_t *)off_11A8C0 |= 2u;
  else
    *(uint32_t *)off_11A8C0 &= ~2u;
  v8 = dword_11A8D8;
  v9 = off_11A8DC;
  v10 = off_11A8E0;
  v11 = 224 * v2;
  v12 = 224 * v2 + 8 + dword_11A8D8;
  v13 = a1 - 4;
  for ( i = 0; i != 4; ++i )
  {
    v16 = *((uint32_t *)v13 + 1);
    v13 += 4;
    v15 = v16;
    if ( v16 )
    {
      *(uint32_t *)(v12 + 4 * i) = v15;
      v7 = *(void **)off_11A8C4;
      v17 = *(unsigned __int8 *)(v8 + v11 + 96);
      *(uint32_t *)(*(uint32_t *)off_11A8C4 + 4 * i) = v15;
      if ( v17 )
      {
        if ( i == 1 )
        {
          *v9 = v15;
        }
        else if ( (unsigned __int8)i == 2 )
        {
          *v10 = v15;
        }
        else if ( (uint8_t)i )
        {
          *(uint32_t *)off_11A8C8 = v15;
        }
        else
        {
          *(uint32_t *)off_11A8D4 = v15;
        }
        sub_1183A0();
      }
    }
  }
  if ( a1[24] )
    *(uint8_t *)off_11A8CC = a1[24];
  sub_11F504(dword_11A8D0, v7);
  return sub_11F594(a1, 28, 1, 0);
}

