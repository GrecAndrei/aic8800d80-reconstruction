// fwstruct annotate: 114588_rf_emit_setup_word.c
// rf_emit_setup_word @ 0x114588, size 14 bytes
void rf_emit_setup_word()
{
  *(_DWORD *)(*(_DWORD *)off_114598 + 8) &= ~2u;
}

