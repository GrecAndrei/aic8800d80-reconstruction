// sub_10EA74 @ 0x10ea74, size 416 bytes
int  sub_10EA74(unsigned int a1, unsigned int a2, unsigned int *a3)
{
  unsigned int v3; // r4
  unsigned int *v4; // r6
  unsigned int *v5; // r5
  __int16 *v7; // r5
  int inited; // r10
  int v9; // r2
  unsigned int *v10; // r7
  unsigned int *v11; // r6
  unsigned int v12; // r11
  int v13; // r8
  int v14; // r9
  int v15; // r2
  int v16; // r0
  int v17; // r2
  int v19; // r5
  unsigned int v20; // [sp+Ch] [bp-20h]
  unsigned int v21; // [sp+10h] [bp-1Ch]
  int v22; // [sp+14h] [bp-18h]
  unsigned int v23; // [sp+18h] [bp-14h]
  unsigned int v24; // [sp+1Ch] [bp-10h]

  v4 = (unsigned int *)off_10EC14;
  v5 = (unsigned int *)off_10EC18;
  *(uint32_t *)off_10EC14 = *(uint32_t *)off_10EC14 & 0xFFFFFFF8 | a1 & 7;
  *v5 = ((uint16_t)a1 << 12) & 0x7000 | *v5 & 0xFFFF8FFF;
  *v4 = (8 * a2) & 0x78 | *v4 & 0xFFFFFF87;
  *v5 = (a2 << 15) & 0x78000 | *v5 & 0xFFF87FFF;
  v7 = (__int16 *)off_10EC1C;
  inited = rf_init_wake_n_e8();
  msg_parse(dword_10EC20, a1);
  v9 = *v7;
  if ( v9 > inited )
  {
    v22 = 1;
  }
  else
  {
    if ( v9 >= inited )
    {
      v19 = 0;
      goto LABEL_9;
    }
    v22 = -1;
  }
  v3 = a2;
  v10 = (unsigned int *)off_10EC14;
  v11 = (unsigned int *)off_10EC18;
  v20 = a1;
  v21 = a1 + a2;
  v12 = a1;
  v13 = 7;
  v19 = 0;
  while ( 1 )
  {
    v23 = v12;
    v19 += v22;
    v12 = __usat(3u, v20 + v19);
    *v10 = *v10 & 0xFFFFFFF8 | v12;
    *v11 = *v11 & 0xFFFF8FFF | (v12 << 12);
    v24 = v3;
    v3 = __usat(4u, v21 + v19 - v12);
    *v10 = *v10 & 0xFFFFFF87 | (8 * v3);
    *v11 = *v11 & 0xFFF87FFF | (v3 << 15);
    v14 = inited;
    inited = rf_init_wake_n_e8();
    msg_parse(dword_10EC24, v12);
    v15 = *(__int16 *)off_10EC1C;
    v16 = inited - v15;
    v17 = v14 - v15;
    if ( v17 * v16 <= 0 )
      break;
    if ( !--v13 )
      goto LABEL_9;
  }
  if ( v17 < 0 )
    v17 = -v17;
  if ( v16 < 0 )
    v16 = -v16;
  if ( v17 <= v16 )
  {
    v3 = v24;
    *v10 = *v10 & 0xFFFFFFF8 | v23 & 7;
    *v11 = (v23 << 12) & 0x7000 | *v11 & 0xFFFF8FFF;
    *v10 = (8 * v24) & 0x78 | *v10 & 0xFFFFFF87;
    *v11 = (v24 << 15) & 0x78000 | *v11 & 0xFFF87FFF;
  }
  msg_parse(dword_10EC28, v19);
LABEL_9:
  *a3 = v3;
  return v19;
}

