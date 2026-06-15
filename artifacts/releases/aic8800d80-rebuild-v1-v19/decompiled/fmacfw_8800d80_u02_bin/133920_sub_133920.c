// sub_133920 @ 0x133920, size 52 bytes
// Doc: sub_1233920 [util]: Check global signed status word and branch
// sub_1233920 [util]: Check global signed status word and branch
int __fastcall sub_133920(int value)
{
  int v2; // r0

  if ( **(__int16 **)off_133954 >= 0 || (value = msg_get_value(6u), value == 10) )
  {
    sub_1347BC(value);
    return 0;
  }
  else
  {
    v2 = sub_12F46C(dword_13395C, dword_133958, 871);
    sub_1347BC(v2);
    return 0;
  }
}

