// sub_133BE4 @ 0x133be4, size 52 bytes
int  sub_133BE4(int value)
{
  int v2; // r0

  if ( **(__int16 **)off_133C18 >= 0 || (value = msg_get_value(6u), value == 4) )
  {
    sub_1349D8(value);
    return 0;
  }
  else
  {
    v2 = sub_12F694(dword_133C20, dword_133C1C, 670);
    sub_1349D8(v2);
    return 0;
  }
}

