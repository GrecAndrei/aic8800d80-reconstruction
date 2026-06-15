// v23 annotated: sub_12D4B8 @ 0x12d4b8
// Original: 12d4b8_sub_12D4B8.c
// Primary struct: <unclustered>
//
// sub_12D4B8 @ 0x12d4b8, size 52 bytes
int __fastcall sub_12D4B8(int result, _DWORD *a2)
{
  _DWORD *v2; // r5

  v2 = (_DWORD *)result;
  if ( **(__int16 **)off_12D4EC < 0 && !a2 )
    result = sub_12F694(dword_12D4F4, dword_12D4F0, 95);
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

