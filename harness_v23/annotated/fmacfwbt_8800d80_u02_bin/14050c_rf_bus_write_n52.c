// v23 annotated: rf_bus_write_n52 @ 0x14050c
// Original: 14050c_rf_bus_write_n52.c
// Primary struct: <unclustered>
//
// rf_bus_write_n52 @ 0x14050c, size 50 bytes
// Doc: rf_bus_write_n52 [rf]: RF bus MMIO write to 0x40200b08/0x40200b00 control registers
// rf_bus_write_n52 [rf]: RF bus MMIO write to 0x40200b08/0x40200b00 control registers
int rf_bus_write_n52()
{
  if ( msg_get_value(0xBu) == 4 )
  {
    sub_14157C();
    return 0;
  }
  else
  {
    if ( **(__int16 **)off_140540 < 0 )
      sub_12F6C4(dword_140548, dword_140544, 129);
    return 0;
  }
}

