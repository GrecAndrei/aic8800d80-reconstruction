// bt_fw_init_or_handler @ 0x1029c4, size 16 bytes
// Doc: bt_fw_init_or_handler [bt]: Bluetooth firmware init/handler routine
// bt_fw_init_or_handler [bt]: Bluetooth firmware init/handler routine
_BYTE *__fastcall bt_fw_init_or_handler(_BYTE *result, _BYTE *a2)
{
  _BYTE *v2; // r3

  v2 = off_1029D4;
  *result = *((_BYTE *)off_1029D4 + 294);
  *a2 = v2[295];
  return result;
}

