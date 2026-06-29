// rf_status_check_init @ 0x119f10, size 118 bytes
// Doc: rf_status_check_init [util]: Check status flag and initialize RF context state
// rf_status_check_init [util]: Check status flag and initialize RF context state
int  rf_status_check_init(int a1, void ( **a2)(int), int a3)
{
  __int16 **v3; // r5
  int result; // r0
  int v7; // r0

  v3 = (__int16 **)off_119F88;
  if ( **(__int16 **)off_119F88 < 0 && sub_11E34C(a3) == 4 )
    rf_cmd_send_n264(dword_119F90, dword_119F8C, 1587);
  result = sub_11E34C(a3);
  if ( result )
  {
    if ( result != 2 )
    {
      sub_11D01C();
      sub_11E1E4(a3);
      return 2;
    }
  }
  else
  {
    if ( **v3 < 0 && *(uint32_t *)off_119F94 << 28 )
      rf_cmd_send_n264(dword_119F98, dword_119F8C, 1594);
    v7 = sub_11E1E4(a3);
    (*a2)(v7);
    return 0;
  }
  return result;
}

