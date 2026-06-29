// fwstruct annotate: 102a38_bt_fw_init_or_status_check.c
// bt_fw_init_or_status_check @ 0x102a38, size 38 bytes
// Doc: bt_fw_init_or_status_check [bt]: BT firmware init/status check using global config and signed counter
// bt_fw_init_or_status_check [bt]: BT firmware init/status check using global config and signed counter
int __fastcall bt_fw_init_or_status_check(int a1, int a2, int a3)
{
  int result; // r0

  result = sub_12ECB0(dword_102A64, dword_102A60, a3);
  if ( **(__int16 **)off_102A68 < 0 )
    return sub_12F694(dword_102A70, dword_102A6C, 61);
  return result;
}

