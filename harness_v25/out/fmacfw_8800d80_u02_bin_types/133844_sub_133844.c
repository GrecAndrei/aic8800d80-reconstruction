// sub_133844 @ 0x133844, size 54 bytes
int  sub_133844(int a1, int a2, __int16 a3, __int16 a4)
{
  int value; // r0
  __int16 v6; // r1
  __int16 v7; // r2
  __int16 v10; // [sp+0h] [bp-8h]
  __int16 v12; // [sp+4h] [bp-4h]

  value = msg_get_value(6u);
  v6 = a4;
  v7 = a3;
  if ( value == 6 )
  {
    v10 = a3;
    v12 = v6;
    sub_135930(*(unsigned __int16 *)(a2 + 2));
    v7 = v10;
    v6 = v12;
  }
  sub_12CA10(6156, v6, v7);
  return 0;
}

