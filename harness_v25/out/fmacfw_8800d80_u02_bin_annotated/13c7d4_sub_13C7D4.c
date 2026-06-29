// fwstruct annotate: 13c7d4_sub_13C7D4.c
// sub_13C7D4 @ 0x13c7d4, size 936 bytes
int __fastcall sub_13C7D4(_DWORD *a1, _DWORD *a2)
{
  int v2; // r3
  int v3; // r4
  int v4; // r8
  int v7; // r0
  int v8; // r1
  int v9; // r5
  int v10; // r9
  int v11; // lr
  int v12; // r9
  int v13; // r5
  int v14; // r2
  int v15; // r11
  int v16; // r12
  int v17; // lr
  unsigned int v18; // r9
  int v19; // r7
  int v20; // r2
  int v21; // r1
  unsigned __int8 v22; // r6^2
  int v23; // r5
  int v24; // r3
  int v25; // r1
  int v26; // r0
  unsigned int v27; // r7
  unsigned int v28; // r6
  int v29; // r1
  int v30; // r3
  int v31; // r1
  int v32; // r0
  int v33; // r8
  int v34; // r6
  int v35; // r7
  int v36; // r1
  int v37; // r4
  int v38; // r0
  int v39; // r6
  int result; // r0
  unsigned int v41; // [sp+0h] [bp-3Ch]
  int v42; // [sp+0h] [bp-3Ch]
  int v43; // [sp+0h] [bp-3Ch]
  unsigned int v44; // [sp+4h] [bp-38h]
  unsigned int v45; // [sp+8h] [bp-34h]
  unsigned int v46; // [sp+Ch] [bp-30h]
  int v47; // [sp+Ch] [bp-30h]
  int v49; // [sp+14h] [bp-28h]
  _DWORD *v50; // [sp+1Ch] [bp-20h]
  int v51; // [sp+24h] [bp-18h]
  int v52; // [sp+28h] [bp-14h]
  _DWORD *v53; // [sp+30h] [bp-Ch]

  v2 = a2[1];
  v3 = dword_13CA98;
  v4 = dword_13CAA0;
  v44 = *a2 ^ *a1;
  v7 = a2[3];
  v8 = a2[2];
  *a2 = v44;
  v50 = a1;
  v9 = v2 ^ a1[1];
  a2[1] = v9;
  v41 = v9;
  v10 = v8 ^ a1[2];
  a2[2] = v10;
  v46 = v10;
  v45 = a1[3] ^ v7;
  v53 = a1 + 36;
  do
  {
    v49 = *(unsigned __int8 *)(v3 + BYTE1(v41));
    v51 = *(unsigned __int8 *)(v3 + BYTE1(v46));
    v11 = *(unsigned __int8 *)(v3 + BYTE2(v46));
    v12 = *(unsigned __int8 *)(v3 + BYTE2(v45));
    v13 = v11 ^ *(unsigned __int8 *)(v4 + (unsigned __int8)v44) ^ *(unsigned __int8 *)(dword_13CA9C + HIBYTE(v45)) ^ v49;
    v14 = ((*(unsigned __int8 *)(v4 + HIBYTE(v45))
          ^ *(unsigned __int8 *)(v3 + (unsigned __int8)v44)
          ^ v49
          ^ *(unsigned __int8 *)(dword_13CA9C + BYTE2(v46))) << 16)
        | ((*(unsigned __int8 *)(dword_13CA9C + BYTE1(v41))
          ^ *(unsigned __int8 *)(v3 + (unsigned __int8)v44)
          ^ *(unsigned __int8 *)(v3 + HIBYTE(v45))
          ^ *(unsigned __int8 *)(v4 + BYTE2(v46))) << 8)
        | v11
        ^ *(unsigned __int8 *)(v3 + HIBYTE(v45))
        ^ *(unsigned __int8 *)(dword_13CA9C + (unsigned __int8)v44)
        ^ *(unsigned __int8 *)(v4 + BYTE1(v41));
    v15 = v12 ^ *(unsigned __int8 *)(dword_13CA9C + HIBYTE(v44)) ^ *(unsigned __int8 *)(v4 + (unsigned __int8)v41) ^ v51;
    v16 = ((*(unsigned __int8 *)(dword_13CA9C + BYTE2(v45))
          ^ v51
          ^ *(unsigned __int8 *)(v3 + (unsigned __int8)v41)
          ^ *(unsigned __int8 *)(v4 + HIBYTE(v44))) << 16)
        | ((*(unsigned __int8 *)(v3 + HIBYTE(v44))
          ^ *(unsigned __int8 *)(v3 + (unsigned __int8)v41)
          ^ *(unsigned __int8 *)(dword_13CA9C + BYTE1(v46))
          ^ *(unsigned __int8 *)(v4 + BYTE2(v45))) << 8)
        | v12
        ^ *(unsigned __int8 *)(v3 + HIBYTE(v44))
        ^ *(unsigned __int8 *)(dword_13CA9C + (unsigned __int8)v41)
        ^ *(unsigned __int8 *)(v4 + BYTE1(v46));
    v17 = (unsigned __int8)v46;
    v18 = HIBYTE(v46);
    v47 = v14 | (v13 << 24);
    *a2 = v47;
    v19 = *(unsigned __int8 *)(v3 + BYTE1(v45));
    a2[1] = v16 | (v15 << 24);
    v20 = *(unsigned __int8 *)(v3 + HIBYTE(v41));
    v21 = *(unsigned __int8 *)(v3 + v17);
    v52 = *(unsigned __int8 *)(dword_13CA9C + HIBYTE(v41));
    v22 = BYTE2(v41);
    v23 = *(unsigned __int8 *)(v3 + (unsigned __int8)v45);
    v24 = *(unsigned __int8 *)(v4 + HIBYTE(v41)) ^ v21 ^ v19 ^ *(unsigned __int8 *)(dword_13CA9C + BYTE2(v44));
    v42 = *(unsigned __int8 *)(v3 + BYTE1(v44));
    v25 = (v24 << 16)
        | ((*(unsigned __int8 *)(dword_13CA9C + BYTE1(v45)) ^ v21 ^ v20 ^ *(unsigned __int8 *)(v4 + BYTE2(v44))) << 8)
        | v20
        ^ *(unsigned __int8 *)(dword_13CA9C + v17)
        ^ *(unsigned __int8 *)(v4 + BYTE1(v45))
        ^ *(unsigned __int8 *)(v3 + BYTE2(v44))
        | ((v19 ^ *(unsigned __int8 *)(v3 + BYTE2(v44)) ^ *(unsigned __int8 *)(v4 + v17) ^ v52) << 24);
    v26 = ((*(unsigned __int8 *)(v4 + v18) ^ v23 ^ v42 ^ *(unsigned __int8 *)(dword_13CA9C + v22)) << 16)
        | ((*(unsigned __int8 *)(dword_13CA9C + BYTE1(v44))
          ^ *(unsigned __int8 *)(v3 + v18)
          ^ v23
          ^ *(unsigned __int8 *)(v4 + v22)) << 8)
        | *(unsigned __int8 *)(v3 + v22)
        ^ *(unsigned __int8 *)(v3 + v18)
        ^ *(unsigned __int8 *)(dword_13CA9C + (unsigned __int8)v45)
        ^ *(unsigned __int8 *)(v4 + BYTE1(v44))
        | ((v42
          ^ *(unsigned __int8 *)(v3 + v22)
          ^ *(unsigned __int8 *)(v4 + (unsigned __int8)v45)
          ^ *(unsigned __int8 *)(dword_13CA9C + v18)) << 24);
    a2[2] = v25;
    a2[3] = v26;
    v27 = v47 ^ v50[4];
    *a2 = v27;
    v44 = v27;
    v28 = v50[5] ^ (v16 | (v15 << 24));
    a2[1] = v28;
    v41 = v28;
    v29 = v25 ^ v50[6];
    a2[2] = v29;
    v46 = v29;
    v45 = v50[7] ^ v26;
    a2[3] = v45;
    v50 += 4;
  }
  while ( v53 != v50 );
  v43 = *(unsigned __int8 *)(v3 + (unsigned __int8)v28) | (*(unsigned __int8 *)(v3 + HIBYTE(v27)) << 24);
  v30 = *(unsigned __int8 *)(v3 + (unsigned __int8)v29) | (*(unsigned __int8 *)(v3 + HIBYTE(v28)) << 24);
  v31 = *(unsigned __int8 *)(v3 + (unsigned __int8)v27)
      | (*(unsigned __int8 *)(v3 + HIBYTE(v45)) << 24)
      | (*(unsigned __int8 *)(v3 + BYTE1(v28)) << 8);
  v32 = *(unsigned __int8 *)(v3 + BYTE1(v45));
  v33 = *(unsigned __int8 *)(v3 + BYTE2(v27));
  v34 = *(unsigned __int8 *)(v3 + BYTE2(v28));
  v35 = *(unsigned __int8 *)(v3 + (unsigned __int8)v45)
      | (*(unsigned __int8 *)(v3 + HIBYTE(v46)) << 24)
      | (*(unsigned __int8 *)(v3 + BYTE1(v27)) << 8);
  v36 = v31 | (*(unsigned __int8 *)(v3 + BYTE2(v46)) << 16);
  v37 = v43 | (*(unsigned __int8 *)(v3 + BYTE1(v46)) << 8) | (*(unsigned __int8 *)(v3 + BYTE2(v45)) << 16);
  v38 = v30 | (v32 << 8) | (v33 << 16);
  v39 = v35 | (v34 << 16);
  *a2 = v36;
  a2[1] = v37;
  a2[2] = v38;
  a2[3] = v39;
  *a2 = v36 ^ a1[40];
  a2[1] = v37 ^ a1[41];
  result = v38 ^ a1[42];
  a2[2] = result;
  a2[3] = v39 ^ a1[43];
  return result;
}

