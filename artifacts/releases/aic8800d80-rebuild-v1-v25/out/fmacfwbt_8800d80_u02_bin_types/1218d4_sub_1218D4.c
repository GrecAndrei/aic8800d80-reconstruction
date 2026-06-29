// sub_1218D4 @ 0x1218d4, size 198 bytes
uint32_t * sub_1218D4(int a1)
{
  int v2; // r1
  uint32_t *v3; // r5
  uint32_t *v4; // r2
  int *v5; // r1
  uint32_t *v6; // r5
  uint32_t *result; // r0
  int v8; // r5
  int v9; // r6
  uint32_t *v10; // r2

  if ( (unsigned int)a1 > HIBYTE(*(uint32_t *)off_12199C) )
    return (uint32_t *)rf_chan_table_init(
                       dword_1219A4 + 1320 * ((a1 - (HIBYTE(*(uint32_t *)off_12199C) + 1)) / 2),
                       (((uint8_t)a1 - 1 - HIBYTE(*(uint32_t *)off_12199C)) & 1) + 4);
  if ( (unsigned int)a1 > 0xF )
  {
    v8 = dword_1219C0 + 696 * (unsigned __int8)(a1 - 16);
    v9 = *(unsigned __int8 *)(v8 + 34);
    result = (uint32_t *)sub_11F6F0(v8);
    if ( *(uint8_t *)(dword_1219A4 + 1320 * v9 + 106) == 2 )
      return result;
    v10 = off_1219A8;
    *(uint32_t *)off_1219A0 = *(unsigned __int16 *)(v8 + 38) | (*(unsigned __int16 *)(v8 + 40) << 16);
    *v10 = *(unsigned __int16 *)(v8 + 42);
  }
  else
  {
    v2 = dword_1219A4;
    v3 = off_1219A8;
    *(uint32_t *)off_1219A0 = -1;
    *v3 = -1;
    rf_chan_table_init(v2 + 1320 * (a1 >> 2), a1 & 3);
  }
  v4 = off_1219AC;
  v5 = (int *)off_1219B0;
  v6 = off_1219B8;
  result = off_1219BC;
  *(uint32_t *)off_1219B4 = 0;
  *v6 = 0;
  *v4 = 0;
  *result = 0;
  *v5 = (a1 << 16) | 0x40000000;
  while ( (*v5 & 0x40000000) != 0 )
    ;
  return result;
}

