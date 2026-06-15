// v23 annotated: sub_123660 @ 0x123660
// Original: 123660_sub_123660.c
// Primary struct: <unclustered>
//
// sub_123660 @ 0x123660, size 68 bytes
int __fastcall sub_123660(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v7; // r0

  if ( **(__int16 **)off_1236A4 < 0 )
  {
    v7 = *a2;
    if ( HIBYTE(*(_DWORD *)off_1236A8) + 8 >= v7 )
      goto LABEL_3;
    sub_12F32C(dword_1236B0, dword_1236AC, 1801);
  }
  v7 = *a2;
LABEL_3:
  sub_121534(v7);
  sub_12C8D0(39, a4, a3);
  return 0;
}

