// v23 annotated: sub_114944 @ 0x114944
// Original: 114944_sub_114944.c
// Primary struct: <unclustered>
//
// sub_114944 @ 0x114944, size 164 bytes
int __fastcall sub_114944(char a1, __int16 a2, _DWORD *a3)
{
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r4
  int v10; // r1
  int v11; // r2
  int v12; // r6
  int v13; // r5
  _WORD *v14; // r3
  int v15; // r5
  __int16 v16; // r1
  __int16 v17; // r2
  int v18; // r3
  int v19; // r2
  int v20; // r3
  __int64 v21; // r4

  v6 = log_free_dispatch_1();
  if ( v6 )
  {
    v9 = v6;
    v12 = log_free_dispatch_n2b4();
    if ( v12 )
    {
      v13 = *a3;
      v14 = off_1149E8;
      *(_BYTE *)(v9 + 2) = a1;
      v15 = (unsigned __int16)(v13 + 4);
      *(_BYTE *)v9 = v15 + 12;
      *(_BYTE *)(v9 + 1) = ((unsigned __int16)(v15 + 12) >> 8) & 0xF;
      *(_BYTE *)(v9 + 3) = 0;
      v16 = v14[13];
      v17 = v14[12];
      v18 = dword_1149EC;
      *(_WORD *)(v9 + 6) = v16;
      *(_WORD *)(v9 + 8) = v17;
      *(_WORD *)(v9 + 10) = v15;
      *(_WORD *)(v9 + 4) = a2;
      *(_DWORD *)(v9 + 12) = v18;
      if ( v15 )
      {
        *(_DWORD *)(v9 + 16) = *a3;
        sub_14380C(v9 + 20, a3 + 1, *a3);
      }
      v19 = *(_DWORD *)(v12 + 8);
      v20 = dword_1149F0;
      *(_DWORD *)v12 = v9;
      LODWORD(v21) = 0;
      HIDWORD(v21) = (unsigned __int16)(v15 + 16) | v20 & v19 | 0x80000000;
      *(_QWORD *)(v12 + 4) = v21;
      log_queue_push(v12);
      return 0;
    }
    else
    {
      sub_12ECB0(dword_1149F8, v10, v11);
      log_free_dispatch_2((_DWORD *)v9);
      return -2;
    }
  }
  else
  {
    sub_12ECB0(dword_1149F4, v7, v8);
    return -1;
  }
}

