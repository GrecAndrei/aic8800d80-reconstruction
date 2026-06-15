// v23 annotated: rf_subcmd_dispatch @ 0x11532c
// Original: 11532c_rf_subcmd_dispatch.c
// Primary struct: <unclustered>
//
// rf_subcmd_dispatch @ 0x11532c, size 80 bytes
// Doc: rf_subcmd_dispatch [rf]: Dispatch on subcommand (cmp r0, 5)
// rf_subcmd_dispatch [rf]: Dispatch on subcommand (cmp r0, 5)
int __fastcall rf_subcmd_dispatch(int result)
{
  switch ( result )
  {
    case 0:
      *(_DWORD *)off_11537C = 2;
      break;
    case 1:
      *(_DWORD *)off_11537C = 4;
      break;
    case 2:
      *(_DWORD *)off_11537C = 8;
      break;
    case 3:
      *(_DWORD *)off_11537C = 16;
      break;
    case 5:
      *(_DWORD *)off_11537C = 32;
      break;
    default:
      if ( **(__int16 **)off_115380 < 0 )
        result = rf_cmd_send_n264(dword_115388, dword_115384, 944);
      break;
  }
  return result;
}

