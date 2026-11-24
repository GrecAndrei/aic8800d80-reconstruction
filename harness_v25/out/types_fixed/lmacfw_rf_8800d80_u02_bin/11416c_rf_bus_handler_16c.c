// rf_bus_handler_16c @ 0x11416c, size 40 bytes
// Doc: rf_bus_handler_16c [rf]: RF bus transaction handler
// rf_bus_handler_16c [rf]: RF bus transaction handler
int __fastcall rf_bus_handler_16c(_BYTE *a1)
{
  __int16 v2; // r0

  v2 = sub_113A44(0xFu);
  if ( (v2 & 0xFF00) != 0 )
  {
    *a1 = HIBYTE(v2);
    return 0;
  }
  else
  {
    *a1 = v2;
    if ( (_BYTE)v2 )
      return 1;
    else
      return 2;
  }
}

