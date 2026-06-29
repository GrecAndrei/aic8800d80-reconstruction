// fwstruct annotate: 12d460_sub_12D460.c
// sub_12D460 @ 0x12d460, size 126 bytes
int __fastcall sub_12D460(int result, _DWORD *a2, _DWORD *a3)
{
  __int16 **v3; // r7
  _DWORD *v4; // r6

  v3 = (__int16 **)off_12D4E0;
  v4 = (_DWORD *)result;
  if ( **(__int16 **)off_12D4E0 < 0 )
  {
    if ( result || (result = sub_12F46C(dword_12D4F0, dword_12D4E4, 384), **v3 < 0) )
    {
      if ( a2 )
      {
        if ( (_DWORD *)*a2 != a3 )
        {
          result = sub_12F46C(dword_12D4E8, dword_12D4E4, 385);
          if ( **v3 >= 0 )
            goto LABEL_3;
        }
        if ( a3 )
          goto LABEL_3;
      }
      else if ( a3 )
      {
        goto LABEL_14;
      }
      result = sub_12F46C(dword_12D4EC, dword_12D4E4, 386);
    }
  }
  if ( a2 )
  {
LABEL_3:
    *a2 = *a3;
    goto LABEL_4;
  }
LABEL_14:
  *v4 = *a3;
LABEL_4:
  if ( (_DWORD *)v4[1] == a3 )
    v4[1] = a2;
  *a3 = 0;
  return result;
}

