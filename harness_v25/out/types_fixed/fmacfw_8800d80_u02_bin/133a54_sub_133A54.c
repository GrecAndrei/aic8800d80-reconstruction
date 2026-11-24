// sub_133A54 @ 0x133a54, size 90 bytes
// Doc: sub_1233A54 [unknown]: Unidentified firmware routine in fmacfw
// sub_1233A54 [unknown]: Unidentified firmware routine in fmacfw
int sub_133A54()
{
  int v0; // r2
  int v2; // [sp+0h] [bp-Ch] BYREF
  int v3; // [sp+4h] [bp-8h] BYREF

  v0 = **(__int16 **)off_133AB0;
  v2 = 0;
  v3 = 0;
  if ( v0 < 0 && msg_get_value(6u) != 1 )
    sub_12F46C(dword_133AB8, dword_133AB4, 303);
  sub_134474(&v2, &v3);
  if ( v2 && v3 )
  {
    sub_1345C0();
    return 0;
  }
  else
  {
    sub_134E04(1);
    return 0;
  }
}

