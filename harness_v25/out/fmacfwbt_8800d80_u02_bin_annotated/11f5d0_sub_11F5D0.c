// fwstruct annotate: 11f5d0_sub_11F5D0.c
// sub_11F5D0 @ 0x11f5d0, size 258 bytes
int __fastcall sub_11F5D0(int a1, unsigned __int8 a2)
{
  int v2; // r4
  int v3; // r8
  unsigned __int8 *v4; // r7
  int *v5; // r6
  int v7; // r9
  int *v8; // r0
  int v9; // r0
  int *v10; // r2
  int v11; // r3
  int result; // r0
  __int64 v13; // kr00_8
  int v14; // r1
  int v15; // r2
  int v16; // r0
  int v17; // r1
  int v18; // r3

  v2 = *(unsigned __int8 *)(a1 + 1);
  v3 = dword_11F6EC;
  v4 = (unsigned __int8 *)(dword_11F6EC + 696 * v2);
  v4[162] = a2;
  v4[160] = *(_BYTE *)(a1 + 40);
  v4[161] = *(_BYTE *)a1;
  v5 = (int *)(696 * v2 + 64 + v3);
  v7 = v4[34];
  v8 = sub_100200(v5, 0, 0x48u);
  switch ( v4[160] )
  {
    case 0u:
    case 3u:
      v9 = sub_143A18(v8);
      v10 = (int *)(v3 + 696 * v2 + 136);
      *v10 = v9 & 0xFFFFFF;
      v10[1] = 0;
      break;
    case 1u:
      v18 = v3 + 696 * v2;
      *(_DWORD *)(v18 + 144) = *(_DWORD *)(a1 + 24);
      *(_DWORD *)(v18 + 148) = *(_DWORD *)(a1 + 28);
      *(_DWORD *)(v18 + 152) = *(_DWORD *)(a1 + 32);
      *(_DWORD *)(v18 + 156) = *(_DWORD *)(a1 + 36);
      *(_QWORD *)(v18 + 136) = 0;
      break;
    case 4u:
      v16 = *(unsigned __int8 *)(dword_11F6E8 + 1320 * v7 + 106);
      v17 = v3 + 696 * v2;
      *(_QWORD *)(v17 + 136) = *(_QWORD *)&dword_11F6D8;
      if ( v16 == 2 )
        *(_QWORD *)(v17 + 136) = *(_QWORD *)&dword_11F6E0;
      break;
    default:
      *(_QWORD *)(v3 + 696 * v2 + 136) = 0;
      break;
  }
  v11 = v3 + 696 * v2;
  v13 = *(_QWORD *)(a1 + 8);
  result = *(_DWORD *)(a1 + 12);
  v14 = *(_DWORD *)(a1 + 16);
  *(_BYTE *)(v11 + 163) = 1;
  v15 = *(_DWORD *)(a1 + 20);
  *(_DWORD *)(v11 + 184) = v5;
  *(_QWORD *)(v11 + 164) = v13;
  *(_DWORD *)(v11 + 172) = v14;
  *(_DWORD *)(v11 + 176) = v15;
  *(_BYTE *)(v11 + 180) = *(_BYTE *)(a1 + 4);
  return result;
}

