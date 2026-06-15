// rf_event_dispatch_n1a4 @ 0x118674, size 550 bytes
// Doc: rf_event_dispatch_n1a4 [rf]: Dispatch RF event processing from queued struct
// rf_event_dispatch_n1a4 [rf]: Dispatch RF event processing from queued struct
int __fastcall rf_event_dispatch_n1a4(int a1, int a2, int a3, _DWORD *a4, int a5, int a6)
{
  unsigned int v7; // r4
  __int64 v8; // r10
  int v10; // r5
  int v11; // r3
  char *v12; // r2
  int v13; // r9
  int *v14; // r0
  _DWORD *v15; // r2
  __int16 **v16; // r3
  int v17; // r8
  char *v18; // r1
  int *v19; // r0
  _DWORD *v20; // r1
  unsigned int v21; // r6
  int v22; // r8
  __int64 v23; // kr08_8
  bool v24; // cf
  int v25; // r4
  __int64 v26; // r0
  _DWORD *v27; // r6
  int v28; // r3
  unsigned __int64 v29; // r0
  unsigned int v30; // r2
  int v31; // r4
  int result; // r0
  unsigned int v33; // [sp+0h] [bp-1Ch]
  int v34; // [sp+Ch] [bp-10h]
  unsigned int v35; // [sp+10h] [bp-Ch]

  v7 = *(_DWORD *)(a3 + 32);
  v35 = *(_DWORD *)(a3 + 36);
  v8 = *(_QWORD *)(a1 + 24);
  v10 = *(unsigned __int16 *)(a1 + 32) << 10;
  if ( a6 )
  {
    v11 = *(unsigned __int8 *)(a6 + 2);
    if ( !*(_BYTE *)(a6 + 2) )
      v11 = *(unsigned __int8 *)(a6 + 3);
    v34 = v10 * v11;
    if ( !(*(unsigned __int8 *)(a3 + 40) << 28) )
      goto LABEL_5;
LABEL_24:
    v21 = 500;
    v22 = 0;
    goto LABEL_14;
  }
  v34 = *(unsigned __int16 *)(a1 + 32) << 10;
  if ( *(unsigned __int8 *)(a3 + 40) << 28 )
    goto LABEL_24;
LABEL_5:
  v12 = (char *)off_11889C;
  v13 = dword_1188C0;
  v14 = (int *)off_1188A0;
  *(_DWORD *)off_11889C = *(_BYTE *)(dword_1188C0 + (*(unsigned __int8 *)(a3 + 44) >> 4)) & 0x7F
                        | *(_DWORD *)off_11889C & 0xFFFFFF80;
  v15 = v12 + 8;
  *v14 = a2 | (*(unsigned __int8 *)(a3 + 40) >> 7 << 20);
  *v15 = 0x80000000;
  __dsb(0xFu);
  while ( (*v15 & 0xC0000000) != 0x40000000 )
    ;
  v16 = (__int16 **)off_1188A4;
  if ( **(__int16 **)off_1188A4 >= 0 || (*v15 & 0x40000000) != 0 )
  {
    v17 = (unsigned __int16)*(_DWORD *)off_1188A8;
  }
  else
  {
    sub_121960(dword_1188BC, dword_1188B8, 430, off_1188A4);
    v17 = 500;
    v16 = (__int16 **)off_1188A4;
  }
  if ( !(*(unsigned __int8 *)(a3 + 40) << 28) )
  {
    v18 = (char *)off_11889C;
    v19 = (int *)off_1188A0;
    *(_DWORD *)off_11889C = *(_BYTE *)(v13 + (*(unsigned __int8 *)(a3 + 44) >> 4)) & 0x7F
                          | *(_DWORD *)off_11889C & 0xFFFFFF80;
    v20 = v18 + 8;
    *v19 = (*(unsigned __int8 *)(a3 + 40) >> 7 << 20) | 0x18;
    *v20 = 0x80000000;
    __dsb(0xFu);
    while ( (*v20 & 0xC0000000) != 0x40000000 )
      ;
    if ( **v16 >= 0 || (*v20 & 0x40000000) != 0 )
    {
      v21 = (unsigned __int16)*(_DWORD *)off_1188A8;
      v22 = v17 - v21;
      goto LABEL_14;
    }
    sub_121960(dword_1188BC, dword_1188B8, 430, *v20);
  }
  v22 = v17 - 500;
  v21 = 500;
LABEL_14:
  v23 = v8 - __PAIR64__(v35, v7);
  v24 = __CFADD__(v8 - v7, v22);
  v25 = v8 - v7 + v22;
  a4[10] = v25;
  a4[11] = HIDWORD(v23) + v24;
  v26 = sub_127F8C(v8, HIDWORD(v8), v10, v10 >> 31);
  v24 = (unsigned int)v8 >= v21;
  v33 = v8 - v21;
  v27 = off_1188AC;
  v28 = v26 * (v10 >> 31) + v10 * HIDWORD(v26);
  v29 = (unsigned int)v26 * (unsigned __int64)(unsigned int)v10;
  HIDWORD(v29) += v28;
  if ( v29 < __PAIR64__(HIDWORD(v8) - (unsigned int)!v24, v33) )
    v33 = v29;
  v30 = v33 + v34;
  if ( (*(_DWORD *)off_1188B0 & 0x2000000) != 0 )
    v30 -= v25;
  v31 = *((_DWORD *)off_1188AC + 4) - *(_DWORD *)off_1188B4 + v30 - 400;
  if ( v31 - v27[4] - 4300 - sub_101A20() < 0 )
    v31 += v10;
  result = v31 - *((_DWORD *)off_1188AC + 4) - 4300 - sub_101A20();
  if ( result >= 0 && a4[9] != v31 )
  {
    sub_11AB18(a4 + 6, v31);
    return sub_11C01C(a4);
  }
  return result;
}

