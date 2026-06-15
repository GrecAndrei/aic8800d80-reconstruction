// v23 annotated: rf_init_blocka @ 0x10ef50
// Original: 10ef50_rf_init_blocka.c
// Primary struct: <unclustered>
//
// rf_init_blocka @ 0x10ef50, size 430 bytes
// Doc: rf_init_blocka [rf]: Initialize RF block A with config write and sub-call setup
// rf_init_blocka [rf]: Initialize RF block A with config write and sub-call setup
int rf_init_blocka()
{
  int result; // r0

  sub_10EE2C(1879048192, 256, 264, 1);
  sub_10EE2C(dword_10F100, 0x8000000, 0x8000000, 1);
  sub_10EE2C(dword_10F104, 21, 31, 1);
  sub_10EE2C(dword_10F110, dword_10F10C, dword_10F108, 1);
  sub_10EE2C(dword_10F114, 2560, 2560, 1);
  sub_10EE2C(dword_10F118, 255, 255, 1);
  sub_10EE2C(dword_10F11C, 0, 100663296, 1);
  sub_10EE2C(dword_10F120, 0, 983040, 1);
  sub_10EE2C(dword_10F124, 96, 96, 1);
  sub_10EE2C(dword_10F128, 256, 256, 1);
  sub_10EE2C(dword_10F12C, 469762048, 469762048, 1);
  sub_10EE2C(dword_10F130, 104, 252, 1);
  sub_10EE2C(dword_10F134, 6, 6, 1);
  sub_10EE2C(dword_10F138, 320, 992, 1);
  sub_10EE2C(dword_10F144, dword_10F140, dword_10F13C, 1);
  sub_10EE2C(dword_10F148, 0x400000, 15728640, 1);
  sub_10EE2C(dword_10F14C, 16, 63, 1);
  sub_10EE2C(dword_10F150, 0, 60, 1);
  sub_10EE2C(dword_10F154, 0, 256, 1);
  sub_10EE2C(dword_10F158, 2048, 16128, 1);
  result = sub_10EE2C(dword_10F15C, 1, 1, 1);
  if ( **(_BYTE **)off_10F160 == 1 )
  {
    rf_reg_write_wait(dword_10F168, dword_10F164, 1);
    rf_reg_write_wait(dword_10F170, dword_10F16C, 1);
    sub_10EE2C(dword_10F15C, 0x100000, 0x100000, 1);
    result = sub_10EE2C(dword_10F174, 2, 31, 1);
    if ( !*((_BYTE *)off_10F178 + 375) )
    {
      sub_10EE2C(dword_10F17C, 1, 1, 1);
      sub_10EE2C(dword_10F154, 256, 256, 1);
      sub_10EE2C(dword_10F158, 0x2000, 16128, 1);
      sub_10EE2C(dword_10F11C, 2359296, 16515072, 1);
      return sub_10EE2C(dword_10F15C, 256, 256, 1);
    }
  }
  return result;
}

