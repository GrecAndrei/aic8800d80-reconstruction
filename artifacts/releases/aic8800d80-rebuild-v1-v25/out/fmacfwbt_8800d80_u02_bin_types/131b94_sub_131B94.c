// sub_131B94 @ 0x131b94, size 70 bytes
// Doc: sub_1231B9E [unknown]: Helper routine preserving r4, saving r2 to r4
// sub_1231B9E [unknown]: Helper routine preserving r4, saving r2 to r4
int  sub_131B94(int a1, int a2, unsigned int a3)
{
  int v4; // r1

  if ( **(__int16 **)off_131BDC < 0 && msg_get_value(a3) != 1 )
    sub_12F694(dword_131BE8, dword_131BE4, 670);
  v4 = *((unsigned __int16 *)off_131BE0 + 4);
  if ( v4 != 255 )
    message_dispatch_n84(5144, v4, a3);
  rf_bus_mark_n_3b7(a3, 0);
  return 0;
}

