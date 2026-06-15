// v23 annotated: sub_12F554 @ 0x12f554
// Original: 12f554_sub_12F554.c
// Primary struct: <unclustered>
//
// sub_12F554 @ 0x12f554, size 48 bytes
// Doc: sub_122F554 [unknown]: Save callee-saved regs and dereference first argument pointer
// sub_122F554 [unknown]: Save callee-saved regs and dereference first argument pointer
_DWORD **__fastcall sub_12F554(_DWORD **result)
{
  _DWORD *v1; // r4
  int v2; // r6
  _DWORD *v3; // r5
  int v4; // r2

  v1 = *result;
  if ( *result )
  {
    v2 = dword_12F584;
    v3 = result;
    do
    {
      while ( 1 )
      {
        rf_bus_mark_n100_d2d0((int)v3);
        result = (_DWORD **)v2;
        if ( !v1[3] )
          break;
        result = (_DWORD **)list_push_tail(v2, v1);
        v1 = (_DWORD *)*v3;
        if ( !*v3 )
          return result;
      }
      v4 = v1[2];
      v1 = (_DWORD *)*v3;
      *(_WORD *)(v4 + 8) = 0;
    }
    while ( v1 );
  }
  return result;
}

