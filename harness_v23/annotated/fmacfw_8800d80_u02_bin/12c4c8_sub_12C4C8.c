// v23 annotated: sub_12C4C8 @ 0x12c4c8
// Original: 12c4c8_sub_12C4C8.c
// Primary struct: <unclustered>
//
// sub_12C4C8 @ 0x12c4c8, size 26 bytes
int __fastcall sub_12C4C8(int a1, _BYTE *a2, _BYTE *a3)
{
  int v3; // r3
  int result; // r0

  v3 = *(char *)(a1 + 109);
  if ( v3 == 127 )
    result = *(_DWORD *)off_12C4E4;
  else
    result = (unsigned __int8)v3;
  if ( v3 == 127 )
    result = (unsigned __int8)result;
  if ( a2 )
    *a2 = v3;
  if ( a3 )
    *a3 = result;
  return result;
}

