// sub_131184 @ 0x131184, size 170 bytes
// Doc: sub_1231184 [unknown]: Wrapper that calls helper 0x12de90 with stack-based out param, checks r0==0
// sub_1231184 [unknown]: Wrapper that calls helper 0x12de90 with stack-based out param, checks r0==0
int __fastcall sub_131184(unsigned __int8 *a1, int a2, int a3)
{
  unsigned __int8 *v4; // r0
  unsigned int v5; // r6
  unsigned __int8 *v6; // r4
  int v7; // r3
  int v8; // r1
  __int16 v9; // r3
  int v10; // r2
  unsigned __int8 *v11; // r3
  unsigned __int8 *v12; // r1
  __int16 v13; // r4
  __int16 v14; // r0
  __int16 v15; // r1
  __int16 v16; // r3
  _BYTE *(_DWORD *)(v18 + 0x14); // [sp+7h] [bp-5h] BYREF

  v4 = sdio_buffer_prepare_n_28c(a1, a2, v18);
  if ( !v4 )
    return 0;
  v5 = (unsigned int)&v4[*(_DWORD *)(v18 + 0x0) + 3];
  v6 = &v4[4 - a3];
  v7 = a3 - 1;
  do
  {
    *(_BYTE *)(v7 + 1) = v6[v7];
    ++v7;
  }
  while ( v7 != a3 + 5 );
  do
  {
    *(_BYTE *)(v7 + 1) = v6[v7];
    ++v7;
  }
  while ( v7 != a3 + 16 );
  v8 = *(unsigned __int8 *)(a3 + 6);
  v9 = *(_DWORD *)(v4 + 0x58) | (*(_DWORD *)(v4 + 0x5c) << 8);
  *(_WORD *)(a3 + 18) = *(_DWORD *)(v4 + 0x50) | (*(_DWORD *)(v4 + 0x54) << 8);
  v10 = v8 >> 1;
  *(_WORD *)(a3 + 20) = v9;
  v11 = v4 + 24;
  if ( (v8 & 8) != 0 )
  {
    v12 = v4 + 28;
    if ( (unsigned int)(v4 + 28) <= v5 )
    {
      v13 = *(_DWORD *)(v4 + 0x60) | (*(_DWORD *)(v4 + 0x64) << 8);
      v14 = *(_DWORD *)(v4 + 0x68) | (*(_DWORD *)(v4 + 0x6c) << 8);
      *(_WORD *)(a3 + 22) = v13;
      v11 = v12;
      *(_WORD *)(a3 + 24) = v14;
      goto LABEL_8;
    }
    return 0;
  }
LABEL_8:
  if ( (v10 & 8) != 0 )
  {
    if ( (unsigned int)(v11 + 4) <= v5 )
    {
      v15 = *v11 | (*(_DWORD *)(v11 + 0x4) << 8);
      v16 = *(_DWORD *)(v11 + 0x8) | (*(_DWORD *)(v11 + 0xc) << 8);
      *(_WORD *)(a3 + 26) = v15;
      *(_WORD *)(a3 + 28) = v16;
      return 1;
    }
    return 0;
  }
  return 1;
}

