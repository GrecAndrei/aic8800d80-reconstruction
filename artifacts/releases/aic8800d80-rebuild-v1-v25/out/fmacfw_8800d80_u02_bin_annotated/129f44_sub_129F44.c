// fwstruct annotate: 129f44_sub_129F44.c
// sub_129F44 @ 0x129f44, size 26 bytes
// Doc: sub_1229F44 [util]: Init helper: calls sub with arg=1, then writes 0xff to indexed offset
// sub_1229F44 [util]: Init helper: calls sub with arg=1, then writes 0xff to indexed offset
int *sub_129F44()
{
  int *result; // r0
  _BYTE *v1; // r3

  result = memset_thunk((int *)dword_129F60, 0, 1u);
  v1 = off_129F64;
  *((_BYTE *)off_129F64 + 113) = -1;
  v1[253] = -1;
  return result;
}

