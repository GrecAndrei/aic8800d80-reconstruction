// v23 annotated: rf_bus_reset_short @ 0x112af8
// Original: 112af8_rf_bus_reset_short.c
// Primary struct: <unclustered>
//
// rf_bus_reset_short @ 0x112af8, size 6 bytes
// Doc: rf_msg_handler_n_466 [rf]: Handle incoming RF control message and dispatch
// rf_msg_handler_n_466 [rf]: Handle incoming RF control message and dispatch
int rf_bus_reset_short()
{
  return *(unsigned __int8 *)rf_bus_reset_n2bc;
}

