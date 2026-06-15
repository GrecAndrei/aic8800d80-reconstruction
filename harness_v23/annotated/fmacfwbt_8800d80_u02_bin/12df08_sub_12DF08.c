// v23 annotated: sub_12DF08 @ 0x12df08
// Original: 12df08_sub_12DF08.c
// Primary struct: bt_hci_cmd (cluster 4, 22 funcs)
// Fields: ogf=0x0, ocf=0x1
//
// sub_12DF08 @ 0x12df08, size 36 bytes
unsigned __int8 *__fastcall sub_12DF08(unsigned __int8 *a1, int a2)
{
  unsigned __int8 *result; // r0
  _WORD v3[3]; // [sp+Eh] [bp-6h] BYREF

  result = sub_12D9B0(a1, a2, (unsigned __int8 *)dword_12DF2C, 5, v3);
  if ( result )
  {
    if ( v3[0] != 26 )
      return nullptr;
  }
  return result;
}

