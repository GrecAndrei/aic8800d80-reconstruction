// sub_131B3C @ 0x131b3c, size 70 bytes
// Doc: sub_1231B46 [unknown]: Helper wrapper saving r2 to r4 before tail call
// sub_1231B46 [unknown]: Helper wrapper saving r2 to r4 before tail call
int  sub_131B3C(int a1, int a2, unsigned int a3)
{
  int v4; // r1

  if ( **(__int16 **)off_131B84 < 0 && msg_get_value(a3) != 1 )
    sub_12F694(dword_131B90, dword_131B8C, 822);
  v4 = *((unsigned __int16 *)off_131B88 + 4);
  if ( v4 != 255 )
    message_dispatch_n84(5146, v4, a3);
  rf_bus_mark_n_3b7(a3, 0);
  return 0;
}

