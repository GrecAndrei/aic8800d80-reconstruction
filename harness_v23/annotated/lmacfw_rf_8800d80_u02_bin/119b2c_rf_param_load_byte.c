// v23 annotated: rf_param_load_byte @ 0x119b2c
// Original: 119b2c_rf_param_load_byte.c
// Primary struct: <unclustered>
//
// rf_param_load_byte @ 0x119b2c, size 32 bytes
// Doc: rf_param_load_byte [util]: Load a single parameter byte and dispatch to handler
// rf_param_load_byte [util]: Load a single parameter byte and dispatch to handler
int __fastcall rf_param_load_byte(int a1, unsigned __int8 *a2, int a3, int a4)
{
  lmac_table_lookup_n540(*a2);
  sub_11DED8(58, a4, a3);
  return 0;
}

