// sub_13688C @ 0x13688c, size 290 bytes
uint32_t * sub_13688C(int a1)
{
  uint8_t *v2; // r6
  int v3; // r0
  uint8_t *v4; // r5
  int v5; // r1
  unsigned int v6; // r2
  int *v7; // r3
  uint8_t *v8; // r0
  uint8_t *v9; // r3
  char *v10; // r0
  int v12; // r0
  int v13; // r0

  v2 = (uint8_t *)sub_12C7EC(5145, 5, 7, 2u);
  v3 = sub_12C7EC(5143, 5, 7, 2u);
  *(uint8_t *)(dword_1369B0 + 696 * (*(unsigned __int8 *)(a1 + 107) + 32) + 37) = 0;
  v4 = (uint8_t *)v3;
  sub_136528();
  *v2 = 0;
  v2[1] = *(uint8_t *)(a1 + 107);
  sub_12D108(dword_1369B4, (uint32_t *)v2 - 3);
  v7 = *((int **)off_1369B8 + 2);
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
    sub_10D0BC(v6 | (*((unsigned __int8 *)v7 + 413) << 16) | 0x80000000, 4999, v6);
  }
  else
  {
LABEL_7:
    sub_10D0BC(0, v5, v6);
  }
  sub_12063C((int *)a1, 0, 0);
  if ( *(uint8_t *)(a1 + 108) )
  {
    v12 = sub_12C7EC(30, 0, 7, 4u);
    *(uint8_t *)(v12 + 2) = 0;
    *(uint8_t *)(v12 + 3) = *(uint8_t *)(a1 + 107);
    sub_12D108(dword_1369B4, (uint32_t *)(v12 - 12));
  }
  if ( *(uint32_t *)(a1 + 72) )
  {
    v8 = (uint8_t *)sub_12C7EC(57, 0, 7, 1u);
    *v8 = *(uint8_t *)(a1 + 107);
    sub_12D108(dword_1369B4, (uint32_t *)v8 - 3);
  }
  *v4 = 0;
  v4[1] = *(uint8_t *)(a1 + 107);
  sub_12D108(dword_1369B4, (uint32_t *)v4 - 3);
  sub_1366E0();
  if ( !*(uint8_t *)(a1 + 1224) )
  {
    v13 = dword_1369C4;
    *(uint8_t *)off_1369C0 = 0;
    sub_12E948(v13);
  }
  v9 = off_1369BC;
  v10 = (char *)off_1369BC + 20;
  *((uint8_t *)off_1369BC + 13) = 0;
  v9[14] = 0;
  sub_124CF4((int)v10);
  return sub_12CBF4(7u, 3);
}

