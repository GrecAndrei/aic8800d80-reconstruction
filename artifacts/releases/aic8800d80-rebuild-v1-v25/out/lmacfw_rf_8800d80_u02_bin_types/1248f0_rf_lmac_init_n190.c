// rf_lmac_init_n190 @ 0x1248f0, size 26 bytes
// Doc: rf_lmac_init_n190 [rf]: LMAC RF subsystem init: clear status byte and invoke bringup at 0x11dc54
// rf_lmac_init_n190 [rf]: LMAC RF subsystem init: clear status byte and invoke bringup at 0x11dc54
int rf_lmac_init_n190()
{
  *(uint8_t *)off_12490C = 0;
  event_queue_push(144, 0);
  msg_parse(dword_124910);
  return 0;
}

