// patch_apply_n_2ac @ 0x136b28, size 256 bytes
// Doc: patch_apply_n_2ac [patch]: Applies a firmware patch from the patch table
// patch_apply_n_2ac [patch]: Applies a firmware patch from the patch table
uint32_t * patch_apply_n_2ac(int a1)
{
  uint8_t *v2; // r6
  int v3; // r0
  uint8_t *v4; // r5
  int v5; // r1
  unsigned int v6; // r2
  int *v7; // r3
  uint8_t *v8; // r0
  int v9; // r0
  int v11; // r0

  v2 = (uint8_t *)rf_bus_setup_n3a8(5145, 5, 7, 2u);
  v3 = rf_bus_setup_n3a8(5143, 5, 7, 2u);
  *(uint8_t *)(dword_136C28 + 696 * (*(unsigned __int8 *)(a1 + 107) + 32) + 37) = 0;
  v4 = (uint8_t *)v3;
  sub_136828();
  *v2 = 0;
  v2[1] = *(uint8_t *)(a1 + 107);
  list_push_tail(dword_136C2C, (uint32_t *)v2 - 3);
  v7 = *((int **)off_136C30 + 2);
  if ( v7 )
  {
    v5 = 4999;
    while ( 1 )
    {
      if ( (int *)a1 != v7 )
      {
        v6 = *((unsigned __int8 *)v7 + 108);
        if ( *((uint8_t *)v7 + 108) )
        {
          v6 = *((unsigned __int16 *)v7 + 208);
          if ( v6 <= 0x1387 )
            break;
        }
      }
      v7 = (int *)*v7;
      if ( !v7 )
        goto LABEL_7;
    }
    sub_10D054(v6 | (*((unsigned __int8 *)v7 + 413) << 16) | 0x80000000, 4999, v6);
  }
  else
  {
LABEL_7:
    sub_10D054(0, v5, v6);
  }
  sub_120AB4((int *)a1, 0, 0);
  if ( *(uint8_t *)(a1 + 108) )
  {
    v11 = rf_bus_setup_n3a8(30, 0, 7, 4u);
    *(uint8_t *)(v11 + 2) = 0;
    *(uint8_t *)(v11 + 3) = *(uint8_t *)(a1 + 107);
    list_push_tail(dword_136C2C, (uint32_t *)(v11 - 12));
  }
  if ( *(uint32_t *)(a1 + 72) )
  {
    v8 = (uint8_t *)rf_bus_setup_n3a8(57, 0, 7, 1u);
    *v8 = *(uint8_t *)(a1 + 107);
    list_push_tail(dword_136C2C, (uint32_t *)v8 - 3);
  }
  *v4 = 0;
  v9 = dword_136C2C;
  v4[1] = *(uint8_t *)(a1 + 107);
  list_push_tail(v9, (uint32_t *)v4 - 3);
  sub_13697C();
  return rf_bus_mark_n_3b7(7u, 3);
}

