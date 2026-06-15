// v23 annotated: sub_141FDC @ 0x141fdc
// Original: 141fdc_sub_141FDC.c
// Primary struct: <unclustered>
//
// sub_141FDC @ 0x141fdc, size 160 bytes
int __fastcall sub_141FDC(int a1, int a2, int a3, int a4)
{
  int v6; // r0
  int v7; // r1
  int v8; // r1
  __int16 v9; // r3
  int v10; // r5
  __int16 v11; // r3
  int v12; // r4
  int v13; // r1
  __int64 v14; // r2
  int v16; // [sp+Ch] [bp-8h] BYREF

  v6 = msg_handler_1241c0c((int)&v16, a1, a2, 6, *(_BYTE *)(a3 + 2));
  v7 = *(_DWORD *)(v16 + 72) + 108;
  *(_BYTE *)(v7 + v6) = -40;
  v8 = v7 + v6;
  *(_BYTE *)(v8 + 2) = (8 * *(_BYTE *)a3) & 0x30;
  v9 = (a4 != 4) | (unsigned __int16)(2 * a4) | *(_WORD *)a3 & 0x10 | *(_WORD *)a3 & 0x20;
  if ( *(_BYTE *)(a3 + 4) )
    v9 |= 0x40u;
  v10 = *(_DWORD *)(a3 + 24);
  v11 = v9 | (*(unsigned __int8 *)(a3 + 5) << 10) | (*(unsigned __int8 *)(a3 + 2) << 7);
  *(_DWORD *)(v8 + 9) = *(_DWORD *)(a3 + 28);
  *(_DWORD *)(v8 + 5) = v10;
  *(_WORD *)(v8 + 3) = v11;
  *(_BYTE *)(v8 + 13) = *(_BYTE *)(a3 + 7);
  *(_WORD *)(v8 + 14) = *(_WORD *)(a3 + 8);
  *(_BYTE *)(v8 + 16) = *(_BYTE *)(a3 + 41);
  *(_BYTE *)(v8 + 1) = 15;
  v12 = v16;
  v13 = *(_DWORD *)(v16 + 76);
  HIDWORD(v14) = (unsigned __int16)(v6 + 17);
  LODWORD(v14) = *(_DWORD *)(v13 + 28) - 1 + HIDWORD(v14);
  HIDWORD(v14) += 4;
  *(_QWORD *)(v13 + 32) = v14;
  return sub_1190B4(v12, 3);
}

