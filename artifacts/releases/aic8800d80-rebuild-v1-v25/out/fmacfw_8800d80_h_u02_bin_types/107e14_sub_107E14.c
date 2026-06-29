// sub_107E14 @ 0x107e14, size 276 bytes
int  sub_107E14(int a1, uint32_t *a2)
{
  uint32_t *v2; // r6
  unsigned int *v3; // r8
  int v4; // r7
  int v6; // r9
  int *v7; // r4
  int v8; // r11
  int v9; // r10
  int v10; // r0
  int v11; // t1
  int v12; // r1
  int v13; // r5
  unsigned int *v14; // r3
  int v15; // r2
  int v17; // [sp+8h] [bp-1Ch]
  int v18; // [sp+Ch] [bp-18h]
  int v19; // [sp+10h] [bp-14h]
  int v20; // [sp+14h] [bp-10h]
  int v21; // [sp+18h] [bp-Ch]

  v2 = off_107F28;
  v3 = (unsigned int *)off_107F3C;
  *(uint32_t *)off_107F28 |= 0x1000000u;
  v4 = 1;
  *v2 &= ~0x2000000u;
  v6 = 1000;
  sub_12EB90(1, dword_107F2C);
  v7 = (int *)(a1 + 12);
  v20 = 1;
  v21 = 1;
  v18 = 1;
  v17 = 1;
  v19 = 1;
  v8 = 1;
  v9 = 1000;
  do
  {
    while ( 1 )
    {
      v10 = v7[10];
      v11 = v7[1];
      ++v7;
      *v3 = dword_107F30 & (v10 << 16) | *v3 & 0xF000FFFF;
      *v3 = v11 & 0xFFF | *v3 & 0xFFFFF000;
      sub_100644(40);
      v12 = dword_107F34;
      *v2 |= 0x4000000u;
      v13 = *(uint32_t *)off_107F38 & 0x7FFF;
      *v2 &= ~0x4000000u;
      sub_12EB90(1, v12);
      if ( v13 >= v6 )
        break;
      v20 = v18;
      v21 = v17;
      v18 = v7[9];
      v19 = v8;
      v9 = v6;
      v17 = *v7;
      v6 = v13;
      v8 = v4;
LABEL_3:
      if ( ++v4 == 10 )
        goto LABEL_7;
    }
    if ( v13 >= v9 )
      goto LABEL_3;
    v19 = v4++;
    v21 = *v7;
    v20 = v7[9];
    v9 = v13;
  }
  while ( v4 != 10 );
LABEL_7:
  v14 = (unsigned int *)off_107F28;
  v15 = *(uint32_t *)off_107F28;
  a2[5] = v17;
  a2[6] = v18;
  a2[7] = v21;
  a2[3] = v6;
  a2[8] = v20;
  a2[9] = v8;
  a2[4] = v9;
  a2[10] = v19;
  *v14 = v15 & 0xFEFFFFFF;
  *v14 &= ~0x2000000u;
  return v19;
}

