// fwstruct annotate: 1337bc_sub_1337BC.c
// sub_1337BC @ 0x1337bc, size 52 bytes
int __fastcall sub_1337BC(int value)
{
  int v2; // r0

  if ( **(__int16 **)off_1337F0 >= 0 || (value = msg_get_value(6u), value == 10) )
  {
    sub_134DF0(value);
    return 0;
  }
  else
  {
    v2 = sub_12F46C(dword_1337F8, dword_1337F4, 1038);
    sub_134DF0(v2);
    return 0;
  }
}

