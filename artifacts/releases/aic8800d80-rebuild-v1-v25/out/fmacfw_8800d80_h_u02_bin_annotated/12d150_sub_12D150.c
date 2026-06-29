// fwstruct annotate: 12d150_sub_12D150.c
// sub_12D150 @ 0x12d150, size 52 bytes
int __fastcall sub_12D150(int result, _DWORD *a2)
{
  _DWORD *v2; // r5

  v2 = (_DWORD *)result;
  if ( **(__int16 **)off_12D184 < 0 && !a2 )
    result = sub_12F32C(dword_12D18C, dword_12D188, 95);
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

