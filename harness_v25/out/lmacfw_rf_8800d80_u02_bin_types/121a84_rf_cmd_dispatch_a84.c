// rf_cmd_dispatch_a84 @ 0x121a84, size 82 bytes
// Doc: rf_cmd_dispatch [rf]: Dispatch RF command by opcode field
// rf_cmd_dispatch [rf]: Dispatch RF command by opcode field
void  rf_cmd_dispatch_a84(int a1)
{
  int word_n_ce4; // r0
  int v3; // r5
  uint32_t *v4; // r4

  if ( **(uint8_t **)rf_cmd_dispatch_46c == 3 )
  {
    word_n_ce4 = rf_efuse_read_word_n_ce4();
    v3 = word_n_ce4;
    if ( word_n_ce4 )
    {
      *(uint32_t *)(a1 + 24) = 49374;
      sub_1282E8(word_n_ce4, a1, 28);
      v4 = off_121ADC;
      while ( !*(uint32_t *)off_121ADC )
        ;
      list_push_tail(*(uint32_t *)off_121AE0 + 540, (uint32_t *)(v3 - 4));
      *v4 = 1;
      sub_10CF3C();
    }
    else
    {
      msg_parse(dword_121AE4);
    }
  }
}

