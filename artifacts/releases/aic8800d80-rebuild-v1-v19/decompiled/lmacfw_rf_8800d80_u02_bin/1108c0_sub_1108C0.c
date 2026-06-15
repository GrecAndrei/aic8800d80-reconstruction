// sub_1108C0 @ 0x1108c0, size 414 bytes
int sub_1108C0()
{
  _DWORD *v0; // r3
  _DWORD *v1; // r1
  int *v2; // r4
  unsigned int *v3; // r5
  unsigned int *v4; // r2
  _DWORD *v5; // r0
  _DWORD *v6; // r7
  _DWORD *v7; // r6
  int v8; // r1
  _DWORD *v9; // r3
  _DWORD *v10; // r2
  _DWORD *v11; // r0
  int v12; // r1
  int v13; // r0
  int *v14; // r3
  int v15; // r1
  _DWORD *v16; // r1
  int result; // r0
  _DWORD *v18; // r3
  unsigned int *v19; // r2
  unsigned int *v20; // r1

  v0 = off_110A64;
  *(_DWORD *)off_110A60 = 16;
  if ( (*v0 & 4) != 0 )
  {
    v19 = (unsigned int *)off_110A94;
    v20 = (unsigned int *)off_110A78;
    *(_DWORD *)off_110A94 = *(_DWORD *)off_110A94 & 0x8000FFFF | 0x4E200000;
    *v19 = *v19 & 0xFFFF8000 | 0x4E20;
    *v20 = *v20 & 0xFFFFF000 | 0x960;
    result = sub_10F7FC();
  }
  else
  {
    msg_parse(dword_110A68, 16);
    do
    {
      while ( (*(_DWORD *)off_110A6C & 0x20000000) != 0 )
        ;
    }
    while ( *(int *)off_110A6C < 0 );
    v1 = off_110A6C;
    *(_DWORD *)off_110A6C = dword_110A70;
    while ( (*v1 & 0x20000000) != 0 )
      ;
    if ( (*v1 & 2) == 0 )
    {
      while ( (*(_DWORD *)off_110A64 & 1) == 0 )
        ;
    }
    v2 = (int *)off_110A74;
    v3 = (unsigned int *)off_110A78;
    v4 = (unsigned int *)off_110A7C;
    v5 = off_110A80;
    v6 = off_110A84;
    v7 = off_110A88;
    *(_DWORD *)off_110A64 = 2;
    v8 = dword_110A8C;
    *v2 = (HIWORD(*v2) << 16) | 0x7E0;
    *v3 = *v3 & 0xFFFFF000 | 0x50;
    *v4 = *v4 & 0xFFFFFF00 | 8;
    *v4 = *v4 & 0xFFFF00FF | 0xF00;
    v9 = off_110A90;
    *v5 &= v8;
    *(int *)((char *)v2 + 0xFFFFFFF8) = 385;
    v3[136] = 385;
    v10 = off_110A94;
    *v9 &= ~0x80000000;
    *v9 &= ~0x20u;
    v11 = off_110A98;
    *v10 = *v10 & v8 | 0x4E200000;
    *v10 = *v10 & 0xFFFF8000 | 0x4E20;
    v3[3] = -1;
    *(int *)((char *)v2 + 0xFFFFFFD8) = -1;
    *v11 = 0x1FFFFFF;
    v12 = dword_110A9C;
    *v6 = 15;
    v13 = dword_110AA0;
    *v7 = 15;
    *(v10 - 75) = v12;
    msg_parse(v13, v12);
    v14 = (int *)off_110A6C;
    v15 = dword_110A70;
    while ( 1 )
    {
      while ( (*v14 & 0x20000000) != 0 )
        ;
      if ( *v14 >= 0 )
      {
        *v14 = v15;
        while ( (*v14 & 0x20000000) != 0 )
          ;
        if ( (*v14 & 6) != 0 )
          break;
      }
    }
    do
    {
      while ( (*(_DWORD *)off_110A6C & 0x20000000) != 0 )
        ;
    }
    while ( *(int *)off_110A6C < 0 );
    v16 = off_110A6C;
    *(_DWORD *)off_110A6C = dword_110AA4;
    while ( (*v16 & 0x20000000) != 0 )
      ;
    result = msg_parse(dword_110AA8, v16);
    *(_DWORD *)off_110A78 = *(_DWORD *)off_110A78 & 0xFFFFF000 | 0x960;
  }
  v18 = off_110AB0;
  *(_DWORD *)(*((_DWORD *)off_110AAC + 2) + 324) = dword_110AB4;
  v18[2] = 2;
  return result;
}

