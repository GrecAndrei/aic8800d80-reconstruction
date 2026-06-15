// v23 annotated: sub_119874 @ 0x119874
// Original: 119874_sub_119874.c
// Primary struct: <unclustered>
//
// sub_119874 @ 0x119874, size 326 bytes
// Doc: sub_1219874 [unknown]: Unknown behavioral function in fmacfw
// sub_1219874 [unknown]: Unknown behavioral function in fmacfw
int __fastcall sub_119874(int a1, int *a2, unsigned int a3, unsigned int a4, unsigned __int8 a5)
{
  int *v5; // r4
  int v6; // r5
  int v8; // r6
  int v9; // r8
  _WORD *v10; // lr
  int v11; // r9
  char v12; // r0
  int v13; // r0
  unsigned int v14; // r0
  unsigned int v15; // r7
  unsigned int v16; // r0
  unsigned int v17; // r3
  __int16 v18; // r10
  int *v19; // r8
  unsigned int v20; // r7
  __int16 v21; // r12
  int v22; // r10
  int v23; // r8

  v5 = (int *)*a2;
  if ( (*(_WORD *)(*a2 + 82) & 1) == 0 )
    return 0;
  v6 = *(_DWORD *)(a1 + 68);
  if ( *(unsigned __int8 *)(v6 + 12) != *((unsigned __int8 *)v5 + 29)
    || *(unsigned __int8 *)(v6 + 13) != *((unsigned __int8 *)v5 + 27) )
  {
    return 0;
  }
  v8 = v5[19];
  v9 = *(_DWORD *)(v6 + 324);
  v10 = *(_WORD **)(v8 + 28);
  v11 = *(_DWORD *)(v9 + 76);
  if ( !v10 || (*v10 & 0x8000) != 0 )
  {
    v13 = *(_DWORD *)(v8 + 36);
  }
  else
  {
    *v10 = ~((unsigned int)~((unsigned __int16)*v10 << 17) >> 17);
    v12 = *((_BYTE *)v5 + 50) + 4;
    *((_BYTE *)v5 + 51) += 4;
    *((_BYTE *)v5 + 50) = v12;
    v13 = *(_DWORD *)(v8 + 36) + 4;
    *(_DWORD *)(v8 + 32) += 4;
    *(_DWORD *)(v8 + 36) = v13;
  }
  v14 = (unsigned __int16)(((v13 + 3) & 0xFFFC) + 4);
  if ( a4 <= v14 )
  {
    v15 = 0;
  }
  else
  {
    v15 = ((unsigned int)(unsigned __int16)(a4 - v14) + 3) >> 2;
    v14 = (unsigned __int16)(v14 + 4 * v15);
  }
  v16 = v14 + *(_DWORD *)(v6 + 40);
  if ( v16 > a3 )
    return 0;
  v17 = *(_DWORD *)(v9 + 36) & 0xFFE7FFFF;
  v18 = *(_WORD *)(v6 + 10);
  --*(_BYTE *)(dword_1199BC + 84 * a5 + 80);
  *(_DWORD *)(v9 + 36) = v17 | 0x300000;
  v19 = (int *)off_1199C4;
  v20 = v5[9] & 0xFFE7FFFF | (v15 << 9);
  v21 = *((_WORD *)v5 + 40) + v18;
  v22 = *v5;
  *(_DWORD *)(v11 + 68) = v17 | 0x300100;
  *(_DWORD *)(v11 + 20) = v8 + 12;
  v23 = *v19;
  v5[9] = v20 | 0x780000;
  *(_DWORD *)(v8 + 68) = v20 | 0x780100;
  *(_DWORD *)(v8 + 16) = 0;
  *(_DWORD *)(v8 + 48) = 0;
  *(_DWORD *)(v6 + 40) = v16;
  v5[17] = v6;
  *(_DWORD *)(v6 + 324) = v5;
  *(_WORD *)(v6 + 10) = v21;
  *a2 = v22;
  if ( !*(_BYTE *)(v23 + 1) )
    *(_DWORD *)(v6 + 20) = *(unsigned __int8 *)(v23 + 1);
  if ( v10 )
    *(_DWORD *)(*(_DWORD *)(v8 + 32) - 3) = *((_DWORD *)off_1199C0 + 43);
  *(_BYTE *)(v8 + 1) = *(_BYTE *)(v11 + 1) + 1;
  return 1;
}

