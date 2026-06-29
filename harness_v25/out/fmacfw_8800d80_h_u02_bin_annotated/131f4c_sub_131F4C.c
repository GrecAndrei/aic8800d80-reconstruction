// fwstruct annotate: 131f4c_sub_131F4C.c
// sub_131F4C @ 0x131f4c, size 62 bytes
int __fastcall sub_131F4C(int a1, unsigned __int8 *a2)
{
  int v2; // r6
  int v4; // r0

  v2 = dword_131F8C;
  sub_124CF4(696 * *a2 + 672 + dword_131F8C);
  v4 = *a2;
  if ( *(_BYTE *)(v2 + 696 * v4 + 37) )
    sub_1321E4(v4);
  else
    sub_12C8D0(5130, 13, 5);
  return 0;
}

