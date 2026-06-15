// sub_12D320 @ 0x12d320, size 126 bytes
int __fastcall sub_12D320(int result, _DWORD *a2, _DWORD *a3)
{
  __int16 **v3; // r7
  _DWORD *v4; // r6

  v3 = (__int16 **)off_12D3A0;
  v4 = (_DWORD *)result;
  if ( **(__int16 **)off_12D3A0 < 0 )
  {
    if ( result || (result = sub_12F32C(dword_12D3B0, dword_12D3A4, 384), **v3 < 0) )
    {
      if ( a2 )
      {
        if ( (_DWORD *)*a2 != a3 )
        {
          result = sub_12F32C(dword_12D3A8, dword_12D3A4, 385);
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
      result = sub_12F32C(dword_12D3AC, dword_12D3A4, 386);
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

