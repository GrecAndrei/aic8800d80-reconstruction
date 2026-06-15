// sub_12018C @ 0x12018c, size 136 bytes
int __fastcall sub_12018C(int result, int a2)
{
  int v2; // r3
  int v3; // r4
  int v4; // r1
  int v5; // r3
  int v6; // r3
  int v7; // r3

  v2 = 15 * a2;
  v3 = *(_DWORD *)(result + 1200);
  v4 = result + 120 * a2 + 480;
  *(_BYTE *)(result + 8 * v2 + 579) = 0;
  if ( v3 == v4 )
  {
    v5 = *(unsigned __int8 *)(result + 579);
    *(_DWORD *)(result + 1200) = 0;
    v4 = result + 480;
    if ( v5
      || (v4 = result + 600, *(_BYTE *)(result + 699))
      || (v4 = result + 720, *(_BYTE *)(result + 819))
      || (v4 = result + 840, *(_BYTE *)(result + 939)) )
    {
      *(_DWORD *)(result + 1200) = v4;
      return result;
    }
  }
  if ( *(_DWORD *)(result + 1204) == v4 )
  {
    v6 = *(unsigned __int8 *)(result + 1059);
    *(_DWORD *)(result + 1204) = 0;
    if ( v6 )
    {
      v7 = result + 960;
    }
    else
    {
      if ( !*(_BYTE *)(result + 1179) )
        return result;
      v7 = result + 1080;
    }
    *(_DWORD *)(result + 1204) = v7;
  }
  return result;
}

