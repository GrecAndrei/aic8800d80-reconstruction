// sub_136FA0 @ 0x136fa0, size 90 bytes
int __fastcall sub_136FA0(int a1, unsigned __int8 *a2, int a3, __int16 a4)
{
  _WORD *v4; // r4
  _BYTE *v6; // r0
  _DWORD *v7; // r6
  unsigned int v8; // r2
  int *v10; // r4
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r1
  int v24; // r2

  v4 = off_136FFC;
  v6 = (_BYTE *)rf_bus_setup_n3a8(4102, a4, 4, 0x3Cu);
  v7 = v6;
  if ( *(_DWORD *)(v4 + 0x8) && (v8 = *a2, (unsigned __int16)*(_DWORD *)(v4 + 0x8) > v8) )
  {
    v10 = (int *)&v4[30 * v8 + 4];
    v11 = *v10;
    v12 = *(_DWORD *)(v10 + 0x4);
    v13 = *(_DWORD *)(v10 + 0x8);
    v14 = *(_DWORD *)(v10 + 0xc);
    v10 += 4;
    *v7 = v11;
    *(_DWORD *)(v7 + 0x4) = v12;
    *(_DWORD *)(v7 + 0x8) = v13;
    *(_DWORD *)(v7 + 0xc) = v14;
    v15 = *v10;
    v16 = *(_DWORD *)(v10 + 0x4);
    v17 = *(_DWORD *)(v10 + 0x8);
    v18 = *(_DWORD *)(v10 + 0xc);
    v10 += 4;
    *(_DWORD *)(v7 + 0x10) = v15;
    *(_DWORD *)(v7 + 0x14) = v16;
    *(_DWORD *)(v7 + 0x18) = v17;
    *(_DWORD *)(v7 + 0x1c) = v18;
    v19 = *v10;
    v20 = *(_DWORD *)(v10 + 0x4);
    v21 = *(_DWORD *)(v10 + 0x8);
    v22 = *(_DWORD *)(v10 + 0xc);
    v10 += 4;
    *(_DWORD *)(v7 + 0x20) = v19;
    *(_DWORD *)(v7 + 0x24) = v20;
    *(_DWORD *)(v7 + 0x28) = v21;
    *(_DWORD *)(v7 + 0x2c) = v22;
    v23 = *(_DWORD *)(v10 + 0x4);
    v24 = *(_DWORD *)(v10 + 0x8);
    *(_DWORD *)(v7 + 0x30) = *v10;
    *(_DWORD *)(v7 + 0x34) = v23;
    *(_DWORD *)(v7 + 0x38) = v24;
    sub_12CBB4((int)v7);
    return 0;
  }
  else
  {
    *v6 = 0;
    sub_12CBB4((int)v6);
    return 0;
  }
}

