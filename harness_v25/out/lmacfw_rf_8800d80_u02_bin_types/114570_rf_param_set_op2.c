// rf_param_set_op2 @ 0x114570, size 10 bytes
// Doc: rf_param_set_op2 [rf]: Set RF parameter via opcode 2 with 12-byte payload
// rf_param_set_op2 [rf]: Set RF parameter via opcode 2 with 12-byte payload
int  rf_param_set_op2(int a1)
{
  return rf_init_or_config_n_318(2, a1, 0xCu);
}

