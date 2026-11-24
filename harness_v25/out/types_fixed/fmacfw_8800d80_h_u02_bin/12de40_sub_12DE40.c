// sub_12DE40 @ 0x12de40, size 32 bytes
unsigned __int8 *__fastcall sub_12DE40(unsigned __int8 *a1, int a2)
{
  unsigned __int8 *result; // r0
  _WORD *(_DWORD *)(v3 + 0xc); // [sp+6h] [bp-6h] BYREF

  result = sub_12D6EC(a1, a2, 37, v3);
  if ( result )
  {
    if ( *(_DWORD *)(v3 + 0x0) != 4 )
      return nullptr;
  }
  return result;
}

