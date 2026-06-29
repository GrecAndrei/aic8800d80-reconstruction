// sub_123660 @ 0x123660, size 68 bytes
int  sub_123660(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v7; // r0

  if ( **(__int16 **)off_1236A4 < 0 )
  {
    v7 = *a2;
    if ( HIBYTE(*(uint32_t *)off_1236A8) + 8 >= v7 )
      goto LABEL_3;
    sub_12F32C(dword_1236B0, dword_1236AC, 1801);
  }
  v7 = *a2;
LABEL_3:
  sub_121534(v7);
  sub_12C8D0(39, a4, a3);
  return 0;
}

