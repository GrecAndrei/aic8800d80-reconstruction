// sub_133F24 @ 0x133f24, size 162 bytes
int sub_133F24()
{
  int v1; // r4
  int v2; // r6
  int v3; // r5
  int v4; // r0
  int v5; // r2
  int v6; // r3
  __int16 v7; // r1
  uint8_t *v8; // r0

  if ( sub_12CD48(6u) == 9 )
  {
    v1 = *((uint32_t *)off_133FC8 + 4);
    v2 = dword_133FCC + 1320 * *(unsigned __int8 *)(v1 + 61);
    v3 = *(unsigned __int8 *)(v2 + 116);
    v4 = sub_12C7EC(75, 0, 6, 6u);
    *(uint8_t *)(v4 + 4) = *(uint8_t *)(v1 + 58);
    *(uint16_t *)(v4 + 2) = *(uint16_t *)(v1 + 56);
    *(uint8_t *)v4 = *(uint8_t *)(v1 + 61);
    sub_12C84C(v4);
    v5 = dword_133FD0 + 696 * v3;
    v6 = 2 - (*(uint32_t *)(v2 + 1208) & 1);
    v7 = __rev16(*(unsigned __int16 *)(v1 + 52));
    *(uint8_t *)(v5 + 52) = v6;
    *(uint16_t *)(v5 + 56) = v7;
    if ( v6 == 2 )
    {
      v8 = (uint8_t *)sub_12C7EC(5145, 5, 6, 2u);
      *v8 = 0;
      v8[1] = *(uint8_t *)(v1 + 61);
      sub_12C84C((int)v8);
    }
    sub_134CC4(0);
    return 0;
  }
  else
  {
    if ( sub_12CD48(6u) == 10 )
      sub_13467C(10);
    return 0;
  }
}

