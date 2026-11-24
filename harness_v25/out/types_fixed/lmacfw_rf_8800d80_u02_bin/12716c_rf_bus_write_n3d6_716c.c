// rf_bus_write_n3d6_716c @ 0x12716c, size 36 bytes
// Doc: rf_level_apply_n3a6 [rf]: Apply RF TX power level adjustment
// rf_level_apply_n3a6 [rf]: Apply RF TX power level adjustment
int rf_bus_write_n3d6_716c()
{
  int result; // r0

  *((_BYTE *)off_127190 + 1) = 0;
  result = sub_11DDCC(1070, 1);
  if ( result )
    return event_queue_push(1070, 1);
  return result;
}

