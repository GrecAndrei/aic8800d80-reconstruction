// rf_bus_setup_n_39c @ 0x12c564, size 22 bytes
// Doc: rf_bus_setup_n_39c [rf]: Configure RF bus access and address/data masking
// rf_bus_setup_n_39c [rf]: Configure RF bus access and address/data masking
int rf_bus_setup_n_39c()
{
  int v0; // r4

  v0 = dword_12C57C;
  bt_xtal_init_check(dword_12C57C);
  return bt_xtal_init_check(v0 + 8);
}

