// sub_11BD88 @ 0x11bd88, size 312 bytes
int sub_11BD88()
{
  int *v0; // r4
  int v1; // r3
  int v2; // lr
  int v3; // r8
  int *v4; // r3
  int v5; // r3
  _DWORD *v6; // r5
  int v7; // r6
  int v8; // r3
  int bit1a; // r0
  int v10; // r3
  unsigned int v11; // r3

  v0 = (int *)off_11BEC0;
  memset_thunk((int *)off_11BEC4, 0, 0xD4u);
  memset_thunk(v0, 0, 0x4C8u);
  v1 = dword_11BEC8;
  *(_DWORD *)(v0 + 0x440) = dword_11BECC;
  *((_WORD *)v0 + 34) = 456;
  *((_WORD *)v0 + 494) = -32312;
  v2 = dword_11BEDC;
  *((_WORD *)v0 + 506) = -208;
  *(_DWORD *)(v0 + 0x3a8) = (int)(v0 + 247);
  *(_DWORD *)(v0 + 0x3ac) = (int)v0 + 1021;
  *(_DWORD *)(v0 + 0x3b0) = 34;
  *(_DWORD *)(v0 + 0x398) = v1;
  *(_DWORD *)(v0 + 0x3fc) = v1;
  *v0 = v1;
  v3 = v1;
  *(_DWORD *)(v0 + 0x38) = 0x200000;
  *(_DWORD *)(v0 + 0x3bc) = (int)(v0 + 272);
  *(_DWORD *)(v0 + 0x420) = (int)(v0 + 272);
  *(_DWORD *)(v0 + 0x24) = (int)(v0 + 272);
  *(_DWORD *)(v0 + 0x3a4) = 0;
  *(_DWORD *)(v0 + 0x3cc) = 0;
  *(_DWORD *)(v0 + 0x430) = 0;
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
  v5 = dword_11BED0;
  v6 = off_11BEC4;
  *(_DWORD *)(v0 + 0x4a8) = 0;
  v7 = v5 + 15;
  *(_DWORD *)(v0 + 0x49c) = 0;
  *(_DWORD *)(v0 + 0x4a0) = 0;
  *(_DWORD *)(v0 + 0x4a4) = 0;
  *(_DWORD *)(v0 + 0x494) = 0;
  *(_DWORD *)(v0 + 0x480) = 0;
  *(_DWORD *)(v0 + 0x484) = v5;
  v8 = dword_11BED4;
  *(_DWORD *)(v0 + 0x48c) = 20;
  *(_DWORD *)(v0 + 0x4ac) = v8;
  *(_DWORD *)(v0 + 0x498) = (int)(v0 + 272);
  *(_DWORD *)(v0 + 0x474) = v3;
  *(_DWORD *)(v0 + 0x488) = v7;
  *(_DWORD *)(v6 + 0xac) = 467;
  *((_WORD *)v0 + 604) = 164;
  bit1a = mmio_flag_get_bit1a();
  v10 = *(_DWORD *)off_11BED8 & 0xFFFFFFF;
  if ( bit1a )
    v11 = v10 | 0xB0000000;
  else
    v11 = v10 | 0x90000000;
  *(_DWORD *)off_11BED8 = v11;
  *(_DWORD *)(v6 + 0x1c) = 0;
  *(_DWORD *)(v6 + 0x38) = 1;
  *(_DWORD *)(v6 + 0x54) = 2;
  *(_DWORD *)(v6 + 0x70) = 3;
  return 0;
}

