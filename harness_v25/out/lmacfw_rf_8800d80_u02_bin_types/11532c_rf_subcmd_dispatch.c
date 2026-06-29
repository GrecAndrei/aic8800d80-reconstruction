// rf_subcmd_dispatch @ 0x11532c, size 80 bytes
// Doc: rf_subcmd_dispatch [rf]: Dispatch on subcommand (cmp r0, 5)
// rf_subcmd_dispatch [rf]: Dispatch on subcommand (cmp r0, 5)
int  rf_subcmd_dispatch(int result)
{
  switch ( result )
  {
    case 0:
      *(uint32_t *)off_11537C = 2;
      break;
    case 1:
      *(uint32_t *)off_11537C = 4;
      break;
    case 2:
      *(uint32_t *)off_11537C = 8;
      break;
    case 3:
      *(uint32_t *)off_11537C = 16;
      break;
    case 5:
      *(uint32_t *)off_11537C = 32;
      break;
    default:
      if ( **(__int16 **)off_115380 < 0 )
        result = rf_cmd_send_n264(dword_115388, dword_115384, 944);
      break;
  }
  return result;
}

