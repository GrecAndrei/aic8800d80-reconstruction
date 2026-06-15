// sub_127AEC @ 0x127aec, size 38 bytes
int __fastcall sub_127AEC(int a1)
{
  int v2; // r0
  int result; // r0

  v2 = sub_121BE4(*(_DWORD *)(a1 + 88));
  *(_DWORD *)(a1 + 88) = v2;
  result = sub_12ACF8(a1, v2);
  *(_BYTE *)(a1 + 85) = *(_BYTE *)(a1 + 85) & 0x9F | 0x20;
  return result;
}

