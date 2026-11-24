// rf_msg_process_body_n_102 @ 0x135780, size 48 bytes
// Doc: rf_msg_process_body_n_102 [rf]: Processes RF message body with frequency and channel data
// rf_msg_process_body_n_102 [rf]: Processes RF message body with frequency and channel data
_DWORD *__fastcall rf_msg_process_body_n_102(__int16 a1)
{
  int v2; // r5
  int v3; // r0

  v2 = *((_DWORD *)off_1357B0 + 4);
  v3 = rf_bus_setup_n3a8(30, 0, 6, 4u);
  *(_WORD *)v3 = a1;
  *(_BYTE *)(v3 + 2) = 1;
  *(_BYTE *)(v3 + 3) = *(_BYTE *)(v2 + 61);
  sub_12CBB4(v3);
  return rf_bus_mark_n_3b7(6u, 9);
}

