// sub_104470 @ 0x104470, size 486 bytes
int __fastcall sub_104470(int a1, int a2, _DWORD *a3)
{
  unsigned int v3; // r3
  int v4; // r5
  int v5; // r0
  int v6; // r11
  int v7; // r10
  int v8; // r4
  int v9; // r0
  float v10; // s16
  __int64 v11; // r8
  __int64 v12; // r4
  __int64 v13; // r6
  __int64 v14; // r0
  __int64 v15; // r0
  __int64 v16; // r0
  int v17; // r0
  int v18; // r0
  __int64 v19; // r0
  int v20; // r0
  int result; // r0
  __int64 v22; // r0
  int v23; // r0
  float v24; // s16
  __int64 v25; // r8
  __int64 v26; // r4
  __int64 v27; // r6
  __int64 v28; // r0
  __int64 v29; // r0
  __int64 v30; // r0
  int v31; // r0
  __int64 v32; // r0
  int v33; // r0

  v3 = a3[seqno_incr_check_3fff(a1, a2, a3)];
  v4 = (unsigned __int16)v3 >> 4;
  if ( (v3 & 0x80000000) == 0 )
  {
    v5 = v3 >> 20;
    if ( ((v3 >> 4) & 0x800) != 0 )
    {
      v4 -= 4096;
      v6 = 1;
      v7 = -1;
    }
    else
    {
      v6 = 1;
      v7 = 1;
    }
LABEL_4:
    v8 = sub_1437A4(v5);
    v9 = sub_1437A4(v4);
    if ( v8 < v9 )
      goto LABEL_5;
    goto LABEL_11;
  }
  v5 = (v3 >> 20) - 4096;
  if ( ((v3 >> 4) & 0x800) == 0 )
  {
    v6 = -1;
    v7 = 1;
    goto LABEL_4;
  }
  v8 = sub_1437A4(v5);
  v9 = sub_1437A4(v4 - 4096);
  v6 = -1;
  v7 = -1;
  if ( v8 < v9 )
  {
LABEL_5:
    v10 = (float)v8 / (float)v9;
    v11 = sub_142A94(LODWORD(v10));
    v12 = sub_142B44(v11, HIDWORD(v11), dword_104658, dword_10465C);
    v13 = sub_142A94((float)(v10 - 1.0) * v10);
    v14 = sub_142B44(v11, HIDWORD(v11), dword_104660, dword_104664);
    v15 = sub_1427D8(v14, HIDWORD(v14), dword_104668, dword_10466C);
    v16 = sub_142B44(v13, HIDWORD(v13), v15, HIDWORD(v15));
    v17 = sub_1427D4(v12, HIDWORD(v12), v16, HIDWORD(v16));
    v18 = sub_143108(v17);
    v19 = sub_142A94(v18);
    v20 = sub_1427D4(dword_104670, dword_104674, v19, HIDWORD(v19));
    result = sub_143108(v20);
    if ( v7 != 1 )
      goto LABEL_16;
    goto LABEL_12;
  }
LABEL_11:
  v24 = (float)v9 / (float)v8;
  v25 = sub_142A94(LODWORD(v24));
  v26 = sub_142B44(v25, HIDWORD(v25), dword_104658, dword_10465C);
  v27 = sub_142A94((float)(v24 - 1.0) * v24);
  v28 = sub_142B44(v25, HIDWORD(v25), dword_104660, dword_104664);
  v29 = sub_1427D8(v28, HIDWORD(v28), dword_104668, dword_10466C);
  v30 = sub_142B44(v27, HIDWORD(v27), v29, HIDWORD(v29));
  v31 = sub_1427D4(v26, HIDWORD(v26), v30, HIDWORD(v30));
  result = sub_143108(v31);
  if ( v7 != 1 )
  {
LABEL_16:
    if ( v6 == 1 )
      return result ^ 0x80000000;
    v22 = sub_142A94(result);
    v23 = sub_1427D4(v22, HIDWORD(v22), dword_104678, dword_10467C);
    return sub_143108(v23);
  }
LABEL_12:
  if ( v6 != 1 )
  {
    v32 = sub_142A94(result ^ 0x80000000);
    v33 = sub_1427D8(v32, HIDWORD(v32), dword_104678, dword_10467C);
    return sub_143108(v33);
  }
  return result;
}

