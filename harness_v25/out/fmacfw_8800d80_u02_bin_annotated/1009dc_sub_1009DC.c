// fwstruct annotate: 1009dc_sub_1009DC.c
// sub_1009DC @ 0x1009dc, size 184 bytes
int __fastcall sub_1009DC(int a1, int a2)
{
  unsigned int *v2; // r3
  int v3; // r7
  unsigned int *v5; // r8
  int v6; // lr
  int v7; // r12
  int v8; // r5
  int v9; // r5
  int v10; // r1
  int v11; // r3
  _DWORD *v12; // r2
  int v13; // t1
  _DWORD *v14; // r2
  int v15; // r5
  int i; // r4
  int v17; // r1
  int result; // r0

  v2 = (unsigned int *)off_100A98;
  *(_DWORD *)off_100A94 |= 0x100u;
  v3 = 0;
  *v2 &= 0xFFFCFFFF;
  v5 = v2;
  v6 = -a1;
  v7 = 0;
  v8 = 128;
  while ( 1 )
  {
    v9 = a1 + 4 * (v8 + v3);
    v10 = dword_100A9C + v6;
    v11 = -v6;
    do
    {
      v12 = (_DWORD *)(v10 + v11);
      v13 = *(_DWORD *)v11;
      v11 += 4;
      *v12 = v13;
    }
    while ( v11 != v9 );
    ++v7;
    if ( v3 == 384 )
      break;
    v3 += 128;
    v6 -= 512;
    *v5 = *v5 & 0xFFFCFFFF | (v7 << 16);
    if ( v7 == 3 )
      v8 = 48;
    else
      v8 = 128;
  }
  v14 = off_100AA0;
  *(_DWORD *)off_100A94 &= ~0x100u;
  *v14 |= 0x1000000u;
  v15 = 1;
  for ( i = 0; i != 12; ++i )
  {
    sub_10410C((2 * i) & 0xFE, *(_DWORD *)(a2 + 8 * i));
    v17 = *(_DWORD *)(a2 + 4 + 8 * i);
    result = sub_10410C(v15, v17);
    v15 = (unsigned __int8)(v15 + 2);
  }
  *(_DWORD *)off_100AA4 &= ~2u;
  return result;
}

