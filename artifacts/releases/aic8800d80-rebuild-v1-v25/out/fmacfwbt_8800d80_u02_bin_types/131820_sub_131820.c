// sub_131820 @ 0x131820, size 118 bytes
int  sub_131820(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  int v4; // r0
  int v7; // r4
  int v8; // r1
  int v9; // r7
  uint8_t *v10; // r0

  v4 = *a2;
  if ( a2[1] )
  {
    v7 = dword_131898 + 696 * v4;
    v8 = *(unsigned __int8 *)(v7 + 34);
    v9 = *(unsigned __int8 *)(dword_13189C + 1320 * v8 + 106);
    *(uint8_t *)(v7 + 52) = 2;
    if ( !v9 && ((*((uint32_t *)off_1318A0 + 1) >> v8) & 1) != 0 )
    {
      v10 = (uint8_t *)rf_bus_setup_n3a8(5145, 5, 6, 2u);
      *v10 = 0;
      v10[1] = *(uint8_t *)(v7 + 34);
      sub_12CBB4((int)v10);
    }
  }
  else
  {
    *(uint8_t *)(dword_131898 + 696 * v4 + 52) = 1;
  }
  message_dispatch_n84(5125, a4, a3);
  return 0;
}

