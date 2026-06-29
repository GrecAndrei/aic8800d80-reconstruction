// fwstruct annotate: 108080_sub_108080.c
// sub_108080 @ 0x108080, size 348 bytes
int __fastcall sub_108080(int a1, int *a2, _DWORD *a3)
{
  int v4; // r3
  __int64 v5; // kr08_8
  int v6; // r2
  int v9; // r8
  int v10; // r7
  __int64 v11; // r2
  int v12; // kr00_4
  int v13; // kr04_4
  unsigned __int64 v14; // kr18_8
  __int64 v15; // r2
  int v17; // r12
  unsigned int v18; // r1
  int v19; // r4
  __int64 v20; // kr20_8
  int v21; // r2
  int v22; // r6
  int v23; // r12
  unsigned int v24; // r4
  int v25; // r6
  int v26; // r7
  int v27; // r3

  v4 = a3[1] - 1;
  v5 = *(_QWORD *)(a1 + 36);
  v6 = *(_DWORD *)(a1 + 12);
  if ( *(_DWORD *)a1 < v4 && v6 <= 49 )
  {
    sub_12ECD0(1, dword_1081E4);
    sub_1078DC((int)a2, a3, a1);
    v6 = *(_DWORD *)(a1 + 12);
  }
  if ( *(_DWORD *)(a1 + 16) - v6 >= a3[6] )
  {
LABEL_8:
    HIDWORD(v15) = ((unsigned __int64)(dword_1081DC * (__int64)a2[1]) >> 32) - (a2[1] >> 31);
    LODWORD(v15) = ((unsigned __int64)(dword_1081DC * (__int64)*a2) >> 32) - (*a2 >> 31);
    v14 = *(_QWORD *)(a1 + 20);
    *(_QWORD *)a2 = v15;
    goto LABEL_9;
  }
  v9 = ((unsigned __int64)(dword_1081DC * (__int64)(int)v5) >> 32) - ((int)v5 >> 31);
  v10 = ((unsigned __int64)(dword_1081DC * (__int64)SHIDWORD(v5)) >> 32) - (SHIDWORD(v5) >> 31);
  if ( (int)v5 - 1 - 3 * (((unsigned __int64)(dword_1081DC * (__int64)((int)v5 - 1)) >> 32) - (((int)v5 - 1) >> 31)) == HIDWORD(v5) - 1 - 3 * (((unsigned __int64)(dword_1081DC * (__int64)(HIDWORD(v5) - 1)) >> 32) - ((HIDWORD(v5) - 1) >> 31)) )
  {
    if ( v9 != v10 )
    {
      v17 = *(_DWORD *)(a1 + 32);
      v18 = *(_DWORD *)(a1 + 20);
      v19 = ((unsigned __int64)(dword_1081DC * (__int64)(2 * *(_DWORD *)(a1 + 24))) >> 32)
          - ((2 * *(_DWORD *)(a1 + 24)) >> 31);
      v20 = dword_1081DC * (__int64)v17;
      v21 = ((unsigned __int64)(dword_1081DC * (__int64)*a2) >> 32) - (*a2 >> 31);
      a2[1] = 2 * (((unsigned __int64)(dword_1081DC * (__int64)a2[1]) >> 32) - (a2[1] >> 31));
      *a2 = v21;
      v14 = __PAIR64__(v19 + HIDWORD(v20) - (v17 >> 31), v18);
      goto LABEL_9;
    }
    goto LABEL_8;
  }
  if ( v9 == v10 )
  {
    v22 = *(_DWORD *)(a1 + 20);
    v23 = *(_DWORD *)(a1 + 28);
    v24 = *(_DWORD *)(a1 + 24);
    v25 = ((unsigned __int64)(dword_1081DC * (__int64)(2 * v22)) >> 32) - ((2 * v22) >> 31);
    v26 = ((unsigned __int64)(dword_1081DC * (__int64)v23) >> 32) - (v23 >> 31);
    v27 = ((unsigned __int64)(dword_1081DC * (__int64)a2[1]) >> 32) - (a2[1] >> 31);
    *a2 = 2 * (((unsigned __int64)(dword_1081DC * (__int64)*a2) >> 32) - (*a2 >> 31));
    a2[1] = v27;
    v14 = __PAIR64__(v24, v25 + v26);
  }
  else
  {
    LODWORD(v11) = 2 * (((unsigned __int64)(dword_1081DC * (__int64)*a2) >> 32) - (*a2 >> 31));
    HIDWORD(v11) = 2 * (((unsigned __int64)(dword_1081DC * (__int64)a2[1]) >> 32) - (a2[1] >> 31));
    v12 = *(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 28);
    v13 = *(_DWORD *)(a1 + 32) + *(_DWORD *)(a1 + 24);
    *(_QWORD *)a2 = v11;
    v14 = __PAIR64__(v13 / 2, v12 / 2);
  }
LABEL_9:
  *((_QWORD *)a2 + 1) = v14;
  return sub_12ECD0(1, dword_1081E0);
}

