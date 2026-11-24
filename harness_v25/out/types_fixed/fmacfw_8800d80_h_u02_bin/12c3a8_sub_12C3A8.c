// sub_12C3A8 @ 0x12c3a8, size 64 bytes
int __fastcall sub_12C3A8(int result, int a2)
{
  int v2; // r4
  int v3; // r0

  if ( *((_BYTE *)off_12C3E8 + 197) )
  {
    v2 = *(_DWORD *)(*(_DWORD *)(a2 + 76) + 48);
    v3 = sub_101CAC(
           (*(_DWORD *)(v2 + 20) >> 11) & 7,
           *(_DWORD *)(v2 + 20) & 0x7F,
           (unsigned __int8 *)(*(_DWORD *)(result + 72) + 4));
    result = v3 | (v3 << 8);
    *(_DWORD *)(v2 + 36) = result;
  }
  else if ( **(__int16 **)off_12C3EC < 0 )
  {
    return sub_12F32C(dword_12C3F4, dword_12C3F0, 92);
  }
  return result;
}

