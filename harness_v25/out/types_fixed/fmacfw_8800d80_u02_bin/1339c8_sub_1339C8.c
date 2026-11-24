// sub_1339C8 @ 0x1339c8, size 52 bytes
int __fastcall sub_1339C8(int value)
{
  int v2; // r0

  if ( **(__int16 **)off_1339FC >= 0 || (value = msg_get_value(6u), value == 4) )
  {
    sub_1347BC(value);
    return 0;
  }
  else
  {
    v2 = sub_12F46C(dword_133A04, dword_133A00, 670);
    sub_1347BC(v2);
    return 0;
  }
}

