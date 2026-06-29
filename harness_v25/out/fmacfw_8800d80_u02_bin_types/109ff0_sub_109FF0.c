// sub_109FF0 @ 0x109ff0, size 300 bytes
int * sub_109FF0(
        int a1,
        int *a2,
        int a3,
        unsigned __int8 a4,
        int a5,
        unsigned __int8 a6,
        int a7,
        int a8,
        int a9,
        int a10,
        uint64_t *a11)
{
  uint32_t *v11; // r4
  int v15; // r1
  int *v17; // r5
  int *v18; // r2
  int *v19; // r3
  int v20; // r0
  int *v21; // r4
  int v22; // t1
  int v23; // r6
  int v24; // t1
  int v25; // r1
  int v26; // t1
  int *result; // r0
  uint32_t *v28; // r3
  int v29; // r1
  uint32_t *v30; // r2
  uint32_t *v31; // r0
  uint32_t *v32; // r1
  int v33; // r5
  int *v34; // r3
  int v35; // t1
  uint8_t v36[20]; // [sp+18h] [bp-14h] BYREF

  v11 = off_10A11C;
  *(uint32_t *)off_10A11C |= 0x400u;
  v15 = dword_10A120;
  *v11 &= ~0x400u;
  feature_guard_check(1, v15);
  if ( a5 )
  {
    crypto_or_phy_init((int)a2, 1, dword_100000, dword_100000, 0, 1);
    return (int *)memcpy_vfp_n9db4(24, (int)a2, 1, (int)v36);
  }
  else
  {
    if ( a8 == 1 )
    {
      crypto_or_phy_init((int)a2, 1, dword_100000, dword_100000, 0, 0);
      memcpy_vfp_n9db4(24, (int)a2, 0, (int)v36);
      v30 = (uint32_t *)dword_10A124;
      v31 = (uint32_t *)dword_10A128;
      v32 = (uint32_t *)dword_10A12C;
      v33 = dword_10A124 + 128;
      v34 = a2;
      do
      {
        v35 = *v34++;
        *v30++ = v35;
        *v31++ = v34[31];
        *v32++ = v34[95];
      }
      while ( v30 != (uint32_t *)v33 );
    }
    else
    {
      v17 = (int *)dword_10A124;
      v18 = (int *)dword_10A128;
      v19 = (int *)dword_10A12C;
      v20 = dword_10A124 + 128;
      v21 = a2;
      do
      {
        v22 = *v17++;
        *v21++ = v22;
        v24 = *v18++;
        v23 = v24;
        v21[31] = v24;
        v26 = *v19++;
        v25 = v26;
        v21[95] = v26;
        v21[63] = v23;
      }
      while ( v17 != (int *)v20 );
      sub_104DE0(a2, v25, a9, a10, a11);
    }
    fmac_crypto_or_xfer_proc(16, 32, (float *)a2, a3, a4, 1, a6, a1, a7);
    result = sub_103FA8(a3);
    v28 = off_10A130;
    v29 = dword_10A134;
    *(uint32_t *)off_10A130 &= ~0x200u;
    *v28 |= 0x200u;
    *v28 &= ~0x200u;
    a2[129] = v29;
    a2[131] = v29;
  }
  return result;
}

