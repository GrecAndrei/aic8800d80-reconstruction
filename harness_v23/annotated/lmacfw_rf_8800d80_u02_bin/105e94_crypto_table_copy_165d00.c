// v23 annotated: crypto_table_copy_165d00 @ 0x105e94
// Original: 105e94_crypto_table_copy_165d00.c
// Primary struct: <unclustered>
//
// crypto_table_copy_165d00 @ 0x105e94, size 146 bytes
// Doc: crypto_table_copy_165d00 [ke]: Copy crypto table from ROM to RAM
// crypto_table_copy_165d00 [ke]: Copy crypto table from ROM to RAM
int __fastcall crypto_table_copy_165d00(int a1, int a2)
{
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int *v13; // r4
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r0
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r6
  int v26; // r2
  _BYTE *v27; // r3
  int v28; // r1
  unsigned int *v29; // r4
  int v30; // r3
  int v31; // r1
  unsigned int v32; // r3
  int v34; // [sp+0h] [bp-6Ch]
  int v35; // [sp+4h] [bp-68h]
  int v36; // [sp+8h] [bp-64h]
  int v37; // [sp+Ch] [bp-60h]
  int v38; // [sp+10h] [bp-5Ch]
  int v39; // [sp+14h] [bp-58h]
  int v40; // [sp+18h] [bp-54h]
  int v41; // [sp+1Ch] [bp-50h]
  int v42; // [sp+20h] [bp-4Ch]
  int v43; // [sp+24h] [bp-48h]
  int v44; // [sp+28h] [bp-44h]
  int v45; // [sp+2Ch] [bp-40h]
  int v46; // [sp+30h] [bp-3Ch]
  int v47; // [sp+34h] [bp-38h]
  int v48; // [sp+38h] [bp-34h]
  int v49; // [sp+3Ch] [bp-30h]
  int v50; // [sp+40h] [bp-2Ch]
  int v51; // [sp+44h] [bp-28h]
  int v52; // [sp+48h] [bp-24h]
  int v53; // [sp+4Ch] [bp-20h]
  int v54; // [sp+50h] [bp-1Ch]
  int v55; // [sp+54h] [bp-18h]
  int v56; // [sp+58h] [bp-14h]
  int v57; // [sp+5Ch] [bp-10h]
  int v58; // [sp+60h] [bp-Ch]
  int v59; // [sp+64h] [bp-8h]
  _BYTE v60[4]; // [sp+68h] [bp-4h] BYREF

  v4 = *(_DWORD *)(dword_105F28 + 4);
  v5 = *(_DWORD *)(dword_105F28 + 8);
  v6 = *(_DWORD *)(dword_105F28 + 12);
  v34 = *(_DWORD *)dword_105F28;
  v35 = v4;
  v36 = v5;
  v37 = v6;
  v7 = *(_DWORD *)(dword_105F28 + 20);
  v8 = *(_DWORD *)(dword_105F28 + 24);
  v9 = *(_DWORD *)(dword_105F28 + 28);
  v38 = *(_DWORD *)(dword_105F28 + 16);
  v39 = v7;
  v40 = v8;
  v41 = v9;
  v10 = *(_DWORD *)(dword_105F28 + 36);
  v11 = *(_DWORD *)(dword_105F28 + 40);
  v12 = *(_DWORD *)(dword_105F28 + 44);
  v42 = *(_DWORD *)(dword_105F28 + 32);
  v43 = v10;
  v44 = v11;
  v45 = v12;
  v13 = (int *)(dword_105F28 + 48 + 4);
  v46 = *(_DWORD *)(dword_105F28 + 48);
  v14 = *v13;
  v15 = v13[1];
  v16 = v13[2];
  v17 = v13[3];
  v13 += 4;
  v47 = v14;
  v48 = v15;
  v49 = v16;
  v50 = v17;
  v18 = *v13;
  v19 = v13[1];
  v20 = v13[2];
  v21 = v13[3];
  v13 += 4;
  v51 = v18;
  v52 = v19;
  v53 = v20;
  v54 = v21;
  v22 = v13[1];
  v23 = v13[2];
  v24 = v13[3];
  v55 = *v13;
  v56 = v22;
  v57 = v23;
  v58 = v24;
  v25 = *(_DWORD *)(a1 + 4 * a2 + 140);
  v59 = v13[4];
  sub_11F74C(1, dword_105F2C, v25, v59);
  if ( v25 > 25 )
    v26 = 12;
  else
    v26 = (v25 / 2) & ~((v25 / 2) >> 31);
  v27 = &v60[4 * v26];
  v28 = *((_DWORD *)v27 - 26);
  v29 = (unsigned int *)off_105F34;
  v30 = *((_DWORD *)v27 - 13);
  *(_DWORD *)off_105F30 = (8 * v28) & 0x38 | *(_DWORD *)off_105F30 & 0xFFFFFFC7;
  v31 = dword_105F38;
  v32 = (4 * v30) & 0x1C | *v29 & 0xFFFFFFE3;
  *v29 = v32;
  return sub_11F74C(1, v31, v26, v32);
}

