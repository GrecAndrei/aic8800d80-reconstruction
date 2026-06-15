// v23 annotated: rf_event_dispatch @ 0x131144
// Original: 131144_rf_event_dispatch.c
// Primary struct: <unclustered>
//
// rf_event_dispatch @ 0x131144, size 40 bytes
// Doc: rf_event_dispatch [rf]: Wrapper dispatching to lower-level handler with 3 args
// rf_event_dispatch [rf]: Wrapper dispatching to lower-level handler with 3 args
unsigned __int8 *__fastcall rf_event_dispatch(_BYTE *a1, int a2, int a3)
{
  unsigned __int8 *result; // r0

  result = sub_12DEC8(a1, a2);
  if ( result )
  {
    *(_WORD *)(a3 + 228) = result[2] | (result[3] << 8);
    *(_BYTE *)(a3 + 230) = result[4];
  }
  else
  {
    *(_BYTE *)(a3 + 230) = 0;
    *(_WORD *)(a3 + 228) = 0;
  }
  return result;
}

