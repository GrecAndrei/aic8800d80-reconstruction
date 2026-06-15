// float_compare_9988 @ 0x109988, size 610 bytes
// Doc: float_compare_9988 [util]: Float32 pair compare and range helper
// float_compare_9988 [util]: Float32 pair compare and range helper
int __fastcall float_compare_9988(unsigned int a1, float *a2, float *a3, int a4)
{
  float v4; // s13
  float v5; // s14
  float v10; // s15
  float v11; // s16
  float v12; // s19
  float v13; // s18
  float v14; // s20
  float v15; // s17
  float v16; // s21
  __int64 v17; // r0
  int v18; // r1
  int v19; // r2
  int v20; // r0
  float v21; // s10
  float v22; // s11
  float v23; // s15
  float v24; // s17
  float v25; // s16
  int v26; // r0
  int result; // r0
  float v28; // s12
  float v29; // s15
  char v30; // r3
  __int64 v31; // r0
  float v32; // s15
  float v33; // s13
  float v34; // s14
  float v35; // s9
  float v36; // s10
  float v37; // s11
  __int64 v38; // r0

  v4 = a2[1];
  v5 = *a2;
  if ( v4 <= *a2 )
  {
    v4 = *a2;
    v5 = a2[1];
  }
  v10 = a2[2];
  if ( v10 <= v4 )
  {
    if ( v10 < v5 )
      v5 = a2[2];
    v10 = v4;
  }
  *(_BYTE *)(a4 + 2) = (unsigned int)(float)(v10 - v5);
  v11 = *a2;
  v12 = a2[1];
  v13 = a2[2];
  v14 = (float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v13 * v13);
  v15 = (float)(*a2 + v12) + v13;
  v16 = (float)(v14 * 3.0) - (float)(v15 * v15);
  if ( v16 > 0.0 )
  {
    v17 = sub_142A94((float)(v14 * 3.0) - (float)(v15 * v15));
    if ( !sub_143028(v17, HIDWORD(v17), dword_109BF0, dword_109BF4) )
      goto LABEL_11;
    v16 = flt_109BF8;
    goto LABEL_10;
  }
  v38 = sub_142A94(-v16);
  if ( sub_143028(v38, HIDWORD(v38), dword_109BF0, dword_109BF4) )
  {
    v16 = flt_109C08;
LABEL_10:
    v20 = dword_109BFC;
    *(_BYTE *)a4 |= 4u;
    log_printf(v20, v18, v19);
    v11 = *a2;
    v12 = a2[1];
    v13 = a2[2];
  }
LABEL_11:
  v21 = a3[1];
  v22 = a3[2];
  v23 = -(float)((float)(1.0 / v16) * v15);
  v24 = (float)((float)((float)((float)((float)((float)(1.0 / v16) * 3.0) * v11) - (float)((float)(1.0 / v16) * v15))
                      * *a3)
              + (float)((float)((float)((float)((float)(1.0 / v16) * 3.0) * v12) - (float)((float)(1.0 / v16) * v15))
                      * v21))
      + (float)((float)((float)((float)((float)(1.0 / v16) * 3.0) * v13) - (float)((float)(1.0 / v16) * v15)) * v22);
  v25 = (float)((float)((float)((float)(v23 * v11) + (float)(v14 * (float)(1.0 / v16))) * *a3)
              + (float)((float)((float)(v23 * v12) + (float)(v14 * (float)(1.0 / v16))) * v21))
      + (float)((float)((float)(v23 * v13) + (float)(v14 * (float)(1.0 / v16))) * v22);
  if ( a1 > 0xD && v24 < 20.0
    || (v31 = sub_142A94(LODWORD(v24)), (result = sub_143028(v31, HIDWORD(v31), dword_109BF0, dword_109BF4)) != 0) )
  {
    v26 = dword_109C00;
    *(_BYTE *)a4 |= 8u;
    result = log_printf(v26, v18, v19);
    v24 = 1.0;
    v28 = 2.0;
  }
  else
  {
    v28 = (float)(v24 * v24) + 1.0;
  }
  v29 = (float)-v25 / v24;
  if ( v29 > flt_109C04 )
  {
    v30 = -1;
  }
  else if ( v29 < 0.0 )
  {
    v30 = 0;
  }
  else
  {
    v30 = (unsigned int)(float)(v29 + 0.5);
  }
  *(_BYTE *)(a4 + 1) = v30;
  v32 = *a2;
  v33 = a2[1];
  v34 = a2[2];
  v35 = *a3;
  v36 = a3[1];
  v37 = a3[2];
  *(float *)(a4 + 12) = v25;
  *(float *)(a4 + 8) = v24;
  *(float *)(a4 + 4) = (float)((float)((float)((float)((float)((float)(v24 * v32) + v25) - v35)
                                             * (float)((float)((float)(v24 * v32) + v25) - v35))
                                     + (float)((float)((float)((float)(v24 * v33) + v25) - v36)
                                             * (float)((float)((float)(v24 * v33) + v25) - v36)))
                             + (float)((float)((float)((float)(v24 * v34) + v25) - v37)
                                     * (float)((float)((float)(v24 * v34) + v25) - v37)))
                     / v28;
  return result;
}

