// sub_1234E4 @ 0x1234e4, size 480 bytes
void sub_1234E4()
{
  _BYTE *v0; // r6
  unsigned __int8 *v1; // r5
  _BYTE *v2; // r7
  __int64 v3; // r2
  unsigned __int8 v4; // r4
  int v5; // r3
  int v6; // r3
  int v7; // r7
  int v8; // r4
  int v9; // r0
  int n; // r4
  int v11; // r3
  int v12; // r6
  int v13; // r4
  int v14; // r0
  int *v15; // r2
  int v16; // r4
  int v17; // r0
  int v18; // r0
  int v19; // r3
  int v20; // r4
  int v21; // r2
  int v22; // r0
  int v23; // r4
  int v24; // r0
  unsigned __int8 v25; // [sp+Eh] [bp-6h] BYREF
  unsigned __int8 v26[5]; // [sp+Fh] [bp-5h] BYREF

  v0 = off_1236C4;
  v1 = (unsigned __int8 *)off_1236C8;
  v2 = off_1236CC;
  HIDWORD(v3) = *(unsigned __int8 *)off_1236CC;
  LODWORD(v3) = *(unsigned __int8 *)off_1236C4 | *(unsigned __int8 *)off_1236C8;
  v4 = BYTE4(v3) | v3;
  if ( !v3 )
  {
    sub_126538();
    if ( (*(_BYTE *)off_1236D0 & 0xFD) == 1 )
    {
      v25 = v4;
      v26[0] = v4;
      sub_113B88(&v25);
      rf_cmd_query_status(v26);
      msg_parse(dword_1236F0, v25, v26[0]);
      v22 = v25;
      if ( v25 )
      {
        if ( v25 > 0x1Fu )
        {
          v22 = 31;
          v25 = 31;
        }
        sub_10F170(v22);
        msg_parse(dword_1236F4, v25);
      }
      if ( v26[0] )
      {
        if ( v26[0] > 0x3Fu )
        {
          v26[0] = 63;
          v23 = 16515072;
        }
        else
        {
          v23 = (v26[0] << 18) & 0xFC0000;
        }
        v24 = dword_1236F8;
        *(_DWORD *)off_1236DC = *(_DWORD *)off_1236DC & 0xFF03FFFF | v23;
        msg_parse(v24);
      }
    }
    BYTE4(v3) = *v2;
  }
  v5 = (unsigned __int8)(BYTE4(v3) + 1);
  if ( v5 != 8 )
  {
    *v2 = v5;
    return;
  }
  v6 = (unsigned __int8)*v0;
  *v2 = 0;
  if ( !v6 )
  {
    v7 = *(_DWORD *)off_1236D4;
    if ( (*(_BYTE *)off_1236D0 & 0xFD) != 1 )
    {
      if ( (v7 & 0x1000000) != 0 )
        v8 = 1;
      else
        v8 = -1;
      v9 = mmio_bit_extract_n() + v8;
      if ( v9 < 1 )
        v9 = 1;
      if ( v9 >= 31 )
        v9 = 31;
      sub_10F170(v9);
    }
    n = mmio_bit_extract_n();
    rf_level_apply_n200((unsigned __int8)n);
    msg_parse(dword_1236D8, *v1, n, v7);
    v11 = (unsigned __int8)(*v1 + 1);
    if ( v11 != 16 )
      goto LABEL_15;
    goto LABEL_33;
  }
  if ( v6 == 1 )
  {
    v19 = *(_DWORD *)off_1236D4;
    if ( (*(_BYTE *)off_1236D0 & 0xFD) != 1 )
    {
      if ( (v19 & 0x1000000) != 0 )
        v20 = 1;
      else
        v20 = -1;
      v21 = ((*(_DWORD *)off_1236DC >> 18) & 0x3F) + v20;
      if ( v21 < 1 )
        v21 = 1;
      if ( v21 >= 63 )
        v21 = 63;
      *(_DWORD *)off_1236DC = *(_DWORD *)off_1236DC & 0xFF03FFFF | (v21 << 18);
    }
    msg_parse(dword_1236EC, *v1, (*(_DWORD *)off_1236DC >> 18) & 0x3F, v19);
    v11 = (unsigned __int8)(*v1 + 1);
    if ( v11 != 32 )
      goto LABEL_15;
LABEL_33:
    ++*v0;
    *v1 = 0;
    return;
  }
  v12 = *(_DWORD *)off_1236D4;
  if ( (*(_DWORD *)off_1236D4 & 0x1000000) != 0 )
    v13 = 0x2000000 - v12;
  else
    v13 = *(_DWORD *)off_1236D4;
  v14 = mmio_bit_extract_n();
  msg_parse(dword_1236E0, v14, (*(_DWORD *)off_1236DC >> 18) & 0x3F, v12, v13);
  v15 = (int *)off_1236E4;
  v11 = (unsigned __int8)(*v1 + 1);
  v16 = v13 + *(_DWORD *)off_1236E4;
  *(_DWORD *)off_1236E4 = v16;
  if ( v11 != 16 )
  {
LABEL_15:
    *v1 = v11;
    return;
  }
  v17 = dword_1236E8;
  *v1 = 0;
  *v15 = v16 / 16;
  v18 = msg_parse(v17);
  if ( (unsigned int)*(unsigned __int8 *)off_1236D0 - 2 <= 1 )
    rf_init_n_dc(v18);
  else
    sub_12646C(2);
}

