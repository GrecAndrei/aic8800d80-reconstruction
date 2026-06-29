// fwstruct annotate: 141dd0_sub_141DD0.c
// sub_141DD0 @ 0x141dd0, size 102 bytes
int __fastcall sub_141DD0(int a1)
{
  int v1; // r2
  int v3; // r3
  __int64 v4; // r0
  int v5; // r5
  _BYTE *v6; // r2
  int v7; // r3
  __int16 v8; // r1
  int result; // r0
  int v10; // r1

  v1 = *(_DWORD *)(a1 + 12);
  v3 = *((_DWORD *)off_141E38 + 4) + 100;
  v4 = *(_QWORD *)(a1 + 24) + *(unsigned int *)(a1 + 16);
  *(_DWORD *)(a1 + 56) = dword_141E3C;
  *(_QWORD *)(a1 + 24) = v4;
  v5 = *(unsigned __int8 *)(a1 + 47);
  sub_124D3C(a1 + 52, v3 + v1);
  v6 = off_141E44;
  v7 = dword_141E40 + 1320 * v5;
  v8 = *(_WORD *)a1 | 8;
  result = *(_DWORD *)(v7 + 4) | 0x100;
  *(_DWORD *)(v7 + 4) = result;
  *(_WORD *)a1 = v8;
  v10 = *(unsigned __int8 *)(a1 + 4);
  ++v6[1];
  if ( !v10 )
  {
    result = *(unsigned __int8 *)(a1 + 47);
    v6[2] |= 1 << result;
  }
  return result;
}

