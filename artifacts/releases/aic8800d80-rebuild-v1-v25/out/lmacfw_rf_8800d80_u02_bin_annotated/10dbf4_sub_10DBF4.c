// fwstruct annotate: 10dbf4_sub_10DBF4.c
// sub_10DBF4 @ 0x10dbf4, size 64 bytes
int __fastcall sub_10DBF4(int a1)
{
  int v1; // r3
  int v2; // r0
  int v3; // r1

  v1 = dword_10DC3C;
  if ( (*(_BYTE *)off_10DC34 & 0xC0) == 0xC0 )
    v1 = dword_10DC38;
  v2 = 4 * a1;
  v3 = v1 + 16;
  do
  {
    *(_DWORD *)(v3 - 12) = *(_DWORD *)(v3 - 12) & 0xFFFFFFF3 | v2;
    v3 += 12;
  }
  while ( v1 + 208 != v3 );
  return sub_102D4C(1, 16, 0x10u, v1);
}

