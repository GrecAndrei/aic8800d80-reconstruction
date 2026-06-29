// fwstruct annotate: 12de88_sub_12DE88.c
// sub_12DE88 @ 0x12de88, size 64 bytes
// Doc: log_free_dispatch_n2ee_deb2 [util]: Dispatch log free events (logging utility)
// log_free_dispatch_n2ee_deb2 [util]: Dispatch log free events (logging utility)
_BYTE *__fastcall sub_12DE88(_BYTE *result, int a2)
{
  unsigned int v2; // r1
  _BYTE *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v3 = &result[(unsigned __int8)result[1] + 2];
    if ( *result == 32 )
      break;
    result += (unsigned __int8)result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return nullptr;
  }
  if ( v2 < (unsigned int)v3 )
    return nullptr;
  if ( result )
  {
    if ( result[1] != 1 )
      return nullptr;
  }
  return result;
}

