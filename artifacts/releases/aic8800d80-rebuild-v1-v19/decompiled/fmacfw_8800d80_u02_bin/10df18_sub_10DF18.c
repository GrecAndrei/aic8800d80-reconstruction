// sub_10DF18 @ 0x10df18, size 40 bytes
int __fastcall sub_10DF18(int a1)
{
  int v1; // r2
  int v2; // r0
  int v3; // r1

  v1 = dword_10DF40;
  v2 = 4 * a1;
  v3 = dword_10DF40 + 192;
  do
  {
    *(_DWORD *)(v1 - 12) = *(_DWORD *)(v1 - 12) & 0xFFFFFFF3 | v2;
    v1 += 12;
  }
  while ( v1 != v3 );
  return sub_102EB8(1, 16, 0x10u, dword_10DF44);
}

