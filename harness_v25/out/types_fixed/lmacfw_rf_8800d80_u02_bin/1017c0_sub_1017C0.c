// sub_1017C0 @ 0x1017c0, size 404 bytes
void __fastcall sub_1017C0()
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
  _BYTE *v11; // r3
  unsigned __int8 *v12; // r1
  int v13; // r2
  _DWORD *v14; // r2
  int v15; // r1

  if ( **(__int16 **)off_101954 < 0
    && (unsigned __int8)BYTE2(*(_DWORD *)off_1019A8) + 10 * (HIBYTE(*(_DWORD *)off_1019A8) + 2) != 32 )
  {
    rf_cmd_send_n264(dword_1019B0, dword_1019AC, 6119);
  }
  panic_loop();
  v0 = off_10195C;
  v1 = off_101960;
  *(_DWORD *)off_101958 |= 0x8000000u;
  *v0 |= 8u;
  if ( ((*v1 >> 8) & 0xF) == 2 )
    *(v0 - 4897) |= 3u;
  if ( (unsigned __int8)*(_DWORD *)off_101960 >> 4 == 2 )
    *(_DWORD *)off_101964 = dword_101968;
  v2 = off_10196C;
  v3 = (unsigned int *)off_101970;
  v4 = (unsigned int *)off_101974;
  v5 = off_101978;
  v6 = off_10197C;
  v7 = off_101958;
  *(_DWORD *)off_10196C = *(_DWORD *)off_10196C & 0xFFFFF800 | 0x700;
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
  v9 = (unsigned int *)off_101980;
  *v2 &= 0xFFFFF0FF;
  *v9 |= 0x800000u;
  *v9 |= 0x400000u;
  *v9 |= 1u;
  *v9 = *v9 & 0xFFFFFF3F | 0x80;
  if ( *(_DWORD *)(v2 + 0x10c24) > 1u )
  {
    v10 = (unsigned int *)off_101984;
    *v8 = 1;
    *v10 = *v10 & 0xFFFFFF | 0xA0000000;
    *v3 = *v3 & 0xFFFFFCFF | 0x100;
  }
  v11 = off_101990;
  *(_DWORD *)off_101988 = dword_10198C;
  v12 = (unsigned __int8 *)off_101994;
  if ( (*v11 & 0xC0) == 0xC0 )
    v13 = dword_10199C;
  else
    v13 = dword_1019A0;
  *(_DWORD *)off_101998 = v13;
  v14 = off_1019A4;
  v15 = *(_DWORD *)(v12 + 0x658);
  *(_DWORD *)off_1019A4 |= 0x10u;
  if ( !v15 )
    *(v14 - 10802) &= ~0x40u;
}
