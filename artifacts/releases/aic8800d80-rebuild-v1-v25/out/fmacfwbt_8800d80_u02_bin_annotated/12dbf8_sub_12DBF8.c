// fwstruct annotate: 12dbf8_sub_12DBF8.c
// sub_12DBF8 @ 0x12dbf8, size 40 bytes
// Doc: sub_122DBF8 [unknown]: Setup call frame, prepare 5 args, call helper
// sub_122DBF8 [unknown]: Setup call frame, prepare 5 args, call helper
unsigned __int8 *__fastcall sub_12DBF8(unsigned __int8 *a1, int a2, _BYTE *a3)
{
  unsigned __int8 *result; // r0
  unsigned __int16 v5; // [sp+Eh] [bp-2h] BYREF

  result = sub_12D9B0(a1, a2, (unsigned __int8 *)dword_12DC20, 5, &v5);
  if ( result )
  {
    if ( v5 <= 0x17u )
      return nullptr;
    else
      *a3 = v5 - 2;
  }
  return result;
}

