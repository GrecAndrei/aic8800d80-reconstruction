// sub_11DA5C @ 0x11da5c, size 26 bytes
int __fastcall sub_11DA5C(int result, int a2)
{
  int v2; // r3

  if ( a2 != 127 )
  {
    v2 = *(char *)(result + 97);
    *(_BYTE *)(result + 97) = a2;
    if ( v2 != a2 )
    {
      result = *(_DWORD *)(result + 72);
      if ( result )
        return rf_get_status_byte_n_a24(result);
    }
  }
  return result;
}

