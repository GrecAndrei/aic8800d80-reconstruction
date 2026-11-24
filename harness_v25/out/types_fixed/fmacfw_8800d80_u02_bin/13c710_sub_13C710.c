// sub_13C710 @ 0x13c710, size 192 bytes
int __fastcall sub_13C710(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5; // lr
  __int64 v6; // r4
  __int64 v7; // kr00_8
  _BYTE *v8; // r8
  int v9; // r5
  unsigned int v10; // r4
  int v11; // r6
  _BYTE *v12; // r6
  _BYTE *v13; // r4
  unsigned int v14; // r0
  unsigned int v15; // r1
  int i; // r3
  int v17; // r2
  unsigned int v18; // r4

  result = *(_DWORD *)(dword_13C7D0 + 1320 * *(unsigned __int8 *)(a1 + 28) + 1204);
  if ( result )
  {
    if ( a4 )
      v5 = a4;
    else
      v5 = a3 + a2;
    *(_BYTE *)v5 = 76;
    *(_BYTE *)(v5 + 1) = 16;
    v6 = *(_QWORD *)(result + 72);
    *(_WORD *)(v5 + 2) = *(unsigned __int8 *)(result + 97);
    v7 = v6 + 1;
    *(_QWORD *)(result + 72) = v6 + 1;
    v8 = (_BYTE *)(v5 + 4);
    v9 = 0;
    while ( 1 )
    {
      v10 = ((unsigned int)v7 >> v9) | (HIDWORD(v7) << (32 - v9));
      v11 = HIDWORD(v7) >> (v9 - 32);
      v9 += 8;
      *v8++ = v10 | v11;
      if ( v9 == 48 )
        break;
      v7 = *(_QWORD *)(result + 72);
    }
    v12 = (_BYTE *)(v5 + 10);
    v13 = (_BYTE *)(v5 + 10);
    do
      *v13++ = 0;
    while ( (_BYTE *)(v5 + 18) != v13 );
    v14 = sub_13CBEC(result, a2, a3, 24, a4);
    for ( i = 0; i != 64; i += 8 )
    {
      v17 = (v14 >> i) | (v15 << (32 - i));
      v18 = v15 >> (i - 32);
      *v12++ = v17 | v18;
    }
    return 18;
  }
  return result;
}

