// sub_101600 @ 0x101600, size 390 bytes
void __fastcall sub_101600()
{
  _DWORD *v0; // r2
  _DWORD *v1; // r0
  _DWORD *v2; // r5
  unsigned int *v3; // r1
  unsigned int *v4; // r4
  _DWORD *v5; // r3
  _DWORD *v6; // r0
  _DWORD *v7; // r6
  _DWORD *v8; // r4
  unsigned int *v9; // r3
  unsigned int *v10; // r2
  int *v11; // r3
  _DWORD *v12; // r2
  int v13; // r0
  int v14; // r1

  if ( **(__int16 **)off_101788 < 0
    && (unsigned __int8)BYTE2(*(_DWORD *)off_1017D4) + 10 * (HIBYTE(*(_DWORD *)off_1017D4) + 2) != 32 )
  {
    sub_12F694(dword_1017DC, dword_1017D8, 6119);
  }
  message_dispatch_n238();
  v0 = off_101790;
  v1 = off_101794;
  *(_DWORD *)off_10178C |= 0x8000000u;
  *v0 |= 8u;
  if ( ((*v1 >> 8) & 0xF) == 2 )
    *(v0 - 4897) |= 3u;
  if ( (unsigned __int8)*(_DWORD *)off_101794 >> 4 == 2 )
    *(_DWORD *)off_101798 = dword_10179C;
  v2 = off_1017A0;
  v3 = (unsigned int *)off_1017A4;
  v4 = (unsigned int *)off_1017A8;
  v5 = off_1017AC;
  v6 = off_1017B0;
  v7 = off_10178C;
  *(_DWORD *)off_1017A0 = *(_DWORD *)off_1017A0 & 0xFFFFF800 | 0x700;
  *v3 = 256;
  *v4 = *v4 & 0xFFFFE000 | 0x580;
  *v5 |= 0x10000u;
  *v5 |= 0x10000000u;
  *v5 |= 2u;
  v2 -= 236;
  *v6 |= 2u;
  *v2 = 1;
  v8 = v4 + 16846;
  *v5 &= 0xFFFFFF8F;
  *v8 = 1;
  *v3 = *v3 & 0xFFFFFCFF | 0x100;
  v2 -= 10753;
  *v7 |= 0x8000000u;
  v9 = (unsigned int *)off_1017B4;
  *v2 &= 0xFFFFF0FF;
  *v9 |= 0x800000u;
  *v9 |= 0x400000u;
  *v9 |= 1u;
  *v9 = *v9 & 0xFFFFFF3F | 0x80;
  if ( *(_DWORD *)(v2 + 0x10c24) > 1u )
  {
    v10 = (unsigned int *)off_1017B8;
    *v8 = 1;
    *v10 = *v10 & 0xFFFFFF | 0xA0000000;
    *v3 = *v3 & 0xFFFFFCFF | 0x100;
  }
  v11 = (int *)off_1017C0;
  v12 = off_1017C4;
  v13 = dword_1017CC;
  *(_DWORD *)off_1017BC = dword_1017C8;
  *v11 = v13;
  v14 = *((unsigned __int8 *)off_1017D0 + 406);
  *v12 |= 0x10u;
  if ( !v14 )
    *(v12 - 10802) &= ~0x40u;
}
