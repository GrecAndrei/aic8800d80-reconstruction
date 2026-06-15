// v23 annotated: sub_1160C8 @ 0x1160c8
// Original: 1160c8_sub_1160C8.c
// Primary struct: <unclustered>
//
// sub_1160C8 @ 0x1160c8, size 166 bytes
int __fastcall sub_1160C8(int result, int a2)
{
  int v2; // r3
  int v3; // r8
  int v4; // r12
  _DWORD *v5; // r7
  int v6; // lr
  int v7; // r6
  int v8; // r4
  int v9; // r2
  int v10; // r6
  int v11; // r2
  int v12; // r1

  v2 = *(_DWORD *)(result + 72);
  v3 = *(unsigned __int8 *)(result + 50);
  v4 = *(_DWORD *)(v2 + 40);
  v5 = *(_DWORD **)(result + 76);
  v6 = *(unsigned __int8 *)(v2 + 36);
  v7 = v2 - *(unsigned __int8 *)(result + 66) + 172;
  v8 = v3 + v2 + 172 - *(unsigned __int8 *)(result + 51);
  v9 = *(unsigned __int8 *)(result + 53) + *(unsigned __int16 *)(result + 4) - 1 + v2 + 172;
  *(_DWORD *)(v2 + 40) = v4 & 0xFFFFFFFD;
  if ( v3 )
  {
    v5[7] = v7;
    v5[8] = v3 + v7 - 1;
  }
  v10 = v5[17];
  *(_DWORD *)(v2 + 24) = v8;
  *(_DWORD *)(v2 + 28) = v9;
  *(_DWORD *)(v2 + 20) = 0;
  v5[6] = v2 + 16;
  *(_DWORD *)(v2 + 32) = 0;
  v5[17] = v10 | 0x100;
  if ( (v4 & 1) == 0 )
  {
    v11 = *(_DWORD *)(result + 36);
    result = v11 & 0x380000;
    if ( (v11 & 0x380000) == 0x380000 || (v11 & 0x200000) == 0 )
    {
      v12 = dword_116170 + 36 * (a2 + v6);
      result = *(unsigned __int8 *)(v12 + 32);
      *(_DWORD *)(v2 + 40) = v4 & 0xFFFFFFFC | 1;
      *(_BYTE *)(v12 + 32) = result + 1;
      v5[17] = v10 | 0x100;
    }
  }
  *(_DWORD *)(v2 + 20) = 0;
  return result;
}

