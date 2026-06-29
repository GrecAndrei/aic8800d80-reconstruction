// bt_fmac_sub_a5bc @ 0x10a5bc, size 572 bytes
// Doc: bt_fmac_sub_a5bc [bt]: Bluetooth FMAC auxiliary handler
// bt_fmac_sub_a5bc [bt]: Bluetooth FMAC auxiliary handler
int  bt_fmac_sub_a5bc(int a1, unsigned int a2, unsigned __int8 *a3, int *a4)
{
  unsigned __int8 *v6; // r6
  uint8_t *v7; // r9
  int i; // r8
  int v9; // r2
  int v10; // r0
  int v11; // r4
  char v12; // r0
  float *v13; // r5
  int v14; // r4
  float *v15; // r2
  int v16; // r3
  int v17; // r1
  int v18; // r0
  uint8_t *v19; // r1
  int v20; // r2
  int v21; // r4
  float v23; // s12
  float v24; // s13
  float v25; // s14
  float v26; // s15
  int v27; // r3
  int v28; // r0
  int v29; // r3
  float v30[3]; // [sp+0h] [bp-58h] BYREF
  float v31[3]; // [sp+Ch] [bp-4Ch] BYREF
  uint8_t v32[4]; // [sp+18h] [bp-40h] BYREF
  uint8_t var3C[92]; // [sp+1Ch] [bp-3Ch] BYREF

  if ( a2 > 9 && a1 != 3 )
  {
    v6 = a3 - 1;
    v7 = v32;
    for ( i = 0; i != 4; ++i )
    {
      v9 = 0;
      v10 = 0;
      do
      {
        if ( (unsigned __int8)i != (unsigned __int8)v9 )
        {
          if ( (uint8_t)v9 )
          {
            v30[v10] = (float)v6[v9];
            v11 = 4 * v10;
          }
          else
          {
            v11 = 4 * v10;
            v30[v10] = 128.0;
          }
          v10 = (unsigned __int8)(v10 + 1);
          *(float *)&var3C[v11 - 16] = (float)a4[v9];
        }
        ++v9;
      }
      while ( v9 != 4 );
      *v7 = 0;
      v12 = sub_1095B8(v30, v31);
      *v7 = v12;
      if ( (v12 & 0xE) == 0 )
        float_compare_9988(a2, v30, v31, (int)v7);
      v7 += 16;
    }
    v13 = (float *)var3C;
    v14 = 0;
    v15 = (float *)var3C;
    v16 = 0;
    v17 = 128;
    do
    {
      v18 = *((unsigned __int8 *)v15 - 4);
      if ( *((uint8_t *)v15 - 4) )
      {
        if ( (v18 & 8) != 0 )
          goto LABEL_42;
        if ( v18 == 1 )
          v14 = 1;
      }
      else if ( v17 == 128 )
      {
        v17 = v16;
      }
      else if ( *v15 <= *(float *)&var3C[16 * v17] )
      {
        v17 = v16;
      }
      v16 = (unsigned __int8)(v16 + 1);
      v15 += 4;
    }
    while ( v16 != 4 );
    if ( v14 )
    {
      if ( v17 != 128 )
      {
LABEL_21:
        v19 = &var3C[16 * v17 + 60];
        v20 = (unsigned __int8)*(v19 - 64);
        v21 = (unsigned __int8)*(v19 - 63);
        if ( !*(v19 - 64) )
          return v21;
        goto LABEL_22;
      }
      v29 = 0;
      do
      {
        v15 = (float *)*((unsigned __int8 *)v13 - 4);
        if ( v15 == (float *)1 )
        {
          v15 = (float *)&var3C[16 * v17 + 60];
          if ( v17 == 128 )
          {
            v17 = v29;
          }
          else if ( *v13 <= *(v15 - 15) )
          {
            v17 = v29;
          }
        }
        v29 = (unsigned __int8)(v29 + 1);
        v13 += 4;
      }
      while ( v29 != 4 );
    }
    if ( v17 == 128 )
    {
LABEL_42:
      v21 = 32 * (9 - a2);
      log_printf(dword_10A7FC, a2, v15);
      return v21;
    }
    goto LABEL_21;
  }
  v23 = (float)a3[1];
  v24 = (float)*a4;
  v25 = (float)a4[1];
  v26 = (float)a4[2];
  v30[1] = (float)*a3;
  v30[2] = v23;
  v31[0] = v24;
  v31[1] = v25;
  v31[2] = v26;
  v30[0] = 128.0;
  v32[0] = 0;
  if ( a2 > 9 )
  {
    v28 = sub_1095B8(v30, v31);
    v32[0] = v28;
    if ( (v28 & 0xE) != 0 )
    {
      v20 = v28;
    }
    else
    {
      float_compare_9988(a2, v30, v31, (int)v32);
      v27 = v32[0];
      v20 = v32[0];
      if ( (v32[0] & 0xE) == 0 )
        goto LABEL_26;
    }
    v21 = 32 * (9 - a2);
    log_printf(dword_10A7F8, a2, v20);
    return v21;
  }
  float_compare_9988(a2, v30, v31, (int)v32);
  v20 = v32[0];
  v27 = v32[0];
  if ( (v32[0] & 0xE) != 0 )
  {
    v21 = 128;
    log_printf(dword_10A7F8, a2, v32[0]);
    return v21;
  }
LABEL_26:
  v21 = v32[1];
  if ( v27 )
  {
LABEL_22:
    log_printf(dword_10A7F8, a2, v20);
    return v21;
  }
  return v21;
}

