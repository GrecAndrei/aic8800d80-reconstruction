// sub_13C698 @ 0x13c698, size 110 bytes
int __fastcall sub_13C698(int a1, int a2, int a3)
{
  int v3; // r5
  int v4; // r6
  int v5; // r7
  int result; // r0
  char v7; // r4
  int v8; // r2
  int v9; // r5

  v3 = *(unsigned __int8 *)(a1 + 29);
  v4 = *(unsigned __int8 *)(a1 + 28);
  if ( v3 == 255 )
    return 0;
  v5 = dword_13C708;
  result = *(_DWORD *)(dword_13C708 + 1320 * v4 + 1200);
  if ( result )
  {
    v7 = a2;
    result = sub_13C484(a2, a3);
    if ( result )
    {
      v9 = 696 * v3;
      result = *(_BYTE *)(v9 + dword_13C70C) & 1;
      if ( (*(_BYTE *)(v9 + dword_13C70C) & 1) != 0 )
      {
        if ( (v7 & 0xFC) != 0xD0 || (unsigned int)(v8 - 13) > 1 )
        {
          if ( *(_DWORD *)(v5 + 1320 * v4 + 1204) )
            return 2;
          else
            return 0;
        }
      }
      else
      {
        return (*(_DWORD *)(v9 + dword_13C70C - 34) >> 3) & 1;
      }
    }
  }
  return result;
}

