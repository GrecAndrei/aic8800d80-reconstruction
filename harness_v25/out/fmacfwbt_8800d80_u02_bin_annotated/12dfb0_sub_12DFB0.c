// fwstruct annotate: 12dfb0_sub_12DFB0.c
// sub_12DFB0 @ 0x12dfb0, size 72 bytes
// Doc: rf_fault_dump [rf]: Dumps RF fault status and triggers fault handling path
// rf_fault_dump [rf]: Dumps RF fault status and triggers fault handling path
unsigned __int8 *__fastcall sub_12DFB0(unsigned __int8 *result, int a2)
{
  unsigned int v2; // r1
  unsigned int v3; // r3
  unsigned __int8 *v4; // r4

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v3 = result[1] + 2;
    v4 = &result[v3];
    if ( !*result )
      break;
    result += v3;
    if ( v2 <= (unsigned int)(v4 + 1) )
      return nullptr;
  }
  if ( v2 < (unsigned int)v4 )
    return (unsigned __int8 *)*result;
  if ( result )
  {
    if ( v3 < 6 )
      return nullptr;
  }
  return result;
}

