// sub_1338E0 @ 0x1338e0, size 52 bytes
int __fastcall sub_1338E0(int value)
{
  int v2; // r0

  if ( **(__int16 **)off_133914 >= 0 || (value = msg_get_value(6u), value == 10) )
  {
    sub_1347BC(value);
    return 0;
  }
  else
  {
    v2 = sub_12F46C(dword_13391C, dword_133918, 898);
    sub_1347BC(v2);
    return 0;
  }
}

