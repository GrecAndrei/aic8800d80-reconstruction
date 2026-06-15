// v23 annotated: sub_12D890 @ 0x12d890
// Original: 12d890_sub_12D890.c
// Primary struct: <unclustered>
//
// sub_12D890 @ 0x12d890, size 40 bytes
unsigned __int8 *__fastcall sub_12D890(unsigned __int8 *a1, int a2, _BYTE *a3)
{
  unsigned __int8 *result; // r0
  unsigned __int16 v5; // [sp+Eh] [bp-2h] BYREF

  result = sub_12D648(a1, a2, (unsigned __int8 *)dword_12D8B8, 5, &v5);
  if ( result )
  {
    if ( v5 <= 0x17u )
      return nullptr;
    else
      *a3 = v5 - 2;
  }
  return result;
}

