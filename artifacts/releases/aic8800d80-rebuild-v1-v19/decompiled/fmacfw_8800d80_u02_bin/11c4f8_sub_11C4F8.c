// sub_11C4F8 @ 0x11c4f8, size 44 bytes
int __fastcall sub_11C4F8(int result, int a2)
{
  int v2; // r2
  int v3; // r3

  v2 = dword_11C524;
  v3 = dword_11C524 + 28 * a2;
  if ( *(_DWORD *)(v3 + 24) )
  {
    if ( *(_BYTE *)(v3 + 46) )
      *(_DWORD *)(v3 + 36) = result;
    *(_BYTE *)(v2 + 28 * a2 + 45) = 1;
  }
  return result;
}

