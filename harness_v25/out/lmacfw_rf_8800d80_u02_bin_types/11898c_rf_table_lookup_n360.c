// rf_table_lookup_n360 @ 0x11898c, size 180 bytes
// Doc: rf_table_lookup_n360 [rf]: Looks up an entry in the RF register/object table by index
// rf_table_lookup_n360 [rf]: Looks up an entry in the RF register/object table by index
int  rf_table_lookup_n360(int a1, int a2)
{
  int v2; // r6
  uint32_t *v3; // r3
  uint32_t *v4; // lr
  uint32_t *v5; // r12
  uint32_t *v6; // r7
  unsigned __int16 *v7; // r2
  uint32_t *v8; // r5
  int *v9; // r2
  int v10; // r4
  unsigned int v11; // r5
  uint32_t *v12; // r12
  uint32_t *v13; // r7
  unsigned __int16 *v14; // r3
  uint32_t *v15; // r2

  v2 = dword_118A40;
  v3 = off_118A44;
  v4 = off_118A58;
  v5 = off_118A5C;
  v6 = off_118A48;
  v7 = (unsigned __int16 *)(dword_118A40 + 152 * a1);
  *(uint32_t *)off_118A44 = v7[18] | (v7[19] << 16);
  v8 = off_118A4C;
  v3[1] = v7[20];
  v9 = (int *)off_118A50;
  *v4 = 0;
  *v5 = 0;
  *v8 = 0;
  *v6 = 0;
  v10 = (unsigned __int8)(a1 + 16);
  *v9 = 0x20000000;
  while ( (*v9 & 0x20000000) != 0 )
    ;
  if ( (*v9 & 0x10000000) == 0 )
  {
    v11 = HIWORD(*v9);
    if ( (unsigned __int8)BYTE2(*v9) != v10 )
    {
      v12 = off_118A54;
      v13 = off_118A50;
      *(uint32_t *)off_118A44 = -1;
      *v12 = -1;
      *v9 = ((unsigned __int8)v11 << 16) | 0x40000000;
      while ( (*v13 & 0x40000000) != 0 )
        ;
      v14 = (unsigned __int16 *)(v2 + 152 * a1);
      *(uint32_t *)off_118A44 = v14[18] | (v14[19] << 16);
      *(uint32_t *)off_118A54 = v14[20];
    }
  }
  v15 = off_118A50;
  *(uint32_t *)off_118A50 = (16 * a2) | (v10 << 16) | 0x40000002;
  while ( (*v15 & 0x40000000) != 0 )
    ;
  return (unsigned __int8)(a1 + 16);
}

