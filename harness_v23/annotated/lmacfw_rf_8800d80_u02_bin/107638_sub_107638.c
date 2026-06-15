// v23 annotated: sub_107638 @ 0x107638
// Original: 107638_sub_107638.c
// Primary struct: <unclustered>
//
// sub_107638 @ 0x107638, size 418 bytes
int __fastcall sub_107638(int a1)
{
  int *v1; // r4
  _DWORD *v2; // r5
  int *v3; // r8
  int v4; // r9
  int *v5; // r6
  _DWORD *v6; // r10
  int v8; // r1
  int v9; // r3
  int v10; // r2
  int *v11; // r5
  int v12; // r3
  int v13; // r3
  int v14; // r6
  bool v15; // cc
  _DWORD *v16; // r4
  int v17; // r3
  int v18; // r11
  int v19; // r1
  int result; // r0
  _DWORD *v21; // r3
  unsigned int v22; // [sp+18h] [bp-14h] BYREF
  unsigned int v23; // [sp+1Ch] [bp-10h]
  int v24; // [sp+20h] [bp-Ch]
  int v25; // [sp+24h] [bp-8h]

  v1 = (int *)off_1077DC;
  v2 = off_1077E0;
  v3 = (int *)off_1077EC;
  v4 = dword_1077F0;
  v5 = (int *)off_1077E4;
  v6 = off_1077E4;
  sub_107150(a1);
  v8 = dword_1077E8;
  *v1 |= 0x1000000u;
  v9 = *v1 | 0x2000000;
  *v1 = v9;
  sub_11F74C(1, v8, v10, v9);
  sub_106F08();
  *v2 &= ~1u;
  sub_100560(20);
  *v2 |= 4u;
  *v2 |= 8u;
  sub_100560(20);
  v11 = (int *)off_1077EC;
  *v1 |= 0x400000u;
  *v3 = *v3 & v4 | 0xC00;
  sub_100560(20);
  *v1 |= 0x4000000u;
  v12 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  v22 = v12;
  *v3 = *v3 & v4 | 0x400;
  sub_100560(20);
  *v1 |= 0x4000000u;
  v13 = *v5;
  v14 = dword_1077F0;
  v23 = v13 & 0x7FFF;
  *v1 &= ~0x4000000u;
  v15 = v22 > v23;
  v16 = off_1077DC;
  if ( v22 > v23 )
    v17 = 1536;
  else
    v17 = 3584;
  *v11 = *v11 & v14 | v17;
  if ( v15 )
    v18 = 512;
  else
    v18 = 2560;
  sub_100560(20);
  *v16 |= 0x4000000u;
  v24 = *v6 & 0x7FFF;
  *v16 &= ~0x4000000u;
  *v11 = *v11 & v14 | v18;
  sub_100560(20);
  v19 = dword_1077F4;
  *v16 |= 0x4000000u;
  v25 = *v6 & 0x7FFF;
  *v16 &= ~0x4000000u;
  *v16 &= ~0x400000u;
  sub_11F74C(1, v19, 3072, v22);
  result = sub_1073BC(&v22, a1);
  v21 = off_1077E0;
  *(_DWORD *)off_1077E0 &= ~4u;
  *v21 &= ~8u;
  *v11 &= v14;
  *v16 &= ~0x1000000u;
  *v16 &= ~0x2000000u;
  return result;
}

