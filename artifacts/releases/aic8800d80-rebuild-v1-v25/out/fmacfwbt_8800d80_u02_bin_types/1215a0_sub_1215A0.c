// sub_1215A0 @ 0x1215a0, size 184 bytes
// Doc: sub_12215A0 [unknown]: Indexed table accessor (likely per-instance struct init by index)
// sub_12215A0 [unknown]: Indexed table accessor (likely per-instance struct init by index)
int  sub_1215A0(int a1, int a2)
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

  v2 = dword_121658;
  v3 = off_12165C;
  v4 = off_121670;
  v5 = off_121674;
  v6 = off_121660;
  v7 = (unsigned __int16 *)(dword_121658 + 696 * a1);
  *(uint32_t *)off_12165C = v7[19] | (v7[20] << 16);
  v8 = off_121664;
  v3[1] = v7[21];
  v9 = (int *)off_121668;
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
      v12 = off_12166C;
      v13 = off_121668;
      *(uint32_t *)off_12165C = -1;
      *v12 = -1;
      *v9 = ((unsigned __int8)v11 << 16) | 0x40000000;
      while ( (*v13 & 0x40000000) != 0 )
        ;
      v14 = (unsigned __int16 *)(v2 + 696 * a1);
      *(uint32_t *)off_12165C = v14[19] | (v14[20] << 16);
      *(uint32_t *)off_12166C = v14[21];
    }
  }
  v15 = off_121668;
  *(uint32_t *)off_121668 = (16 * a2) | (v10 << 16) | 0x40000002;
  while ( (*v15 & 0x40000000) != 0 )
    ;
  return (unsigned __int8)(a1 + 16);
}

