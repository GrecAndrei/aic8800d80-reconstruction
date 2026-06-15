// sub_1200D4 @ 0x1200d4, size 28 bytes
int __fastcall sub_1200D4(int result)
{
  _DWORD *v1; // r4
  int v2; // r5

  v1 = *(_DWORD **)(result + 240);
  if ( v1 )
  {
    v2 = result;
    do
    {
      result = sub_11F28C(v2, (int)v1, 0);
      v1 = (_DWORD *)*v1;
    }
    while ( v1 );
  }
  return result;
}

