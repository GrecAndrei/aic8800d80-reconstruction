// sub_1237A0 @ 0x1237a0, size 68 bytes
int  sub_1237A0(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v7; // r0

  if ( **(__int16 **)off_1237E4 < 0 )
  {
    v7 = *a2;
    if ( HIBYTE(*(uint32_t *)off_1237E8) + 8 >= v7 )
      goto LABEL_3;
    sub_12F46C(dword_1237F0, dword_1237EC, 1801);
  }
  v7 = *a2;
LABEL_3:
  sub_121674(v7);
  sub_12CA10(39, a4, a3);
  return 0;
}

