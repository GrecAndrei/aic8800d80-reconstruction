// v23 annotated: sub_107620 @ 0x107620
// Original: 107620_sub_107620.c
// Primary struct: <unclustered>
//
// sub_107620 @ 0x107620, size 176 bytes
int __fastcall sub_107620(int a1)
{
  int v2; // r1
  int v3; // r2
  int v4; // r3
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r8
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r6
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r6
  int *v23; // r7
  unsigned int *v24; // lr
  int v25; // r4
  int v26; // r8
  unsigned int *v27; // r5
  int v28; // r0
  int v29; // r1
  int v31; // [sp+0h] [bp-60h]
  int v32; // [sp+4h] [bp-5Ch]
  int v33; // [sp+8h] [bp-58h]
  int v34; // [sp+Ch] [bp-54h]
  int v35; // [sp+10h] [bp-50h]
  int v36; // [sp+14h] [bp-4Ch]
  int v37; // [sp+18h] [bp-48h]
  int v38; // [sp+1Ch] [bp-44h]
  int v39; // [sp+20h] [bp-40h]
  int v40; // [sp+24h] [bp-3Ch]
  int v41; // [sp+28h] [bp-38h]
  int v42; // [sp+2Ch] [bp-34h]
  int v43; // [sp+30h] [bp-30h]
  int v44; // [sp+34h] [bp-2Ch]
  int v45; // [sp+38h] [bp-28h]
  int v46; // [sp+3Ch] [bp-24h]
  int v47; // [sp+40h] [bp-20h]
  int v48; // [sp+44h] [bp-1Ch]
  int v49; // [sp+48h] [bp-18h]
  int v50; // [sp+4Ch] [bp-14h]
  int v51; // [sp+50h] [bp-10h]
  int v52; // [sp+54h] [bp-Ch]
  int v53; // [sp+58h] [bp-8h]
  int v54; // [sp+5Ch] [bp-4h]
  int v55; // [sp+60h] [bp+0h] BYREF

  v2 = *(_DWORD *)(dword_1076D0 + 396);
  v3 = *(_DWORD *)(dword_1076D0 + 400);
  v4 = *(_DWORD *)(dword_1076D0 + 404);
  v31 = *(_DWORD *)(dword_1076D0 + 392);
  v32 = v2;
  v33 = v3;
  v34 = v4;
  v5 = *(_DWORD *)(dword_1076D0 + 412);
  v6 = *(_DWORD *)(dword_1076D0 + 416);
  v7 = *(_DWORD *)(dword_1076D0 + 420);
  v35 = *(_DWORD *)(dword_1076D0 + 408);
  v36 = v5;
  v37 = v6;
  v38 = v7;
  v8 = *(_DWORD *)(dword_1076D0 + 428);
  v9 = *(_DWORD *)(dword_1076D0 + 432);
  v10 = *(_DWORD *)(dword_1076D0 + 436);
  v39 = *(_DWORD *)(dword_1076D0 + 424);
  v40 = v8;
  v41 = v9;
  v42 = v10;
  v11 = *(_DWORD *)(dword_1076D0 + 444);
  v12 = *(_DWORD *)(dword_1076D0 + 448);
  v13 = *(_DWORD *)(dword_1076D0 + 452);
  v43 = *(_DWORD *)(dword_1076D0 + 440);
  v44 = v11;
  v45 = v12;
  v46 = v13;
  v14 = *(_DWORD *)(a1 + 8);
  v15 = *(_DWORD *)(dword_1076D0 + 460);
  v16 = *(_DWORD *)(dword_1076D0 + 464);
  v17 = *(_DWORD *)(dword_1076D0 + 468);
  v18 = ((unsigned __int64)(dword_1076D4 * (__int64)*(int *)(a1 + 4)) >> 32) - (*(int *)(a1 + 4) >> 31);
  v47 = *(_DWORD *)(dword_1076D0 + 456);
  v48 = v15;
  v49 = v16;
  v50 = v17;
  if ( v18 >= (int)(((unsigned __int64)(dword_1076D4 * (__int64)v14) >> 32) - (v14 >> 31)) )
    v18 = ((unsigned __int64)(dword_1076D4 * (__int64)v14) >> 32) - (v14 >> 31);
  v19 = *(_DWORD *)(dword_1076D0 + 476);
  v20 = *(_DWORD *)(dword_1076D0 + 480);
  v21 = *(_DWORD *)(dword_1076D0 + 484);
  v22 = v18 & ~(v18 >> 31);
  v23 = &v55 + v22;
  v24 = (unsigned int *)off_1076E0;
  v25 = *(v23 - 24);
  v26 = *(_DWORD *)off_1076E0;
  v51 = *(_DWORD *)(dword_1076D0 + 472);
  v52 = v19;
  v53 = v20;
  v54 = v21;
  v27 = (unsigned int *)off_1076D8;
  v28 = *(v23 - 12);
  v29 = dword_1076DC;
  *(_DWORD *)(a1 + 8) = 3 * v22;
  *v24 = (v25 << 12) & 0x7000 | v26 & 0xFFFF8FFF;
  *v27 |= 0x400u;
  *v27 = (v28 << 8) & 0x300 | *v27 & 0xFFFFFCFF;
  return sub_12EB90(1, v29);
}

