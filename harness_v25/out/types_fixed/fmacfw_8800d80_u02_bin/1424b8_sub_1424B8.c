// sub_1424B8 @ 0x1424b8, size 266 bytes
int __fastcall sub_1424B8(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  int v4; // r8
  int v5; // r9
  _BYTE *v6; // r5
  int v10; // r11
  int v11; // r10
  int v12; // r0
  char v13; // r5
  __int16 v14; // r3
  int v15; // r1
  __int16 v16; // r2
  int v17; // r3
  unsigned __int8 v18; // r0
  bool v19; // r4
  bool *v20; // r0
  __int64 v22; // r0
  char v23; // [sp+4h] [bp-50h]
  int *(_DWORD *)(v24 + 0x8); // [sp+8h] [bp-4Ch] BYREF
  __int16 v25; // [sp+10h] [bp-44h]
  int v26; // [sp+18h] [bp-3Ch]
  __int64 v27; // [sp+20h] [bp-34h]
  char v28; // [sp+31h] [bp-23h]
  char v29; // [sp+36h] [bp-1Eh]
  char v30; // [sp+37h] [bp-1Dh]

  v4 = dword_1425C8;
  v5 = *a2;
  v6 = (_BYTE *)(dword_1425C8 + 1320 * v5);
  if ( !*(_DWORD *)(v6 + 0x1b0) || *(_DWORD *)(v6 + 0x1a8) || *(unsigned __int8 *)off_1425C4 > 7u )
  {
    v19 = 1;
  }
  else
  {
    v10 = (unsigned __int8)*(_DWORD *)(v6 + 0x1d0);
    v11 = dword_1425CC;
    v23 = *(_DWORD *)(v6 + 0x1a8);
    memset_thunk(v24, 0, 0x48u);
    v12 = *(_DWORD *)(a2 + 0x10);
    v13 = *(_DWORD *)(v6 + 0x1ac);
    BYTE2(*(_DWORD *)(v24 + 0x0)) = *(_BYTE *)off_1425C4;
    v30 = v13;
    v29 = *(_BYTE *)(v11 + 696 * v10 + 35);
    v28 = v23;
    v14 = *(_DWORD *)(v24 + 0x0);
    if ( v12 )
      v14 = LOWORD(*(_DWORD *)(v24 + 0x0)) | 4;
    v15 = *((unsigned __int16 *)a2 + 3);
    *(_DWORD *)(v24 + 0x4) = *(_DWORD *)(a2 + 2);
    v25 = *((_WORD *)a2 + 3);
    v16 = v14 | 0x30;
    v17 = *(_DWORD *)(a2 + 0x4);
    v18 = *(_DWORD *)(a2 + 0xc);
    LOWORD(*(_DWORD *)(v24 + 0x0)) = v16;
    v26 = v15 << v18;
    if ( (unsigned int)(v17 - 1) <= 1 )
    {
      LODWORD(v22) = sub_12BE40();
      v17 = *(_DWORD *)(a2 + 0x4);
      v27 = *(_QWORD *)(v4 + 1320 * v5 + 40) + (unsigned int)dword_1425D0 + v22;
    }
    v19 = sub_141F40(v4 + 1320 * v5, v11 + 696 * v10, (int)v24, v17) == 0;
  }
  v20 = (bool *)sub_12C92C(12289, a4, a3, 1u);
  *v20 = v19;
  sdio_buffer_prepare_n_4e8((int)v20);
  return 0;
}

