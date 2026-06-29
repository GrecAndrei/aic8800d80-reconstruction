// sub_1201D4 @ 0x1201d4, size 210 bytes
int  sub_1201D4(int a1)
{
  uint8_t *v2; // r5
  int v3; // r0
  int v4; // r1
  int v5; // r0
  char v6; // r1
  int v7; // r3
  int v8; // r7
  char v10[5]; // [sp+7h] [bp-5h] BYREF

  v2 = (uint8_t *)sub_12C7EC(88, 13, 0, 3);
  v3 = *(unsigned __int8 *)(a1 + 107);
  v10[0] = -1;
  sub_12847C(v3);
  v4 = *(uint32_t *)(a1 + 1216);
  *(uint32_t *)(a1 + 412) = *(uint32_t *)(a1 + 1212);
  *(uint32_t *)(a1 + 416) = v4;
  *(uint16_t *)(a1 + 420) = *(uint16_t *)(a1 + 1220);
  *(uint8_t *)(a1 + 464) = 0;
  sub_12C444(a1);
  v5 = sub_127BF4(a1 + 1212, v10);
  v6 = v10[0];
  v2[1] = v5;
  v2[2] = v6;
  *v2 = *(uint8_t *)(a1 + 107);
  v7 = *(unsigned __int8 *)(a1 + 106);
  if ( *(uint8_t *)(a1 + 106) )
  {
    if ( v7 == 2 )
    {
      *(uint8_t *)(a1 + 231) = 0;
      if ( !v5 )
      {
        sub_128748();
        *((uint8_t *)off_1202B0 + 9) = 1;
      }
    }
    return sub_12C84C(v2);
  }
  *(uint8_t *)(a1 + 146) = v7;
  if ( !v5 )
  {
    v8 = *(unsigned __int8 *)(a1 + 116);
    sub_128748();
    sub_124CF4(a1 + 48);
    sub_124BFC(a1 + 24, *((uint32_t *)off_1202AC + 4) + *(uint32_t *)(dword_1202A8 + 696 * v8 + 8));
    *(uint8_t *)(a1 + 128) = 0;
    *(uint8_t *)(a1 + 147) = 1;
    return sub_12C84C(v2);
  }
  sub_121ED4(a1);
  return sub_12C84C(v2);
}

