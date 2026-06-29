// sub_1104FC @ 0x1104fc, size 286 bytes
int  sub_1104FC(int a1, int a2)
{
  uint32_t *v2; // r4
  int *v3; // r7
  unsigned int v6; // r2
  uint32_t *v7; // r9
  int *v8; // r11
  int v9; // r10
  uint32_t *v10; // r0
  uint32_t *v11; // r5
  int v12; // r0
  int *v13; // r3
  int v14; // r0
  int v15; // r1
  __int16 v16; // r2
  uint32_t *v17; // r1
  int v18; // r0
  int v19; // r2
  unsigned int v21; // [sp+4h] [bp-8h]

  v2 = off_110620;
  v3 = (int *)off_110624;
  v21 = *(unsigned __int16 *)(*(uint32_t *)off_11061C + 48);
  sub_1103C4(a2);
  v6 = *(unsigned __int16 *)(a2 + 0xC);
LABEL_2:
  v7 = off_11064C;
  v8 = (int *)off_110650;
  while ( v21 > v6 )
  {
    if ( *v7 <= 4u )
      goto LABEL_24;
    v9 = (*(int ( **)(uint32_t))(*(uint32_t *)(a1 + 4 + 4) + 16))(*(uint32_t *)(a1 + 4));
    if ( !v9 )
    {
      sub_10DAE4(dword_110648, *v7);
LABEL_23:
      if ( *(unsigned __int16 *)(a2 + 0xC) >= (unsigned int)*(unsigned __int16 *)(*(uint32_t *)off_11061C + 50) )
        return 1;
LABEL_24:
      sub_12CFC4(32);
      return 1;
    }
    v10 = (uint32_t *)sub_11017C();
    v11 = v10;
    if ( !v10 )
    {
      sub_10DAE4(dword_110644);
      (*(void ( **)(uint32_t, int))(*(uint32_t *)(a1 + 4 + 4) + 20))(*(uint32_t *)(a1 + 4), v9);
      goto LABEL_23;
    }
    *v10 = 0;
    v12 = *v8;
    v11[1] = 0;
    v11[2] = 0;
    *v11 = v12 + v9;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_110628 = 1;
    }
    v13 = (int *)off_11062C;
    v14 = *(uint32_t *)off_11062C + 1;
    *(uint32_t *)off_11062C = v14;
    *v2 = 1;
    while ( (*v2 & 2) != 0 )
      ;
    if ( *v3 )
    {
      v19 = *(uint32_t *)(a2 + 4);
      if ( v19 )
        *(uint32_t *)(v19 + 4) = v11;
    }
    else
    {
      if ( **(__int16 **)off_110630 < 0 && *(uint32_t *)off_110634 )
      {
        sub_12F32C(dword_11063C, dword_110640, 400);
        v13 = (int *)off_11062C;
        v14 = *(uint32_t *)off_11062C;
      }
      *(uint32_t *)off_110634 = v11;
    }
    v15 = *v3;
    v16 = *(uint16_t *)(a2 + 0xC);
    *(uint32_t *)(a2 + 4) = v11;
    v6 = (unsigned __int16)(v16 + 1);
    *(uint16_t *)(a2 + 0xC) = v6;
    *v3 = (unsigned __int16)(v15 + 1);
    *(uint32_t *)off_110638 = 1;
    if ( v14 )
    {
      v17 = off_110628;
      v18 = v14 - 1;
      *v13 = v18;
      if ( !v18 )
      {
        if ( *v17 )
        {
          __enable_irq();
          v6 = *(unsigned __int16 *)(a2 + 0xC);
        }
      }
      goto LABEL_2;
    }
  }
  return 1;
}

