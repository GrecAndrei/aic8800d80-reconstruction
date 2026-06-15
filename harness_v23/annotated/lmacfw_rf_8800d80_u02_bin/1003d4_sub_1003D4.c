// v23 annotated: sub_1003D4 @ 0x1003d4
// Original: 1003d4_sub_1003D4.c
// Primary struct: <unclustered>
//
// sub_1003D4 @ 0x1003d4, size 190 bytes
void __noreturn sub_1003D4()
{
  _BYTE *v0; // r4
  _DWORD *v1; // r2
  _DWORD *v2; // r5
  _DWORD *v3; // r1
  _DWORD *v4; // r3
  _DWORD *v5; // r2
  _DWORD *v6; // r6
  int v7; // r0
  _DWORD *v8; // r3
  int v9; // r0
  int v10; // r0
  _WORD *v11; // r2
  unsigned __int8 *v12; // r6
  int v13; // r0
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int v17; // r0
  int v18; // r0
  int v19; // r0

  v0 = off_100498;
  v1 = off_10049C;
  v2 = off_1004A0;
  *(_DWORD *)off_100494 = off_100498;
  *v1 = v0 + 12;
  v3 = off_1004A4;
  v4 = off_1004A8;
  v5 = off_1004AC;
  v6 = off_1004B0;
  *v2 = v0 + 76;
  *v3 = v0 + 136;
  *v4 = v0 + 152;
  *v6 = v0 + 178;
  *v5 = v0 + 176;
  v7 = sub_1002A0();
  if ( *(_BYTE *)*v2 == 1 )
  {
    v8 = off_1004B8;
    *((_DWORD *)off_1004B4 + 22) &= ~1u;
    v8[20] |= 1u;
    v8[20] &= ~2u;
  }
  v9 = sub_123068(v7);
  v10 = sub_10F4B8(v9);
  sub_115000(v10);
  v11 = (_WORD *)*v6;
  v12 = (unsigned __int8 *)off_1004BC;
  v13 = dword_1004C0;
  *v11 |= 0x2000u;
  v14 = sub_11F504(v13, *v12);
  v15 = sub_126174(v14);
  if ( v0[363] )
  {
    v19 = sub_12704C(v15);
    sub_127108(v19);
  }
  v16 = sub_11F504(dword_1004C4, (unsigned __int8)v0[76]);
  v17 = sub_10FFF0(v16);
  v18 = sub_10F6A4(v17);
  if ( *(_BYTE *)*v2 == 3 )
    *(_DWORD *)off_1004C8 = 1;
  sub_115018(v18);
}

