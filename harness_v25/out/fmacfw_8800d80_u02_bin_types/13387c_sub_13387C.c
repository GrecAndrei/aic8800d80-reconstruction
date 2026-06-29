// sub_13387C @ 0x13387c, size 98 bytes
// Doc: sub_12023fc [unknown]: Unknown function in fmacfwbt firmware
// sub_12023fc [unknown]: Unknown function in fmacfwbt firmware
int  sub_13387C(int a1, int a2)
{
  int v2; // r3

  v2 = *(uint16_t *)(a2 + 2) & 0xFC;
  switch ( v2 )
  {
    case 176:
      if ( msg_get_value(6u) == 5 )
        sub_135A00(a2);
      break;
    case 16:
    case 48:
      if ( msg_get_value(6u) == 8 )
        msg_send_cmd_180a(a2);
      break;
    case 192:
    case 160:
      return timer_set_relative_5668(a2);
    default:
      if ( v2 == 208 && *(uint8_t *)(a2 + 12) == 8 )
        sub_135708(a2);
      break;
  }
  return 0;
}

