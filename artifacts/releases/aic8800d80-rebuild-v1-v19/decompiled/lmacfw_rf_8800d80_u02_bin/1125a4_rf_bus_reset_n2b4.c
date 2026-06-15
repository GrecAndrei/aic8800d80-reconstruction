// rf_bus_reset_n2b4 @ 0x1125a4, size 6 bytes
// Doc: rf_bus_reset_n2b4 [rf]: RF bus reset/read register byte stub
// rf_bus_reset_n2b4 [rf]: RF bus reset/read register byte stub
int rf_bus_reset_n2b4()
{
  return *(unsigned __int8 *)rf_cmd_send_n_36c;
}

