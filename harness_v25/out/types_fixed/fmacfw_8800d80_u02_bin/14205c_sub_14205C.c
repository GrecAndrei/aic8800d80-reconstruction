// sub_14205C @ 0x14205c, size 64 bytes
int __fastcall sub_14205C(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r3

  v3 = 0;
  v4 = dword_14209C;
  do
  {
    if ( (*(_WORD *)v4 & 1) != 0
      && *(unsigned __int8 *)(v4 + 47) == a2
      && *(unsigned __int8 *)(v4 + 46) == a1
      && *(unsigned __int8 *)(v4 + 2) == a3 )
    {
      return dword_14209C + 72 * v3;
    }
    ++v3;
    v4 += 72;
  }
  while ( v3 != 8 );
  return 0;
}

