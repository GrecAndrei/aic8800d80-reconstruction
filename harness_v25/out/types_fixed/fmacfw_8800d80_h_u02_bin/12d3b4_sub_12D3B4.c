// sub_12D3B4 @ 0x12d3b4, size 40 bytes
unsigned int __fastcall sub_12D3B4(unsigned __int8 *a1, int a2, unsigned int a3)
{
  unsigned __int8 *v3; // r1
  int v4; // t1

  if ( !a2 )
    return a3;
  v3 = &a1[a2];
  do
  {
    v4 = *a1++;
    a3 = *(_DWORD *)(dword_12D3DC + 4 * (v4 ^ HIBYTE(a3))) ^ (a3 << 8);
  }
  while ( v3 != a1 );
  return a3;
}

