// fw_state_check_n_c0 @ 0x1017c0, size 404 bytes
// Doc: fw_state_check_n_c0 [util]: Checks firmware state flag (halfword) from global pointer
// fw_state_check_n_c0 [util]: Checks firmware state flag (halfword) from global pointer
void __noreturn fw_state_check_n_c0()
{
  if ( **(__int16 **)off_101954 < 0
    && (unsigned __int8)BYTE2(*(uint32_t *)off_1019A8) + 10 * (HIBYTE(*(uint32_t *)off_1019A8) + 2) != 32 )
  {
    rf_cmd_send_n264(dword_1019B0, dword_1019AC, 6119);
  }
  panic_loop();
}

