// rf_level_apply_n1b8 @ 0x126f90, size 62 bytes
// Doc: rf_level_apply_n1ce [rf]: Apply RF level/temperature compensation delta
// rf_level_apply_n1ce [rf]: Apply RF level/temperature compensation delta
unsigned int rf_level_apply_n1b8()
{
  int v0; // s15
  int v1; // r3

  v0 = (int)COERCE_FLOAT(sub_10DEF0());
  msg_parse(rf_level_apply_n1f8, v0);
  v1 = (char)v0 - *((char *)off_126FD4 + 3);
  if ( v1 < 0 )
    v1 = *((char *)off_126FD4 + 3) - (char)v0;
  if ( v1 > 4 )
  {
    *((_BYTE *)off_126FD4 + 3) = v0;
    rf_level_compute((char)v0);
  }
  return rf_level_step();
}

