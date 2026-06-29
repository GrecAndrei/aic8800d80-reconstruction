// sub_122C34 @ 0x122c34, size 92 bytes
int  sub_122C34(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v4; // r7
  int v6; // r5
  int v9; // r0

  v4 = dword_122C94;
  v6 = *a2;
  if ( **(__int16 **)off_122C90 < 0 && *(uint8_t *)(dword_122C94 + 1320 * v6 + 106) )
    sub_12F46C(dword_122C9C, dword_122C98, 2639);
  v9 = v4 + 1320 * v6;
  *(uint16_t *)(v9 + 112) = *((uint16_t *)a2 + 1);
  *(uint8_t *)(v9 + 114) = a2[4];
  sub_12CA10(76, a4, a3);
  return 0;
}

