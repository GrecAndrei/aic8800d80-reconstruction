// rf_iq_dc_calib_n7c @ 0x1197dc, size 186 bytes
// Doc: rf_iq_dc_calib_n7c [rf]: RF IQ/DC calibration init using 0x7c register
// rf_iq_dc_calib_n7c [rf]: RF IQ/DC calibration init using 0x7c register
int __fastcall rf_iq_dc_calib_n7c(int a1, _BYTE *a2, int a3, int a4)
{
  int v5; // r1
  _BYTE *v6; // r5
  char v7; // r2
  _BYTE *v8; // r6
  int v9; // r1
  _BYTE v11[5]; // [sp+7h] [bp-5h] BYREF

  v11[0] = 0;
  v6 = (_BYTE *)rf_setup_dispatch(124, a4, a3, 2);
  if ( *a2 )
  {
    msg_parse(dword_119898, v5);
    **(_BYTE **)off_11989C = 0;
  }
  else
  {
    msg_parse(dword_1198A8, v5);
    **(_BYTE **)off_11989C = 3;
  }
  rf_bus_handler_16c(v11);
  v7 = v11[0];
  v6[1] = v11[0];
  v8 = off_1198A0;
  if ( a2[1] )
    *((_BYTE *)off_1198A0 + 188) = (v7 & 0x20) != 0;
  else
    *((_BYTE *)off_1198A0 + 188) = (a2[2] & 0x20) != 0;
  if ( sub_1141F8() )
  {
    v8[188] = 0;
    v9 = 0;
  }
  else
  {
    v9 = (unsigned __int8)v8[188];
  }
  if ( *a2 )
  {
    if ( a2[3] )
      *((_WORD *)v8 + 89) |= 0x4000u;
    msg_parse(dword_1198A4, v9);
    LOBYTE(v9) = v8[188];
  }
  *v6 = v9;
  sub_11DE50(v6);
  return 0;
}

