// sub_117DD8 @ 0x117dd8, size 44 bytes
int __fastcall sub_117DD8(int a1, int a2, int a3)
{
  int v3; // r3
  int v5; // r0
  int result; // r0

  v3 = *(_DWORD *)(a1 + 76);
  v5 = dword_117E04;
  *(_DWORD *)(v3 + 4) = a2;
  result = sub_12D108(v5 + 8 * a3);
  if ( (*(_DWORD *)(a1 + 36) & 0x200000) == 0 )
    return sub_12CFC4(*(_DWORD *)(dword_117E08 + 4 * a3));
  return result;
}

