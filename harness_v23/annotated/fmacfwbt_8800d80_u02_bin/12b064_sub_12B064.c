// v23 annotated: sub_12B064 @ 0x12b064
// Original: 12b064_sub_12B064.c
// Primary struct: <unclustered>
//
// sub_12B064 @ 0x12b064, size 48 bytes
int *sub_12B064()
{
  int *result; // r0
  _BYTE *v1; // r3
  int v2; // r1

  sub_12B028(0);
  sub_12B028(1);
  sub_12B028(2);
  result = sub_12B028(3);
  v1 = (_BYTE *)dword_12B094;
  v2 = dword_12B094 + 96;
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

