// fwstruct annotate: 12b114_mac_check_msg_id_0x96c.c
// mac_check_msg_id_0x96c @ 0x12b114, size 88 bytes
// Doc: mac_check_msg_id_0x96c [mac]: Check incoming message id against 0x96c and dispatch via context
// mac_check_msg_id_0x96c [mac]: Check incoming message id against 0x96c and dispatch via context
int __fastcall mac_check_msg_id_0x96c(unsigned __int16 *a1)
{
  int v1; // r3
  int result; // r0

  v1 = *a1;
  result = *(_DWORD *)(*(_DWORD *)off_12B16C + 16);
  if ( v1 == 2412
    || v1 == 2437
    || v1 == 2462
    || v1 == 2472
    || v1 == 5180
    || v1 == 5220
    || v1 == 5765
    || v1 == 5785
    || v1 == 5805 )
  {
    result += 20000;
  }
  return result;
}

