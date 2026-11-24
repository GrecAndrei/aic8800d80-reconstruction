// sub_100BE0 @ 0x100be0, size 520 bytes
// rf_cmd_queue_next_n_d4 [rf]: Advance RF command queue to next entry
void __fastcall rf_cmd_queue_next_n_d4(int a1, int a2, int a3, int a4, char a5)
{
  _BYTE *v5; // r8
  _DWORD *v10; // r2
  _DWORD *v11; // r1
  char *v12; // r2
  _DWORD *v13; // r2
  _DWORD *v14; // r1
  int v15; // r3
  char *v16; // r0
  unsigned int *v17; // r5
  unsigned int *v18; // r1
  int v19; // r2
  unsigned int *v20; // r1
  char *v21; // r0
  unsigned int *v22; // r2
  int v23; // r3
  int v24; // r2
  unsigned int *v25; // r1
  unsigned int *v26; // r2
  unsigned int *v27; // r2
  _DWORD *v28; // r1
  _DWORD *v29; // r2
  _DWORD *v30; // r1
  int v31; // r2

  v5 = off_100E20;
  panic_loop_06d8();
  if ( *(_DWORD *)(v5 + 0x674) && *(_BYTE *)off_100DE8 )
  {
    sub_100B90();
  }
  else
  {
    v10 = off_100DEC;
    v11 = off_100DF0;
    *(_DWORD *)off_100DEC &= ~0x800u;
    *v11 &= ~0x20u;
    *(_DWORD *)(v10 + 0x84) &= ~0x1000u;
  }
  v12 = (char *)off_100DF4;
  *(_DWORD *)off_100DF4 &= ~0x40u;
  if ( a1 == 1 )
  {
    v27 = (unsigned int *)(v12 - 728);
    v28 = off_100DFC;
    *v27 = *v27 & 0xFFFE3FFF | 0x18000;
    *v28 &= ~1u;
    *(_DWORD *)(v27 + 0x1b344) |= 0x100u;
    if ( (a5 & 4) != 0 )
    {
      if ( *(_DWORD *)(v5 + 0x674) && *(_BYTE *)off_100DE8 )
      {
        sub_100B14();
      }
      else
      {
        v29 = off_100DEC;
        v30 = off_100DF0;
        *(_DWORD *)off_100DEC |= 0x800u;
        *v30 |= 0x20u;
        *(_DWORD *)(v29 + 0x84) |= 0x1000u;
      }
      *(_DWORD *)off_100DF4 |= 0x40u;
      if ( a4 != 1 )
        goto LABEL_7;
      goto LABEL_22;
    }
  }
  else
  {
    v13 = off_100DF8;
    v14 = off_100DFC;
    *(_DWORD *)off_100DF8 = *(_DWORD *)off_100DF8 & 0xFFFE3FFF | 0xC000;
    *v14 |= 1u;
    *(_DWORD *)(v13 + 0x1b344) &= ~0x100u;
  }
  if ( a4 != 1 )
  {
LABEL_7:
    if ( a4 == 2 )
    {
      v23 = a3 - a2;
      if ( a3 - a2 <= 0 )
      {
        if ( v23 >= -10 )
          v24 = 2;
        else
          v24 = 3;
      }
      else
      {
        v24 = v23 <= 10;
      }
      v15 = ((unsigned __int8)((int)((unsigned __int64)(dword_100E14 * (__int64)(a2 - (a3 - 30))) >> 32) >> 3)
           - (unsigned __int8)((a2 - (a3 - 30)) >> 31))
          & 7;
      *(_DWORD *)off_100E00 = v24;
    }
    else
    {
      v15 = 0;
      *(_DWORD *)off_100E00 = 0;
    }
    goto LABEL_9;
  }
LABEL_22:
  if ( a3 <= (unsigned int)a2 )
    v31 = 2;
  else
    v31 = 1;
  *(_DWORD *)off_100E00 = v31;
  v15 = a3 <= (unsigned int)a2;
LABEL_9:
  v16 = (char *)off_100E04;
  v17 = (unsigned int *)off_100E08;
  v18 = (unsigned int *)off_100E0C;
  *(_DWORD *)off_100E04 = v15 | *(_DWORD *)off_100E04 & 0xFFFFFFF8;
  v19 = (a4 << 24) & 0x3000000;
  *v17 = *v17 & 0xFCFFFFFF | v19;
  *v18 = (a4 << 16) & 0x30000 | *v18 & 0xFFFCFFFF;
  v20 = v18 + 16708;
  *(_DWORD *)&v16[-80] = *(_DWORD *)&v16[-80] & 0xFFFFFFF0 | a4 & 0xF;
  v21 = v16 - 80;
  *v20 = v19 | *v20 & 0xFCFFFFFF;
  if ( a4 )
  {
    if ( a4 == 1 )
    {
      v25 = (unsigned int *)off_100E1C;
      v26 = (unsigned int *)off_100E10;
      *(_DWORD *)off_100E18 = *(_DWORD *)off_100E18 & 0xFFFFFF | 0x18000000;
      *v25 = *v25 & 0xFFFFFFCF | 0x10;
      *v26 = *v26 & 0xFFFF00FF | 0x6C00;
    }
  }
  else
  {
    v22 = (unsigned int *)off_100E10;
    *((_DWORD *)v21 + 1) = *((_DWORD *)v21 + 1) & 0xFFFFFF | 0x19000000;
    *(_DWORD *)(v20 + 0xf7e8) &= 0xFFFFFFCF;
    *v22 = *v22 & 0xFFFF00FF | 0x9C00;
  }
}

