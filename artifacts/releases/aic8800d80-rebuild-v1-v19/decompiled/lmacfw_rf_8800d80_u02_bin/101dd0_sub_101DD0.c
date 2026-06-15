// sub_101DD0 @ 0x101dd0, size 58 bytes
int __fastcall sub_101DD0(int result)
{
  _DWORD *v1; // r2
  unsigned int v2; // r3
  int v3; // r3

  v1 = off_101E10;
  *(_DWORD *)off_101E0C = *(_DWORD *)off_101E0C & 0xFFFFFF | ((unsigned __int8)(result / 2) << 24);
  v2 = *v1 & 0xFFFFF0FF;
  if ( (result & 1) != 0 )
  {
    if ( result >= 0 )
      v3 = v2 | 0xB00;
    else
      v3 = v2 | 0x500;
    *v1 = v3;
  }
  else
  {
    *v1 = v2 | 0x800;
  }
  return result;
}

