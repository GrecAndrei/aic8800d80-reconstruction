// fwstruct annotate: 12d5a0_fp_convert_uint.c
// fp_convert_uint @ 0x12d5a0, size 26 bytes
// Doc: fp_convert_uint [util]: Convert value via float helpers and pack into uint64
// fp_convert_uint [util]: Convert value via float helpers and pack into uint64
float __fastcall fp_convert_uint(unsigned int a1)
{
  float v1; // r0
  __int64 v2; // r0
  int v3; // r0

  v1 = sub_12D464(a1);
  v2 = sub_1428B8(LODWORD(v1));
  v3 = sub_142968(v2, HIDWORD(v2), dword_12D5C0, dword_12D5C4);
  return sub_142F2C(v3);
}

