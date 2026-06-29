// sub_109EB0 @ 0x109eb0, size 300 bytes
int * sub_109EB0(
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

  v11 = off_109FDC;
  *(uint32_t *)off_109FDC |= 0x400u;
  v15 = dword_109FE0;
  *v11 &= ~0x400u;
  sub_12EB90(1, v15);
  if ( a5 )
  {
    sub_1048E8((int)a2, 1, dword_100000, dword_100000, 0, 1);
    return (int *)sub_109C74(24, (int)a2, 1, (int)v36);
  }
  else
  {
    if ( a8 == 1 )
    {
      sub_1048E8((int)a2, 1, dword_100000, dword_100000, 0, 0);
      sub_109C74(24, (int)a2, 0, (int)v36);
      v30 = (uint32_t *)dword_109FE4;
      v31 = (uint32_t *)dword_109FE8;
      v32 = (uint32_t *)dword_109FEC;
      v33 = dword_109FE4 + 128;
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
      v17 = (int *)dword_109FE4;
      v18 = (int *)dword_109FE8;
      v19 = (int *)dword_109FEC;
      v20 = dword_109FE4 + 128;
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
      sub_104CC8(a2, v25, a9, a10, a11);
    }
    sub_105270(16, 32, (float *)a2, a3, a4, 1, a6, a1, a7);
    result = sub_103E90(a3);
    v28 = off_109FF0;
    v29 = dword_109FF4;
    *(uint32_t *)off_109FF0 &= ~0x200u;
    *v28 |= 0x200u;
    *v28 &= ~0x200u;
    a2[129] = v29;
    a2[131] = v29;
  }
  return result;
}

