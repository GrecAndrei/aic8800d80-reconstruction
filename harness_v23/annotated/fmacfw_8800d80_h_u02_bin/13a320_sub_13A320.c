// v23 annotated: sub_13A320 @ 0x13a320
// Original: 13a320_sub_13A320.c
// Primary struct: <unclustered>
//
// sub_13A320 @ 0x13a320, size 64 bytes
int __fastcall sub_13A320(int a1, int a2)
{
  int v2; // r4
  _DWORD *v3; // r5
  int result; // r0

  v2 = a1 + 4 * a2;
  v3 = *(_DWORD **)(v2 + 408);
  if ( **(__int16 **)off_13A360 < 0 && !v3 )
    sub_12F32C(dword_13A36C, dword_13A368, 3320);
  sub_124CF4((int)(v3 + 68));
  result = sub_12D108(dword_13A364, v3);
  *(_DWORD *)(v2 + 408) = 0;
  return result;
}

