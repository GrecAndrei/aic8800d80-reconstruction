// rf_emit_setup_word @ 0x114588, size 14 bytes
void rf_emit_setup_word()
{
  *(uint32_t *)(*(uint32_t *)off_114598 + 8) &= ~2u;
}

