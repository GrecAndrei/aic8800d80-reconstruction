// v23 annotated: rf_bus_write_n_42a_13ec @ 0x1213ec
// Original: 1213ec_rf_bus_write_n_42a_13ec.c
// Primary struct: <unclustered>
//
// rf_bus_write_n_42a_13ec @ 0x1213ec, size 42 bytes
// Doc: rf_bus_write_n_42a_13ec [rf]: RF bus write operation
// rf_bus_write_n_42a_13ec [rf]: RF bus write operation
int rf_bus_write_n_42a_13ec()
{
  if ( msg_get_value(0) == 1 )
    *(_DWORD *)off_121418 = 48;
  return rf_bus_mark_n_3b7(0);
}

