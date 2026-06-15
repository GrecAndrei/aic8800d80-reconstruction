// v23 annotated: sub_125EFC @ 0x125efc
// Original: 125efc_sub_125EFC.c
// Primary struct: <unclustered>
//
// sub_125EFC @ 0x125efc, size 22 bytes
char *__fastcall sub_125EFC(int a1, char a2)
{
  char *result; // r0

  if ( !*((_DWORD *)off_125F14 + 1) )
    return (char *)sub_125260(a1, a2);
  result = (char *)off_125F14 + a1;
  result[20] = a2;
  return result;
}

