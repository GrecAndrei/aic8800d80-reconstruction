// sub_11BC48 @ 0x11bc48, size 312 bytes
int sub_11BC48()
{
  int *v0; // r4
  int v1; // r3
  int v2; // lr
  int v3; // r8
  int *v4; // r3
  int v5; // r3
  uint32_t *v6; // r5
  int v7; // r6
  int v8; // r3
  int v9; // r0
  int v10; // r3
  unsigned int v11; // r3

  v0 = (int *)off_11BD80;
  sub_100200((int *)off_11BD84, 0, 0xD4u);
  sub_100200(v0, 0, 0x4C8u);
  v1 = dword_11BD88;
  v0[272] = dword_11BD8C;
  *((uint16_t *)v0 + 34) = 456;
  *((uint16_t *)v0 + 494) = -32312;
  v2 = dword_11BD9C;
  *((uint16_t *)v0 + 506) = -208;
  v0[234] = (int)(v0 + 247);
  v0[235] = (int)v0 + 1021;
  v0[236] = 34;
  v0[230] = v1;
  v0[255] = v1;
  *v0 = v1;
  v3 = v1;
  v0[14] = 0x200000;
  v0[239] = (int)(v0 + 272);
  v0[264] = (int)(v0 + 272);
  v0[9] = (int)(v0 + 272);
  v0[233] = 0;
  v0[243] = 0;
  v0[268] = 0;
  v4 = v0 + 45;
  do
  {
    *(v4 - 22) = v3;
    *(v4 - 16) = 30;
    *(v4 - 9) = 0;
    *(v4 - 5) = v2;
    *(v4 - 19) = (int)(v4 - 5);
    *(v4 - 2) = (int)v4 + 1;
    *(v4 - 18) = (int)(v0 + 17);
    *(v4 - 17) = (int)v0 + 91;
    *(v4 - 3) = (int)v4;
    v4 += 23;
  }
  while ( v0 + 252 != v4 );
  v5 = dword_11BD90;
  v6 = off_11BD84;
  v0[298] = 0;
  v7 = v5 + 15;
  v0[295] = 0;
  v0[296] = 0;
  v0[297] = 0;
  v0[293] = 0;
  v0[288] = 0;
  v0[289] = v5;
  v8 = dword_11BD94;
  v0[291] = 20;
  v0[299] = v8;
  v0[294] = (int)(v0 + 272);
  v0[285] = v3;
  v0[290] = v7;
  v6[43] = 467;
  *((uint16_t *)v0 + 604) = 164;
  v9 = sub_10198C();
  v10 = *(uint32_t *)off_11BD98 & 0xFFFFFFF;
  if ( v9 )
    v11 = v10 | 0xB0000000;
  else
    v11 = v10 | 0x90000000;
  *(uint32_t *)off_11BD98 = v11;
  v6[7] = 0;
  v6[14] = 1;
  v6[21] = 2;
  v6[28] = 3;
  return 0;
}

