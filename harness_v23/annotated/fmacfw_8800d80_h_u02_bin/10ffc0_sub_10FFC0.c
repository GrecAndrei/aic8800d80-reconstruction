// v23 annotated: sub_10FFC0 @ 0x10ffc0
// Original: 10ffc0_sub_10FFC0.c
// Primary struct: <unclustered>
//
// sub_10FFC0 @ 0x10ffc0, size 122 bytes
int sub_10FFC0()
{
  void *v0; // r4
  int v1; // r3
  _DWORD *v2; // r0
  __int16 v3; // r2
  __int16 v4; // r1
  __int64 v5; // kr00_8
  _WORD v7[2]; // [sp+4h] [bp-14h] BYREF
  _WORD v8[8]; // [sp+8h] [bp-10h] BYREF

  v0 = off_11003C;
  v1 = *(_DWORD *)off_11003C;
  v2 = off_110044;
  v3 = *((_WORD *)off_110040 + 153);
  v4 = *((_WORD *)off_110040 + 154) - 4;
  v7[1] = *(_WORD *)(*(_DWORD *)off_11003C + 2);
  v8[1] = *(_WORD *)(v1 + 4);
  v8[5] = *(_WORD *)(v1 + 6);
  v8[7] = *(_WORD *)(v1 + 8);
  v5 = *(_QWORD *)(v1 + 20);
  *(_DWORD *)off_110044 = v5;
  v2[3] = dword_110048;
  v2[1] = HIDWORD(v5);
  *((_BYTE *)v2 + 8) = 1;
  v8[2] = v4;
  v8[6] = v3 - 4;
  v7[0] = 12;
  v8[4] = 1596;
  v8[0] = 124;
  v8[3] = 0;
  sub_10F7E4(v2, (int)v7, 0x20u);
  return sub_10FE2C((int)v8, *(_DWORD *)(*(_DWORD *)v0 + 28), *(_DWORD *)(*(_DWORD *)v0 + 32));
}

