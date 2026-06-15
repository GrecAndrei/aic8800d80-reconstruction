// v23 annotated: rf_bus_reset_n2c0 @ 0x112b04
// Original: 112b04_rf_bus_reset_n2c0.c
// Primary struct: <unclustered>
//
// rf_bus_reset_n2c0 @ 0x112b04, size 48 bytes
// Doc: rf_fault_dump_n41f [rf]: Dumps RF fault state
// rf_fault_dump_n41f [rf]: Dumps RF fault state
_BYTE *__fastcall rf_bus_reset_n2c0(int a1, int a2, int a3)
{
  _BYTE *result; // r0
  _DWORD *v4; // r2

  if ( (*((_WORD *)rf_cmd_send_n_338_2b34 + 89) & 0x4000) != 0 )
    result = sub_10D60C((_BYTE *)rf_bus_reset_n300);
  else
    result = (_BYTE *)sub_12ECB0(rf_cmd_send_n_334, a2, a3);
  v4 = rf_cmd_send_n_32c;
  *(_BYTE *)rf_bus_reset_n2f8 = 0;
  v4[896] &= ~1u;
  return result;
}

