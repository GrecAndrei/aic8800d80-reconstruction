// v23 annotated: sub_102A74 @ 0x102a74
// Original: 102a74_sub_102A74.c
// Primary struct: <unclustered>
//
// sub_102A74 @ 0x102a74, size 104 bytes
int sub_102A74()
{
  _DWORD *v0; // r2
  _BYTE *v1; // r3
  int v2; // r1
  int v4; // r6
  void *v5; // r5
  int v6; // r6
  void *v7; // r7
  void *v8; // r5

  v0 = off_102ADC;
  v1 = off_102AE0;
  *(_DWORD *)(*((_DWORD *)off_102ADC + 2) + 80) = dword_102AE4;
  *(_DWORD *)v1 = 16;
  v2 = dword_102AE8;
  *(_DWORD *)(v0[2] + 84) = dword_102AE8;
  *(_DWORD *)v1 = 32;
  v4 = dword_102AEC;
  *(_DWORD *)(v0[2] + 92) = v2;
  *(_DWORD *)v1 = 128;
  v5 = off_102AF0;
  *(_DWORD *)(v0[2] + 72) = v4;
  *(_DWORD *)v1 = 4;
  v6 = dword_102AF4;
  *(_DWORD *)(v0[2] + 88) = v5;
  *(_DWORD *)v1 = 64;
  v7 = off_102AF8;
  *(_DWORD *)(v0[2] + 76) = v6;
  v1[771] = -8;
  *(_DWORD *)v1 = 8;
  v8 = off_102AFC;
  *(_DWORD *)(v0[2] + 208) = v7;
  *((_DWORD *)v1 + 1) = 16;
  *(_DWORD *)(v0[2] + 212) = v8;
  *((_DWORD *)v1 + 1) = 32;
  *(_DWORD *)v1 = 0x800000;
  *((_DWORD *)v1 + 1) = 64;
  __enable_irq();
  return 32;
}

