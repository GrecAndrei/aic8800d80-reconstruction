// sub_102A58 @ 0x102a58, size 96 bytes
int sub_102A58()
{
  _DWORD *v0; // r2
  _BYTE *v1; // r3
  int v3; // r4
  int v4; // r5
  int v5; // r6
  int v6; // r5
  int v7; // r6
  void *v8; // r4

  v0 = off_102AB8;
  v1 = off_102ABC;
  *(_DWORD *)(*((_DWORD *)off_102AB8 + 2) + 80) = dword_102AC0;
  *(_DWORD *)v1 = 16;
  v3 = dword_102AC4;
  *(_DWORD *)(v0[2] + 84) = dword_102AC4;
  *(_DWORD *)v1 = 32;
  v4 = dword_102AC8;
  *(_DWORD *)(v0[2] + 92) = v3;
  *(_DWORD *)v1 = 128;
  v5 = dword_102ACC;
  *(_DWORD *)(v0[2] + 72) = v4;
  *(_DWORD *)v1 = 4;
  v6 = dword_102AD0;
  *(_DWORD *)(v0[2] + 88) = v5;
  *(_DWORD *)v1 = 64;
  v7 = dword_102AD4;
  *(_DWORD *)(v0[2] + 76) = v6;
  v1[771] = -8;
  *(_DWORD *)v1 = 8;
  v8 = off_102AD8;
  *(_DWORD *)(v0[2] + 208) = v7;
  *((_DWORD *)v1 + 1) = 16;
  *(_DWORD *)(v0[2] + 212) = v8;
  *((_DWORD *)v1 + 1) = 32;
  __enable_irq();
  return 16;
}

