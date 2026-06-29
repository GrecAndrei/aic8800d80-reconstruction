// ipc_doorbell_handler_n_3d6 @ 0x1210b4, size 42 bytes
// Doc: ipc_doorbell_handler_n_3d6 [ipc]: IPC doorbell interrupt handler variant 3d6
// ipc_doorbell_handler_n_3d6 [ipc]: IPC doorbell interrupt handler variant 3d6
int ipc_doorbell_handler_n_3d6()
{
  if ( msg_get_value(0) == 1 )
    *(uint32_t *)off_1210E0 = 48;
  return sub_12CD34(0);
}

