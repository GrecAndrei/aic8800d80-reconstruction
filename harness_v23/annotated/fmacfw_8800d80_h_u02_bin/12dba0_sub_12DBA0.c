// v23 annotated: sub_12DBA0 @ 0x12dba0
// Original: 12dba0_sub_12DBA0.c
// Primary struct: <unclustered>
//
// sub_12DBA0 @ 0x12dba0, size 36 bytes
unsigned __int8 *__fastcall sub_12DBA0(unsigned __int8 *a1, int a2)
{
  unsigned __int8 *result; // r0
  _WORD v3[3]; // [sp+Eh] [bp-6h] BYREF

  result = sub_12D648(a1, a2, (unsigned __int8 *)dword_12DBC4, 5, v3);
  if ( result )
  {
    if ( v3[0] != 26 )
      return nullptr;
  }
  return result;
}

