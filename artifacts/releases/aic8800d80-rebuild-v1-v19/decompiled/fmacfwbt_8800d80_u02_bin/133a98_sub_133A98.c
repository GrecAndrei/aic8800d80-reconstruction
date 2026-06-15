// sub_133A98 @ 0x133a98, size 98 bytes
// Doc: rf_cmd_send_n_356 [rf]: Clears cmd flag and disables RF cmd interrupt in MMIO 0x40200e00
// rf_cmd_send_n_356 [rf]: Clears cmd flag and disables RF cmd interrupt in MMIO 0x40200e00
int __fastcall sub_133A98(int a1, int a2)
{
  int v2; // r3

  v2 = *(_WORD *)(a2 + 2) & 0xFC;
  switch ( v2 )
  {
    case 176:
      if ( msg_get_value(6u) == 5 )
        bt_state_query_n_c3c(a2);
      break;
    case 16:
    case 48:
      if ( msg_get_value(6u) == 8 )
        sub_1357B4(a2);
      break;
    case 192:
    case 160:
      return ipc_msg_handle_n_884(a2);
    default:
      if ( v2 == 208 && *(_BYTE *)(a2 + 12) == 8 )
        sub_135924(a2);
      break;
  }
  return 0;
}

