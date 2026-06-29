// rf_cmd_process_n4e @ 0x12ec6c, size 6 bytes
// Doc: rf_cmd_process_n4e [rf]: RF command processing: store header, call sub, shift nibble from r8
// rf_cmd_process_n4e [rf]: RF command processing: store header, call sub, shift nibble from r8
int rf_cmd_process_n4e()
{
  return *(uint32_t *)off_12EC74;
}

