// sub_12A2B4 @ 0x12a2b4, size 152 bytes
unsigned __int8 *__fastcall sub_12A2B4(unsigned __int8 *result, int a2)
{
  int v2; // r5
  int v3; // r7
  unsigned __int8 *v4; // r8
  int v5; // r9
  int v6; // r4
  unsigned __int8 *v7; // r5
  int v8; // r3

  if ( *(_DWORD *)(result + 0x1320) && !(*(_DWORD *)(result + 0x1a8) | a2) )
  {
    v2 = *(_DWORD *)(result + 0x1324);
    v3 = dword_12A34C;
    v4 = (unsigned __int8 *)(dword_12A34C + 140 * v2);
    v5 = 140 * v2;
    if ( *(_DWORD *)(v4 + 0x40) )
    {
      timestamp_remove_058(dword_12A34C + 140 * v2);
      *(_DWORD *)(v4 + 0x40) = 0;
    }
    v6 = v3 + 140 * v2;
    if ( *(_BYTE *)(v6 + 64) )
    {
      timestamp_remove_058(v5 + 48 + v3);
      *(_BYTE *)(v6 + 64) = 0;
    }
    v7 = (unsigned __int8 *)(v3 + 140 * v2);
    v8 = *(_DWORD *)(v7 + 0x1c8);
    *(_DWORD *)(v7 + 0x1cc) = 0;
    *(_DWORD *)(v7 + 0x1e0) = 0;
    *(_DWORD *)(v7 + 0x210) = 0;
    if ( v8 )
    {
      timestamp_remove_058(v5 + 96 + v3);
      *(_DWORD *)(v7 + 0x1c8) = 0;
    }
    return sub_129A28(v4);
  }
  return result;
}

