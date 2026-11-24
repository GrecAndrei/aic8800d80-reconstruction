// sub_100BE0 @ 0x100be0, size 520 bytes
void __fastcall sub_100BE0(int a1, int a2, int a3, int a4, char a5)
{
  int *v5; // r8
  int v10; // r0
  _DWORD *v11; // r2
  _DWORD *v12; // r1
  char *v13; // r2
  _DWORD *v14; // r2
  _DWORD *v15; // r1
  int v16; // r3
  char *v17; // r0
  unsigned int *v18; // r5
  unsigned int *v19; // r1
  int v20; // r2
  unsigned int *v21; // r1
  char *v22; // r0
  unsigned int *v23; // r2
  int v24; // r3
  int v25; // r2
  unsigned int *v26; // r1
  unsigned int *v27; // r2
  unsigned int *v28; // r2
  _DWORD *v29; // r1
  _DWORD *v30; // r2
  _DWORD *v31; // r1
  int v32; // r2

  v5 = (int *)off_100E20;
  v10 = sub_1006D8();
  if ( *((_BYTE *)v5 + 413) && *(_BYTE *)off_100DE8 )
  {
    sub_100B90(v10);
  }
  else
  {
    v11 = off_100DEC;
    v12 = off_100DF0;
    *(_DWORD *)off_100DEC &= ~0x800u;
    *v12 &= ~0x20u;
    *(_DWORD *)(v11 + 0x84) &= ~0x1000u;
  }
  v13 = (char *)off_100DF4;
  *(_DWORD *)off_100DF4 &= ~0x40u;
  if ( a1 == 1 )
  {
    v28 = (unsigned int *)(v13 - 728);
    v29 = off_100DFC;
    *v28 = *v28 & 0xFFFE3FFF | 0x18000;
    *v29 &= ~1u;
    *(_DWORD *)(v28 + 0x1b344) |= 0x100u;
    if ( (a5 & 4) != 0 )
    {
      if ( *((_BYTE *)v5 + 413) && *(_BYTE *)off_100DE8 )
      {
        sub_100B14(a3);
      }
      else
      {
        v30 = off_100DEC;
        v31 = off_100DF0;
        *(_DWORD *)off_100DEC |= 0x800u;
        *v31 |= 0x20u;
        *(_DWORD *)(v30 + 0x84) |= 0x1000u;
      }
      *(_DWORD *)off_100DF4 |= 0x40u;
      if ( a4 != 1 )
        goto LABEL_7;
      goto LABEL_22;
    }
  }
  else
  {
    v14 = off_100DF8;
    v15 = off_100DFC;
    *(_DWORD *)off_100DF8 = *(_DWORD *)off_100DF8 & 0xFFFE3FFF | 0xC000;
    *v15 |= 1u;
    *(_DWORD *)(v14 + 0x1b344) &= ~0x100u;
  }
  if ( a4 != 1 )
  {
LABEL_7:
    if ( a4 == 2 )
    {
      v24 = a3 - a2;
      if ( a3 - a2 <= 0 )
      {
        if ( v24 >= -10 )
          v25 = 2;
        else
          v25 = 3;
      }
      else
      {
        v25 = v24 <= 10;
      }
      v16 = ((unsigned __int8)((int)((unsigned __int64)(dword_100E14 * (__int64)(a2 - (a3 - 30))) >> 32) >> 3)
           - (unsigned __int8)((a2 - (a3 - 30)) >> 31))
          & 7;
      *(_DWORD *)off_100E00 = v25;
    }
    else
    {
      v16 = 0;
      *(_DWORD *)off_100E00 = 0;
    }
    goto LABEL_9;
  }
LABEL_22:
  if ( a3 <= (unsigned int)a2 )
    v32 = 2;
  else
    v32 = 1;
  *(_DWORD *)off_100E00 = v32;
  v16 = a3 <= (unsigned int)a2;
LABEL_9:
  v17 = (char *)off_100E04;
  v18 = (unsigned int *)off_100E08;
  v19 = (unsigned int *)off_100E0C;
  *(_DWORD *)off_100E04 = v16 | *(_DWORD *)off_100E04 & 0xFFFFFFF8;
  v20 = (a4 << 24) & 0x3000000;
  *v18 = *v18 & 0xFCFFFFFF | v20;
  *v19 = (a4 << 16) & 0x30000 | *v19 & 0xFFFCFFFF;
  v21 = v19 + 16708;
  *(_DWORD *)&v17[-80] = *(_DWORD *)&v17[-80] & 0xFFFFFFF0 | a4 & 0xF;
  v22 = v17 - 80;
  *v21 = v20 | *v21 & 0xFCFFFFFF;
  if ( a4 )
  {
    if ( a4 == 1 )
    {
      v26 = (unsigned int *)off_100E1C;
      v27 = (unsigned int *)off_100E10;
      *(_DWORD *)off_100E18 = *(_DWORD *)off_100E18 & 0xFFFFFF | 0x18000000;
      *v26 = *v26 & 0xFFFFFFCF | 0x10;
      *v27 = *v27 & 0xFFFF00FF | 0x6C00;
    }
  }
  else
  {
    v23 = (unsigned int *)off_100E10;
    *((_DWORD *)v22 + 1) = *((_DWORD *)v22 + 1) & 0xFFFFFF | 0x19000000;
    *(_DWORD *)(v21 + 0xf7e8) &= 0xFFFFFFCF;
    *v23 = *v23 & 0xFFFF00FF | 0x9C00;
  }
}

