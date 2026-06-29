// fwstruct annotate: 133800_sub_133800.c
// sub_133800 @ 0x133800, size 74 bytes
_DWORD *__fastcall sub_133800(int a1, _DWORD *a2, int a3, unsigned __int16 *a4, unsigned __int8 a5)
{
  int v5; // r7
  int v6; // r5
  int v7; // r6
  int v8; // r2
  int v9; // r6
  int v10; // r4
  _DWORD *v11; // r0
  int *v12; // r1
  _DWORD *v13; // r0
  int *v14; // r1
  _DWORD *v15; // r0
  int *v16; // r1

  v5 = *a4;
  v6 = *(_DWORD *)(a4 + 1);
  v7 = *(unsigned __int16 *)(a3 + 4);
  v8 = *(_DWORD *)a3;
  *(_DWORD *)a1 = *a2;
  *(_DWORD *)(a1 + 4) = a2[1];
  *(_DWORD *)(a1 + 8) = 0;
  *(_BYTE *)(a1 + 12) = 0;
  v9 = v7 | (v5 << 16);
  if ( a5 == 255 )
    v10 = 0;
  else
    v10 = a5 & 7;
  v11 = sub_1337CC((_DWORD *)a1, (int *)(a1 + 4), v8);
  v13 = sub_1337CC(v11, v12, v9);
  v15 = sub_1337CC(v13, v14, v6);
  return sub_1337CC(v15, v16, v10);
}

