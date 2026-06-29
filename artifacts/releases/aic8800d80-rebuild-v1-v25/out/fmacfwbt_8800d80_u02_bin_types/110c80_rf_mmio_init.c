// rf_mmio_init @ 0x110c80, size 414 bytes
// Doc: rf_mmio_init [mmio]: Initialize RF MMIO register at 0x40240124
// rf_mmio_init [mmio]: Initialize RF MMIO register at 0x40240124
int rf_mmio_init()
{
  int *v0; // r3
  int v1; // r3
  uint32_t *v2; // r1
  int *v3; // r4
  unsigned int *v4; // r5
  unsigned int *v5; // r2
  uint32_t *v6; // r0
  uint32_t *v7; // r7
  uint32_t *v8; // r6
  int v9; // r1
  uint32_t *v10; // r3
  uint32_t *v11; // r2
  uint32_t *v12; // r0
  int v13; // r1
  int v14; // r0
  int *v15; // r3
  int v16; // r1
  void *v17; // r2
  uint32_t *v18; // r1
  int result; // r0
  uint32_t *v20; // r3
  unsigned int *v21; // r2
  unsigned int *v22; // r1

  v0 = (int *)off_110E24;
  *(uint32_t *)off_110E20 = 16;
  v1 = *v0;
  if ( (v1 & 4) != 0 )
  {
    v21 = (unsigned int *)off_110E54;
    v22 = (unsigned int *)off_110E38;
    *(uint32_t *)off_110E54 = *(uint32_t *)off_110E54 & 0x8000FFFF | 0x4E200000;
    *v21 = *v21 & 0xFFFF8000 | 0x4E20;
    *v22 = *v22 & 0xFFFFF000 | 0x960;
    result = send_msg_40d();
  }
  else
  {
    sub_12ECB0(dword_110E28, 16, v1 << 29);
    do
    {
      while ( (*(uint32_t *)off_110E2C & 0x20000000) != 0 )
        ;
    }
    while ( *(int *)off_110E2C < 0 );
    v2 = off_110E2C;
    *(uint32_t *)off_110E2C = dword_110E30;
    while ( (*v2 & 0x20000000) != 0 )
      ;
    if ( (*v2 & 2) == 0 )
    {
      while ( (*(uint32_t *)off_110E24 & 1) == 0 )
        ;
    }
    v3 = (int *)off_110E34;
    v4 = (unsigned int *)off_110E38;
    v5 = (unsigned int *)off_110E3C;
    v6 = off_110E40;
    v7 = off_110E44;
    v8 = off_110E48;
    *(uint32_t *)off_110E24 = 2;
    v9 = dword_110E4C;
    *v3 = (HIWORD(*v3) << 16) | 0x7E0;
    *v4 = *v4 & 0xFFFFF000 | 0x50;
    *v5 = *v5 & 0xFFFFFF00 | 8;
    *v5 = *v5 & 0xFFFF00FF | 0xF00;
    v10 = off_110E50;
    *v6 &= v9;
    *(int *)((char *)v3 + 0xFFFFFFF8) = 385;
    v4[136] = 385;
    v11 = off_110E54;
    *v10 &= ~0x80000000;
    *v10 &= ~0x20u;
    v12 = off_110E58;
    *v11 = *v11 & v9 | 0x4E200000;
    *v11 = *v11 & 0xFFFF8000 | 0x4E20;
    v11 -= 75;
    v4[3] = -1;
    *(int *)((char *)v3 + 0xFFFFFFD8) = -1;
    *v12 = 0x1FFFFFF;
    v13 = dword_110E5C;
    *v7 = 15;
    v14 = dword_110E60;
    *v8 = 15;
    *v11 = v13;
    sub_12ECB0(v14, v13, v11);
    v15 = (int *)off_110E2C;
    v16 = dword_110E30;
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
    v17 = off_110E2C;
    do
    {
      while ( (*(uint32_t *)off_110E2C & 0x20000000) != 0 )
        ;
    }
    while ( *(int *)off_110E2C < 0 );
    v18 = off_110E2C;
    *(uint32_t *)off_110E2C = dword_110E64;
    while ( (*v18 & 0x20000000) != 0 )
      ;
    result = sub_12ECB0(dword_110E68, v18, v17);
    *(uint32_t *)off_110E38 = *(uint32_t *)off_110E38 & 0xFFFFF000 | 0x960;
  }
  v20 = off_110E70;
  *(uint32_t *)(*((uint32_t *)off_110E6C + 2) + 324) = dword_110E74;
  v20[2] = 2;
  return result;
}

