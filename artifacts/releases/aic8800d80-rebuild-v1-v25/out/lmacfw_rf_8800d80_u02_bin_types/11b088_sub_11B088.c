// sub_11B088 @ 0x11b088, size 272 bytes
int  sub_11B088(int a1, int a2, unsigned int a3)
{
  int v3; // r8
  int v4; // r9
  int v5; // r10
  int v6; // r7
  int v7; // r4
  int v10; // r4
  int v11; // r0
  int v12; // r4
  int v13; // r7
  int v14; // r7
  unsigned int v15; // r0
  int v16; // r0
  int v17; // r3
  char *v18; // r1
  bool v19; // zf
  int v20; // r3
  char *v21; // r3
  int result; // r0

  v3 = dword_11B1A0;
  v4 = *((uint32_t *)off_11B198 + 4);
  v5 = *(uint32_t *)(a1 + 72);
  v6 = *(unsigned __int8 *)(v4 + 8);
  v7 = *(uint32_t *)(v4 + 4) - 4000;
  v10 = v7 - a2 - sub_101A20();
  if ( *(uint32_t *)(v3 + 224 * v6 + 72) == v5 )
  {
    result = sub_101A20();
    v12 = v10 - 4000 - result;
    if ( v12 <= 4999 )
      return result;
    v13 = *(uint32_t *)(v4 + 4);
    v14 = v13 - 4000 - sub_101A20();
    v15 = (v12 + a3) >> 1;
    if ( a3 > v15 || (v16 = v15 + a2 - a3, a2 == v16) )
    {
      rf_init_or_query();
      v16 = a2;
    }
    v17 = *(unsigned __int8 *)(v5 + 24);
    v18 = (char *)off_11B19C;
    if ( v17 == 2 )
    {
      if ( *((unsigned __int8 *)off_11B19C + 24) != 255 )
        goto LABEL_18;
      v20 = 1;
    }
    else
    {
      if ( *((unsigned __int8 *)off_11B19C + 28 * v17 + 52) != 255 )
      {
        v18 = (char *)off_11B19C + 28 * v17 + 28;
LABEL_18:
        rf_xosc_setup(v16, (int)v18, 0);
        return rf_xosc_setup(v14, v5, v4);
      }
      v19 = v17 == 1;
      v20 = v17 + 2;
      if ( v19 )
        v20 = 0;
    }
    v21 = (char *)off_11B19C + 28 * v20;
    if ( (unsigned __int8)v21[24] == 255 )
      v18 = nullptr;
    else
      v18 = v21;
    goto LABEL_18;
  }
  sub_101A20();
  if ( a3 > (v10 + a3) >> 1 || (v11 = ((v10 + a3) >> 1) + a2 - a3, a2 == v11) )
  {
    rf_init_or_query();
    v11 = a2;
  }
  return rf_xosc_setup(v11, *(uint32_t *)(v3 + 224 * v6 + 72), v4);
}

