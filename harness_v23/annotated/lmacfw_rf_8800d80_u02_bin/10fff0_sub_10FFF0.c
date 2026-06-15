// v23 annotated: sub_10FFF0 @ 0x10fff0
// Original: 10fff0_sub_10FFF0.c
// Primary struct: <unclustered>
//
// sub_10FFF0 @ 0x10fff0, size 122 bytes
// Doc: log_free_pool_dispatch2_n460 [util]: Dispatch log entry into free pool with metadata fields
// log_free_pool_dispatch2_n460 [util]: Dispatch log entry into free pool with metadata fields
int sub_10FFF0()
{
  void *v0; // r4
  int v1; // r3
  _DWORD *v2; // r0
  __int16 v3; // r2
  __int16 v4; // r1
  __int64 v5; // kr00_8
  _WORD v7[2]; // [sp+4h] [bp-14h] BYREF
  _WORD v8[8]; // [sp+8h] [bp-10h] BYREF

  v0 = log_free_pool_dispatch2_n49c;
  v1 = *(_DWORD *)log_free_pool_dispatch2_n49c;
  v2 = off_110074;
  v3 = *((_WORD *)off_110070 + 153);
  v4 = *((_WORD *)off_110070 + 154) - 4;
  v7[1] = *(_WORD *)(*(_DWORD *)log_free_pool_dispatch2_n49c + 2);
  v8[1] = *(_WORD *)(v1 + 4);
  v8[5] = *(_WORD *)(v1 + 6);
  v8[7] = *(_WORD *)(v1 + 8);
  v5 = *(_QWORD *)(v1 + 20);
  *(_DWORD *)off_110074 = v5;
  v2[3] = dword_110078;
  v2[1] = HIDWORD(v5);
  *((_BYTE *)v2 + 8) = 1;
  v8[2] = v4;
  v8[6] = v3 - 4;
  v7[0] = 12;
  v8[4] = 1596;
  v8[0] = 124;
  v8[3] = 0;
  sub_10F814(v2, (int)v7, 0x20u);
  return rf_init_setup_n3ac((int)v8, *(_DWORD *)(*(_DWORD *)v0 + 28), *(_DWORD *)(*(_DWORD *)v0 + 32));
}

