// fwstruct annotate: 100478_sub_100478.c
// sub_100478 @ 0x100478, size 240 bytes
void __noreturn sub_100478()
{
  _BYTE *v0; // r4
  _DWORD *v1; // r5
  _DWORD *v2; // r3
  _DWORD *v3; // r0
  _DWORD *v4; // r2
  _DWORD *v5; // r3
  _DWORD *v6; // r1
  int v7; // r0
  _DWORD *v8; // r3
  _BYTE *v9; // r6
  int v10; // r0
  int v11; // r0
  int v12; // r0
  int v13; // r0
  int v14; // r0
  int v15; // r0
  int v16; // r0
  _DWORD *v17; // r2
  int v18; // r1
  int v19; // r0
  int v20; // r0

  v0 = off_100568;
  v1 = off_100570;
  v2 = off_100574;
  v3 = off_100578;
  *(_DWORD *)off_10056C = off_100568;
  v4 = off_10057C;
  *v1 = v0 + 76;
  *v2 = v0 + 12;
  *v3 = v0 + 136;
  v5 = off_100580;
  v6 = off_100584;
  *v4 = v0 + 152;
  *v5 = v0 + 178;
  *v6 = v0 + 176;
  v7 = sub_1002A0();
  if ( *(_BYTE *)*v1 == 1 )
  {
    v8 = off_10058C;
    *((_DWORD *)off_100588 + 22) &= ~1u;
    v8[20] |= 1u;
    v8[20] &= ~2u;
  }
  v9 = off_100594;
  *((_BYTE *)off_100594 + 2) = (*(_DWORD *)off_100590 & 0xF) == 10;
  v10 = sub_12FE58(v7);
  v11 = sub_10D068(v10);
  v12 = sub_10F0C4(v11);
  v13 = sub_115674(v12);
  if ( v0[363] )
  {
    v20 = sub_1303B8(v13);
    sub_130474(v20);
  }
  v14 = sub_12E948(dword_10059C, (unsigned __int8)v0[76], *(unsigned __int8 *)off_100598);
  v15 = sub_10FFC0(v14);
  v16 = sub_10F318(v15);
  if ( v9[2] )
  {
    sub_114428(v16);
    v17 = off_100590;
    v18 = dword_1005A4;
    *(_DWORD *)off_1005A0 &= ~8u;
    *v17 &= 0xFFFFFFF0;
    v19 = sub_12EB90(2, v18);
  }
  else
  {
    v19 = sub_12EB90(2, dword_1005AC);
  }
  if ( *(_BYTE *)*v1 == 3 )
    *(_DWORD *)off_1005A8 = 1;
  sub_115C20(v19);
}

