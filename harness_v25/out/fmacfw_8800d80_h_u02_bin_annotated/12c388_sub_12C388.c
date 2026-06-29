// fwstruct annotate: 12c388_sub_12C388.c
// sub_12C388 @ 0x12c388, size 26 bytes
int __fastcall sub_12C388(int a1, _BYTE *a2, _BYTE *a3)
{
  int v3; // r3
  int result; // r0

  v3 = *(char *)(a1 + 109);
  if ( v3 == 127 )
    result = *(_DWORD *)off_12C3A4;
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

