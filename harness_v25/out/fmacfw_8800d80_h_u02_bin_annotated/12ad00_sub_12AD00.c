// fwstruct annotate: 12ad00_sub_12AD00.c
// sub_12AD00 @ 0x12ad00, size 48 bytes
int *sub_12AD00()
{
  int *result; // r0
  _BYTE *v1; // r3
  int v2; // r1

  sub_12ACC4(0);
  sub_12ACC4(1);
  sub_12ACC4(2);
  result = sub_12ACC4(3);
  v1 = (_BYTE *)dword_12AD30;
  v2 = dword_12AD30 + 96;
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

