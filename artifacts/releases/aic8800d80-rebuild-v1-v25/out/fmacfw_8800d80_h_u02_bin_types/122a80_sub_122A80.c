// sub_122A80 @ 0x122a80, size 98 bytes
int  sub_122A80(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v4; // r7
  int v6; // r4
  uint8_t *v9; // r4

  v4 = dword_122AE8;
  v6 = *a2;
  if ( **(__int16 **)off_122AE4 < 0 && *(uint8_t *)(dword_122AE8 + 1320 * v6 + 106) )
    sub_12F32C(dword_122AF0, dword_122AEC, 3702);
  v9 = (uint8_t *)(v4 + 1320 * v6);
  v9[143] = a2[1];
  v9[144] = a2[2];
  v9[145] = 0;
  sub_12C8D0(134, a4, a3);
  return 0;
}

