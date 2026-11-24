// sub_12AA40 @ 0x12aa40, size 44 bytes
int __fastcall sub_12AA40(int a1)
{
  unsigned __int8 *v1; // r3
  int result; // r0

  v1 = (unsigned __int8 *)(dword_12AA6C + 140 * a1);
  if ( *(_DWORD *)(v1 + 0x1c4) == 255 )
    return 0;
  result = *(_DWORD *)(v1 + 0x210);
  if ( *(_DWORD *)(v1 + 0x210) )
    return (unsigned __int8)(13 * *(_DWORD *)(v1 + 0x220) + 11);
  return result;
}

