// fwstruct annotate: 102e84_sub_102E84.c
// sub_102E84 @ 0x102e84, size 334 bytes
int __fastcall sub_102E84(int a1, int a2, int a3)
{
  _DWORD *v3; // r3
  _DWORD *v4; // r5
  unsigned int *v5; // r4
  int v6; // r6
  int v7; // r3
  int v8; // r5
  int v9; // r4
  int result; // r0
  int *v11; // r1
  unsigned int *v12; // r1
  int v13; // r3
  int v14; // r4
  int v15; // r3
  unsigned int *v16; // r1

  if ( !a3 )
  {
    v12 = (unsigned int *)off_102FDC;
    *((_DWORD *)off_102FD8 + 13) = 31;
    *v12 = *v12 & 0xF1FFFFFF | 0x8000000;
    if ( !a1 )
    {
      v6 = 0;
      goto LABEL_17;
    }
    if ( (*(_DWORD *)off_102FF0 & 0x8000000) != 0 )
    {
      v13 = 1 - ((*(_DWORD *)off_102FF4 >> 10) & 1);
      goto LABEL_11;
    }
LABEL_20:
    v14 = a3;
    goto LABEL_21;
  }
  if ( a3 == 1 )
  {
    v16 = (unsigned int *)off_102FDC;
    *((_DWORD *)off_102FD8 + 13) = 29;
    *v16 = *v16 & 0xF1FFFFFF | 0x4000000;
    if ( !a1 )
    {
      v7 = dword_103000;
      v6 = 1;
      v8 = 770048;
      v9 = 12;
      goto LABEL_6;
    }
    if ( (*(_DWORD *)off_102FF0 & 0x8000000) == 0 || (*(_DWORD *)off_102FF4 & 0x400) != 0 )
    {
      v8 = 409600;
      v15 = *((_DWORD *)off_103008 + 3);
      v14 = 1;
    }
    else
    {
      v14 = 1;
      v15 = *((_DWORD *)off_102FF8 + 3);
      v8 = 409600;
    }
LABEL_13:
    lmac_sub_init(0, 32, 0x10u, v15);
    result = msg_parse(dword_102FFC, v14);
    v9 = 12;
    goto LABEL_7;
  }
  v3 = off_102FD4;
  v4 = off_102FD8;
  v5 = (unsigned int *)off_102FDC;
  *(_DWORD *)off_102FD4 |= 1u;
  *v3 |= 2u;
  v4[13] = 25;
  *v5 = *v5 & 0xF1FFFFFF | 0x2000000;
  if ( a1 )
  {
    if ( (*(_DWORD *)off_102FF0 & 0x8000000) != 0 )
    {
      v13 = 1 - ((*(_DWORD *)off_102FF4 >> 10) & 1);
      if ( a3 == 2 )
      {
        if ( v13 )
        {
          v14 = 2;
          v15 = *((_DWORD *)off_102FF8 + 4);
          v8 = 819200;
          goto LABEL_13;
        }
LABEL_29:
        v8 = 819200;
        v15 = *((_DWORD *)off_103008 + 4);
        v14 = 2;
        goto LABEL_13;
      }
LABEL_11:
      v14 = a3;
      if ( v13 )
      {
        v15 = *((_DWORD *)off_102FF8 + 2);
        v8 = 204800;
        goto LABEL_13;
      }
LABEL_21:
      v8 = 204800;
      v15 = *((_DWORD *)off_103008 + 2);
      goto LABEL_13;
    }
    if ( a3 == 2 )
      goto LABEL_29;
    goto LABEL_20;
  }
  v6 = a3;
  if ( a3 != 2 )
  {
LABEL_17:
    v7 = dword_103004;
    v8 = 385024;
    v9 = 12;
    goto LABEL_6;
  }
  v7 = dword_102FE0;
  v8 = 1540096;
  v9 = 17;
LABEL_6:
  lmac_sub_init(0, 0, 0x10u, v7);
  result = msg_parse(dword_102FE4, v6);
LABEL_7:
  v11 = (int *)off_102FEC;
  *(_DWORD *)off_102FE8 = *(_DWORD *)off_102FE8 & 0xFFC01FFF | v8;
  *v11 = v9;
  return result;
}

