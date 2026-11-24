// rf_init_load_globals @ 0x11639c, size 252 bytes
// Doc: rf_init_load_globals [rf]: Loads RF subsystem globals from ROM/RAM pointers
// rf_init_load_globals [rf]: Loads RF subsystem globals from ROM/RAM pointers
int __fastcall rf_init_load_globals(int a1)
{
  int v2; // r5
  _DWORD *v3; // r4
  _DWORD *v4; // r11
  int v5; // r7
  int v6; // r10
  int v7; // r9
  int v8; // r8
  _DWORD *v9; // r6
  int v10; // r8
  int v11; // r0
  int *v12; // r5
  int v13; // r7
  int result; // r0
  int v15; // r3
  int v16; // r2
  _DWORD *v17; // r1
  int v18; // r0

  v2 = dword_11649C;
  v3 = (_DWORD *)dword_1164A0;
  v4 = (_DWORD *)dword_1164B8;
  v5 = dword_1164A4;
  v6 = dword_1164BC;
  v7 = dword_1164C0;
  v8 = dword_116498;
  sub_11E71C(dword_116498);
  sub_11E71C(v8 + 8);
  do
  {
    if ( !a1 || !*(_BYTE *)(v2 + 53) )
    {
      sub_100200((int *)v2, 0, 0x38u);
      v15 = 0;
      *(_DWORD *)(v2 + 28) = v3;
      *(_DWORD *)(v2 + 32) = v4;
      *(_DWORD *)(v4 + 0x30) = 0;
      *(_DWORD *)(v4 + 0x34) = 0;
      *(_DWORD *)(v3 + 0x60) = 0;
      *(_DWORD *)(v3 + 0x64) = 0;
      v16 = dword_1164B4;
      *(_DWORD *)(v4 + 0x18) = v3 + 26;
      *(_DWORD *)(v4 + 0x8) = v6;
      *(_DWORD *)(v3 + 0x2c) = v7;
      *(_BYTE *)(v2 + 52) = 0;
      *(_DWORD *)(v4 + 0x24) = 0;
      *(_DWORD *)(v4 + 0x38) = 0;
      v17 = v3 + 25;
      do
      {
        v18 = v16 | v15++;
        *(_DWORD *)(v17 + 0x4) = v18;
        ++v17;
        v16 -= 0x10000;
      }
      while ( v15 != 1024 );
      list_push_tail(v8);
    }
    v3 += 1050;
    v2 += 56;
    v4 += 19;
  }
  while ( v3 != (_DWORD *)v5 );
  v9 = off_1164A8;
  v10 = dword_1164C0;
  *(_DWORD *)off_1164A8 = dword_1164C0;
  *(_DWORD *)(v9 + 0x4) = lmac_rf_unk_1a9c() << 14;
  v11 = sub_1029BC();
  v12 = (int *)off_1164AC;
  v13 = dword_1164B0;
  *(_DWORD *)(v9 + 0x8) = v11;
  *(_DWORD *)(v9 + 0x14) = 1024;
  *(_DWORD *)(v9 + 0x18) = 0;
  *(_DWORD *)(v9 + 0x1c) = 0;
  *(_DWORD *)(v9 + 0x28) = 0;
  *(_DWORD *)(v9 + 0x2c) = 0;
  *v12 = v10;
  *(_DWORD *)(v9 + 0xc) = 0;
  *(_DWORD *)(v9 + 0x20) = 0;
  *(_DWORD *)(v9 + 0x30) = 0;
  *(_DWORD *)(v9 + 0x10) = v13;
  *(_DWORD *)(v12 + 0x4) = lmac_rf_unk_1a9c() << 14;
  result = sub_1029BC();
  *(_DWORD *)(v12 + 0x8) = result;
  *(_DWORD *)(v12 + 0xc) = 0;
  *(_DWORD *)(v12 + 0x18) = 0;
  *(_DWORD *)(v12 + 0x1c) = 0;
  *(_DWORD *)(v12 + 0x28) = 0;
  *(_DWORD *)(v12 + 0x2c) = 0;
  *(_DWORD *)(v12 + 0x10) = v13;
  *(_DWORD *)(v12 + 0x20) = 0;
  *(_DWORD *)(v12 + 0x30) = 0;
  *(_DWORD *)(v12 + 0x14) = 4;
  return result;
}

