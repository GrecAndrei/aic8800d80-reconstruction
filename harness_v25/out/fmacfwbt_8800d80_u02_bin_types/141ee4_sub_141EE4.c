// sub_141EE4 @ 0x141ee4, size 130 bytes
uint8_t * sub_141EE4(int a1)
{
  int v2; // r5
  __int16 v3; // r3
  int v4; // r2
  uint8_t *result; // r0
  int v6; // r5
  uint64_t v7; // r2
  int i; // r8
  unsigned uint64_t v9; // r6
  unsigned uint64_t v10; // r0

  v2 = *(unsigned __int8 *)(a1 + 47);
  timestamp_remove_058(a1 + 52);
  v3 = *(uint16_t *)a1;
  v4 = dword_141F68;
  result = off_141F6C;
  *(uint16_t *)a1 &= ~8u;
  v6 = v4 + 1320 * v2;
  LOBYTE(v4) = result[1] - 1;
  *(uint32_t *)(v6 + 4) &= ~0x100u;
  result[1] = v4;
  if ( (v3 & 0x60) == 0x20 )
  {
    v7 = *(QWORD *)(a1 + 24);
    for ( i = 1; ; i = (unsigned __int8)(i + 1) )
    {
      v9 = v7 - *(QWORD *)(v6 + 40);
      LODWORD(v10) = sub_12C068();
      if ( v9 >= v10 )
        break;
      v7 = *(QWORD *)(a1 + 24) + *(unsigned int *)(a1 + 16);
      *(QWORD *)(a1 + 24) = v7;
    }
    return (uint8_t *)sub_141DE8(a1, i);
  }
  return result;
}

