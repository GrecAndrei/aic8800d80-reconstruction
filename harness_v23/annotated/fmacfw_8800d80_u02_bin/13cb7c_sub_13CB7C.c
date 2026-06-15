// v23 annotated: sub_13CB7C @ 0x13cb7c
// Original: 13cb7c_sub_13CB7C.c
// Primary struct: <unclustered>
//
// sub_13CB7C @ 0x13cb7c, size 108 bytes
unsigned int *__fastcall sub_13CB7C(unsigned int *result)
{
  __int64 v1; // r2
  int v2; // r1
  unsigned int v3; // r5
  unsigned int v4; // r7
  unsigned int v5; // r1

  v1 = *(_QWORD *)(result + 1);
  v2 = dword_13CBE8;
  v3 = *result;
  v4 = result[3];
  *result = dword_13CBE8 & (*result >> 15) | ((_DWORD)v1 << 17) & 0x1000000 | (2 * *result) & 0xFEFEFEFE;
  LODWORD(v1) = (2 * v1) & 0xFEFEFEFE | v2 & ((unsigned int)v1 >> 15) | (HIDWORD(v1) << 17) & 0x1000000;
  HIDWORD(v1) = (2 * HIDWORD(v1)) & 0xFEFEFEFE | v2 & (HIDWORD(v1) >> 15) | (v4 << 17) & 0x1000000;
  v5 = v2 & (v4 >> 15) | (2 * v4) & 0xFEFEFEFE;
  *(_QWORD *)(result + 1) = v1;
  if ( (v3 & 0x80) != 0 )
    v5 ^= 0x87000000;
  result[3] = v5;
  return result;
}

