// sub_1239D4 @ 0x1239d4, size 68 bytes
int  sub_1239D4(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v7; // r0
  int v8; // r3

  if ( **(__int16 **)off_123A18 < 0 )
  {
    v7 = *a2;
    if ( HIBYTE(*(uint32_t *)off_123A1C) + 8 >= v7 )
      goto LABEL_3;
    sub_12F694(dword_123A24, dword_123A20, 1801);
  }
  v7 = *a2;
LABEL_3:
  sub_1218D4(v7);
  message_dispatch_n84(39, a4, a3, v8);
  return 0;
}

