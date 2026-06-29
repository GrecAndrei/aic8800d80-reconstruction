// sub_121B98 @ 0x121b98, size 156 bytes
int  sub_121B98(int a1, uint8_t *a2, uint8_t *a3)
{
  int v6; // r4
  int v8; // r5
  int v9; // r9
  int v10; // r0
  int v11; // r3
  uint8_t *v12; // r3
  int v13; // r1

  v6 = sub_11EDC8((int *)a1, a2);
  if ( v6 )
    return v6;
  v8 = *(unsigned __int8 *)(a1 + 25);
  v9 = dword_121C34 + 696 * (unsigned __int8)*a2;
  *(uint8_t *)(v9 + 669) = 0;
  *(uint16_t *)(v9 + 670) = 0;
  v10 = sub_121200((unsigned __int8)*a2, v8);
  *a3 = v10;
  v11 = *(uint32_t *)(v9 + 44);
  if ( v11 )
    v10 = sub_121200(*(unsigned __int8 *)(v11 + 35), *(unsigned __int8 *)(a1 + 25));
  v12 = (uint8_t *)(dword_121C38 + 1320 * v8);
  if ( v12[106] )
  {
    if ( (unsigned __int8)*a2 <= 0x1Fu && v12[106] == 2 && !v12[1224] )
    {
      v13 = *(unsigned __int8 *)off_121C40;
      ++*(uint8_t *)off_121C3C;
      if ( v13 == 1 )
        sub_136D48(v10);
    }
    return v6;
  }
  v12[116] = *a2;
  v12[117] = *(uint8_t *)(a1 + 29);
  v12[118] = *(uint8_t *)(a1 + 30);
  return 0;
}

