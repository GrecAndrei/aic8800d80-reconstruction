// fwstruct annotate: 136504_sub_136504.c
// sub_136504 @ 0x136504, size 52 bytes
// Doc: sub_1236504 [util]: Loads a signed halfword from a global pointer table
// sub_1236504 [util]: Loads a signed halfword from a global pointer table
int __fastcall sub_136504(int value)
{
  int v2; // r0

  if ( **(__int16 **)off_136538 >= 0 || (value = msg_get_value(7u), value == 1) )
  {
    sub_13697C(value);
    return 0;
  }
  else
  {
    v2 = sub_12F694(dword_136540, dword_13653C, 311);
    sub_13697C(v2);
    return 0;
  }
}

