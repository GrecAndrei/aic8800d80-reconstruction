// v23 annotated: sub_12DCE0 @ 0x12dce0
// Original: 12dce0_sub_12DCE0.c
// Primary struct: bt_hci_cmd (cluster 5, 21 funcs)
// Fields: ogf=0x0, ocf=0x1
//
// sub_12DCE0 @ 0x12dce0, size 36 bytes
unsigned __int8 *__fastcall sub_12DCE0(unsigned __int8 *a1, int a2)
{
  unsigned __int8 *result; // r0
  _WORD v3[3]; // [sp+Eh] [bp-6h] BYREF

  result = sub_12D788(a1, a2, (unsigned __int8 *)dword_12DD04, 5, v3);
  if ( result )
  {
    if ( v3[0] != 26 )
      return nullptr;
  }
  return result;
}

