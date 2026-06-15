// v23 annotated: sub_12AE40 @ 0x12ae40
// Original: 12ae40_sub_12AE40.c
// Primary struct: <unclustered>
//
// sub_12AE40 @ 0x12ae40, size 48 bytes
int *sub_12AE40()
{
  int *result; // r0
  _BYTE *v1; // r3
  int v2; // r1

  sub_12AE04(0);
  sub_12AE04(1);
  sub_12AE04(2);
  result = sub_12AE04(3);
  v1 = (_BYTE *)dword_12AE70;
  v2 = dword_12AE70 + 96;
  do
  {
    v1[1] = 0;
    v1[2] = 0;
    *v1 = 0;
    v1 += 3;
  }
  while ( v1 != (_BYTE *)v2 );
  return result;
}

