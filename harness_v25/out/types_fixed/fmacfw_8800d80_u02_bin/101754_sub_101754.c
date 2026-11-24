// sub_101754 @ 0x101754, size 390 bytes
void __fastcall sub_101754()
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

  if ( **(__int16 **)off_1018DC < 0
    && (unsigned __int8)BYTE2(*(_DWORD *)off_101928) + 10 * (HIBYTE(*(_DWORD *)off_101928) + 2) != 32 )
  {
    sub_12F46C(dword_101930, dword_10192C, 6119);
  }
  panic_loop_06d8();
  v0 = off_1018E4;
  v1 = off_1018E8;
  *(_DWORD *)off_1018E0 |= 0x8000000u;
  *v0 |= 8u;
  if ( ((*v1 >> 8) & 0xF) == 2 )
    *(v0 - 4897) |= 3u;
  if ( (unsigned __int8)*(_DWORD *)off_1018E8 >> 4 == 2 )
    *(_DWORD *)off_1018EC = dword_1018F0;
  v2 = off_1018F4;
  v3 = (unsigned int *)off_1018F8;
  v4 = (unsigned int *)off_1018FC;
  v5 = off_101900;
  v6 = off_101904;
  v7 = off_1018E0;
  *(_DWORD *)off_1018F4 = *(_DWORD *)off_1018F4 & 0xFFFFF800 | 0x700;
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
  v9 = (unsigned int *)off_101908;
  *v2 &= 0xFFFFF0FF;
  *v9 |= 0x800000u;
  *v9 |= 0x400000u;
  *v9 |= 1u;
  *v9 = *v9 & 0xFFFFFF3F | 0x80;
  if ( *(_DWORD *)(v2 + 0x10c24) > 1u )
  {
    v10 = (unsigned int *)off_10190C;
    *v8 = 1;
    *v10 = *v10 & 0xFFFFFF | 0xA0000000;
    *v3 = *v3 & 0xFFFFFCFF | 0x100;
  }
  v11 = (int *)off_101914;
  v12 = off_101918;
  v13 = dword_101920;
  *(_DWORD *)off_101910 = dword_10191C;
  *v11 = v13;
  v14 = *((unsigned __int8 *)off_101924 + 406);
  *v12 |= 0x10u;
  if ( !v14 )
    *(v12 - 10802) &= ~0x40u;
}
