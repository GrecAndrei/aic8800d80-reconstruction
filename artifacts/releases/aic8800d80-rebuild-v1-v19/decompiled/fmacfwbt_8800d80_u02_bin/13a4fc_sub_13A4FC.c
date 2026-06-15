// sub_13A4FC @ 0x13a4fc, size 64 bytes
int __fastcall sub_13A4FC(int a1, int a2)
{
  int v2; // r4
  _DWORD *v3; // r5
  int result; // r0

  v2 = a1 + 4 * a2;
  v3 = *(_DWORD **)(v2 + 408);
  if ( **(__int16 **)off_13A53C < 0 && !v3 )
    sub_12F694(dword_13A548, dword_13A544, 3320);
  sub_125058((int)(v3 + 68));
  result = sub_12D470(dword_13A540, v3);
  *(_DWORD *)(v2 + 408) = 0;
  return result;
}

