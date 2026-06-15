// v23 annotated: sub_12D290 @ 0x12d290
// Original: 12d290_sub_12D290.c
// Primary struct: <unclustered>
//
// sub_12D290 @ 0x12d290, size 52 bytes
int __fastcall sub_12D290(int result, _DWORD *a2)
{
  _DWORD *v2; // r5

  v2 = (_DWORD *)result;
  if ( **(__int16 **)off_12D2C4 < 0 && !a2 )
    result = sub_12F46C(dword_12D2CC, dword_12D2C8, 95);
  if ( *v2 )
  {
    *a2 = *v2;
  }
  else
  {
    v2[1] = a2;
    *a2 = 0;
  }
  *v2 = a2;
  return result;
}

