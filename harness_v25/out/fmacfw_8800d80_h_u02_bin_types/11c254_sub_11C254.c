// sub_11C254 @ 0x11c254, size 208 bytes
unsigned int  sub_11C254(int a1, int a2, uint32_t *a3, uint32_t *a4, uint32_t *a5, int *a6)
{
  unsigned int v6; // r4
  int v7; // r8
  int v8; // r0
  int v9; // r9
  unsigned int v10; // r12
  unsigned int v11; // r7
  __int16 **v12; // r4
  __int16 *v13; // r1
  int v14; // r2
  __int16 **v16; // r4
  __int16 *v17; // r1
  int v18; // r2

  v6 = *(uint32_t *)(a1 + 4);
  v7 = *(unsigned __int8 *)(a1 + 12);
  v8 = ((v6 >> 4) & 7) + 1;
  *a6 = v8;
  v9 = (v6 >> 9) & 3;
  v10 = v6 >> 4;
  v11 = v6 & 0xF;
  if ( a2 == 7 && ((v6 >> 7) & 3) == 1 )
  {
    v16 = (__int16 **)off_11C324;
    v17 = *(__int16 **)off_11C324;
    *a3 = dword_11C33C;
    v18 = *v17;
    *a4 = dword_11C340;
    if ( v18 < 0 )
    {
      if ( v11 )
      {
        sub_12F32C(dword_11C34C, dword_11C334, 2707);
        if ( **v16 >= 0 )
          goto LABEL_3;
        v8 = *a6;
      }
      if ( v8 != 1 )
        sub_12F32C(dword_11C344, dword_11C334, 2709);
    }
  }
  else
  {
    v12 = (__int16 **)off_11C324;
    v13 = *(__int16 **)off_11C324;
    *a3 = dword_11C328;
    v14 = *v13;
    *a4 = dword_11C32C;
    if ( v14 < 0 )
    {
      if ( (v10 & 4) == 0 || (sub_12F32C(dword_11C348, dword_11C334, 2717), **v12 < 0) )
      {
        if ( v11 > 0xB )
          sub_12F32C(dword_11C338, dword_11C334, 2718);
      }
    }
  }
LABEL_3:
  *a5 = *(uint32_t *)(dword_11C330 + 696 * v7 + 12);
  return v9 + 6 * v11;
}

