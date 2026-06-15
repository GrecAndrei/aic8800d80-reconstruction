// v23 annotated: sub_132350 @ 0x132350
// Original: 132350_sub_132350.c
// Primary struct: <unclustered>
//
// sub_132350 @ 0x132350, size 144 bytes
int __fastcall sub_132350(int a1, _BYTE *a2, unsigned int a3, __int16 a4)
{
  _WORD *v7; // r7
  bool *v9; // r0
  char v10; // r1
  int v11; // r3

  if ( msg_get_value(5u) == 1 )
    return 2;
  v7 = off_1323E0;
  if ( *(_DWORD *)off_1323E0 )
  {
    if ( *a2 )
    {
      *(_DWORD *)off_1323E0 |= 1 << a2[1];
      message_dispatch_n84(5144, a4, a3);
      return 0;
    }
  }
  else if ( !*a2 )
  {
    message_dispatch_n84(5144, a4, a3);
    return 0;
  }
  v9 = (bool *)rf_bus_setup_n3a8(34, 0, a3, 1u);
  v10 = a2[1];
  if ( *a2 )
    v11 = (1 << v10) | *(_DWORD *)v7;
  else
    v11 = *(_DWORD *)v7 & ~(1 << v10);
  *(_DWORD *)v7 = v11;
  v7[4] = a4;
  *v9 = v11 == 0;
  sub_12CBB4((int)v9);
  rf_bus_mark_n_3b7(a3, 1);
  return 0;
}

