// sub_12141C @ 0x12141c, size 112 bytes
int __fastcall sub_12141C(int a1, int *a2, __int16 a3, __int16 a4)
{
  int *v5; // r5
  int v6; // r2
  int v7; // r0
  int v8; // r3
  int v9; // r1

  v5 = (int *)rf_setup_dispatch(1042, a4, a3, 8u);
  if ( (((unsigned int)*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
  {
    sub_10F064(*a2, *(_DWORD *)(a2 + 0x8), *(_DWORD *)(a2 + 0x4), 1);
    v7 = sub_10EFBC(*a2, 1);
    v6 = *a2;
  }
  else
  {
    *(_DWORD *)*a2 ^= (*(_DWORD *)(a2 + 0x8) ^ *(_DWORD *)*a2) & *(_DWORD *)(a2 + 0x4);
    v6 = *a2;
    v7 = *(_DWORD *)*a2;
  }
  *(_DWORD *)(v5 + 0x4) = v7;
  v8 = *(_DWORD *)(a2 + 0x8);
  v9 = *(_DWORD *)(a2 + 0x4);
  *v5 = v6;
  msg_parse(dword_12148C, v9, v8, v8, v6, v7, v7);
  sub_11DE50((int)v5);
  return 0;
}

