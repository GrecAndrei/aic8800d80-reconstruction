// mmio_reg_init_n_e24 @ 0x110e24, size 414 bytes
// Doc: mmio_reg_init_n_e24 [mmio]: Initializes MMIO control registers at 0x40240000 region
// mmio_reg_init_n_e24 [mmio]: Initializes MMIO control registers at 0x40240000 region
int mmio_reg_init_n_e24()
{
  int *v0; // r3
  int v1; // r3
  _DWORD *v2; // r1
  int *v3; // r4
  unsigned int *v4; // r5
  unsigned int *v5; // r2
  _DWORD *v6; // r0
  _DWORD *v7; // r7
  _DWORD *v8; // r6
  int v9; // r1
  _DWORD *v10; // r3
  _DWORD *v11; // r2
  _DWORD *v12; // r0
  int v13; // r1
  int v14; // r0
  int *v15; // r3
  int v16; // r1
  void *v17; // r2
  _DWORD *v18; // r1
  int result; // r0
  _DWORD *v20; // r3
  unsigned int *v21; // r2
  unsigned int *v22; // r1

  v0 = (int *)off_110FC8;
  *(_DWORD *)off_110FC4 = 16;
  v1 = *v0;
  if ( (v1 & 4) != 0 )
  {
    v21 = (unsigned int *)off_110FF8;
    v22 = (unsigned int *)off_110FDC;
    *(_DWORD *)off_110FF8 = *(_DWORD *)off_110FF8 & 0x8000FFFF | 0x4E200000;
    *v21 = *v21 & 0xFFFF8000 | 0x4E20;
    *v22 = *v22 & 0xFFFFF000 | 0x960;
    result = sub_10F90C();
  }
  else
  {
    msg_parse(dword_110FCC, 16, v1 << 29);
    do
    {
      while ( (*(_DWORD *)off_110FD0 & 0x20000000) != 0 )
        ;
    }
    while ( *(int *)off_110FD0 < 0 );
    v2 = off_110FD0;
    *(_DWORD *)off_110FD0 = dword_110FD4;
    while ( (*v2 & 0x20000000) != 0 )
      ;
    if ( (*v2 & 2) == 0 )
    {
      while ( (*(_DWORD *)off_110FC8 & 1) == 0 )
        ;
    }
    v3 = (int *)off_110FD8;
    v4 = (unsigned int *)off_110FDC;
    v5 = (unsigned int *)off_110FE0;
    v6 = off_110FE4;
    v7 = off_110FE8;
    v8 = off_110FEC;
    *(_DWORD *)off_110FC8 = 2;
    v9 = dword_110FF0;
    *v3 = (HIWORD(*v3) << 16) | 0x7E0;
    *v4 = *v4 & 0xFFFFF000 | 0x50;
    *v5 = *v5 & 0xFFFFFF00 | 8;
    *v5 = *v5 & 0xFFFF00FF | 0xF00;
    v10 = off_110FF4;
    *v6 &= v9;
    *(int *)((char *)v3 + 0xFFFFFFF8) = 385;
    v4[136] = 385;
    v11 = off_110FF8;
    *v10 &= ~0x80000000;
    *v10 &= ~0x20u;
    v12 = off_110FFC;
    *v11 = *v11 & v9 | 0x4E200000;
    *v11 = *v11 & 0xFFFF8000 | 0x4E20;
    v11 -= 75;
    v4[3] = -1;
    *(int *)((char *)v3 + 0xFFFFFFD8) = -1;
    *v12 = 0x1FFFFFF;
    v13 = dword_111000;
    *v7 = 15;
    v14 = dword_111004;
    *v8 = 15;
    *v11 = v13;
    msg_parse(v14, v13, v11);
    v15 = (int *)off_110FD0;
    v16 = dword_110FD4;
    while ( 1 )
    {
      while ( (*v15 & 0x20000000) != 0 )
        ;
      if ( *v15 >= 0 )
      {
        *v15 = v16;
        while ( (*v15 & 0x20000000) != 0 )
          ;
        if ( (*v15 & 6) != 0 )
          break;
      }
    }
    v17 = off_110FD0;
    do
    {
      while ( (*(_DWORD *)off_110FD0 & 0x20000000) != 0 )
        ;
    }
    while ( *(int *)off_110FD0 < 0 );
    v18 = off_110FD0;
    *(_DWORD *)off_110FD0 = dword_111008;
    while ( (*v18 & 0x20000000) != 0 )
      ;
    result = msg_parse(dword_11100C, v18, v17);
    *(_DWORD *)off_110FDC = *(_DWORD *)off_110FDC & 0xFFFFF000 | 0x960;
  }
  v20 = off_111014;
  *(_DWORD *)(*((_DWORD *)off_111010 + 2) + 324) = dword_111018;
  v20[2] = 2;
  return result;
}

