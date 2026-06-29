// sub_103E84 @ 0x103e84, size 186 bytes
int  sub_103E84(int a1, int a2, int a3)
{
  int v3; // r1
  int v4; // r2
  unsigned int *v5; // r3
  int v6; // r8
  int v7; // r12
  int v8; // r6
  unsigned int *v9; // lr
  int v10; // r7
  int result; // r0
  int v12; // r4
  int v13; // r1
  int v14; // r1
  int v15; // r3
  uint32_t *v16; // r3
  int v17; // r4
  int v18; // r5
  int v19; // r4

  v3 = 3 * a2;
  if ( !a3 )
  {
    v16 = (uint32_t *)(a1 + 16 * v3);
    v17 = dword_103F4C;
    v16[13] = dword_103F48;
    v16[14] = v17;
    v18 = dword_103F50;
    v19 = dword_103F54;
    v16[12] = dword_103F58;
    v16[18] = 0;
    v16[19] = 0;
    v16[20] = 0;
    v16[21] = 0;
    v16[22] = 0;
    v16[23] = 0;
    v16[15] = dword_103F5C;
    v16[16] = v18;
    v16[17] = v19;
  }
  v4 = 4 * v3;
  v5 = (unsigned int *)off_103F44;
  v6 = dword_103F60;
  *(uint32_t *)off_103F40 |= 0x100u;
  v7 = 0;
  v8 = a1 + 48;
  *v5 &= 0xFFFCFFFF;
  v9 = v5;
  v10 = 0;
  result = 0;
  v12 = 4 * v3 + 11;
  v13 = 128;
  while ( 1 )
  {
    v14 = v13 + v10;
    v15 = v10;
    do
    {
      if ( v15 >= v4 && v15 <= v12 )
        *(uint32_t *)(v7 + v6 + 4 * v15) = *(uint32_t *)(v8 + 4 * v15);
      ++v15;
    }
    while ( v15 != v14 );
    if ( ++result == 3 )
      break;
    v10 += 128;
    v7 -= 512;
    *v9 = *v9 & 0xFFFCFFFF | (result << 16);
    if ( result == 2 )
      v13 = 32;
    else
      v13 = 128;
  }
  *(uint32_t *)off_103F40 &= ~0x100u;
  return result;
}

