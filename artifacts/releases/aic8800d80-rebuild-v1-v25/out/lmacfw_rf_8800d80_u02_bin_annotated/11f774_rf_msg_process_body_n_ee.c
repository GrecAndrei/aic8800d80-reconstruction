// fwstruct annotate: 11f774_rf_msg_process_body_n_ee.c
// rf_msg_process_body_n_ee @ 0x11f774, size 32 bytes
// Doc: rf_mem_read_n1e8 [rf]: Read RF memory region with mailbox kick and flag clear
// rf_mem_read_n1e8 [rf]: Read RF memory region with mailbox kick and flag clear
int rf_msg_process_body_n_ee()
{
  msg_parse(dword_11F794);
  event_queue_push(1071, 1);
  *((_DWORD *)off_11F798 + 20) &= ~2u;
  return 0;
}

