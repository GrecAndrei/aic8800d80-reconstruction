// sub_119478 @ 0x119478, size 108 bytes
int  sub_119478(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v4; // r4
  int v6; // r8
  int v9; // r7
  uint8_t *v10; // r4

  v4 = dword_1194E8;
  v6 = *a2;
  if ( **(__int16 **)off_1194E4 < 0 )
  {
    v9 = 8 * v6;
    if ( *(uint8_t *)(dword_1194E8 + 224 * v6 + 94) )
      rf_cmd_send_n264(dword_1194F0, dword_1194EC, 3702);
  }
  else
  {
    v9 = 8 * v6;
  }
  v10 = (uint8_t *)(v4 + 32 * (v9 - v6));
  v10[118] = a2[1];
  v10[119] = a2[2];
  v10[120] = 0;
  sub_11DED8(134, a4, a3);
  return 0;
}

