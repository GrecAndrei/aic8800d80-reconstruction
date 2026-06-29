// sub_10E83C @ 0x10e83c, size 416 bytes
int  sub_10E83C(unsigned int a1, unsigned int a2, unsigned int *a3)
{
  unsigned int v3; // r4
  unsigned int *v4; // r6
  unsigned int *v5; // r5
  __int16 *v8; // r5
  int inited; // r10
  int v10; // r2
  unsigned int *v11; // r7
  unsigned int *v12; // r6
  unsigned int v13; // r11
  int v14; // r8
  int v15; // r9
  int v16; // r2
  int v17; // r0
  int v18; // r2
  int v20; // r5
  unsigned int v21; // [sp+Ch] [bp-20h]
  unsigned int v22; // [sp+10h] [bp-1Ch]
  int v23; // [sp+14h] [bp-18h]
  unsigned int v24; // [sp+18h] [bp-14h]
  unsigned int v25; // [sp+1Ch] [bp-10h]

  v4 = (unsigned int *)off_10E9DC;
  v5 = (unsigned int *)off_10E9E0;
  *(uint32_t *)off_10E9DC = *(uint32_t *)off_10E9DC & 0xFFFFFFF8 | a1 & 7;
  *v5 = ((uint16_t)a1 << 12) & 0x7000 | *v5 & 0xFFFF8FFF;
  *v4 = (8 * a2) & 0x78 | *v4 & 0xFFFFFF87;
  *v5 = (a2 << 15) & 0x78000 | *v5 & 0xFFF87FFF;
  v8 = (__int16 *)off_10E9E4;
  inited = phy_init_n_3ac();
  msg_parse(dword_10E9E8, a1, a2);
  v10 = *v8;
  if ( v10 > inited )
  {
    v23 = 1;
  }
  else
  {
    if ( v10 >= inited )
    {
      v20 = 0;
      goto LABEL_9;
    }
    v23 = -1;
  }
  v3 = a2;
  v11 = (unsigned int *)off_10E9DC;
  v12 = (unsigned int *)off_10E9E0;
  v21 = a1;
  v22 = a1 + a2;
  v13 = a1;
  v14 = 7;
  v20 = 0;
  while ( 1 )
  {
    v24 = v13;
    v20 += v23;
    v13 = __usat(3u, v21 + v20);
    *v11 = *v11 & 0xFFFFFFF8 | v13;
    *v12 = *v12 & 0xFFFF8FFF | (v13 << 12);
    v25 = v3;
    v3 = __usat(4u, v22 + v20 - v13);
    *v11 = *v11 & 0xFFFFFF87 | (8 * v3);
    *v12 = *v12 & 0xFFF87FFF | (v3 << 15);
    v15 = inited;
    inited = phy_init_n_3ac();
    msg_parse(dword_10E9EC, v13, v3);
    v16 = *(__int16 *)off_10E9E4;
    v17 = inited - v16;
    v18 = v15 - v16;
    if ( v18 * v17 <= 0 )
      break;
    if ( !--v14 )
      goto LABEL_9;
  }
  if ( v18 < 0 )
    v18 = -v18;
  if ( v17 < 0 )
    v17 = -v17;
  if ( v18 <= v17 )
  {
    v3 = v25;
    *v11 = *v11 & 0xFFFFFFF8 | v24 & 7;
    *v12 = (v24 << 12) & 0x7000 | *v12 & 0xFFFF8FFF;
    *v11 = (8 * v25) & 0x78 | *v11 & 0xFFFFFF87;
    v13 = v24;
    *v12 = (v25 << 15) & 0x78000 | *v12 & 0xFFF87FFF;
  }
  msg_parse(dword_10E9F0, v20, v13 - v21);
LABEL_9:
  *a3 = v3;
  return v20;
}

