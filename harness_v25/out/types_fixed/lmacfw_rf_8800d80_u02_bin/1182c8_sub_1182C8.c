// sub_1182C8 @ 0x1182c8, size 40 bytes
int __fastcall sub_1182C8(int result)
{
  int v1; // r4
  int v2; // r5
  int v3; // r6

  v1 = dword_1182F0;
  v2 = result;
  v3 = dword_1182F0 + 608;
  do
  {
    if ( *(unsigned __int8 *)(v1 + 32) == *(unsigned __int8 *)(v2 + 95) )
      result = sub_117D6C(v2, v1, 0);
    v1 += 152;
  }
  while ( v3 != v1 );
  return result;
}

