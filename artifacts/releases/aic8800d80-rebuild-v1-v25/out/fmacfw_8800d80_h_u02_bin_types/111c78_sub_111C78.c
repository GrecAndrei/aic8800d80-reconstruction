// sub_111C78 @ 0x111c78, size 262 bytes
int  sub_111C78(uint32_t *a1, int a2)
{
  uint8_t *v4; // r6
  uint32_t *v5; // r7
  void *v6; // r0
  int v7; // r2
  int v8; // r1
  uint32_t *v9; // r4
  int v10; // r1
  void ( *v11)(int); // r2
  int v12; // r1
  uint32_t *v13; // r3
  uint8_t *v15; // r7
  int v16; // r0
  int v17; // r1
  uint32_t *v18; // r3

  sub_12E948(dword_111D80, 0, a2);
  if ( !a1 )
    return 1;
  if ( !*a1 || !a1[1] || !a1[2] || !a1[5] )
    return 2;
  v4 = off_111D84;
  if ( *(uint8_t *)off_111D84 )
    return 3;
  v5 = off_111D88;
  v6 = off_111D8C;
  *(uint8_t *)off_111D84 = 1;
  sub_143630(v6, a1, 80);
  v8 = v5[97];
  if ( v8 )
  {
    sub_12E948(dword_111DB8, v8, v7);
    sub_100644(v5[97]);
  }
  v9 = off_111D90;
  if ( (*((uint32_t *)off_111D90 + 512) & 0x7F0) != 0 )
  {
    v15 = off_111DA8;
    *((uint32_t *)off_111DA8 + 1) = 0;
    *((uint32_t *)v15 + 2) = 0;
    *v15 = 0;
    *v4 = 4;
    v16 = sub_111744();
    v17 = *(uint32_t *)off_111DAC;
    v18 = *(uint32_t **)off_111DB0;
    *v18 = dword_111DB4;
    v18[1] = v17;
    v9[709] = v18;
    v9[706] = v9[706];
    v11 = *((void ( **)(int))off_111D8C + 19);
    v10 = 1;
    v9[704] |= 0x84000000;
    *v15 = 1;
    if ( v11 )
      v11(v16);
  }
  else
  {
    if ( (*((uint32_t *)off_111D90 + 2) & 1) != 0 )
    {
      *((uint32_t *)off_111D90 + 2) &= ~1u;
      v9[513] |= 2u;
    }
    sub_1118BC();
  }
  sub_12E948(dword_111D94, v10, v11);
  v12 = dword_111D9C;
  v13 = off_111DA0;
  *(uint32_t *)(*((uint32_t *)off_111D98 + 2) + 320) = dword_111D9C;
  v13[2] = 1;
  if ( a2 == 1 )
  {
    while ( *v4 != 4 )
      ;
  }
  sub_12E948(dword_111DA4, v12, 1);
  return 0;
}

