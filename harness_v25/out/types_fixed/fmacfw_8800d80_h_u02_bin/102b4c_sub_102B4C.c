// sub_102B4C @ 0x102b4c, size 132 bytes
int sub_102B4C()
{
  _DWORD *v0; // r2
  _BYTE *v1; // r3
  int v2; // r1
  void *v3; // r0
  void *v4; // r4
  int v5; // r0
  int v6; // r1
  unsigned __int8 *v7; // r2
  int v8; // r2
  _DWORD *v9; // r2
  _DWORD *v10; // r3

  v0 = off_102BD0;
  v1 = off_102BD4;
  *(_DWORD *)(*((_DWORD *)off_102BD0 + 2) + 80) = dword_102BD8;
  *(_DWORD *)v1 = 16;
  v2 = dword_102BDC;
  *(_DWORD *)(*(_DWORD *)(v0 + 0x8) + 84) = dword_102BDC;
  *(_DWORD *)v1 = 32;
  v3 = off_102BE0;
  *(_DWORD *)(*(_DWORD *)(v0 + 0x8) + 92) = v2;
  *(_DWORD *)v1 = 128;
  v4 = off_102BE4;
  *(_DWORD *)(*(_DWORD *)(v0 + 0x8) + 72) = v3;
  *(_DWORD *)v1 = 4;
  v5 = dword_102BE8;
  *(_DWORD *)(*(_DWORD *)(v0 + 0x8) + 88) = v4;
  *(_DWORD *)v1 = 64;
  v6 = *(_DWORD *)(v0 + 0x8);
  v7 = (unsigned __int8 *)off_102BEC;
  *(_DWORD *)(v6 + 76) = v5;
  v8 = *(_DWORD *)(v7 + 0x674);
  *(_DWORD *)(v1 + 0xc0c) = -8;
  *(_DWORD *)v1 = 8;
  if ( v8 )
    *(_DWORD *)v1 = 512;
  v9 = off_102BD0;
  v10 = off_102BD4;
  *(_DWORD *)(*((_DWORD *)off_102BD0 + 2) + 208) = off_102BF0;
  *(_DWORD *)(v10 + 0x4) = 16;
  *(_DWORD *)(*(_DWORD *)(v9 + 0x8) + 212) = off_102BF4;
  *(_DWORD *)(v10 + 0x4) = 32;
  *v10 = 0x800000;
  *(_DWORD *)(v10 + 0x4) = 64;
  __enable_irq();
  return 32;
}

