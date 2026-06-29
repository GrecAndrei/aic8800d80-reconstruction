// sub_12917C @ 0x12917c, size 124 bytes
int  sub_12917C(int result, int a2, int a3)
{
  uint32_t *v3; // r6
  int v5; // r2
  int v6; // r5
  unsigned int v7; // r3
  int v9; // r1
  int v10; // r3
  int v11; // r1
  uint32_t *v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r1

  v3 = off_1291F8;
  v5 = *(uint32_t *)(a3 + 4);
  v6 = *(unsigned __int8 *)off_1291F8;
  v7 = v5 & 0xFFFFFFFE;
  *(uint32_t *)(a3 + 4) = v5 & 0xFFFFFFFE;
  if ( v6 )
  {
    v9 = *(unsigned __int8 *)(a3 + 114);
    if ( !*(uint8_t *)(a3 + 114) )
    {
      if ( result )
      {
        v12 = off_129200;
        v13 = *(uint32_t *)off_1291FC;
        *(uint32_t *)(a3 + 4) = v7 | 2;
        v14 = v12[4];
        v15 = *(unsigned __int16 *)(v13 + 56);
        v3[5] = a3;
        *((uint8_t *)v3 + 29) = 5;
        result = timestamp_update((int)(v3 + 3), v15 + v14);
        v7 = *(uint32_t *)(a3 + 4);
        if ( !a2 )
          goto LABEL_6;
        goto LABEL_8;
      }
      v7 = v5 & 0xFFFFFFFC;
    }
    if ( !a2 )
    {
LABEL_6:
      *(uint32_t *)(a3 + 4) = v7 & 0xFFFFFFFB;
      return result;
    }
LABEL_8:
    *(uint32_t *)(a3 + 4) = v7 | 4;
    rf_fault_dump_n_1d4(result, v9, v5);
    sub_128EA0();
    v10 = *((uint32_t *)off_129200 + 4);
    v11 = *(unsigned __int16 *)(*(uint32_t *)off_1291FC + 58);
    v3[5] = a3;
    *((uint8_t *)v3 + 29) = 6;
    return timestamp_update(dword_129204, v11 + v10);
  }
  return result;
}

