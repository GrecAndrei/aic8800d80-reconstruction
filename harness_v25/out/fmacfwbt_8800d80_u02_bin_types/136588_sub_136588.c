// sub_136588 @ 0x136588, size 140 bytes
int sub_136588()
{
  __int16 **v0; // r4

  v0 = (__int16 **)off_136614;
  if ( **(__int16 **)off_136614 < 0 && msg_get_value(7u) != 1 && msg_get_value(7u) && msg_get_value(7u) != 3 )
    sub_12F694(dword_136624, dword_13661C, 341);
  if ( msg_get_value(7u) == 1 )
  {
    if ( **v0 < 0 && *((uint32_t *)off_136618 + 1) )
      sub_12F694(dword_136620, dword_13661C, 349);
    sub_136AE8();
  }
  else if ( msg_get_value(7u) == 3 )
  {
    message_dispatch_n84(7171, 13, 7);
    rf_bus_mark_n_3b7(7u, 0);
  }
  return 0;
}

