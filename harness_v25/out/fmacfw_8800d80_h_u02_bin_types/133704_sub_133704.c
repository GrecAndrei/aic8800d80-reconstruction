// sub_133704 @ 0x133704, size 54 bytes
int  sub_133704(int a1, int a2, __int16 a3, __int16 a4)
{
  int v5; // r0
  __int16 v6; // r1
  __int16 v7; // r2
  __int16 v10; // [sp+0h] [bp-8h]
  __int16 v12; // [sp+4h] [bp-4h]

  v5 = sub_12CD48(6u);
  v6 = a4;
  v7 = a3;
  if ( v5 == 6 )
  {
    v10 = a3;
    v12 = v6;
    sub_1357F0(*(unsigned __int16 *)(a2 + 2));
    v7 = v10;
    v6 = v12;
  }
  sub_12C8D0(6156, v6, v7);
  return 0;
}

