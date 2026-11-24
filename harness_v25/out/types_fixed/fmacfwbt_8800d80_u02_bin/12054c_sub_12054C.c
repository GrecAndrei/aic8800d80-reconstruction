// sub_12054C @ 0x12054c, size 28 bytes
int __fastcall sub_12054C(int result)
{
  _DWORD *v1; // r4
  int v2; // r5

  v1 = *(_DWORD **)(result + 240);
  if ( v1 )
  {
    v2 = result;
    do
    {
      result = sub_11F704(v2, (int)v1, 0);
      v1 = (_DWORD *)*v1;
    }
    while ( v1 );
  }
  return result;
}

