// sub_1362F8 @ 0x1362f8, size 52 bytes
// Doc: sub_12362F8 [util]: Checks a global state value and branches on result
// sub_12362F8 [util]: Checks a global state value and branches on result
int __fastcall sub_1362F8(int value)
{
  int v2; // r0

  if ( **(__int16 **)off_13632C >= 0 || (value = msg_get_value(7u), value == 1) )
  {
    sub_136820(value);
    return 0;
  }
  else
  {
    v2 = sub_12F46C(dword_136334, dword_136330, 311);
    sub_136820(v2);
    return 0;
  }
}

