// rf_emit_setup_word @ 0x114588, size 10 bytes
// Doc: rf_emit_setup_word [rf]: Emits a 4-byte setup word (type 0x14) to RF path
// rf_emit_setup_word [rf]: Emits a 4-byte setup word (type 0x14) to RF path
int  rf_emit_setup_word(int a1)
{
  return rf_init_or_config_n_318(4, a1, 0x14u);
}

