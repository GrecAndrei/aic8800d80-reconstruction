// sub_107A70 @ 0x107a70, size 348 bytes
int __fastcall sub_107A70(int a1, int *a2, _DWORD *a3)
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
  int v16; // r12
  unsigned int v17; // r1
  int v18; // r4
  __int64 v19; // kr20_8
  int v20; // r6
  int v21; // r12
  unsigned int v22; // r4
  int v23; // r6
  int v24; // r7

  v4 = a3[1] - 1;
  v5 = *(_QWORD *)(a1 + 36);
  v6 = *(_DWORD *)(a1 + 12);
  if ( *(_DWORD *)a1 < v4 && v6 <= 49 )
  {
    sub_11F74C(1, dword_107BD4, v6, v4);
    sub_1072CC((int)a2, a3, a1);
    v6 = *(_DWORD *)(a1 + 12);
  }
  if ( *(_DWORD *)(a1 + 16) - v6 >= a3[6] )
  {
LABEL_8:
    HIDWORD(v11) = ((unsigned __int64)(dword_107BCC * (__int64)a2[1]) >> 32) - (a2[1] >> 31);
    LODWORD(v11) = ((unsigned __int64)(dword_107BCC * (__int64)*a2) >> 32) - (*a2 >> 31);
    v14 = *(_QWORD *)(a1 + 20);
    *(_QWORD *)a2 = v11;
    goto LABEL_9;
  }
  v9 = ((unsigned __int64)(dword_107BCC * (__int64)(int)v5) >> 32) - ((int)v5 >> 31);
  v10 = ((unsigned __int64)(dword_107BCC * (__int64)SHIDWORD(v5)) >> 32) - (SHIDWORD(v5) >> 31);
  if ( (int)v5 - 1 - 3 * (((unsigned __int64)(dword_107BCC * (__int64)((int)v5 - 1)) >> 32) - (((int)v5 - 1) >> 31)) == HIDWORD(v5) - 1 - 3 * (((unsigned __int64)(dword_107BCC * (__int64)(HIDWORD(v5) - 1)) >> 32) - ((HIDWORD(v5) - 1) >> 31)) )
  {
    if ( v9 != v10 )
    {
      v16 = *(_DWORD *)(a1 + 32);
      v17 = *(_DWORD *)(a1 + 20);
      v18 = ((unsigned __int64)(dword_107BCC * (__int64)(2 * *(_DWORD *)(a1 + 24))) >> 32)
          - ((2 * *(_DWORD *)(a1 + 24)) >> 31);
      v19 = dword_107BCC * (__int64)v16;
      HIDWORD(v11) = 2 * (((unsigned __int64)(dword_107BCC * (__int64)a2[1]) >> 32) - (a2[1] >> 31));
      LODWORD(v11) = ((unsigned __int64)(dword_107BCC * (__int64)*a2) >> 32) - (*a2 >> 31);
      *(_QWORD *)a2 = v11;
      v14 = __PAIR64__(v18 + HIDWORD(v19) - (v16 >> 31), v17);
      goto LABEL_9;
    }
    goto LABEL_8;
  }
  if ( v9 == v10 )
  {
    v20 = *(_DWORD *)(a1 + 20);
    v21 = *(_DWORD *)(a1 + 28);
    v22 = *(_DWORD *)(a1 + 24);
    v23 = ((unsigned __int64)(dword_107BCC * (__int64)(2 * v20)) >> 32) - ((2 * v20) >> 31);
    LODWORD(v11) = 2 * (((unsigned __int64)(dword_107BCC * (__int64)*a2) >> 32) - (*a2 >> 31));
    v24 = ((unsigned __int64)(dword_107BCC * (__int64)v21) >> 32) - (v21 >> 31);
    HIDWORD(v11) = ((unsigned __int64)(dword_107BCC * (__int64)a2[1]) >> 32) - (a2[1] >> 31);
    *(_QWORD *)a2 = v11;
    v14 = __PAIR64__(v22, v23 + v24);
  }
  else
  {
    LODWORD(v11) = 2 * (((unsigned __int64)(dword_107BCC * (__int64)*a2) >> 32) - (*a2 >> 31));
    HIDWORD(v11) = 2 * (((unsigned __int64)(dword_107BCC * (__int64)a2[1]) >> 32) - (a2[1] >> 31));
    v12 = *(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 28);
    v13 = *(_DWORD *)(a1 + 32) + *(_DWORD *)(a1 + 24);
    *(_QWORD *)a2 = v11;
    v14 = __PAIR64__(v13 / 2, v12 / 2);
  }
LABEL_9:
  *((_QWORD *)a2 + 1) = v14;
  return sub_11F74C(1, dword_107BD0, v11, HIDWORD(v11));
}

