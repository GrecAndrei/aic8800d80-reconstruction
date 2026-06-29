// fwstruct annotate: 1009a0_sub_1009A0.c
// sub_1009A0 @ 0x1009a0, size 52 bytes
int __fastcall sub_1009A0(int a1, unsigned int a2)
{
  unsigned int *v2; // r5
  int v3; // r0
  unsigned int v4; // r4
  int result; // r0
  unsigned int v6; // [sp+4h] [bp-8h] BYREF

  v2 = (unsigned int *)off_1009D4;
  v3 = sub_100898(a1, a2, &v6);
  v4 = *v2;
  *v2 |= 0x4000000u;
  result = sub_1007A4(v3, dword_1009D8, 96, v6);
  *v2 = v4 & 0xFBFFFFFF;
  return result;
}

