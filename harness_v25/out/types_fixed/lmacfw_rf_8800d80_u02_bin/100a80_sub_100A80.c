// sub_100A80 @ 0x100a80, size 400 bytes
// rf_init_or_setup_n_1200a80 [rf]: Initialize/setup RF subsystem with multiple register arguments
void __fastcall rf_init_or_setup_n_1200a80(int a1, unsigned int a2, unsigned int a3, int a4, char a5)
{
  _DWORD *v9; // r2
  _DWORD *v10; // r2
  _DWORD *v11; // r1
  int v12; // r3
  char *v13; // r0
  unsigned int *v14; // r5
  unsigned int *v15; // r1
  int v16; // r2
  unsigned int *v17; // r1
  char *v18; // r0
  unsigned int *v19; // r2
  signed int v20; // r3
  int v21; // r2
  unsigned int *v22; // r1
  unsigned int *v23; // r2
  int v24; // r2
  _DWORD *v25; // r1
  _DWORD *v26; // r0

  panic_loop();
  v9 = off_100C10;
  *(_DWORD *)off_100C10 &= ~0x40u;
  if ( a1 == 1 )
  {
    v25 = off_100C14;
    v26 = off_100C18;
    *(_DWORD *)off_100C14 = *(_DWORD *)off_100C14 & 0xFFFE3FFF | 0x18000;
    *v26 &= ~1u;
    *(_DWORD *)(v25 + 0x1b344) |= 0x100u;
    if ( (a5 & 4) != 0 )
      *v9 |= 0x40u;
  }
  else
  {
    v10 = off_100C14;
    v11 = off_100C18;
    *(_DWORD *)off_100C14 = *(_DWORD *)off_100C14 & 0xFFFE3FFF | 0xC000;
    *v11 |= 1u;
    *(_DWORD *)(v10 + 0x1b344) &= ~0x100u;
  }
  if ( a4 == 1 )
  {
    if ( a2 >= a3 )
      v24 = 2;
    else
      v24 = 1;
    *(_DWORD *)off_100C1C = v24;
    v12 = a2 >= a3;
  }
  else if ( a4 == 2 )
  {
    v20 = a3 - a2;
    if ( (int)(a3 - a2) <= 0 )
    {
      if ( v20 >= -10 )
        v21 = 2;
      else
        v21 = 3;
    }
    else
    {
      v21 = v20 <= 10;
    }
    v12 = ((unsigned __int8)((int)((unsigned __int64)(dword_100C30 * (__int64)(int)(a2 - (a3 - 30))) >> 32) >> 3)
         - (unsigned __int8)((int)(a2 - (a3 - 30)) >> 31))
        & 7;
    *(_DWORD *)off_100C1C = v21;
  }
  else
  {
    v12 = 0;
    *(_DWORD *)off_100C1C = 0;
  }
  v13 = (char *)off_100C20;
  v14 = (unsigned int *)off_100C24;
  v15 = (unsigned int *)off_100C28;
  *(_DWORD *)off_100C20 = v12 | *(_DWORD *)off_100C20 & 0xFFFFFFF8;
  v16 = (a4 << 24) & 0x3000000;
  *v14 = *v14 & 0xFCFFFFFF | v16;
  *v15 = (a4 << 16) & 0x30000 | *v15 & 0xFFFCFFFF;
  v17 = v15 + 16708;
  *(_DWORD *)&v13[-80] = *(_DWORD *)&v13[-80] & 0xFFFFFFF0 | a4 & 0xF;
  v18 = v13 - 80;
  *v17 = v16 | *v17 & 0xFCFFFFFF;
  if ( a4 )
  {
    if ( a4 == 1 )
    {
      v22 = (unsigned int *)off_100C38;
      v23 = (unsigned int *)off_100C2C;
      *(_DWORD *)off_100C34 = *(_DWORD *)off_100C34 & 0xFFFFFF | 0x18000000;
      *v22 = *v22 & 0xFFFFFFCF | 0x10;
      *v23 = *v23 & 0xFFFF00FF | 0x6C00;
    }
  }
  else
  {
    v19 = (unsigned int *)off_100C2C;
    *((_DWORD *)v18 + 1) = *((_DWORD *)v18 + 1) & 0xFFFFFF | 0x19000000;
    *(_DWORD *)(v17 + 0xf7e8) &= 0xFFFFFFCF;
    *v19 = *v19 & 0xFFFF00FF | 0x9C00;
  }
}

