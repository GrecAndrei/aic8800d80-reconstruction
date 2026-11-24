// sub_114FEC @ 0x114fec, size 464 bytes
int sub_114FEC()
{
  _DWORD *v0; // r7
  int v1; // r6
  int *v2; // r5
  int i; // r4
  int v4; // r1
  int v5; // t1
  _DWORD *v6; // r5
  unsigned int v7; // r4
  int v8; // r3
  int v9; // r1
  int v10; // r1
  unsigned int CPSR; // r2
  unsigned int v12; // r3
  int result; // r0
  int v14; // r4
  int v15; // r4
  int v16; // r7
  int v17; // r6
  unsigned int v18; // r4
  unsigned int v19; // r5
  int v20; // t1
  int v21; // r8
  int v22; // r6
  unsigned int v23; // r4
  unsigned int v24; // r5
  int v25; // t1
  unsigned int v26; // [sp+0h] [bp-18h]

  v0 = off_1151BC;
  v1 = dword_1151C0;
  v2 = (int *)off_1151BC;
  for ( i = 0; i != 13; ++i )
  {
    v4 = i;
    v5 = *v2++;
    sub_10DAE4(v1, v4, v5);
  }
  v6 = off_1151C4;
  sub_10DAE4(dword_1151C8, *(_DWORD *)(v0 + 0x34), *(_DWORD *)(v0 + 0x38), *(_DWORD *)(v0 + 0x3c), *(_DWORD *)(v0 + 0x40), *(_DWORD *)(v0 + 0x44), *(_DWORD *)(v0 + 0x48));
  sub_10DAE4(dword_1151CC, *v6, *(_DWORD *)(v6 + 0x4), *(_DWORD *)(v6 + 0x8), *(_DWORD *)(v6 + 0xc));
  sub_10DAE4(dword_1151D0, *(_DWORD *)(v6 + 0x24), *(_DWORD *)(v6 + 0x28), *(_DWORD *)(v6 + 0x2c), *(_DWORD *)(v6 + 0x30), *(_DWORD *)(v6 + 0x3c));
  v7 = *(_DWORD *)(v6 + 0x28);
  if ( (_BYTE)v7 )
  {
    sub_10DAE4(
      dword_1151FC,
      (unsigned __int8)*(_DWORD *)(v6 + 0x28),
      v7 & 1,
      (v7 >> 1) & 1,
      (v7 >> 3) & 1,
      (v7 >> 4) & 1,
      (v7 >> 5) & 1,
      (v7 >> 7) & 1);
    if ( (v7 & 0x80) != 0 )
      sub_10DAE4(dword_115200, *(_DWORD *)(v6 + 0x34));
  }
  if ( (v7 & 0xFF00) != 0 )
  {
    sub_10DAE4(
      dword_1151F4,
      BYTE1(v7),
      (v7 >> 8) & 1,
      (v7 >> 9) & 1,
      (v7 >> 10) & 1,
      (v7 >> 11) & 1,
      (v7 >> 12) & 1,
      (v7 >> 13) & 1,
      (v7 >> 15) & 1);
    if ( (v7 & 0x8000) != 0 )
      sub_10DAE4(dword_1151F8, *((_DWORD *)off_1151C4 + 14));
  }
  if ( HIWORD(v7) )
    sub_10DAE4(
      dword_1151F0,
      HIWORD(v7),
      HIWORD(v7) & 1,
      (v7 >> 17) & 1,
      (v7 >> 18) & 1,
      (v7 >> 19) & 1,
      HIBYTE(v7) & 1,
      (v7 >> 25) & 1);
  if ( (*(_DWORD *)(v0 + 0x4c) & 8) == 0 )
  {
    sub_10DAE4(dword_1151E8);
    goto LABEL_9;
  }
  sub_10DAE4(dword_1151D4);
  if ( (*(_DWORD *)(v0 + 0x50) & 1) == 0 )
  {
LABEL_9:
    sub_10DAE4(dword_1151D8);
    goto LABEL_10;
  }
  sub_10DAE4(dword_1151EC);
LABEL_10:
  v8 = *(_DWORD *)(v0 + 0x4c);
  v9 = v8 << 29;
  if ( (v8 & 4) != 0 )
    sub_10DAE4(dword_1151DC, v9);
  else
    sub_10DAE4(dword_1151E0, v9);
  v10 = *(_DWORD *)(v0 + 0x50);
  CPSR = __get_CPSR();
  v12 = __get_CPSR();
  v26 = __get_CPSR();
  result = sub_10DAE4(dword_1151E4, v10, CPSR, v12, v26);
  v14 = *(_DWORD *)(v0 + 0x48);
  if ( v14 )
  {
    v21 = dword_115208;
    v22 = dword_11520C;
    v23 = v14 & 0xFFFFFFF0;
    sub_10DAE4(dword_115210);
    v24 = v23 + 256;
    do
    {
      if ( !(v23 << 28) )
        sub_10DAE4(v21, v23);
      v25 = *(_DWORD *)v23;
      v23 += 4;
      result = sub_10DAE4(v22, v25);
    }
    while ( v24 != v23 );
  }
  v15 = *(_DWORD *)(v0 + 0x44);
  if ( v15 )
  {
    v16 = dword_115208;
    v17 = dword_11520C;
    v18 = v15 & 0xFFFFFFF0;
    sub_10DAE4(dword_115204);
    v19 = v18 + 256;
    do
    {
      if ( !(v18 << 28) )
        sub_10DAE4(v16, v18);
      v20 = *(_DWORD *)v18;
      v18 += 4;
      result = sub_10DAE4(v17, v20);
    }
    while ( v19 != v18 );
  }
  return result;
}

