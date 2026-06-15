// rf_register_shift_n7d64 @ 0x117d64, size 168 bytes
// Doc: rf_register_shift_n7d64 [rf]: Shifts and masks RF register value loaded from HW table
// rf_register_shift_n7d64 [rf]: Shifts and masks RF register value loaded from HW table
int __fastcall rf_register_shift_n7d64(int result)
{
  int v1; // r4
  int v2; // r5
  unsigned int v3; // r3
  unsigned int v4; // r4

  v1 = *(_DWORD *)off_117E0C;
  if ( (*(_DWORD *)off_117E0C & 0x1000) != 0 )
  {
    result = mmio_init_subsystem(result, *(_DWORD *)off_117E0C << 19);
    *(_DWORD *)off_117E20 = 4096;
  }
  v2 = dword_117E10;
  if ( (v1 & dword_117E10) != 0 )
  {
    result = bt_msg_handler_n_ed4();
    *(_DWORD *)off_117E20 = v2;
  }
  if ( (dword_117E14 & v1) != 0 && (*(_DWORD *)off_117E18 & 0x300000) == 0 )
  {
    *(_DWORD *)off_117E28 |= 0x200u;
    v3 = dword_117E1C & v1;
    if ( (dword_117E1C & v1) == 0 )
      return result;
  }
  else
  {
    v3 = dword_117E1C & v1;
    if ( (dword_117E1C & v1) == 0 )
      return result;
  }
  if ( (v1 & 0x80000) != 0 )
  {
LABEL_9:
    *(_DWORD *)off_117E20 = 0x80000;
    return sub_1174B4(5);
  }
  v4 = (unsigned __int8)(25 - __clz(v3));
  if ( **(__int16 **)off_117E24 >= 0 || v4 <= 6 )
  {
    if ( v4 == 5 )
      goto LABEL_9;
  }
  else
  {
    sub_12F694(dword_117E30, dword_117E2C, 2883);
  }
  *(_DWORD *)off_117E20 = 1 << (v4 + 6);
  return sub_1174B4(v4);
}

